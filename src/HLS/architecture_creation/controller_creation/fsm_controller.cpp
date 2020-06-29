/*
 *
 *                   _/_/_/    _/_/   _/    _/ _/_/_/    _/_/
 *                  _/   _/ _/    _/ _/_/  _/ _/   _/ _/    _/
 *                 _/_/_/  _/_/_/_/ _/  _/_/ _/   _/ _/_/_/_/
 *                _/      _/    _/ _/    _/ _/   _/ _/    _/
 *               _/      _/    _/ _/    _/ _/_/_/  _/    _/
 *
 *             ***********************************************
 *                              PandA Project
 *                     URL: http://panda.dei.polimi.it
 *                       Politecnico di Milano - DEIB
 *                        System Architectures Group
 *             ***********************************************
 *              Copyright (C) 2004-2020 Politecnico di Milano
 *
 *   This file is part of the PandA framework.
 *
 *   The PandA framework is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
/**
 * @file fsm_controller.cpp
 * @brief Starting from the FSM graph, it builds a state transition table
 *
 * @author Christian Pilato <pilato@elet.polimi.it>
 * @author Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
 *
 */

#include "fsm_controller.hpp"

#include "behavioral_helper.hpp"
#include "function_behavior.hpp"
#include "hls.hpp"
#include "hls_manager.hpp"

#include "BambuParameter.hpp"

#include "commandport_obj.hpp"
#include "conn_binding.hpp"
#include "connection_obj.hpp"
#include "fu_binding.hpp"
#include "funit_obj.hpp"
#include "mux_obj.hpp"
#include "reg_binding.hpp"
#include "register_obj.hpp"
#include "schedule.hpp"

#include "state_transition_graph.hpp"
#include "state_transition_graph_manager.hpp"

#include "exceptions.hpp"
#include <iosfwd>

#include "tree_helper.hpp"
#include "tree_manager.hpp"
#include "tree_node.hpp"
#include "tree_reindex.hpp"

#include "structural_manager.hpp"
#include "structural_objects.hpp"

#include "dbgPrintHelper.hpp"
#include "op_graph.hpp"
#include "technology_manager.hpp"
#include "time_model.hpp"

/// HLS/binding/storage_value_insertion
#include "storage_value_information.hpp"

/// HLS/liveness include
#include "liveness.hpp"

/// HLS/module_allocation
#include "allocation_information.hpp"

/// STL includes
#include "custom_map.hpp"
#include "custom_set.hpp"
#include <deque>
#include <list>
#include <utility>
#include <vector>

/// technology/physical_library include
#include "technology_node.hpp"

#include "copyrights_strings.hpp"
#include "string_manipulation.hpp" // for GET_CLASS

#include "basic_block.hpp"

fsm_controller::fsm_controller(const ParameterConstRef _Param, const HLS_managerRef _HLSMgr, unsigned int _funId, const DesignFlowManagerConstRef _design_flow_manager, const HLSFlowStep_Type _hls_flow_step_type)
    : ControllerCreatorBaseStep(_Param, _HLSMgr, _funId, _design_flow_manager, _hls_flow_step_type)
{
   debug_level = parameters->get_class_debug_level(GET_CLASS(*this), DEBUG_LEVEL_NONE);
}

fsm_controller::~fsm_controller() = default;

DesignFlowStep_Status fsm_controller::InternalExec()
{
   THROW_ASSERT(HLS->STG, "State transition graph not created");

   /// top circuit creation
   PRINT_DBG_MEX(DEBUG_LEVEL_VERBOSE, debug_level, "FSM based controller creation");
   const FunctionBehaviorConstRef FB = HLSMgr->CGetFunctionBehavior(funId);

   const std::string function_name = FB->CGetBehavioralHelper()->get_function_name();
   /// main circuit type
   structural_type_descriptorRef module_type = structural_type_descriptorRef(new structural_type_descriptor("controller_" + function_name));

   SM->set_top_info("Controller_i", module_type);
   structural_objectRef circuit = this->SM->get_circ();
   // Now the top circuit is created, just as an empty box. <circuit> is a reference to the structural object that
   // will contain all the circuit components

   circuit->set_black_box(false);

   /// Set some descriptions and legal stuff
   GetPointer<module>(circuit)->set_description("FSM based controller description for " + function_name);
   GetPointer<module>(circuit)->set_copyright(GENERATED_COPYRIGHT);
   GetPointer<module>(circuit)->set_authors("Component automatically generated by bambu");
   GetPointer<module>(circuit)->set_license(GENERATED_LICENSE);

   // Add clock, reset, done and command ports
   this->add_common_ports(circuit);

   PRINT_DBG_MEX(DEBUG_LEVEL_PEDANTIC, debug_level, "Creating state machine representations...");
   std::string state_representation;
   this->create_state_machine(state_representation);
   add_correct_transition_memory(state_representation); // if CS is activated some register are memory

   PRINT_DBG_MEX(DEBUG_LEVEL_PEDANTIC, debug_level, "Machine encoding");
   PRINT_DBG_MEX(DEBUG_LEVEL_PEDANTIC, debug_level, state_representation);
   PRINT_DBG_MEX(DEBUG_LEVEL_PEDANTIC, debug_level, "****");

   PRINT_DBG_MEX(DEBUG_LEVEL_VERBOSE, debug_level, "Circuit created without errors!");
   return DesignFlowStep_Status::SUCCESS;
}

static std::string input_vector_to_string(const std::vector<long long int>& to_be_printed, bool with_comma)
{
   std::string output;
   for(unsigned int i = 0; i < to_be_printed.size(); i++)
   {
      output += (to_be_printed[i] == default_COND ? "-" : std::to_string(to_be_printed[i]));
      if(i != (to_be_printed.size() - 1) && with_comma)
         output += ",";
   }
   return output;
}


void fsm_controller::create_state_machine(std::string& parse)
{
   INDENT_DBG_MEX(DEBUG_LEVEL_PEDANTIC, debug_level, "-->Create state machine");
   const StateTransitionGraphConstRef stg = HLS->STG->CGetStg();
   const StateTransitionGraphConstRef astg = HLS->STG->CGetAstg();
   const FunctionBehaviorConstRef FB = HLSMgr->CGetFunctionBehavior(funId);
   const OpGraphConstRef data = FB->CGetOpGraph(FunctionBehavior::CFG);

   vertex entry = HLS->STG->get_entry_state();
   THROW_ASSERT(boost::out_degree(entry, *stg) == 1, "Non deterministic initial state");
   OutEdgeIterator oe, oend;
   boost::tie(oe, oend) = boost::out_edges(entry, *stg);
   /// Getting first state (initial one). It will be also first state for resetting
   vertex first_state = boost::target(*oe, *stg);
   /// adding reset state to machine encoding
   parse += stg->CGetStateInfo(first_state)->name + " " + RESET_PORT_NAME + " " + START_PORT_NAME + " " + CLOCK_PORT_NAME + "; ";

   const auto& selectors = HLS->Rconn->GetSelectors();

   std::map<vertex, std::vector<long long int>> present_state;
   CustomOrderedSet<unsigned int> unbounded_ports;

   /// analysis for each state to compute the default output
   INDENT_DBG_MEX(DEBUG_LEVEL_PEDANTIC, debug_level, "-->Computation of default output of each state");
   std::list<vertex> working_list;
   //both operations and states are named as vertex
   astg->TopologicalSort(working_list); //astg acyclic state transition graph è quello che interessa a noi
   THROW_ASSERT(std::find(working_list.begin(), working_list.end(), first_state) != working_list.end(), "unexpected case"); 
   working_list.erase(std::find(working_list.begin(), working_list.end(), first_state));
   working_list.push_front(first_state); /// ensure that first_state is the really first one...
   
   std::vector<std::map<std::string, bool>> clock_gating_structure;

   for(const auto&v : working_list){
      std::map<std::string, bool> sub_str_gating;
      const auto& exec_op = astg->CGetStateInfo(v)->executing_operations;
      PRINT_DBG_STRING(DEBUG_LEVEL_PEDANTIC, debug_level, "Checking clock gating for state: " + astg->CGetStateInfo(v)->name + "\n");
      for(const auto& op : exec_op) {
         PRINT_DBG_STRING(DEBUG_LEVEL_PEDANTIC, debug_level, "Operation: " + GET_NAME(data, op) + "\n");
         //active clock gating, the value is true
         sub_str_gating.insert(std::pair<std::string, bool>(GET_NAME(data, op),true));
         if(!clock_gating_structure.empty()) {
            for(auto& state : clock_gating_structure){
               if (state.find(GET_NAME(data, op)) == state.end() ) {
               // not found
                  state.insert(std::pair<std::string, bool>(GET_NAME(data, op), false));  
               } else {
               // found
                  state.find(GET_NAME(data, op))->second = true;
               }
               // check if present   
            }
         }
      }
      //from the first state, the elements are propagated forward in the vector. Because the code above propagete backward all the FU found
      if(!clock_gating_structure.empty()) {
         for(auto& eo : clock_gating_structure[0]) {
            if (sub_str_gating.find(eo.first) == sub_str_gating.end() ) {
            // not found
               sub_str_gating.insert(std::pair<std::string, bool>(eo.first, true));  
            }
         }
      }
      clock_gating_structure.push_back(sub_str_gating);
   }

   int i = 0;
   for(const auto& cg : clock_gating_structure) {
      PRINT_DBG_STRING(DEBUG_LEVEL_PEDANTIC, debug_level, "Checking clock gating for state: S_" + std::to_string(i) + "\n");
      for(const auto& op : cg) {
            PRINT_DBG_STRING(DEBUG_LEVEL_PEDANTIC, debug_level, "- Operation: " + op.first + ", clock gating value: " + std::to_string(op.second) + "\n");
      }
      i++;
   }

   std::map<vertex, std::vector<bool>> state_Xregs;
   std::map<unsigned int, unsigned int> wren_list;
   std::map<unsigned int, unsigned int> register_selectors;

   std::map<unsigned int, CustomUnorderedSet<vertex>> loop_map;
   std::map<unsigned int, std::list<vertex>> loop_executing_ops;
   std::map<unsigned int, std::list<vertex>> loop_starting_ops;
   CustomUnorderedSet<unsigned int> analyzed_loops;
   std::map<unsigned int, vertex> loop_last_state;

   // group vertices under their respective loopId
   if(FB->is_pipelining_enabled())
   {
      for(const auto& v : working_list)
      {
         auto info = astg->CGetStateInfo(v);
         // checking only the pipeline_enabled condition is sufficient
         // since this step is taken only for stallable pipelines
         if(info->loopId != 0)
         {
            loop_map[info->loopId].insert(v);
         }
      }
   }

   // detect entry and exit node for each loop
   for(auto loop : loop_map)
   {
      vertex loop_first_state = first_state;
      InEdgeIterator ie, iend;

#if HAVE_ASSERTS
      bool found_first = false;
      bool found_last = false;
#endif
      OutEdgeIterator lst, lstend;

      for(vertex v : loop_map[get<0>(loop)])
      {
         for(boost::tie(ie, iend) = boost::in_edges(v, *astg); ie != iend; ++ie)
         {
            if(stg->CGetStateInfo(boost::source(*ie, *astg))->loopId != std::get<0>(loop))
            {
               THROW_ASSERT(not found_first, "A loop has multiple first states");
#if HAVE_ASSERTS
               found_first = true;
#endif
               loop_first_state = v;
            }
         }
         bool all_external = true;
         for(boost::tie(lst, lstend) = boost::out_edges(v, *astg); lst != lstend; ++lst)
         {
            all_external = all_external && astg->CGetStateInfo(boost::target(*lst, *astg))->loopId != std::get<0>(loop);
            if(!all_external)
               break;
         }
         if(all_external)
         {
            THROW_ASSERT(not found_last, "A loop has multiple outgoing edges");
#if HAVE_ASSERTS
            found_last = true;
#endif
            loop_last_state[std::get<0>(loop)] = v;
         }
         for(auto op : stg->CGetStateInfo(v)->executing_operations)
         {
            loop_executing_ops[get<0>(loop)].push_front(op);
         }
      }
      THROW_ASSERT(found_last, "No last state was detected for loop " + std::to_string(get<0>(loop)));
      THROW_ASSERT(found_first, "No first state was detected for loop " + std::to_string(get<0>(loop)));
      loop_starting_ops[get<0>(loop)] = stg->CGetStateInfo(loop_first_state)->starting_operations;
   }

   for(const auto& v : working_list)
   {
      state_Xregs[v] = std::vector<bool>(HLS->Rreg->get_used_regs(), true);
      INDENT_DBG_MEX(DEBUG_LEVEL_PEDANTIC, debug_level, "-->Analyzing state " + astg->CGetStateInfo(v)->name);
      INDENT_DBG_MEX(DEBUG_LEVEL_PEDANTIC, debug_level, "---------------------------------------------------------------------------------------------------- " );

      if(analyzed_loops.find(stg->CGetStateInfo(v)->loopId) == analyzed_loops.end())
      {
         INDENT_DBG_MEX(DEBUG_LEVEL_PEDANTIC, debug_level, "Analyzing loop " + std::to_string(stg->CGetStateInfo(v)->loopId));
         present_state[v] = std::vector<long long int>(out_num, 0);
         if(stg->CGetStateInfo(v)->loopId != 0 && FB->is_pipelining_enabled())
         {
            analyzed_loops.insert(stg->CGetStateInfo(v)->loopId);
         }
         if(selectors.find(conn_binding::IN) != selectors.end())
         {
            for(const auto& s : selectors.at(conn_binding::IN))
            {
#ifndef NDEBUG
               std::map<vertex, CustomOrderedSet<vertex>> activations_check;
#endif
               const auto& activations = GetPointer<commandport_obj>(s.second)->get_activations();
               for(const auto& a : activations)
               {
#ifndef NDEBUG
                  if(activations_check.find(std::get<0>(a)) != activations_check.end())
                  {
                     THROW_ASSERT(!activations_check.find(std::get<0>(a))->second.empty(), "empty set not expected here");
                     if(activations_check.at(std::get<0>(a)).find(std::get<1>(a)) == activations_check.at(std::get<0>(a)).end())
                     {
                        if(std::get<1>(a) == NULL_VERTEX)
                           THROW_ERROR("non compatible transitions added");
                        else if(activations_check.at(std::get<0>(a)).find(NULL_VERTEX) != activations_check.at(std::get<0>(a)).end())
                           THROW_ERROR("non compatible transitions added");
                        else
                           activations_check[std::get<0>(a)].insert(std::get<1>(a));
                     }
                     else
                     {
                        THROW_ERROR("activation already added");
                     }
                  }
                  else
                     activations_check[std::get<0>(a)].insert(std::get<1>(a));
#endif
                  if(std::get<0>(a) == v && (stg->CGetStateInfo(v)->loopId == 0 || !FB->is_pipelining_enabled()))
                  {
                     present_state[v][out_ports[s.second]] = 1;
                  }
                  else if(loop_map[stg->CGetStateInfo(v)->loopId].find(std::get<0>(a)) != loop_map[stg->CGetStateInfo(v)->loopId].end() && stg->CGetStateInfo(v)->loopId != 0 && FB->is_pipelining_enabled())
                  {
                     present_state[v][out_ports[s.second]] = 1;
                  }
               }
            }
         }

         CustomOrderedSet<generic_objRef> active_fu;
         const tree_managerRef TreeM = HLSMgr->get_tree_manager();
         const auto& operations = (stg->CGetStateInfo(v)->loopId == 0 || !FB->is_pipelining_enabled()) ? astg->CGetStateInfo(v)->executing_operations : loop_executing_ops[stg->CGetStateInfo(v)->loopId];
         for(const auto& op : operations) //chiedere l executing operations, starting e le ending, 
         {
            active_fu.insert(HLS->Rfu->get(op));
            technology_nodeRef tn = HLS->allocation_information->get_fu(HLS->Rfu->get_assign(op));//get functional unit, a noi interessa create state machine non passiamo passare per copia o per riferimento alla struttura, la struttura riempita con module biding. 
            
            //usando questi metodi qua possiamo capire quali unita stanno andando. ogni stato ha un tot di operazioni, per ogni operazione di stato 
            //non ha senso definire clock gating su operazioni combinatorie, ma per quelle non combinatorie, se sono executing non possiamo fare clock gating, per quelli non executing dobbiamo fare clock gating
            //print viene stampata, mentre debug viene stampato solo se viene chiamato...... per ogni stato, quante operazioni possono usufruire del clock gating, di default le pongo tutte a zero, per le componenti che stanno eseguendo le metto a 1
            //distinguere add da adder.
            //per ogni stato i stati, non tutte le non executing ed executing operation non sono mostrati, avere una struttura dinamica, tale per cui per ogni elemento della lista confrontiamo quello che c'è e quello che non c'è ancora sulla lista ed aggiungerli ne caso con un valore di clock gating dettato dallo stato
            //fare uno scheduling e poi andare a modificare 
            //HLS ha tutte le informazioni su tutta la struttura di creazione per la sintesi.
            

            technology_nodeRef op_tn = GetPointer<functional_unit>(tn)->get_operation(tree_helper::normalized_ID(data->CGetOpNodeInfo(op)->GetOperation()));
            THROW_ASSERT(GetPointer<operation>(op_tn)->time_m, "Time model not available for operation: " + GET_NAME(data, op));
            structural_managerRef CM = GetPointer<functional_unit>(tn)->CM;
            if(!CM)
               continue;
            structural_objectRef top = CM->get_circ();
            THROW_ASSERT(top, "expected");
            auto* fu_module = GetPointer<module>(top);
            THROW_ASSERT(fu_module, "expected");
            structural_objectRef start_port_i = fu_module->find_member(START_PORT_NAME, port_o_K, top);
            structural_objectRef done_port_i = fu_module->find_member(DONE_PORT_NAME, port_o_K, top);
            /// do some checks
            if(!GetPointer<operation>(op_tn)->is_bounded() && (!start_port_i || !done_port_i))
               THROW_ERROR("Unbounded operations have to have both done_port and start_port ports!" + STR(TreeM->CGetTreeNode(data->CGetOpNodeInfo(op)->GetNodeId())));
            bool is_starting_operation;
            if(stg->CGetStateInfo(v)->loopId == 0 || !FB->is_pipelining_enabled())
               is_starting_operation = std::find(stg->CGetStateInfo(v)->starting_operations.begin(), stg->CGetStateInfo(v)->starting_operations.end(), op) != stg->CGetStateInfo(v)->starting_operations.end();
            else
            {
               // since v now has to wait for loop completion, every operation will be unbounded
               is_starting_operation = true;
            }
            if(((GET_TYPE(data, op) & TYPE_EXTERNAL && start_port_i) or !GetPointer<operation>(op_tn)->is_bounded() or start_port_i) and !stg->CGetStateInfo(v)->is_dummy and is_starting_operation)
            {
               unsigned int unbounded_port = out_ports[HLS->Rconn->bind_selector_port(conn_binding::IN, commandport_obj::UNBOUNDED, op, data)];
               unbounded_ports.insert(unbounded_port);
               present_state[v][unbounded_port] = 1;
            }
         }
         if(stg->CGetStateInfo(v)->loopId == 0 || !FB->is_pipelining_enabled())
         {
            for(auto in0 : HLS->Rliv->get_live_in(v))
            {
               if(HLS->storage_value_information->is_a_storage_value(v, in0))
               {
                  unsigned int storage_value_index = HLS->storage_value_information->get_storage_value_index(v, in0);
                  unsigned int accessed_reg = HLS->Rreg->get_register(storage_value_index);
                  state_Xregs[v][accessed_reg] = false;
               }
            }

            if(selectors.find(conn_binding::IN) != selectors.end())
            {
               for(const auto& s : selectors.at(conn_binding::IN))
               {
                  if(s.second->get_type() == generic_obj::COMMAND_PORT)
                  {
                     auto current_port = GetPointer<commandport_obj>(s.second);
                     // compute X values for wr_enable signals
                     if(current_port->get_command_type() == commandport_obj::command_type::WRENABLE)
                     {
                        auto reg_obj = GetPointer<register_obj>(current_port->get_elem());
                        wren_list.insert(std::make_pair(reg_obj->get_register_index(), out_ports[s.second]));
                        if(parameters->IsParameter("enable-FSMX") && parameters->GetParameter<int>("enable-FSMX") == 1)
                        {
                           if(state_Xregs[v][reg_obj->get_register_index()] && v != first_state)
                           {
                              present_state[v][out_ports[s.second]] = 2;
                              PRINT_DBG_STRING(DEBUG_LEVEL_PEDANTIC, debug_level, "Set X value for wr_en on register reg_");
                              PRINT_DBG_STRING(DEBUG_LEVEL_PEDANTIC, debug_level, reg_obj->get_register_index());
                              PRINT_DBG_STRING(DEBUG_LEVEL_PEDANTIC, debug_level, "\n");
                           }
                        }
                     }
                     else if(current_port->get_command_type() == commandport_obj::command_type::SELECTOR)
                     {
                        auto selector_slave = current_port->get_elem();
                        if(GetPointer<mux_obj>(selector_slave))
                        {
                           auto mux_slave = GetPointer<mux_obj>(selector_slave)->get_final_target();
                           if(mux_slave->get_type() == generic_obj::resource_type::REGISTER)
                           {
                              unsigned int reg_index = GetPointer<register_obj>(mux_slave)->get_register_index();
                              register_selectors[out_ports[s.second]] = reg_index;
                           }
                           else if(mux_slave->get_type() == generic_obj::resource_type::FUNCTIONAL_UNIT && active_fu.find(mux_slave) == active_fu.end())
                           {
                              if(parameters->IsParameter("enable-FSMX") && parameters->GetParameter<int>("enable-FSMX") == 1)
                                 present_state[v][out_ports[s.second]] = 2;
                           }
                        }
                     }
                  }
               }
            }
         }
      }

#ifndef NDEBUG
      INDENT_DBG_MEX(DEBUG_LEVEL_PEDANTIC, debug_level, "-->default output after considering unbounded:");
      for(const auto a : present_state[v])
         PRINT_DBG_STRING(DEBUG_LEVEL_PEDANTIC, debug_level, STR(a));
      PRINT_DBG_STRING(DEBUG_LEVEL_PEDANTIC, debug_level, "\n");
      INDENT_DBG_MEX(DEBUG_LEVEL_PEDANTIC, debug_level, "<--");
#endif
      INDENT_DBG_MEX(DEBUG_LEVEL_PEDANTIC, debug_level, "<--");
   }
   INDENT_DBG_MEX(DEBUG_LEVEL_PEDANTIC, debug_level, "<--Computed default output of each state");

   parse += "\n";

   analyzed_loops.clear();

   const tree_managerRef TreeM = HLSMgr->get_tree_manager();
   for(const auto& v : working_list)
   {
      // for every loop controller set the proper transition depending on the done port
      if(HLS->STG->get_entry_state() == v or HLS->STG->get_exit_state() == v)
         continue;

      // skip all but one state per loop
      if(analyzed_loops.find(stg->CGetStateInfo(v)->loopId) == analyzed_loops.end())
      {
         if(stg->CGetStateInfo(v)->loopId != 0 && FB->is_pipelining_enabled())
         {
            analyzed_loops.insert(stg->CGetStateInfo(v)->loopId);
         }
         INDENT_DBG_MEX(DEBUG_LEVEL_PEDANTIC, debug_level, "-->Analyzing state " + stg->CGetStateInfo(v)->name);

         parse += stg->CGetStateInfo(v)->name + " 0" + input_vector_to_string(present_state[v], 0);

         std::list<EdgeDescriptor> sorted;
         EdgeDescriptor default_edge;
         bool found_default = false;
         vertex ver;
         if(stg->CGetStateInfo(v)->loopId == 0 || !FB->is_pipelining_enabled())
            ver = v;
         else
            ver = loop_last_state[stg->CGetStateInfo(v)->loopId];
         for(boost::tie(oe, oend) = boost::out_edges(ver, *stg); oe != oend; oe++)
         {
            if(!found_default)
            {
               if(stg->CGetTransitionInfo(*oe)->get_has_default())
               {
                  found_default = true;
                  default_edge = *oe;
               }
               if(!found_default)
                  sorted.push_back(*oe);
            }
            else
               sorted.push_back(*oe);
         }
         if(found_default)
            sorted.push_back(default_edge);
         INDENT_DBG_MEX(DEBUG_LEVEL_PEDANTIC, debug_level, "---Sorted next states");

         bool done_port_is_registered = HLS->registered_done_port;
         for(const auto e : sorted)
         {
            INDENT_DBG_MEX(DEBUG_LEVEL_PEDANTIC, debug_level, "-->Considering successor state " + stg->CGetStateInfo(boost::target(e, *stg))->name);
            INDENT_DBG_MEX(DEBUG_LEVEL_PEDANTIC, debug_level, "---Number of inputs is " + boost::lexical_cast<std::string>(in_num));
            std::vector<std::string> in(in_num, "-");

            INDENT_DBG_MEX(DEBUG_LEVEL_VERY_PEDANTIC, debug_level, "-->Analyzing condition");
            auto transitionType = stg->CGetTransitionInfo(e)->get_type();
            if(transitionType == DONTCARE_COND)
               ; // do nothing
            else if(transitionType == TRUE_COND)
            {
               auto op = stg->CGetTransitionInfo(e)->get_operation();
               THROW_ASSERT(cond_ports.find(op) != cond_ports.end(), "the port is missing");
               THROW_ASSERT(in[cond_ports.find(op)->second] == "-", "two different values for the same condition port");
               in[cond_ports.find(op)->second] = "1";
            }
            else if(transitionType == FALSE_COND)
            {
               auto op = stg->CGetTransitionInfo(e)->get_operation();
               THROW_ASSERT(cond_ports.find(op) != cond_ports.end(), "the port is missing");
               THROW_ASSERT(in[cond_ports.find(op)->second] == "-", "two different values for the same condition port");
               in[cond_ports.find(op)->second] = "0";
            }
            else if(transitionType == ALL_FINISHED)
            {
               auto ops = stg->CGetTransitionInfo(e)->get_operations();
               if(ops.size() == 1)
               {
                  auto op = *(ops.begin());
                  THROW_ASSERT(cond_ports.find(op) != cond_ports.end(), "the port is missing");
                  THROW_ASSERT(in[cond_ports.find(op)->second] == "-", "two different values for the same condition port");
                  in[cond_ports.find(op)->second] = "1";
               }
               else
               {
                  auto state = stg->CGetTransitionInfo(e)->get_ref_state();
                  THROW_ASSERT(mu_ports.find(state) != mu_ports.end(), "the port is missing");
                  THROW_ASSERT(in[mu_ports.find(state)->second] == "-", "two different values for the same condition port");
                  in[mu_ports.find(state)->second] = "1";
               }
            }
            else if(transitionType == NOT_ALL_FINISHED)
            {
               auto ops = stg->CGetTransitionInfo(e)->get_operations();
               if(ops.size() == 1)
               {
                  auto op = *(ops.begin());
                  THROW_ASSERT(cond_ports.find(op) != cond_ports.end(), "the port is missing");
                  THROW_ASSERT(in[cond_ports.find(op)->second] == "-", "two different values for the same condition port");
                  in[cond_ports.find(op)->second] = "0";
               }
               else
               {
                  auto state = stg->CGetTransitionInfo(e)->get_ref_state();
                  THROW_ASSERT(mu_ports.find(state) != mu_ports.end(), "the port is missing");
                  THROW_ASSERT(in[mu_ports.find(state)->second] == "-", "two different values for the same condition port");
                  in[mu_ports.find(state)->second] = "0";
               }
            }
            else if(transitionType == CASE_COND)
            {
               auto op = stg->CGetTransitionInfo(e)->get_operation();
               THROW_ASSERT(cond_ports.find(op) != cond_ports.end(), "the port is missing");
               THROW_ASSERT(in[cond_ports.find(op)->second] == "-", "two different values for the same condition port");
               std::string value = in[cond_ports.find(op)->second];
               THROW_ASSERT(value == "-", "two different values for the same condition port");
               auto labels = stg->CGetTransitionInfo(e)->get_labels();
               for(auto label : labels)
               {
                  if(value == "-")
                     value = get_guard_value(TreeM, label, op, data);
                  else
                     value += "|" + get_guard_value(TreeM, label, op, data);
               }
               if(stg->CGetTransitionInfo(e)->get_has_default())
               {
                  if(value == "-")
                     value = STR(default_COND);
                  else
                     value += "|" + STR(default_COND);
               }
               in[cond_ports.find(op)->second] = value;
            }
            else
               THROW_ERROR("transition type not supported yet");
            INDENT_DBG_MEX(DEBUG_LEVEL_PEDANTIC, debug_level, "<--Analyzed conditions: " + parse);

            parse += " : ";
            for(std::vector<std::string>::const_iterator in_it = in.begin(); in_it != in.end(); ++in_it)
               if(in_it == in.begin())
                  parse += *in_it;
               else
                  parse += "," + *in_it;

            vertex tgt = boost::target(e, *stg);
            bool last_transition = tgt == HLS->STG->get_exit_state();
            vertex next_state = last_transition ? first_state : tgt;
            bool assert_done_port = false;
            if(done_port_is_registered)
            {
               OutEdgeIterator os_it, os_it_end;
               for(boost::tie(os_it, os_it_end) = boost::out_edges(tgt, *stg); os_it != os_it_end && !assert_done_port; os_it++)
                  if(boost::target(*os_it, *stg) == HLS->STG->get_exit_state())
                     assert_done_port = true;
            }
            else
               assert_done_port = last_transition;

            std::vector<long long int> transition_outputs(out_num, default_COND);
            for(unsigned int k = 0; k < out_num; k++)
            {
               if(present_state[v][k] == 1 && unbounded_ports.find(k) == unbounded_ports.end())
                  transition_outputs[k] = 0;
            }

            if(selectors.find(conn_binding::IN) != selectors.end())
            {
               for(const auto& s : selectors.at(conn_binding::IN))
               {
                  const auto& activations = GetPointer<commandport_obj>(s.second)->get_activations();
                  for(const auto& a : activations)
                  {
                     THROW_ASSERT(v != NULL_VERTEX && std::get<0>(a) != NULL_VERTEX, "error on source vertex");
                     bool source_activation = false;
                     if(stg->CGetStateInfo(v)->loopId == 0 || !FB->is_pipelining_enabled())
                        source_activation = std::get<0>(a) == v;
                     else
                        source_activation = loop_map[stg->CGetStateInfo(v)->loopId].find(std::get<0>(a)) != loop_map[stg->CGetStateInfo(v)->loopId].end();
                     if(source_activation && (std::get<1>(a) == tgt || std::get<1>(a) == NULL_VERTEX))
                     {
                        THROW_ASSERT(present_state[v][out_ports[s.second]] != 0, "unexpected condition");
                        transition_outputs[out_ports[s.second]] = 1;
                     }
                  }
               }

               for(auto const& sel : register_selectors)
               {
                  if(parameters->IsParameter("enable-FSMX") && parameters->GetParameter<int>("enable-FSMX") == 1)
                  {
                     if(wren_list.find(sel.second) != wren_list.end() && ((transition_outputs[wren_list[sel.second]] == 0) || (transition_outputs[wren_list[sel.second]] == default_COND && present_state[v][wren_list[sel.second]] != 1)))
                        transition_outputs[sel.first] = 2;
                  }
               }
            }

            for(unsigned int k = 0; k < out_num; k++)
            {
               if(present_state[v][k] == transition_outputs[k])
                  transition_outputs[k] = default_COND;
               else if(present_state[v][k] != transition_outputs[k] && present_state[v][k] == 1 && transition_outputs[k] == 0)
               {
                  // std::cerr << "k " << k << " to " << HLS->STG->get_state_name(tgt)<< std::endl;
                  // abort();
               }
            }

            parse += " " + stg->CGetStateInfo(next_state)->name + " " + (assert_done_port ? "1" : "-") + input_vector_to_string(transition_outputs, false);
            INDENT_DBG_MEX(DEBUG_LEVEL_PEDANTIC, debug_level, "<--");
         }

         parse += "; ";

         parse += "\n";
         INDENT_DBG_MEX(DEBUG_LEVEL_PEDANTIC, debug_level, "<--Analyzed state " + stg->CGetStateInfo(v)->name);
      }
   }

   // std::cerr << "Finite_state_machine representation: " << std::endl;
   // std::cerr << parse << std::endl << std::endl;
   INDENT_DBG_MEX(DEBUG_LEVEL_PEDANTIC, debug_level, "<--Created state machine");
}

std::string fsm_controller::get_guard_value(const tree_managerRef TM, const unsigned int index, vertex op, const OpGraphConstRef data)
{
   if((GET_TYPE(data, op) & TYPE_MULTIIF) != 0)
   {
      unsigned int node_id = data->CGetOpNodeInfo(op)->GetNodeId();
      unsigned int pos = tree_helper::get_multi_way_if_pos(TM, node_id, index);
      return std::string("&") + STR(pos);
   }
   else
   {
      tree_nodeRef node = TM->get_tree_node_const(index);
      THROW_ASSERT(node->get_kind() == case_label_expr_K, "case_label_expr expected " + GET_NAME(data, op));
      auto* cle = GetPointer<case_label_expr>(node);
      THROW_ASSERT(cle->op0, "guard expected in a case_label_expr");
      auto* ic = GetPointer<integer_cst>(GET_NODE(cle->op0));
      THROW_ASSERT(ic, "expected integer_cst object as guard in a case_label_expr");
      long long int low_result = tree_helper::get_integer_cst_value(ic);
      long long int high_result = 0;
      if(cle->op1)
      {
         auto* ic_high = GetPointer<integer_cst>(GET_NODE(cle->op1));
         THROW_ASSERT(ic_high, "expected integer_cst object as guard in a case_label_expr");
         high_result = tree_helper::get_integer_cst_value(ic_high);
      }
      if(high_result == 0)
         return STR(low_result);
      else
      {
         std::string res_string;
         for(long long int current_value = low_result; current_value <= high_result; ++current_value)
            if(current_value == low_result)
               res_string = STR(current_value);
            else
               res_string += "|" + STR(current_value);
         return res_string;
      }
   }
}

void fsm_controller::add_correct_transition_memory(std::string state_representation)
{
   structural_objectRef circuit = this->SM->get_circ();
   SM->add_NP_functionality(circuit, NP_functionality::FSM, state_representation);
}

