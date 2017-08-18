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
 *              Copyright (c) 2004-2017 Politecnico di Milano
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
 * @file design_flow_step.cpp
 * @brief Base class for step of design flow
 *
 * @author Marco Lattuada <lattuada@elet.polimi.it>
 * $Revision$
 * $Date$
 * Last modified by $Author$
 *
*/

///Header include
#include "design_flow_step.hpp"

///. include
#include "Parameter.hpp"

///design_flows include
#include "design_flow_manager.hpp"

DesignFlowStep::DesignFlowStep(const DesignFlowManagerConstRef _design_flow_manager, const ParameterConstRef _parameters) :
   composed(false),
   design_flow_manager(_design_flow_manager),
   parameters(_parameters),
   debug_level(parameters->getOption<int>(OPT_debug_level)),
   output_level(parameters->getOption<int>(OPT_output_level))
{}

DesignFlowStep::~DesignFlowStep()
{}

void DesignFlowStep::WriteDot(std::ostream & out) const
{
   out << "label=\"" << GetName() << "\\n" << "Signature: " << GetSignature() << "\"";
}

bool DesignFlowStep::IsComposed() const
{
   return composed;
}

void DesignFlowStep::Initialize()
{}

int DesignFlowStep::CGetDebugLevel() const
{
   return debug_level;
}

DesignFlowStep_Status DesignFlowStep::GetStatus() const
{
   return design_flow_manager.lock()->GetStatus(GetSignature());
}

void DesignFlowStep::PrintInitialIR() const
{}

void DesignFlowStep::PrintFinalIR() const
{}

#if not HAVE_UNORDERED
DesignFlowStepSorter::DesignFlowStepSorter()
{}

bool DesignFlowStepSorter::operator()(const DesignFlowStepRef x, const DesignFlowStepRef y) const
{
   return x->GetName() < y->GetName();
}

DesignFlowStepSet::DesignFlowStepSet() :
   std::set<DesignFlowStepRef, DesignFlowStepSorter>(DesignFlowStepSorter())
{}
#endif
