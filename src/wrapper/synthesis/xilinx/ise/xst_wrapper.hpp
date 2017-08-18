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
 * @file xst_wrapper.hpp
 * @brief Wrapper to XST by XILINX
 *
 * A object used to invoke XILINX XST RTL synthesis tool
 *
 * @author Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
 * @author Christian Pilato <pilato@elet.polimi.it>
 * $Date$
 * Last modified by $Author$
 *
*/
#ifndef _XILINX_XST_WRAPPER_HPP_
#define _XILINX_XST_WRAPPER_HPP_

#include "XilinxWrapper.hpp"

#include "refcount.hpp"
CONSTREF_FORWARD_DECL(Parameter);
REF_FORWARD_DECL(target_device);
REF_FORWARD_DECL(ToolManager);
REF_FORWARD_DECL(area_model);
REF_FORWARD_DECL(time_model);
class xml_element;

#include <string>
#include <vector>
#include <map>

#define XST_TOOL_ID   "xst"

#define   PARAM_xst_tmpdir     "xst_tmpdir"
#define   PARAM_xst_hdpdir     "xst_hdpdir"
#define   PARAM_xst_prj_file   "xst_prj_file"

/**
 * @class xst_wrapper
 * Main class for wrapping ISE tools by Xilinx
 */
class xst_wrapper : public XilinxWrapper
{
   protected:

      /**
       * Generates project file
       */
      void GenerateProjectFile(const DesignParametersRef dp);

      /**
       * Initializes the reserved variables
       */
      void init_reserved_vars();

      /**
       * Evaluates the design variables
       */
      void EvaluateVariables(const DesignParametersRef dp);

      /**
       * Returns the proper command line
       */
      std::string get_command_line(const DesignParametersRef& dp) const;

   public:

      /**
       * Constructor
       * @param Param is the set of parameters
       */
      xst_wrapper(const ParameterConstRef Param, const std::string& _output_dir, const target_deviceRef _device);

      /**
       * Destructor
       */
      virtual ~xst_wrapper();

};
///Refcount definition for the class
typedef refcount<xst_wrapper> xst_wrapperRef;

#endif
