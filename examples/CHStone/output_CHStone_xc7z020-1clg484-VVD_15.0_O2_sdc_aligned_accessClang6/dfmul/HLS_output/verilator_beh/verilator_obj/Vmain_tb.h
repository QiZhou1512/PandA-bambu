// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vmain_tb_H_
#define _Vmain_tb_H_

#include "verilated_heavy.h"

class Vmain_tb__Syms;

//----------

VL_MODULE(Vmain_tb) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__andCGSig,0,0);
    VL_SIG8(main_tb__DOT__compare_outputs,0,0);
    VL_SIG8(main_tb__DOT__success,0,0);
    VL_SIG8(main_tb__DOT___bambu_databyte_,7,0);
    VL_SIG8(main_tb__DOT_____05Fstate,3,0);
    VL_SIG8(main_tb__DOT_____05Fnext_state,3,0);
    VL_SIG8(main_tb__DOT__start_results_comparison,0,0);
    VL_SIG8(main_tb__DOT__next_start_port,0,0);
    VL_SIG8(main_tb__DOT__clock_gating_port,0,0);
    VL_SIG8(main_tb__DOT__reset,0,0);
    VL_SIG8(main_tb__DOT__start_port,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__done_delayed_REG_signal_in,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_237_reg_19_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_237_reg_19_0_0_1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_239_reg_20_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_244_reg_25_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_245_reg_26_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_245_reg_26_0_0_1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_266_reg_45_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_267_reg_46_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_267_reg_46_0_0_1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_268_reg_47_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_269_reg_48_0_1_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_272_reg_50_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_272_reg_50_0_0_1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_272_reg_50_0_0_2,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_272_reg_50_0_1_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_272_reg_50_0_1_1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_273_reg_51_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_274_reg_6_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_4_ARRAY_1D_STD_DISTRAM_NN_SDS_1_i0_1_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_545_ui_lshift_expr_FU_64_64_64_206_i1_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_546_ui_lshift_expr_FU_64_64_64_206_i1_1_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_11,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_12,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_13,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_16,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_17,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_18,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_19,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_2,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_20,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_21,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_22,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_23,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_24,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_25,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_26,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_37,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_38,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_4,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_42,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_43,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_45,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_46,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_47,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_48,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_5,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_50,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_51,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_6,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_7,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_MUX_274_reg_6_0_0_0,4,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_bit_ior_concat_expr_FU_159_i0_fu_main_419510_419865,5,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_bit_ior_concat_expr_FU_159_i1_fu_main_419510_420201,5,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_pointer_plus_expr_FU_8_8_8_225_i0_fu_main_419510_419526,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_pointer_plus_expr_FU_8_8_8_225_i1_fu_main_419510_419528,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_pointer_plus_expr_FU_8_8_8_225_i2_fu_main_419510_420471,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_420755__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_420755__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_421157__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_421157__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_421359__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_421359__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422281__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422284__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422284__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422305__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422305__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422311__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422311__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422325__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422325__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422331__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422331__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422365__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422365__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422371__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422371__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422460__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422460__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422491__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422491__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422503__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422503__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422509__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422509__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422513__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422513__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422519__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422519__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422615__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422615__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422635__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422635__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422640__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422640__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422646__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422646__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422652__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422652__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422663__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422663__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422666__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_422666__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_15__DOT__reg_out1,1,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_16__DOT__reg_out1,1,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_17__DOT__reg_out1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_18__DOT__reg_out1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_31__DOT__reg_out1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_34__DOT__reg_out1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_36__DOT__reg_out1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_38__DOT__reg_out1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_39__DOT__reg_out1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_40__DOT__reg_out1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_41__DOT__reg_out1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_6__DOT__reg_out1,4,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_7__DOT__reg_out1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__done_delayed_REG__DOT__reg_out1,0,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_MUX_245_reg_26_0_0_1,12,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_MUX_4_ARRAY_1D_STD_DISTRAM_NN_SDS_1_i0_1_0_0,9,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_plus_expr_FU_16_16_16_136_i0_fu_main_419510_420321,12,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_pointer_plus_expr_FU_16_16_16_224_i0_fu_main_419510_419874,9,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_pointer_plus_expr_FU_16_16_16_224_i1_fu_main_419510_420208,9,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419873_0__DOT__memory_addr_a,15,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420470_0__DOT__memory_addr_a,9,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420492_0__DOT__memory_addr_a,9,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420506_0__DOT__memory_addr_a,9,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_0__DOT__reg_out1,8,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_1__DOT__reg_out1,8,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_13__DOT__reg_out1,9,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_14__DOT__reg_out1,9,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_2__DOT__reg_out1,8,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_20__DOT__reg_out1,12,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_26__DOT__reg_out1,12,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_30__DOT__reg_out1,12,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_4__DOT__reg_out1,9,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_43__DOT__reg_out1,9,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_45__DOT__reg_out1,9,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_47__DOT__reg_out1,9,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_48__DOT__reg_out1,11,0);
    VL_SIG(main_tb__DOT__res_file,31,0);
    VL_SIG(main_tb__DOT__file,31,0);
    VL_SIG(main_tb__DOT___r_,31,0);
    VL_SIG(main_tb__DOT___n_,31,0);
    VL_SIG(main_tb__DOT___i_,31,0);
    VL_SIG(main_tb__DOT___addr_i_,31,0);
    VL_SIG(main_tb__DOT___ch_,31,0);
    VL_SIGW(main_tb__DOT__line,8000,0,251);
    VL_SIG(main_tb__DOT__base_addr,31,0);
    VL_SIG(main_tb__DOT__ex_return_port,31,0);
    VL_SIG(main_tb__DOT__registered_return_port,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Controller_i__DOT___present_state,24,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Controller_i__DOT___next_state,24,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_IUdata_converter_FU_108_i0_fu_main_419510_420958,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_MUX_273_reg_51_0_0_0,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_cond_expr_FU_32_32_32_32_178_i1_fu_main_419510_419898,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419873_0__DOT__tmp_addr,19,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419873_0__DOT__relative_addr,19,0);
    VL_SIGW(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420470_0__DOT__dout_a,127,0,4);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420470_0__DOT__tmp_addr,19,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420470_0__DOT__relative_addr,19,0);
    VL_SIGW(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420492_0__DOT__dout_a,127,0,4);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420492_0__DOT__tmp_addr,19,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420492_0__DOT__relative_addr,19,0);
    VL_SIGW(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420506_0__DOT__dout_a,127,0,4);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420506_0__DOT__tmp_addr,19,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420506_0__DOT__relative_addr,19,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_21__DOT__reg_out1,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_22__DOT__reg_out1,21,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_23__DOT__reg_out1,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_24__DOT__reg_out1,21,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_28__DOT__reg_out1,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_32__DOT__reg_out1,21,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_37__DOT__reg_out1,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_51__DOT__reg_out1,31,0);
    VL_SIG64(main_tb__DOT__startTime,63,0);
    VL_SIG64(main_tb__DOT__endTime,63,0);
    VL_SIG64(main_tb__DOT__sim_time,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_bit_and_expr_FU_64_64_64_154_i0_fu_main_419510_419760,53,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_bit_ior_concat_expr_FU_158_i0_fu_main_419510_419819,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_bit_ior_concat_expr_FU_160_i0_fu_main_419510_420287,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_bit_ior_expr_FU_0_64_64_162_i0_fu_main_419510_420464,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_bit_ior_expr_FU_0_64_64_163_i0_fu_main_419510_420616,51,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_bit_ior_expr_FU_64_64_64_173_i0_fu_main_419510_419790,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_bit_ior_expr_FU_64_64_64_173_i2_fu_main_419510_420591,51,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_bit_xor_expr_FU_64_64_64_175_i0_fu_main_419510_419538,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_cond_expr_FU_64_64_64_64_179_i0_fu_main_419510_419677,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_cond_expr_FU_64_64_64_64_179_i1_fu_main_419510_419777,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_cond_expr_FU_64_64_64_64_179_i4_fu_main_419510_422485,62,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_lshift_expr_FU_64_64_64_206_i1_ui_lshift_expr_FU_64_64_64_206_i1,53,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_ternary_plus_expr_FU_64_64_64_64_243_i0_fu_main_419510_419794,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_widen_mult_expr_FU_32_32_64_0_244_i0_fu_main_419510_419822,53,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_widen_mult_expr_FU_32_32_64_0_244_i1_fu_main_419510_420250,52,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_widen_mult_expr_FU_32_32_64_0_244_i3_fu_main_419510_420290,42,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419873_0__DOT__dout_a,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_11__DOT__reg_out1,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_12__DOT__reg_out1,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_19__DOT__reg_out1,53,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_25__DOT__reg_out1,51,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_27__DOT__reg_out1,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_29__DOT__reg_out1,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_33__DOT__reg_out1,41,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_35__DOT__reg_out1,62,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_42__DOT__reg_out1,62,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_46__DOT__reg_out1,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_5__DOT__reg_out1,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_50__DOT__reg_out1,63,0);
    VL_SIG8(main_tb__DOT___bambu_testbench_mem_[1],7,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419566_0__DOT__memory[1],31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419873_0__DOT__memory[256],31,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420470_0__DOT__memory[20],63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420492_0__DOT__memory[20],63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420506_0__DOT__memory[20],63,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(main_tb__DOT____Vlvbound2,7,0);
    VL_SIG8(__Vclklast__TOP__clock,0,0);
    VL_SIG8(__Vclklast__TOP__main_tb__DOT__main__DOT___main_i0__DOT__andCGSig,0,0);
    VL_SIGW(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT____Vcellout__array_420470_0__out1,127,0,4);
    VL_SIGW(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT____Vcellout__array_420492_0__out1,127,0,4);
    VL_SIGW(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT____Vcellout__array_420506_0__out1,127,0,4);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT____Vcellout__array_419873_0__out1,63,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vmain_tb__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vmain_tb& operator= (const Vmain_tb&);  ///< Copying not allowed
    Vmain_tb(const Vmain_tb&);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vmain_tb(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vmain_tb();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vmain_tb__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vmain_tb__Syms* symsp, bool first);
  private:
    static QData _change_request(Vmain_tb__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__4(Vmain_tb__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset();
  public:
    static void _eval(Vmain_tb__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vmain_tb__Syms* __restrict vlSymsp);
    static void _eval_settle(Vmain_tb__Syms* __restrict vlSymsp);
    static void _initial__TOP__1(Vmain_tb__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__8(Vmain_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vmain_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vmain_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vmain_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vmain_tb__Syms* __restrict vlSymsp);
    static void _settle__TOP__5(Vmain_tb__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
