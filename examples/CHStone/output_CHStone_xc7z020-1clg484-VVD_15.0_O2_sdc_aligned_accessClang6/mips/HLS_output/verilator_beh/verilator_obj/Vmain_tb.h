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
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__fuselector_ARRAY_1D_STD_BRAM_NN_SDS_0_i0_STORE,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__fuselector_ARRAY_1D_STD_BRAM_NN_SDS_1_i0_STORE,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__fuselector_ARRAY_1D_STD_BRAM_NN_SDS_1_i1_STORE,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_0_ARRAY_1D_STD_BRAM_NN_SDS_0_i0_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_0_ARRAY_1D_STD_BRAM_NN_SDS_0_i0_0_0_1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_1_ARRAY_1D_STD_BRAM_NN_SDS_0_i0_1_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_1_ARRAY_1D_STD_BRAM_NN_SDS_0_i0_1_0_1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_1_ARRAY_1D_STD_BRAM_NN_SDS_0_i0_1_0_2,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_1_ARRAY_1D_STD_BRAM_NN_SDS_0_i0_1_1_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_385_reg_0_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_387_reg_10_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_392_reg_15_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_406_reg_28_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_406_reg_28_0_0_1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_406_reg_28_0_0_2,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_406_reg_28_0_0_3,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_406_reg_28_0_1_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_406_reg_28_0_1_1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_407_reg_29_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_407_reg_29_0_0_1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_409_reg_30_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_409_reg_30_0_0_1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_410_reg_31_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_411_reg_32_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_411_reg_32_0_0_1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_414_reg_35_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_420_reg_9_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_436_u_assign_conn_obj_16_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_4_ARRAY_1D_STD_BRAM_NN_SDS_1_i0_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_4_ARRAY_1D_STD_BRAM_NN_SDS_1_i0_0_0_1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_4_ARRAY_1D_STD_BRAM_NN_SDS_1_i0_0_0_2,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_4_ARRAY_1D_STD_BRAM_NN_SDS_1_i0_0_0_3,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_4_ARRAY_1D_STD_BRAM_NN_SDS_1_i0_0_0_4,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_4_ARRAY_1D_STD_BRAM_NN_SDS_1_i0_0_0_5,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_4_ARRAY_1D_STD_BRAM_NN_SDS_1_i0_0_0_6,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_4_ARRAY_1D_STD_BRAM_NN_SDS_1_i0_0_0_7,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_4_ARRAY_1D_STD_BRAM_NN_SDS_1_i0_0_0_8,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_4_ARRAY_1D_STD_BRAM_NN_SDS_1_i0_0_0_9,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_4_ARRAY_1D_STD_BRAM_NN_SDS_1_i0_0_1_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_4_ARRAY_1D_STD_BRAM_NN_SDS_1_i0_0_1_1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_4_ARRAY_1D_STD_BRAM_NN_SDS_1_i0_0_1_2,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_4_ARRAY_1D_STD_BRAM_NN_SDS_1_i0_0_1_3,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_4_ARRAY_1D_STD_BRAM_NN_SDS_1_i0_0_1_4,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_4_ARRAY_1D_STD_BRAM_NN_SDS_1_i0_0_2_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_4_ARRAY_1D_STD_BRAM_NN_SDS_1_i0_0_2_1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_4_ARRAY_1D_STD_BRAM_NN_SDS_1_i0_0_3_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_5_ARRAY_1D_STD_BRAM_NN_SDS_1_i0_1_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_5_ARRAY_1D_STD_BRAM_NN_SDS_1_i0_1_0_1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_5_ARRAY_1D_STD_BRAM_NN_SDS_1_i0_1_1_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_8_ARRAY_1D_STD_BRAM_NN_SDS_1_i1_0_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_8_ARRAY_1D_STD_BRAM_NN_SDS_1_i1_0_0_1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_8_ARRAY_1D_STD_BRAM_NN_SDS_1_i1_0_0_2,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_8_ARRAY_1D_STD_BRAM_NN_SDS_1_i1_0_1_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_8_ARRAY_1D_STD_BRAM_NN_SDS_1_i1_0_1_1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_9_ARRAY_1D_STD_BRAM_NN_SDS_1_i1_1_0_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_9_ARRAY_1D_STD_BRAM_NN_SDS_1_i1_1_0_1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_9_ARRAY_1D_STD_BRAM_NN_SDS_1_i1_1_0_2,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_9_ARRAY_1D_STD_BRAM_NN_SDS_1_i1_1_1_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__selector_MUX_9_ARRAY_1D_STD_BRAM_NN_SDS_1_i1_1_1_1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_0,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_10,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_11,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_12,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_13,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_14,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_15,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_16,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_17,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_19,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_2,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_20,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_21,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_22,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_27,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_28,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_29,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_3,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_30,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_31,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_32,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_35,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_4,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_5,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_6,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_7,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_8,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__wrenable_reg_9,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_MUX_1_ARRAY_1D_STD_BRAM_NN_SDS_0_i0_1_1_0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_MUX_385_reg_0_0_0_0,6,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_MUX_387_reg_10_0_0_0,3,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_MUX_411_reg_32_0_0_1,3,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_MUX_420_reg_9_0_0_0,5,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_pointer_plus_expr_FU_8_0_8_218_i0_fu_main_419510_419617,6,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_pointer_plus_expr_FU_8_0_8_219_i0_fu_main_419510_420223,6,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_pointer_plus_expr_FU_8_8_8_220_i0_fu_main_419510_419525,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_pointer_plus_expr_FU_8_8_8_220_i10_fu_main_419510_420677,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_pointer_plus_expr_FU_8_8_8_220_i11_fu_main_419510_420679,4,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_pointer_plus_expr_FU_8_8_8_220_i1_fu_main_419510_419571,6,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_pointer_plus_expr_FU_8_8_8_220_i2_fu_main_419510_419601,4,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_pointer_plus_expr_FU_8_8_8_220_i3_fu_main_419510_419605,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_pointer_plus_expr_FU_8_8_8_220_i4_fu_main_419510_419673,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_pointer_plus_expr_FU_8_8_8_220_i5_fu_main_419510_419819,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_pointer_plus_expr_FU_8_8_8_220_i6_fu_main_419510_419845,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_pointer_plus_expr_FU_8_8_8_220_i7_fu_main_419510_420197,6,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_pointer_plus_expr_FU_8_8_8_220_i8_fu_main_419510_420216,6,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_pointer_plus_expr_FU_8_8_8_220_i9_fu_main_419510_420286,6,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419542_0__DOT__ARRAY_1D_STD_BRAM_NN_instance__DOT__bram_write,1,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419585_0__DOT__ARRAY_1D_STD_BRAM_NN_instance__DOT__bram_write,1,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419626_0__DOT__memory_addr_a,5,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420700_0__DOT__memory_addr_a,5,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_420747__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_420747__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_420750__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_420750__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_420844__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_420854__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_420854__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_420873__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_420873__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_421188__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_421188__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424139__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424139__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424142__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424142__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424145__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424145__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424148__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424148__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424151__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424151__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424154__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424154__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424157__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424157__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424160__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424160__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424163__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424163__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424166__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424166__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424169__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424169__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424172__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424172__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424175__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424175__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424178__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424178__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424181__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424181__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424184__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424184__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424395__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424395__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424398__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424398__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424401__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424401__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424404__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424404__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424407__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424407__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424410__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424410__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424413__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424413__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424416__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424416__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424419__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424419__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424422__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424422__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424425__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424425__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424428__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424428__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424576__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424576__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424579__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424579__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424584__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424584__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424589__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424589__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424594__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424594__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424600__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424600__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424605__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424605__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424611__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424611__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424616__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424616__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424621__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424621__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424625__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424625__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424629__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424629__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424633__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424633__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424637__DOT__cleaned_in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__fu_main_419510_424637__DOT__in0,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_0__DOT__reg_out1,6,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_1__DOT__reg_out1,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_10__DOT__reg_out1,2,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_12__DOT__reg_out1,6,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_14__DOT__reg_out1,6,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_2__DOT__reg_out1,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_21__DOT__reg_out1,6,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_22__DOT__reg_out1,4,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_3__DOT__reg_out1,6,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_32__DOT__reg_out1,3,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_34__DOT__reg_out1,0,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_4__DOT__reg_out1,6,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_5__DOT__reg_out1,6,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_6__DOT__reg_out1,5,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_7__DOT__reg_out1,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_8__DOT__reg_out1,5,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_9__DOT__reg_out1,4,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__done_delayed_REG__DOT__reg_out1,0,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419542_0__DOT__ARRAY_1D_STD_BRAM_NN_instance__DOT__memory_addr_a,11,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419542_0__DOT__ARRAY_1D_STD_BRAM_NN_instance__DOT__tmp_addr,15,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419542_0__DOT__ARRAY_1D_STD_BRAM_NN_instance__DOT__relative_addr,15,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419585_0__DOT__ARRAY_1D_STD_BRAM_NN_instance__DOT__memory_addr_a,9,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419585_0__DOT__ARRAY_1D_STD_BRAM_NN_instance__DOT__tmp_addr,15,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419585_0__DOT__ARRAY_1D_STD_BRAM_NN_instance__DOT__relative_addr,15,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419626_0__DOT__tmp_addr,15,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419626_0__DOT__relative_addr,15,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420378_0__DOT__memory_addr_a,11,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420378_0__DOT__tmp_addr,15,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420378_0__DOT__relative_addr,15,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420700_0__DOT__tmp_addr,15,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420700_0__DOT__relative_addr,15,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_11__DOT__reg_out1,15,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_16__DOT__reg_out1,15,0);
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
    VL_SIGW(main_tb__DOT__main__DOT___main_i0__DOT__Controller_i__DOT___present_state,67,0,3);
    VL_SIGW(main_tb__DOT__main__DOT___main_i0__DOT__Controller_i__DOT___next_state,67,0,3);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_MUX_0_ARRAY_1D_STD_BRAM_NN_SDS_0_i0_0_0_1,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_MUX_392_reg_15_0_0_0,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_MUX_414_reg_35_0_0_0,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_13__DOT__reg_out1,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_15__DOT__reg_out1,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_17__DOT__reg_out1,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_18__DOT__reg_out1,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_19__DOT__reg_out1,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_20__DOT__reg_out1,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_24__DOT__reg_out1,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_25__DOT__reg_out1,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_27__DOT__reg_out1,27,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_28__DOT__reg_out1,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_29__DOT__reg_out1,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_30__DOT__reg_out1,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_31__DOT__reg_out1,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_33__DOT__reg_out1,31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_35__DOT__reg_out1,31,0);
    VL_SIG64(main_tb__DOT__startTime,63,0);
    VL_SIG64(main_tb__DOT__endTime,63,0);
    VL_SIG64(main_tb__DOT__sim_time,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_ui_widen_mult_expr_FU_32_32_64_0_229_i0_fu_main_419510_420296,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__out_widen_mult_expr_FU_32_32_64_0_230_i0_fu_main_419510_420324,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419542_0__DOT__ARRAY_1D_STD_BRAM_NN_instance__DOT__din_value_aggregated,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419542_0__DOT__ARRAY_1D_STD_BRAM_NN_instance__DOT__dout_a,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419585_0__DOT__ARRAY_1D_STD_BRAM_NN_instance__DOT__din_value_aggregated,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419585_0__DOT__ARRAY_1D_STD_BRAM_NN_instance__DOT__dout_a,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419626_0__DOT__dout_a,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420378_0__DOT__dout_a,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420700_0__DOT__dout_a,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_23__DOT__reg_out1,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__reg_26__DOT__reg_out1,63,0);
    VL_SIG8(main_tb__DOT___bambu_testbench_mem_[1],7,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419542_0__DOT__ARRAY_1D_STD_BRAM_NN_instance__DOT__memory[64],31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419585_0__DOT__ARRAY_1D_STD_BRAM_NN_instance__DOT__memory[32],31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_419626_0__DOT__memory[8],31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420378_0__DOT__memory[44],31,0);
    VL_SIG(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT__array_420700_0__DOT__memory[8],31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(main_tb__DOT____Vlvbound2,7,0);
    VL_SIG8(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT____Vcellinp__array_419585_0__sel_STORE,1,0);
    VL_SIG8(__Vclklast__TOP__clock,0,0);
    VL_SIG8(__Vclklast__TOP__main_tb__DOT__main__DOT___main_i0__DOT__andCGSig,0,0);
    VL_SIG16(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT____Vcellinp__array_419585_0__in2,15,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT____Vcellout__array_419542_0__out1,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT____Vcellinp__array_419585_0__in1,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT____Vcellout__array_419585_0__out1,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT____Vcellout__array_419626_0__out1,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT____Vcellout__array_420378_0__out1,63,0);
    VL_SIG64(main_tb__DOT__main__DOT___main_i0__DOT__Datapath_i__DOT____Vcellout__array_420700_0__out1,63,0);
    
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
