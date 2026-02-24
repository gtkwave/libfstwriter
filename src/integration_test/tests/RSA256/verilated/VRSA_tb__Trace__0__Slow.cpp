// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "VRSA_tb__Syms.h"


VL_ATTR_COLD void VRSA_tb___024root__trace_init_sub__TOP____024unit__0(VRSA_tb___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void VRSA_tb___024root__trace_init_sub__TOP__0(VRSA_tb___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRSA_tb___024root__trace_init_sub__TOP__0\n"); );
    VRSA_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+357,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+358,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("$unit", VerilatedTracePrefixType::SCOPE_MODULE);
    VRSA_tb___024root__trace_init_sub__TOP____024unit__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("Testbench", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+357,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+358,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"i_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+359,0,"i_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+2,0,"i_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 767,0);
    tracep->declBit(c+360,0,"o_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"o_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+54,0,"o_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declArray(c+374,0,"golden_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->pushPrefix("i_rsa", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+357,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+358,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"i_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+359,0,"i_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+2,0,"i_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 767,0);
    tracep->declBit(c+360,0,"o_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"o_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+54,0,"o_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declArray(c+110,0,"msg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declArray(c+118,0,"key",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declArray(c+126,0,"modulus",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBit(c+27,0,"i_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"s1_i_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"s1_i_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+259,0,"s1_o_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"s1_o_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+382,0,"power",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+62,0,"packed_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->pushPrefix("s1_dist_valid", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+135+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("s1_dist_ready", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+30+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("s1_comb_valid", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+361+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("s1_comb_ready", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+32+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->declBit(c+34,0,"s1_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+137,0,"s1_msg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declArray(c+145,0,"s1_key",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declArray(c+153,0,"s1_modulus",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->pushPrefix("i_RSAMont", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+357,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+358,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+259,0,"i_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"i_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+260,0,"i_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1023,0);
    tracep->declBit(c+360,0,"o_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"o_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+54,0,"o_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBus(c+383,0,"N_FANOUT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+161,0,"base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declArray(c+169,0,"msg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declArray(c+177,0,"key",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declArray(c+185,0,"modulus",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declArray(c+70,0,"square",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declArray(c+54,0,"multiply",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBus(c+78,0,"round_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+79,0,"key_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+363,0,"update_multiply",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"loop_init",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+364,0,"loop_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+80,0,"loop_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("dist_o_valid", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+193+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("dist_o_ready", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+365+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->declBit(c+195,0,"loop_o_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"loop_o_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+292,0,"montgomery_o_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+102,0,"montgomery_in_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declArray(c+293,0,"montgomery_in_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declArray(c+301,0,"montgomery_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->pushPrefix("i_dist", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+383,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+357,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+358,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+195,0,"i_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"i_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("o_valid", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+196+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("o_ready", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+37+i*1,0,"",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("o_sent", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+198+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("ready_sent", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+39+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+384,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+200,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("i_filter", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+201,0,"i_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+367,0,"i_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+80,0,"i_pass",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+360,0,"o_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"o_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("i_loop", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+357,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+358,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+259,0,"i_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"i_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"i_cen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+195,0,"o_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"o_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+80,0,"o_done",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+364,0,"o_cen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+368,0,"o_valid_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("i_montgomery", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+385,0,"MOD_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+357,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+358,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+202,0,"i_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+309,0,"i_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+310,0,"i_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 767,0);
    tracep->declBit(c+292,0,"o_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+386,0,"o_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+301,0,"o_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declArray(c+203,0,"data_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 257,0);
    tracep->declArray(c+212,0,"data_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 257,0);
    tracep->declArray(c+221,0,"data_modulus",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 257,0);
    tracep->declArray(c+81,0,"round_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 257,0);
    tracep->declArray(c+334,0,"round_result_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 257,0);
    tracep->declArray(c+343,0,"mod_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 257,0);
    tracep->declBit(c+230,0,"loop_o_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+386,0,"loop_o_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+352,0,"loop_init",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+353,0,"loop_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"loop_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+91,0,"round_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->pushPrefix("i_filter", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+230,0,"i_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+386,0,"i_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"i_pass",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+292,0,"o_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+386,0,"o_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("i_loop", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+357,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+358,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+202,0,"i_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+309,0,"i_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+352,0,"i_cen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+230,0,"o_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+386,0,"o_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"o_done",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+353,0,"o_cen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+369,0,"o_valid_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("i_comb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+383,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("i_valid", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+354+i*1,0,"",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("i_ready", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+41+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->declBit(c+259,0,"o_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"o_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+384,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("i_dist", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+383,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+357,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+358,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"i_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"i_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("o_valid", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+231+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("o_ready", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+43+i*1,0,"",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("o_sent", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+233+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("ready_sent", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+45+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+384,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+235,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("i_twopower", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+357,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+358,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+236,0,"i_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"i_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+237,0,"i_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 287,0);
    tracep->declBit(c+370,0,"o_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"o_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+62,0,"o_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBus(c+246,0,"data_power",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+247,0,"data_modulus",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 256,0);
    tracep->declBus(c+92,0,"round_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+93,0,"round_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 256,0);
    tracep->declBit(c+256,0,"loop_o_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"loop_o_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"loop_init",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"loop_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("i_filter", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+256,0,"i_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"i_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+356,0,"i_pass",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+370,0,"o_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"o_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("i_loop", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+357,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+358,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+236,0,"i_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"i_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"i_cen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+256,0,"o_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"o_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+356,0,"o_done",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"o_cen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+371,0,"o_valid_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("pipeline_input", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+357,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+358,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"i_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+359,0,"i_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"o_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"o_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"o_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+372,0,"o_valid_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("pipeline_stg1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+357,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+358,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+257,0,"i_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"i_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"o_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+258,0,"o_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"o_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+373,0,"o_valid_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void VRSA_tb___024root__trace_init_sub__TOP____024unit__0(VRSA_tb___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRSA_tb___024root__trace_init_sub__TOP____024unit__0\n"); );
    VRSA_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+385,0,"MOD_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+387,0,"INT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
}

VL_ATTR_COLD void VRSA_tb___024root__trace_init_top(VRSA_tb___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRSA_tb___024root__trace_init_top\n"); );
    VRSA_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VRSA_tb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VRSA_tb___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void VRSA_tb___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void VRSA_tb___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void VRSA_tb___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void VRSA_tb___024root__trace_register(VRSA_tb___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRSA_tb___024root__trace_register\n"); );
    VRSA_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VRSA_tb___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&VRSA_tb___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&VRSA_tb___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&VRSA_tb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VRSA_tb___024root__trace_const_0_sub_0(VRSA_tb___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void VRSA_tb___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRSA_tb___024root__trace_const_0\n"); );
    // Body
    VRSA_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VRSA_tb___024root*>(voidSelf);
    VRSA_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VRSA_tb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<8>/*255:0*/ VRSA_tb__ConstPool__CONST_h01a3aaf4_0;

VL_ATTR_COLD void VRSA_tb___024root__trace_const_0_sub_0(VRSA_tb___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRSA_tb___024root__trace_const_0_sub_0\n"); );
    VRSA_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullWData(oldp+374,(VRSA_tb__ConstPool__CONST_h01a3aaf4_0),256);
    bufp->fullIData(oldp+382,(0x00000200U),32);
    bufp->fullIData(oldp+383,(2U),32);
    bufp->fullIData(oldp+384,(2U),32);
    bufp->fullIData(oldp+385,(0x00000100U),32);
    bufp->fullBit(oldp+386,(1U));
    bufp->fullIData(oldp+387,(0x00000020U),32);
}

VL_ATTR_COLD void VRSA_tb___024root__trace_full_0_sub_0(VRSA_tb___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void VRSA_tb___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRSA_tb___024root__trace_full_0\n"); );
    // Body
    VRSA_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VRSA_tb___024root*>(voidSelf);
    VRSA_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VRSA_tb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VRSA_tb___024root__trace_full_0_sub_0(VRSA_tb___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRSA_tb___024root__trace_full_0_sub_0\n"); );
    VRSA_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<8>/*255:0*/ __Vtemp_1;
    VlWide<8>/*255:0*/ __Vtemp_6;
    VlWide<9>/*287:0*/ __Vtemp_7;
    VlWide<8>/*255:0*/ __Vtemp_8;
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+1,(vlSelfRef.Testbench__DOT__i_valid));
    bufp->fullWData(oldp+2,(vlSelfRef.Testbench__DOT__i_in),768);
    bufp->fullBit(oldp+26,(vlSelfRef.Testbench__DOT__o_ready));
    bufp->fullBit(oldp+27,(vlSelfRef.Testbench__DOT__i_rsa__DOT__pipeline_input__DOT__o_en));
    bufp->fullBit(oldp+28,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_i_ready));
    bufp->fullBit(oldp+29,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_o_ready));
    bufp->fullBit(oldp+30,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_ready[0]));
    bufp->fullBit(oldp+31,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_ready[1]));
    bufp->fullBit(oldp+32,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_ready[0]));
    bufp->fullBit(oldp+33,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_ready[1]));
    bufp->fullBit(oldp+34,(vlSelfRef.Testbench__DOT__i_rsa__DOT__pipeline_stg1__DOT__o_en));
    bufp->fullBit(oldp+35,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_init));
    bufp->fullBit(oldp+36,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_ready));
    bufp->fullBit(oldp+37,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__o_ready[0]));
    bufp->fullBit(oldp+38,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__o_ready[1]));
    bufp->fullBit(oldp+39,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__ready_sent[0]));
    bufp->fullBit(oldp+40,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__ready_sent[1]));
    bufp->fullBit(oldp+41,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_comb__DOT__i_ready[0]));
    bufp->fullBit(oldp+42,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_comb__DOT__i_ready[1]));
    bufp->fullBit(oldp+43,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__o_ready[0]));
    bufp->fullBit(oldp+44,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__o_ready[1]));
    bufp->fullBit(oldp+45,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__ready_sent[0]));
    bufp->fullBit(oldp+46,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__ready_sent[1]));
    bufp->fullBit(oldp+47,(vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellout__i_twopower__i_ready));
    bufp->fullBit(oldp+48,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_ready
                           [1U]));
    bufp->fullBit(oldp+49,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__i_filter__DOT__i_ready));
    bufp->fullBit(oldp+50,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__loop_init));
    bufp->fullBit(oldp+51,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__i_loop__DOT__o_cen));
    bufp->fullBit(oldp+52,(vlSelfRef.Testbench__DOT__i_rsa__DOT__pipeline_stg1__DOT__i_ready));
    bufp->fullBit(oldp+53,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_ready
                           [0U]));
    bufp->fullWData(oldp+54,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__multiply),256);
    __Vtemp_1[0U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[0U];
    __Vtemp_1[1U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[1U];
    __Vtemp_1[2U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[2U];
    __Vtemp_1[3U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[3U];
    __Vtemp_1[4U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[4U];
    __Vtemp_1[5U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[5U];
    __Vtemp_1[6U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[6U];
    __Vtemp_1[7U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[7U];
    bufp->fullWData(oldp+62,(__Vtemp_1),256);
    bufp->fullWData(oldp+70,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square),256);
    bufp->fullSData(oldp+78,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter),10);
    bufp->fullSData(oldp+79,((0x000003ffU & (((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter) 
                                              - (IData)(1U)) 
                                             >> 1U))),10);
    bufp->fullBit(oldp+80,((0x0202U == (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter))));
    bufp->fullWData(oldp+81,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result),258);
    bufp->fullBit(oldp+90,((0x0100U == (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_counter))));
    bufp->fullSData(oldp+91,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_counter),9);
    bufp->fullIData(oldp+92,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_counter),32);
    bufp->fullWData(oldp+93,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result),257);
    if ((0U == (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter))) {
        __Vtemp_6[0U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__base[0U];
        __Vtemp_6[1U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__base[1U];
        __Vtemp_6[2U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__base[2U];
        __Vtemp_6[3U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__base[3U];
        __Vtemp_6[4U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__base[4U];
        __Vtemp_6[5U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__base[5U];
        __Vtemp_6[6U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__base[6U];
        __Vtemp_6[7U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__base[7U];
    } else if ((1U & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter))) {
        __Vtemp_6[0U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[0U];
        __Vtemp_6[1U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[1U];
        __Vtemp_6[2U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[2U];
        __Vtemp_6[3U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[3U];
        __Vtemp_6[4U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[4U];
        __Vtemp_6[5U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[5U];
        __Vtemp_6[6U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[6U];
        __Vtemp_6[7U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[7U];
    } else {
        __Vtemp_6[0U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[0U];
        __Vtemp_6[1U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[1U];
        __Vtemp_6[2U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[2U];
        __Vtemp_6[3U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[3U];
        __Vtemp_6[4U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[4U];
        __Vtemp_6[5U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[5U];
        __Vtemp_6[6U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[6U];
        __Vtemp_6[7U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[7U];
    }
    bufp->fullWData(oldp+102,(__Vtemp_6),256);
    bufp->fullWData(oldp+110,(vlSelfRef.Testbench__DOT__i_rsa__DOT__msg),256);
    bufp->fullWData(oldp+118,(vlSelfRef.Testbench__DOT__i_rsa__DOT__key),256);
    bufp->fullWData(oldp+126,(vlSelfRef.Testbench__DOT__i_rsa__DOT__modulus),256);
    bufp->fullBit(oldp+134,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_i_valid));
    bufp->fullBit(oldp+135,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_valid[0]));
    bufp->fullBit(oldp+136,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_valid[1]));
    bufp->fullWData(oldp+137,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_msg),256);
    bufp->fullWData(oldp+145,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_key),256);
    bufp->fullWData(oldp+153,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_modulus),256);
    bufp->fullWData(oldp+161,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__base),256);
    bufp->fullWData(oldp+169,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__msg),256);
    bufp->fullWData(oldp+177,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__key),256);
    bufp->fullWData(oldp+185,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__modulus),256);
    bufp->fullBit(oldp+193,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_valid[0]));
    bufp->fullBit(oldp+194,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_valid[1]));
    bufp->fullBit(oldp+195,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_valid));
    bufp->fullBit(oldp+196,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__o_valid[0]));
    bufp->fullBit(oldp+197,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__o_valid[1]));
    bufp->fullBit(oldp+198,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__o_sent[0]));
    bufp->fullBit(oldp+199,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__o_sent[1]));
    bufp->fullIData(oldp+200,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__unnamedblk4__DOT__i),32);
    bufp->fullBit(oldp+201,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_valid
                            [1U]));
    bufp->fullBit(oldp+202,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_valid
                            [0U]));
    bufp->fullWData(oldp+203,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__data_a),258);
    bufp->fullWData(oldp+212,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__data_b),258);
    bufp->fullWData(oldp+221,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__data_modulus),258);
    bufp->fullBit(oldp+230,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__loop_o_valid));
    bufp->fullBit(oldp+231,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__o_valid[0]));
    bufp->fullBit(oldp+232,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__o_valid[1]));
    bufp->fullBit(oldp+233,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__o_sent[0]));
    bufp->fullBit(oldp+234,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__o_sent[1]));
    bufp->fullIData(oldp+235,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__unnamedblk4__DOT__i),32);
    bufp->fullBit(oldp+236,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_valid
                            [1U]));
    __Vtemp_7[0U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__modulus[0U];
    __Vtemp_7[1U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__modulus[1U];
    __Vtemp_7[2U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__modulus[2U];
    __Vtemp_7[3U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__modulus[3U];
    __Vtemp_7[4U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__modulus[4U];
    __Vtemp_7[5U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__modulus[5U];
    __Vtemp_7[6U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__modulus[6U];
    __Vtemp_7[7U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__modulus[7U];
    __Vtemp_7[8U] = 0x00000200U;
    bufp->fullWData(oldp+237,(__Vtemp_7),288);
    bufp->fullIData(oldp+246,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__data_power),32);
    bufp->fullWData(oldp+247,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__data_modulus),257);
    bufp->fullBit(oldp+256,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__loop_o_valid));
    bufp->fullBit(oldp+257,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_valid
                            [0U]));
    bufp->fullBit(oldp+258,(vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellout__pipeline_stg1__o_valid));
    bufp->fullBit(oldp+259,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_o_valid));
    bufp->fullWData(oldp+260,(vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in),1024);
    bufp->fullBit(oldp+292,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__i_filter__DOT__o_valid));
    bufp->fullWData(oldp+293,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b),256);
    __Vtemp_8[0U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[0U];
    __Vtemp_8[1U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[1U];
    __Vtemp_8[2U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[2U];
    __Vtemp_8[3U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[3U];
    __Vtemp_8[4U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[4U];
    __Vtemp_8[5U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[5U];
    __Vtemp_8[6U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[6U];
    __Vtemp_8[7U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[7U];
    bufp->fullWData(oldp+301,(__Vtemp_8),256);
    bufp->fullBit(oldp+309,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellout__i_montgomery__i_ready));
    bufp->fullWData(oldp+310,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in),768);
    bufp->fullWData(oldp+334,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next),258);
    bufp->fullWData(oldp+343,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result),258);
    bufp->fullBit(oldp+352,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__loop_init));
    bufp->fullBit(oldp+353,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__i_loop__DOT__o_cen));
    bufp->fullBit(oldp+354,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_comb__DOT__i_valid[0]));
    bufp->fullBit(oldp+355,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_comb__DOT__i_valid[1]));
    bufp->fullBit(oldp+356,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT____Vcellinp__i_filter__i_pass));
    bufp->fullBit(oldp+357,(vlSelfRef.clk));
    bufp->fullBit(oldp+358,(vlSelfRef.rst_n));
    bufp->fullBit(oldp+359,((1U & ((~ (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_i_valid)) 
                                   | (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_i_ready)))));
    bufp->fullBit(oldp+360,(((0x0202U == (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter)) 
                             & vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_valid
                             [1U])));
    bufp->fullBit(oldp+361,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_valid[0]));
    bufp->fullBit(oldp+362,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_valid[1]));
    bufp->fullBit(oldp+363,((1U & (vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__key[
                                   (7U & (((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter) 
                                           - (IData)(1U)) 
                                          >> 6U))] 
                                   >> (0x0000001fU 
                                       & (((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter) 
                                           - (IData)(1U)) 
                                          >> 1U))))));
    bufp->fullBit(oldp+364,(((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_ready) 
                             & ((0x0202U != (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter)) 
                                & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_valid)))));
    bufp->fullBit(oldp+365,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_ready[0]));
    bufp->fullBit(oldp+366,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_ready[1]));
    bufp->fullBit(oldp+367,(((0x0202U != (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter)) 
                             | (IData)(vlSelfRef.Testbench__DOT__o_ready))));
    bufp->fullBit(oldp+368,(((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_o_valid) 
                             | ((~ ((0x0202U == (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter)) 
                                    & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_ready))) 
                                & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_valid)))));
    bufp->fullBit(oldp+369,((vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_valid
                             [0U] | (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__i_loop__DOT__o_cen))));
    bufp->fullBit(oldp+370,(((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT____Vcellinp__i_filter__i_pass) 
                             & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__loop_o_valid))));
    bufp->fullBit(oldp+371,((vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_valid
                             [1U] | ((~ ((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT____Vcellinp__i_filter__i_pass) 
                                         & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__i_filter__DOT__i_ready))) 
                                     & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__loop_o_valid)))));
    bufp->fullBit(oldp+372,(((IData)(vlSelfRef.Testbench__DOT__i_valid) 
                             | ((~ (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_i_ready)) 
                                & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_i_valid)))));
    bufp->fullBit(oldp+373,((vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_valid
                             [0U] | ((~ vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_ready
                                      [0U]) & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellout__pipeline_stg1__o_valid)))));
}
