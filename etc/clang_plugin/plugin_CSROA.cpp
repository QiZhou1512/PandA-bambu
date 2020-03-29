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
 *              Copyright (C) 2018-2020 Politecnico di Milano
 *
 *   This file is part of the PandA framework.
 *
 *   The PandA framework is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
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
/*
 * Clang plugin for custom scalar replacement of aggregates.
 *
 * @author Fabrizio Ferrandi <Fabrizio.ferrandi@polimi.it>
 *
 */
#include "plugin_includes.hpp"

#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Transforms/IPO.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include <llvm/IR/Verifier.h>
#include <llvm/Transforms/Scalar.h>
#if __clang_major__ >= 7
#include "llvm/Transforms/Utils.h"
#endif

#include "CustomScalarReplacementOfAggregatesPass.hpp"
#include "GepiCanonicalizationPass.hpp"
#include "ExpandMemOpsPass.hpp"

namespace llvm
{
   template <int SROA_PHASE>
   struct CLANG_VERSION_SYMBOL(_plugin_CSROA);
}

namespace llvm
{
   cl::opt<std::string> TopFunctionName_CSROAP("panda-KN", cl::desc("Specify the name of the top function"), cl::value_desc("name of the top function"));
   template <int SROA_PHASE>
   struct CLANG_VERSION_SYMBOL(_plugin_CSROA) : public CustomScalarReplacementOfAggregatesPass
   {
    public:
      static char ID;
      CLANG_VERSION_SYMBOL(_plugin_CSROA)() : CustomScalarReplacementOfAggregatesPass(TopFunctionName_CSROAP, ID, SROA_PHASE)
      {
         initializeTargetTransformInfoWrapperPassPass(*PassRegistry::getPassRegistry());
         initializeLoopPassPass(*PassRegistry::getPassRegistry());
      }

      bool runOnModule(Module& M) override
      {
         return CustomScalarReplacementOfAggregatesPass::runOnModule(M);
      }
      StringRef getPassName() const override
      {
         if(SROA_PHASE == SROA_functionVersioning)
            return CLANG_VERSION_STRING(_plugin_CSROA) "FV";
         if(SROA_PHASE == SROA_disaggregation)
            return CLANG_VERSION_STRING(_plugin_CSROA) "D";
         if(SROA_PHASE == SROA_wrapperInlining)
            return CLANG_VERSION_STRING(_plugin_CSROA) "WI";
         return CLANG_VERSION_STRING(_plugin_CSROA);
      }
   };

   template <int SROA_PHASE>
   char CLANG_VERSION_SYMBOL(_plugin_CSROA)<SROA_PHASE>::ID = 0;

} // namespace llvm

#ifndef _WIN32
static llvm::RegisterPass<llvm::CLANG_VERSION_SYMBOL(_plugin_CSROA) < SROA_functionVersioning>> XPassFV(CLANG_VERSION_STRING(_plugin_CSROA) "FV", "Custom SROA", false /* Only looks at CFG */, false /* Analysis Pass */);
static llvm::RegisterPass<llvm::CLANG_VERSION_SYMBOL(_plugin_CSROA) < SROA_disaggregation>> XPassD(CLANG_VERSION_STRING(_plugin_CSROA) "D", "Custom SROA", false /* Only looks at CFG */, false /* Analysis Pass */);
static llvm::RegisterPass<llvm::CLANG_VERSION_SYMBOL(_plugin_CSROA) < SROA_wrapperInlining>> XPassWI(CLANG_VERSION_STRING(_plugin_CSROA) "WI", "Custom SROA", false /* Only looks at CFG */, false /* Analysis Pass */);
#endif

namespace llvm
{
	template <int OPT_SELECTION>
	struct CLANG_VERSION_SYMBOL(_plugin_RemLifetime) : public GepiCanonicalizationPass {
	public:
		static char ID;
		CLANG_VERSION_SYMBOL(_plugin_RemLifetime)() : GepiCanonicalizationPass(ID, OPT_SELECTION) {
			initializeTargetTransformInfoWrapperPassPass(*PassRegistry::getPassRegistry());
			initializeLoopPassPass(*PassRegistry::getPassRegistry());
		}

		bool runOnFunction(llvm::Function& function) override {
			return GepiCanonicalizationPass::runOnFunction(function);
		}
		
		StringRef getPassName() const override {
			if(OPT_SELECTION == SROA_removeLifetime)
				return CLANG_VERSION_STRING(_plugin_RemLifetime) "SLTR";
		}
};

	      template <int OPT_SELECTION>
		         char CLANG_VERSION_SYMBOL(_plugin_RemLifetime)<OPT_SELECTION>::ID = 0;

} // namespace llvm

// This function is of type PassManagerBuilder::ExtensionFn
static void loadPass(const llvm::PassManagerBuilder&, llvm::legacy::PassManagerBase& PM)
{
   PM.add(llvm::createSimpleLoopUnrollPass());
   PM.add(new llvm::CLANG_VERSION_SYMBOL(_plugin_CSROA) < SROA_functionVersioning >);
   PM.add(llvm::createVerifierPass());
   PM.add(llvm::createIPSCCPPass());
   PM.add(llvm::createGlobalDCEPass());
   PM.add(llvm::createPromoteMemoryToRegisterPass());
   PM.add(llvm::createDeadArgEliminationPass());
   PM.add(llvm::createArgumentPromotionPass());
   PM.add(llvm::createSimpleLoopUnrollPass());
   PM.add(llvm::createCFGSimplificationPass());
   //   llvm::InlineParams IP;
   //   IP.DefaultThreshold = 75;
   //   IP.HintThreshold = 325;
   //   PM.add(llvm::createFunctionInliningPass(IP));
   //   PM.add(llvm::createIPSCCPPass());
   //   PM.add(llvm::createGlobalDCEPass());
   //   PM.add(llvm::createPromoteMemoryToRegisterPass());
   //   PM.add(llvm::createDeadArgEliminationPass());
   //   PM.add(llvm::createArgumentPromotionPass());
   //   PM.add(llvm::createSimpleLoopUnrollPass());
   PM.add(llvm::createVerifierPass());
   PM.add(new llvm::CLANG_VERSION_SYMBOL(_plugin_RemLifetime) < SROA_removeLifetime>);
   PM.add(new llvm::CLANG_VERSION_SYMBOL(_plugin_CSROA) < SROA_disaggregation >);
   PM.add(llvm::createVerifierPass());
}

static void loadPassLate(const llvm::PassManagerBuilder&, llvm::legacy::PassManagerBase& PM)
{
   PM.add(llvm::createReversePostOrderFunctionAttrsPass());
   PM.add(new llvm::CLANG_VERSION_SYMBOL(_plugin_CSROA) < SROA_wrapperInlining >);
   PM.add(llvm::createDeadStoreEliminationPass());
   PM.add(llvm::createEarlyCSEPass(true));
   PM.add(llvm::createConstantPropagationPass());
   PM.add(llvm::createIPSCCPPass());
   PM.add(llvm::createGlobalDCEPass());
   PM.add(llvm::createPromoteMemoryToRegisterPass());
   PM.add(llvm::createDeadArgEliminationPass());
   PM.add(llvm::createArgumentPromotionPass());
   PM.add(llvm::createSimpleLoopUnrollPass());
}
static void loadPassFull(const llvm::PassManagerBuilder&, llvm::legacy::PassManagerBase& PM)
{
   llvm::TargetIRAnalysis TIRA = llvm::TargetIRAnalysis();
   /*
            // Insert -O3 in chain
            {
               PM.add(llvm::createVerifierPass());
               llvm::PassManagerBuilder passManagerBuilder;
               passManagerBuilder.OptLevel = 1;
               passManagerBuilder.DisableUnrollLoops = true;
               passManagerBuilder.BBVectorize = false;
               passManagerBuilder.LoopVectorize = false;
               passManagerBuilder.SLPVectorize = false;
               /// passManagerBuilder.populateModulePassManager(PM);
            }

   PM.add(llvm::createPromoteMemoryToRegisterPass());
   */
   PM.add(llvm::createPromoteMemoryToRegisterPass());
   PM.add(new llvm::ScalarEvolutionWrapperPass());
   PM.add(new llvm::LoopInfoWrapperPass());
   PM.add(new llvm::DominatorTreeWrapperPass());
   PM.add(new llvm::AssumptionCacheTracker());
   PM.add(llvm::createTargetTransformInfoWrapperPass(TIRA));


   PM.add(llvm::createPromoteMemoryToRegisterPass());
   PM.add(createGepiExplicitation());
#if 0
   PM.add(createGepiCanonicalIdxs());
   PM.add(createRemoveIntrinsicPass());
   PM.add(llvm::createExpandMemOpsPass());
   PM.add(createPtrIteratorSimplificationPass());
   PM.add(createChunkOperationsLoweringPass());
   PM.add(createBitcastVectorRemovalPass());
   PM.add(createSelectLoweringPass());
   PM.add(llvm::createVerifierPass());


   PM.add(createCodeSimplificationPass());


   PM.add(llvm::createPromoteMemoryToRegisterPass());
   PM.add(llvm::createLoopRotatePass());
   PM.add(llvm::createLoopUnrollPass());
   PM.add(createCleanLCSSA());
   PM.add(llvm::createVerifierPass());


   PM.add(createGepiCanonicalIdxs());
   PM.add(createGepiExplicitation());
   PM.add(createRemoveIntrinsicPass());
   PM.add(llvm::createExpandMemOpsPass());
   PM.add(createPtrIteratorSimplificationPass());
   PM.add(createChunkOperationsLoweringPass());
   PM.add(createBitcastVectorRemovalPass());
   PM.add(createSelectLoweringPass());
   PM.add(new llvm::CLANG_VERSION_SYMBOL(_plugin_CSROA) < SROA_functionVersioning >);
   //PM.add(createSROAFunctionVersioningPass(args_info.target_function));
   PM.add(llvm::createVerifierPass());

   // Insert -O3 in chain
   {
      llvm::PassManagerBuilder passManagerBuilder;
      passManagerBuilder.OptLevel = 0;
      passManagerBuilder.DisableUnrollLoops = true;
      //passManagerBuilder.BBVectorize = false;
      passManagerBuilder.LoopVectorize = false;
      passManagerBuilder.SLPVectorize = false;
      passManagerBuilder.populateModulePassManager(PM);
   }

   PM.add(createGepiCanonicalIdxs());
   PM.add(createGepiExplicitation());
   PM.add(createRemoveIntrinsicPass());
   PM.add(llvm::createExpandMemOpsPass());
   PM.add(createPtrIteratorSimplificationPass());
   PM.add(createChunkOperationsLoweringPass());
   PM.add(createBitcastVectorRemovalPass());
   PM.add(createSelectLoweringPass());
   PM.add(llvm::createVerifierPass());

   PM.add(new llvm::CLANG_VERSION_SYMBOL(_plugin_CSROA) < SROA_disaggregation >);
   //PM.add(createSROADisaggregationPass(args_info.target_function));
   PM.add(llvm::createVerifierPass());


   // Insert -O3 in chain
   {
      llvm::PassManagerBuilder passManagerBuilder;
      passManagerBuilder.OptLevel = 1;
      passManagerBuilder.DisableUnrollLoops = true;
      //passManagerBuilder.BBVectorize = false;
      passManagerBuilder.LoopVectorize = false;
      passManagerBuilder.SLPVectorize = false;
      passManagerBuilder.populateModulePassManager(PM);
   }

   PM.add(new llvm::CLANG_VERSION_SYMBOL(_plugin_CSROA) < SROA_wrapperInlining >);
   //PM.add(createSROAWrapperInliningPass(args_info.target_function));
   PM.add(llvm::createVerifierPass());

   // Insert -O3 in chain
   {
      llvm::PassManagerBuilder passManagerBuilder;
      passManagerBuilder.OptLevel = 3;
      passManagerBuilder.DisableUnrollLoops = true;
      //passManagerBuilder.BBVectorize = false;
      passManagerBuilder.LoopVectorize = false;
      passManagerBuilder.SLPVectorize = false;
      passManagerBuilder.populateModulePassManager(PM);
   }
#endif
}

#if ADD_RSP
// These constructors add our pass to a list of global extensions.
static llvm::RegisterStandardPasses CLANG_VERSION_SYMBOL(_plugin_CSROA_OxFull)(llvm::PassManagerBuilder::EP_EarlyAsPossible, loadPassFull);
//static llvm::RegisterStandardPasses CLANG_VERSION_SYMBOL(_plugin_CSROA_OxFVD)(llvm::PassManagerBuilder::EP_ModuleOptimizerEarly, loadPass);
//static llvm::RegisterStandardPasses CLANG_VERSION_SYMBOL(_plugin_CSROA_OxIW)(llvm::PassManagerBuilder::EP_OptimizerLast, loadPassLate);

#endif

#ifdef _WIN32
using namespace llvm;

INITIALIZE_PASS_BEGIN(clang7_plugin_CSROA<SROA_functionVersioning>, "clang7_plugin_CSROAFV", "Custom SROA", false, false)
INITIALIZE_PASS_END(clang7_plugin_CSROA<SROA_functionVersioning>, "clang7_plugin_CSROAFV", "Custom SROA", false, false)
namespace llvm
{
   void clang7_plugin_CSROA_init()
   {
   }
} // namespace llvm
#endif
