// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "VRSA_tb__Syms.h"


void VRSA_tb___024root__trace_chg_0_sub_0(VRSA_tb___024root* vlSelf, VerilatedFst::Buffer* bufp);

void VRSA_tb___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRSA_tb___024root__trace_chg_0\n"); );
    // Body
    VRSA_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VRSA_tb___024root*>(voidSelf);
    VRSA_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    VRSA_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VRSA_tb___024root__trace_chg_0_sub_0(VRSA_tb___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRSA_tb___024root__trace_chg_0_sub_0\n"); );
    VRSA_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<8>/*255:0*/ __Vtemp_1;
    VlWide<8>/*255:0*/ __Vtemp_6;
    VlWide<9>/*287:0*/ __Vtemp_7;
    VlWide<8>/*255:0*/ __Vtemp_8;
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.Testbench__DOT__i_valid));
        bufp->chgWData(oldp+1,(vlSelfRef.Testbench__DOT__i_in),768);
        bufp->chgBit(oldp+25,(vlSelfRef.Testbench__DOT__o_ready));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [7U])))) {
        bufp->chgBit(oldp+26,(vlSelfRef.Testbench__DOT__i_rsa__DOT__pipeline_input__DOT__o_en));
        bufp->chgBit(oldp+27,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_i_ready));
        bufp->chgBit(oldp+28,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_o_ready));
        bufp->chgBit(oldp+29,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_ready[0]));
        bufp->chgBit(oldp+30,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_ready[1]));
        bufp->chgBit(oldp+31,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_ready[0]));
        bufp->chgBit(oldp+32,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_ready[1]));
        bufp->chgBit(oldp+33,(vlSelfRef.Testbench__DOT__i_rsa__DOT__pipeline_stg1__DOT__o_en));
        bufp->chgBit(oldp+34,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_init));
        bufp->chgBit(oldp+35,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_ready));
        bufp->chgBit(oldp+36,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__o_ready[0]));
        bufp->chgBit(oldp+37,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__o_ready[1]));
        bufp->chgBit(oldp+38,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__ready_sent[0]));
        bufp->chgBit(oldp+39,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__ready_sent[1]));
        bufp->chgBit(oldp+40,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_comb__DOT__i_ready[0]));
        bufp->chgBit(oldp+41,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_comb__DOT__i_ready[1]));
        bufp->chgBit(oldp+42,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__o_ready[0]));
        bufp->chgBit(oldp+43,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__o_ready[1]));
        bufp->chgBit(oldp+44,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__ready_sent[0]));
        bufp->chgBit(oldp+45,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__ready_sent[1]));
        bufp->chgBit(oldp+46,(vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellout__i_twopower__i_ready));
        bufp->chgBit(oldp+47,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_ready
                              [1U]));
        bufp->chgBit(oldp+48,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__i_filter__DOT__i_ready));
        bufp->chgBit(oldp+49,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__loop_init));
        bufp->chgBit(oldp+50,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__i_loop__DOT__o_cen));
        bufp->chgBit(oldp+51,(vlSelfRef.Testbench__DOT__i_rsa__DOT__pipeline_stg1__DOT__i_ready));
        bufp->chgBit(oldp+52,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_ready
                              [0U]));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgWData(oldp+53,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__multiply),256);
        __Vtemp_1[0U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[0U];
        __Vtemp_1[1U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[1U];
        __Vtemp_1[2U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[2U];
        __Vtemp_1[3U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[3U];
        __Vtemp_1[4U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[4U];
        __Vtemp_1[5U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[5U];
        __Vtemp_1[6U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[6U];
        __Vtemp_1[7U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[7U];
        bufp->chgWData(oldp+61,(__Vtemp_1),256);
        bufp->chgWData(oldp+69,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square),256);
        bufp->chgSData(oldp+77,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter),10);
        bufp->chgSData(oldp+78,((0x000003ffU & (((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter) 
                                                 - (IData)(1U)) 
                                                >> 1U))),10);
        bufp->chgBit(oldp+79,((0x0202U == (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter))));
        bufp->chgWData(oldp+80,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result),258);
        bufp->chgBit(oldp+89,((0x0100U == (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_counter))));
        bufp->chgSData(oldp+90,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_counter),9);
        bufp->chgIData(oldp+91,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_counter),32);
        bufp->chgWData(oldp+92,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result),257);
    }
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity
                       [4U] | vlSelfRef.__Vm_traceActivity
                       [5U]) | vlSelfRef.__Vm_traceActivity
                      [6U])))) {
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
        bufp->chgWData(oldp+101,(__Vtemp_6),256);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[5U]))) {
        bufp->chgWData(oldp+109,(vlSelfRef.Testbench__DOT__i_rsa__DOT__msg),256);
        bufp->chgWData(oldp+117,(vlSelfRef.Testbench__DOT__i_rsa__DOT__key),256);
        bufp->chgWData(oldp+125,(vlSelfRef.Testbench__DOT__i_rsa__DOT__modulus),256);
        bufp->chgBit(oldp+133,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_i_valid));
        bufp->chgBit(oldp+134,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_valid[0]));
        bufp->chgBit(oldp+135,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_valid[1]));
        bufp->chgWData(oldp+136,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_msg),256);
        bufp->chgWData(oldp+144,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_key),256);
        bufp->chgWData(oldp+152,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_modulus),256);
        bufp->chgWData(oldp+160,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__base),256);
        bufp->chgWData(oldp+168,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__msg),256);
        bufp->chgWData(oldp+176,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__key),256);
        bufp->chgWData(oldp+184,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__modulus),256);
        bufp->chgBit(oldp+192,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_valid[0]));
        bufp->chgBit(oldp+193,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_valid[1]));
        bufp->chgBit(oldp+194,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_valid));
        bufp->chgBit(oldp+195,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__o_valid[0]));
        bufp->chgBit(oldp+196,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__o_valid[1]));
        bufp->chgBit(oldp+197,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__o_sent[0]));
        bufp->chgBit(oldp+198,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__o_sent[1]));
        bufp->chgIData(oldp+199,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__unnamedblk4__DOT__i),32);
        bufp->chgBit(oldp+200,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_valid
                               [1U]));
        bufp->chgBit(oldp+201,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_valid
                               [0U]));
        bufp->chgWData(oldp+202,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__data_a),258);
        bufp->chgWData(oldp+211,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__data_b),258);
        bufp->chgWData(oldp+220,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__data_modulus),258);
        bufp->chgBit(oldp+229,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__loop_o_valid));
        bufp->chgBit(oldp+230,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__o_valid[0]));
        bufp->chgBit(oldp+231,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__o_valid[1]));
        bufp->chgBit(oldp+232,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__o_sent[0]));
        bufp->chgBit(oldp+233,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__o_sent[1]));
        bufp->chgIData(oldp+234,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__unnamedblk4__DOT__i),32);
        bufp->chgBit(oldp+235,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_valid
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
        bufp->chgWData(oldp+236,(__Vtemp_7),288);
        bufp->chgIData(oldp+245,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__data_power),32);
        bufp->chgWData(oldp+246,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__data_modulus),257);
        bufp->chgBit(oldp+255,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__loop_o_valid));
        bufp->chgBit(oldp+256,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_valid
                               [0U]));
        bufp->chgBit(oldp+257,(vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellout__pipeline_stg1__o_valid));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[6U]))) {
        bufp->chgBit(oldp+258,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_o_valid));
        bufp->chgWData(oldp+259,(vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in),1024);
        bufp->chgBit(oldp+291,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__i_filter__DOT__o_valid));
        bufp->chgWData(oldp+292,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b),256);
        __Vtemp_8[0U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[0U];
        __Vtemp_8[1U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[1U];
        __Vtemp_8[2U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[2U];
        __Vtemp_8[3U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[3U];
        __Vtemp_8[4U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[4U];
        __Vtemp_8[5U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[5U];
        __Vtemp_8[6U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[6U];
        __Vtemp_8[7U] = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[7U];
        bufp->chgWData(oldp+300,(__Vtemp_8),256);
        bufp->chgBit(oldp+308,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellout__i_montgomery__i_ready));
        bufp->chgWData(oldp+309,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in),768);
        bufp->chgWData(oldp+333,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next),258);
        bufp->chgWData(oldp+342,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result),258);
        bufp->chgBit(oldp+351,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__loop_init));
        bufp->chgBit(oldp+352,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__i_loop__DOT__o_cen));
        bufp->chgBit(oldp+353,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_comb__DOT__i_valid[0]));
        bufp->chgBit(oldp+354,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_comb__DOT__i_valid[1]));
        bufp->chgBit(oldp+355,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT____Vcellinp__i_filter__i_pass));
    }
    bufp->chgBit(oldp+356,(vlSelfRef.clk));
    bufp->chgBit(oldp+357,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+358,((1U & ((~ (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_i_valid)) 
                                  | (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_i_ready)))));
    bufp->chgBit(oldp+359,(((0x0202U == (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter)) 
                            & vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_valid
                            [1U])));
    bufp->chgBit(oldp+360,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_valid[0]));
    bufp->chgBit(oldp+361,(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_valid[1]));
    bufp->chgBit(oldp+362,((1U & (vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__key[
                                  (7U & (((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter) 
                                          - (IData)(1U)) 
                                         >> 6U))] >> 
                                  (0x0000001fU & (((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter) 
                                                   - (IData)(1U)) 
                                                  >> 1U))))));
    bufp->chgBit(oldp+363,(((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_ready) 
                            & ((0x0202U != (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter)) 
                               & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_valid)))));
    bufp->chgBit(oldp+364,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_ready[0]));
    bufp->chgBit(oldp+365,(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_ready[1]));
    bufp->chgBit(oldp+366,(((0x0202U != (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter)) 
                            | (IData)(vlSelfRef.Testbench__DOT__o_ready))));
    bufp->chgBit(oldp+367,(((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_o_valid) 
                            | ((~ ((0x0202U == (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter)) 
                                   & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_ready))) 
                               & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_valid)))));
    bufp->chgBit(oldp+368,((vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_valid
                            [0U] | (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__i_loop__DOT__o_cen))));
    bufp->chgBit(oldp+369,(((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT____Vcellinp__i_filter__i_pass) 
                            & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__loop_o_valid))));
    bufp->chgBit(oldp+370,((vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_valid
                            [1U] | ((~ ((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT____Vcellinp__i_filter__i_pass) 
                                        & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__i_filter__DOT__i_ready))) 
                                    & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__loop_o_valid)))));
    bufp->chgBit(oldp+371,(((IData)(vlSelfRef.Testbench__DOT__i_valid) 
                            | ((~ (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_i_ready)) 
                               & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_i_valid)))));
    bufp->chgBit(oldp+372,((vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_valid
                            [0U] | ((~ vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_ready
                                     [0U]) & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellout__pipeline_stg1__o_valid)))));
}

void VRSA_tb___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRSA_tb___024root__trace_cleanup\n"); );
    // Body
    VRSA_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VRSA_tb___024root*>(voidSelf);
    VRSA_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[7U] = 0U;
}
