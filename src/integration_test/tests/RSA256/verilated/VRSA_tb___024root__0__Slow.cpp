// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VRSA_tb.h for the primary calling header

#include "VRSA_tb__pch.h"

VL_ATTR_COLD void VRSA_tb___024root___eval_static(VRSA_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRSA_tb___024root___eval_static\n"); );
    VRSA_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
    vlSelfRef.__Vtrigprevexpr_hda97fe31__1 = ((0x0202U 
                                               == (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter)) 
                                              & vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_valid
                                              [1U]);
}

VL_ATTR_COLD void VRSA_tb___024root___eval_final(VRSA_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRSA_tb___024root___eval_final\n"); );
    VRSA_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VRSA_tb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VRSA_tb___024root___eval_phase__stl(VRSA_tb___024root* vlSelf);

VL_ATTR_COLD void VRSA_tb___024root___eval_settle(VRSA_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRSA_tb___024root___eval_settle\n"); );
    VRSA_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            VRSA_tb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("RSA_tb.sv", 37, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (VRSA_tb___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void VRSA_tb___024root___eval_triggers__stl(VRSA_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRSA_tb___024root___eval_triggers__stl\n"); );
    VRSA_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VRSA_tb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool VRSA_tb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VRSA_tb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRSA_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(VRSA_tb___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool VRSA_tb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRSA_tb___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const VlWide<9>/*287:0*/ VRSA_tb__ConstPool__CONST_h52851b6b_0;
extern const VlWide<8>/*255:0*/ VRSA_tb__ConstPool__CONST_h4e9f510d_0;

VL_ATTR_COLD void VRSA_tb___024root___stl_sequent__TOP__0(VRSA_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRSA_tb___024root___stl_sequent__TOP__0\n"); );
    VRSA_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<9>/*287:0*/ __Vtemp_4;
    VlWide<9>/*287:0*/ __Vtemp_6;
    VlWide<9>/*287:0*/ __Vtemp_8;
    VlWide<9>/*287:0*/ __Vtemp_9;
    // Body
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__i_loop__DOT__o_cen 
        = ((0x0100U != (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_counter)) 
           & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__loop_o_valid));
    if ((0x0100U == (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_counter))) {
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__i_filter__DOT__o_valid 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__loop_o_valid;
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_modulus[0U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[1U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_modulus[1U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[2U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_modulus[2U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[3U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_modulus[3U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[4U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_modulus[4U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[5U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_modulus[5U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[6U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_modulus[6U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[7U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_modulus[7U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[8U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_key[0U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[9U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_key[1U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000000aU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_key[2U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000000bU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_key[3U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000000cU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_key[4U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000000dU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_key[5U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000000eU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_key[6U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000000fU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_key[7U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x00000010U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_msg[0U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x00000011U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_msg[1U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x00000012U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_msg[2U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x00000013U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_msg[3U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x00000014U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_msg[4U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x00000015U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_msg[5U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x00000016U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_msg[6U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x00000017U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_msg[7U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x00000018U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[0U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x00000019U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[1U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000001aU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[2U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000001bU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[3U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000001cU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[4U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000001dU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[5U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000001eU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[6U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000001fU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[7U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[0U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[0U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[1U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[1U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[2U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[2U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[3U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[3U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[4U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[4U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[5U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[5U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[6U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[6U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[7U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[7U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[8U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[8U];
    } else {
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__i_filter__DOT__o_valid = 0U;
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_modulus[0U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[1U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_modulus[1U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[2U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_modulus[2U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[3U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_modulus[3U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[4U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_modulus[4U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[5U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_modulus[5U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[6U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_modulus[6U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[7U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_modulus[7U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[8U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_key[0U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[9U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_key[1U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000000aU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_key[2U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000000bU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_key[3U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000000cU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_key[4U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000000dU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_key[5U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000000eU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_key[6U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000000fU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_key[7U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x00000010U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_msg[0U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x00000011U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_msg[1U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x00000012U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_msg[2U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x00000013U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_msg[3U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x00000014U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_msg[4U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x00000015U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_msg[5U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x00000016U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_msg[6U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x00000017U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_msg[7U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x00000018U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[0U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x00000019U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[1U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000001aU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[2U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000001bU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[3U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000001cU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[4U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000001dU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[5U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000001eU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[6U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in[0x0000001fU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result[7U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[0U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[0U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[1U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[1U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[2U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[2U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[3U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[3U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[4U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[4U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[5U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[5U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[6U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[6U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[7U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[7U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[8U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[8U];
        if (((0x0101U >= (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_counter)) 
             && (1U & (vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__data_a[
                       ((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_counter) 
                        >> 5U)] >> (0x0000001fU & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_counter)))))) {
            VL_ADD_W(9, __Vtemp_4, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__data_b);
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[0U] 
                = (VRSA_tb__ConstPool__CONST_h52851b6b_0[0U] 
                   & __Vtemp_4[0U]);
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[1U] 
                = (VRSA_tb__ConstPool__CONST_h52851b6b_0[1U] 
                   & __Vtemp_4[1U]);
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[2U] 
                = (VRSA_tb__ConstPool__CONST_h52851b6b_0[2U] 
                   & __Vtemp_4[2U]);
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[3U] 
                = (VRSA_tb__ConstPool__CONST_h52851b6b_0[3U] 
                   & __Vtemp_4[3U]);
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[4U] 
                = (VRSA_tb__ConstPool__CONST_h52851b6b_0[4U] 
                   & __Vtemp_4[4U]);
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[5U] 
                = (VRSA_tb__ConstPool__CONST_h52851b6b_0[5U] 
                   & __Vtemp_4[5U]);
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[6U] 
                = (VRSA_tb__ConstPool__CONST_h52851b6b_0[6U] 
                   & __Vtemp_4[6U]);
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[7U] 
                = (VRSA_tb__ConstPool__CONST_h52851b6b_0[7U] 
                   & __Vtemp_4[7U]);
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[8U] 
                = (VRSA_tb__ConstPool__CONST_h52851b6b_0[8U] 
                   & __Vtemp_4[8U]);
        }
        if ((1U & vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[0U])) {
            VL_ADD_W(9, __Vtemp_6, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__data_modulus);
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[0U] 
                = (VRSA_tb__ConstPool__CONST_h52851b6b_0[0U] 
                   & __Vtemp_6[0U]);
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[1U] 
                = (VRSA_tb__ConstPool__CONST_h52851b6b_0[1U] 
                   & __Vtemp_6[1U]);
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[2U] 
                = (VRSA_tb__ConstPool__CONST_h52851b6b_0[2U] 
                   & __Vtemp_6[2U]);
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[3U] 
                = (VRSA_tb__ConstPool__CONST_h52851b6b_0[3U] 
                   & __Vtemp_6[3U]);
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[4U] 
                = (VRSA_tb__ConstPool__CONST_h52851b6b_0[4U] 
                   & __Vtemp_6[4U]);
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[5U] 
                = (VRSA_tb__ConstPool__CONST_h52851b6b_0[5U] 
                   & __Vtemp_6[5U]);
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[6U] 
                = (VRSA_tb__ConstPool__CONST_h52851b6b_0[6U] 
                   & __Vtemp_6[6U]);
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[7U] 
                = (VRSA_tb__ConstPool__CONST_h52851b6b_0[7U] 
                   & __Vtemp_6[7U]);
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[8U] 
                = (VRSA_tb__ConstPool__CONST_h52851b6b_0[8U] 
                   & __Vtemp_6[8U]);
        }
        VL_SHIFTR_WWI(258,258,32, __Vtemp_8, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next, 1U);
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[0U] 
            = (VRSA_tb__ConstPool__CONST_h52851b6b_0[0U] 
               & __Vtemp_8[0U]);
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[1U] 
            = (VRSA_tb__ConstPool__CONST_h52851b6b_0[1U] 
               & __Vtemp_8[1U]);
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[2U] 
            = (VRSA_tb__ConstPool__CONST_h52851b6b_0[2U] 
               & __Vtemp_8[2U]);
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[3U] 
            = (VRSA_tb__ConstPool__CONST_h52851b6b_0[3U] 
               & __Vtemp_8[3U]);
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[4U] 
            = (VRSA_tb__ConstPool__CONST_h52851b6b_0[4U] 
               & __Vtemp_8[4U]);
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[5U] 
            = (VRSA_tb__ConstPool__CONST_h52851b6b_0[5U] 
               & __Vtemp_8[5U]);
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[6U] 
            = (VRSA_tb__ConstPool__CONST_h52851b6b_0[6U] 
               & __Vtemp_8[6U]);
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[7U] 
            = (VRSA_tb__ConstPool__CONST_h52851b6b_0[7U] 
               & __Vtemp_8[7U]);
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next[8U] 
            = (VRSA_tb__ConstPool__CONST_h52851b6b_0[8U] 
               & __Vtemp_8[8U]);
    }
    VL_SUB_W(9, __Vtemp_9, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__data_modulus);
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[0U] 
        = (VRSA_tb__ConstPool__CONST_h52851b6b_0[0U] 
           & (VL_GT_W(9, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__data_modulus)
               ? __Vtemp_9[0U] : vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[0U]));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[1U] 
        = (VRSA_tb__ConstPool__CONST_h52851b6b_0[1U] 
           & (VL_GT_W(9, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__data_modulus)
               ? __Vtemp_9[1U] : vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[1U]));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[2U] 
        = (VRSA_tb__ConstPool__CONST_h52851b6b_0[2U] 
           & (VL_GT_W(9, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__data_modulus)
               ? __Vtemp_9[2U] : vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[2U]));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[3U] 
        = (VRSA_tb__ConstPool__CONST_h52851b6b_0[3U] 
           & (VL_GT_W(9, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__data_modulus)
               ? __Vtemp_9[3U] : vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[3U]));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[4U] 
        = (VRSA_tb__ConstPool__CONST_h52851b6b_0[4U] 
           & (VL_GT_W(9, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__data_modulus)
               ? __Vtemp_9[4U] : vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[4U]));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[5U] 
        = (VRSA_tb__ConstPool__CONST_h52851b6b_0[5U] 
           & (VL_GT_W(9, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__data_modulus)
               ? __Vtemp_9[5U] : vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[5U]));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[6U] 
        = (VRSA_tb__ConstPool__CONST_h52851b6b_0[6U] 
           & (VL_GT_W(9, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__data_modulus)
               ? __Vtemp_9[6U] : vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[6U]));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[7U] 
        = (VRSA_tb__ConstPool__CONST_h52851b6b_0[7U] 
           & (VL_GT_W(9, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__data_modulus)
               ? __Vtemp_9[7U] : vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[7U]));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[8U] 
        = (VRSA_tb__ConstPool__CONST_h52851b6b_0[8U] 
           & (VL_GT_W(9, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result, vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__data_modulus)
               ? __Vtemp_9[8U] : vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result[8U]));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_valid[0U] 
        = ((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_i_valid) 
           & (~ vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__o_sent
              [0U]));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_valid[1U] 
        = ((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_i_valid) 
           & (~ vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__o_sent
              [1U]));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_ready[1U] 
        = ((0x0202U != (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter)) 
           | (IData)(vlSelfRef.Testbench__DOT__o_ready));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_valid[0U] 
        = ((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_valid) 
           & (~ vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__o_sent
              [0U]));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_valid[1U] 
        = ((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_valid) 
           & (~ vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__o_sent
              [1U]));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_valid[0U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellout__pipeline_stg1__o_valid;
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT____Vcellinp__i_filter__i_pass 
        = (vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__data_power 
           == vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_counter);
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__modulus[0U];
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[1U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__modulus[1U];
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[2U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__modulus[2U];
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[3U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__modulus[3U];
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[4U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__modulus[4U];
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[5U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__modulus[5U];
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[6U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__modulus[6U];
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[7U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__modulus[7U];
    if ((0U == (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter))) {
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[0U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__msg[0U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[1U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__msg[1U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[2U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__msg[2U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[3U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__msg[3U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[4U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__msg[4U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[5U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__msg[5U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[6U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__msg[6U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[7U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__msg[7U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[8U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[0U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[9U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[1U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x0000000aU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[2U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x0000000bU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[3U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x0000000cU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[4U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x0000000dU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[5U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x0000000eU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[6U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x0000000fU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[7U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000010U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__base[0U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000011U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__base[1U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000012U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__base[2U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000013U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__base[3U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000014U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__base[4U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000015U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__base[5U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000016U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__base[6U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000017U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__base[7U];
    } else if ((1U & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter))) {
        if ((1U == (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter))) {
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[0U] 
                = VRSA_tb__ConstPool__CONST_h4e9f510d_0[0U];
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[1U] 
                = VRSA_tb__ConstPool__CONST_h4e9f510d_0[1U];
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[2U] 
                = VRSA_tb__ConstPool__CONST_h4e9f510d_0[2U];
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[3U] 
                = VRSA_tb__ConstPool__CONST_h4e9f510d_0[3U];
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[4U] 
                = VRSA_tb__ConstPool__CONST_h4e9f510d_0[4U];
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[5U] 
                = VRSA_tb__ConstPool__CONST_h4e9f510d_0[5U];
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[6U] 
                = VRSA_tb__ConstPool__CONST_h4e9f510d_0[6U];
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[7U] 
                = VRSA_tb__ConstPool__CONST_h4e9f510d_0[7U];
        } else {
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[0U] 
                = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__multiply[0U];
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[1U] 
                = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__multiply[1U];
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[2U] 
                = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__multiply[2U];
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[3U] 
                = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__multiply[3U];
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[4U] 
                = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__multiply[4U];
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[5U] 
                = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__multiply[5U];
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[6U] 
                = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__multiply[6U];
            vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[7U] 
                = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__multiply[7U];
        }
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[8U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[0U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[9U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[1U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x0000000aU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[2U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x0000000bU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[3U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x0000000cU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[4U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x0000000dU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[5U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x0000000eU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[6U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x0000000fU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[7U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000010U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[0U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000011U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[1U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000012U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[2U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000013U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[3U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000014U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[4U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000015U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[5U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000016U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[6U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000017U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result[7U];
    } else {
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[0U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[0U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[1U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[1U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[2U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[2U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[3U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[3U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[4U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[4U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[5U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[5U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[6U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[6U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[7U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[7U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[8U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[0U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[9U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[1U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x0000000aU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[2U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x0000000bU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[3U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x0000000cU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[4U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x0000000dU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[5U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x0000000eU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[6U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x0000000fU] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b[7U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000010U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[0U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000011U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[1U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000012U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[2U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000013U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[3U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000014U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[4U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000015U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[5U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000016U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[6U];
        vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in[0x00000017U] 
            = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square[7U];
    }
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__o_valid[0U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_valid
        [0U];
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__o_valid[1U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_valid
        [1U];
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__o_valid[0U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_valid
        [0U];
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__o_valid[1U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_valid
        [1U];
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellout__i_montgomery__i_ready 
        = (1U & ((~ (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__loop_o_valid)) 
                 | (0x0100U == (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_counter))));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__loop_init 
        = ((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellout__i_montgomery__i_ready) 
           & vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_valid
           [0U]);
    vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_valid[1U] 
        = ((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT____Vcellinp__i_filter__i_pass) 
           & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__loop_o_valid));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_ready[0U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellout__i_montgomery__i_ready;
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_comb__DOT__i_valid[0U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_valid
        [0U];
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_comb__DOT__i_valid[1U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_valid
        [1U];
    vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_o_valid 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_valid
        [0U];
    vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_o_valid 
        = ((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_o_valid) 
           & vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_valid
           [1U]);
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__o_ready[0U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_ready
        [0U];
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__o_ready[1U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_ready
        [1U];
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__ready_sent[0U] 
        = (vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_ready
           [0U] | vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__o_sent
           [0U]);
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__ready_sent[1U] 
        = (vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_ready
           [1U] | vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__o_sent
           [1U]);
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_ready 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__ready_sent
        [0U];
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_ready 
        = ((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_ready) 
           & vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__ready_sent
           [1U]);
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_loop__DOT__o_cen 
        = ((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_ready) 
           & ((0x0202U != (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter)) 
              & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_valid)));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_loop__DOT__o_valid_w 
        = ((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_o_valid) 
           | ((~ ((0x0202U == (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter)) 
                  & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_ready))) 
              & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_valid)));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_o_ready 
        = (1U & ((~ (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_valid)) 
                 | ((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_ready) 
                    & (0x0202U == (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter)))));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_init 
        = ((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_o_ready) 
           & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_o_valid));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_ready[0U] 
        = ((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_o_ready) 
           & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_o_valid));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_ready[1U] 
        = ((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_o_ready) 
           & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_o_valid));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_comb__DOT__i_ready[0U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_ready
        [0U];
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_comb__DOT__i_ready[1U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_ready
        [1U];
    vlSelfRef.Testbench__DOT__i_rsa__DOT__pipeline_stg1__DOT__o_valid_w 
        = (vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_valid
           [0U] | ((~ vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_ready
                    [0U]) & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellout__pipeline_stg1__o_valid)));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__pipeline_stg1__DOT__i_ready 
        = (1U & ((~ (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellout__pipeline_stg1__o_valid)) 
                 | vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_ready
                 [0U]));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__i_filter__DOT__i_ready 
        = (1U & ((~ (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT____Vcellinp__i_filter__i_pass)) 
                 | vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_comb_ready
                 [1U]));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__pipeline_stg1__DOT__o_en 
        = ((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__pipeline_stg1__DOT__i_ready) 
           & vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_valid
           [0U]);
    vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_ready[0U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__pipeline_stg1__DOT__i_ready;
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__i_loop__DOT__o_cen 
        = ((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__i_filter__DOT__i_ready) 
           & ((~ (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT____Vcellinp__i_filter__i_pass)) 
              & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__loop_o_valid)));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__i_loop__DOT__o_valid_w 
        = (vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_valid
           [1U] | ((~ ((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT____Vcellinp__i_filter__i_pass) 
                       & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__i_filter__DOT__i_ready))) 
                   & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__loop_o_valid)));
    vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellout__i_twopower__i_ready 
        = (1U & ((~ (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__loop_o_valid)) 
                 | ((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__i_filter__DOT__i_ready) 
                    & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT____Vcellinp__i_filter__i_pass))));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_twopower__DOT__loop_init 
        = ((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellout__i_twopower__i_ready) 
           & vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_valid
           [1U]);
    vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_ready[1U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT____Vcellout__i_twopower__i_ready;
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__o_ready[0U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_ready
        [0U];
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__o_ready[1U] 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_ready
        [1U];
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__ready_sent[0U] 
        = (vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_ready
           [0U] | vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__o_sent
           [0U]);
    vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__ready_sent[1U] 
        = (vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_dist_ready
           [1U] | vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__o_sent
           [1U]);
    vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_i_ready 
        = vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__ready_sent
        [0U];
    vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_i_ready 
        = ((IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_i_ready) 
           & vlSelfRef.Testbench__DOT__i_rsa__DOT__i_dist__DOT__ready_sent
           [1U]);
    vlSelfRef.Testbench__DOT__i_rsa__DOT__pipeline_input__DOT__o_en 
        = (((~ (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_i_valid)) 
            | (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_i_ready)) 
           & (IData)(vlSelfRef.Testbench__DOT__i_valid));
    vlSelfRef.Testbench__DOT__i_rsa__DOT__pipeline_input__DOT__o_valid_w 
        = ((IData)(vlSelfRef.Testbench__DOT__i_valid) 
           | ((~ (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_i_ready)) 
              & (IData)(vlSelfRef.Testbench__DOT__i_rsa__DOT__s1_i_valid)));
}

VL_ATTR_COLD void VRSA_tb___024root____Vm_traceActivitySetAll(VRSA_tb___024root* vlSelf);

VL_ATTR_COLD void VRSA_tb___024root___eval_stl(VRSA_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRSA_tb___024root___eval_stl\n"); );
    VRSA_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        VRSA_tb___024root___stl_sequent__TOP__0(vlSelf);
        VRSA_tb___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool VRSA_tb___024root___eval_phase__stl(VRSA_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRSA_tb___024root___eval_phase__stl\n"); );
    VRSA_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    VRSA_tb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = VRSA_tb___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        VRSA_tb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool VRSA_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VRSA_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRSA_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(VRSA_tb___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @( ((10'h202 == Testbench.i_rsa.i_RSAMont.round_counter) & (Testbench.i_rsa.i_RSAMont.dist_o_valid[1'h1])))\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VRSA_tb___024root____Vm_traceActivitySetAll(VRSA_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRSA_tb___024root____Vm_traceActivitySetAll\n"); );
    VRSA_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
    vlSelfRef.__Vm_traceActivity[6U] = 1U;
    vlSelfRef.__Vm_traceActivity[7U] = 1U;
}

VL_ATTR_COLD void VRSA_tb___024root___ctor_var_reset(VRSA_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRSA_tb___024root___ctor_var_reset\n"); );
    VRSA_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->Testbench__DOT__i_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4585433952531347001ull);
    VL_SCOPED_RAND_RESET_W(768, vlSelf->Testbench__DOT__i_in, __VscopeHash, 12847749529424359176ull);
    vlSelf->Testbench__DOT__o_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11219396584126942081ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->Testbench__DOT__i_rsa__DOT__msg, __VscopeHash, 2352071487445905963ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->Testbench__DOT__i_rsa__DOT__key, __VscopeHash, 14063986081951489779ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->Testbench__DOT__i_rsa__DOT__modulus, __VscopeHash, 18053023517363580070ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__s1_i_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14959958368095173074ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__s1_i_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8909212056187325883ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__s1_o_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3363661460761036823ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__s1_o_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1167787973343477281ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->Testbench__DOT__i_rsa__DOT__s1_dist_valid[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9908298744116251096ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->Testbench__DOT__i_rsa__DOT__s1_dist_ready[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9701258915676502738ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->Testbench__DOT__i_rsa__DOT__s1_comb_valid[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12909548526888667520ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->Testbench__DOT__i_rsa__DOT__s1_comb_ready[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15609840526369639975ull);
    }
    VL_SCOPED_RAND_RESET_W(256, vlSelf->Testbench__DOT__i_rsa__DOT__s1_msg, __VscopeHash, 4984971410753617018ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->Testbench__DOT__i_rsa__DOT__s1_key, __VscopeHash, 10552996289439573168ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->Testbench__DOT__i_rsa__DOT__s1_modulus, __VscopeHash, 13207920966651280947ull);
    vlSelf->Testbench__DOT__i_rsa__DOT____Vcellout__pipeline_stg1__o_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7094767507447358011ull);
    vlSelf->Testbench__DOT__i_rsa__DOT____Vcellout__i_twopower__i_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6098785449535284287ull);
    VL_SCOPED_RAND_RESET_W(1024, vlSelf->Testbench__DOT__i_rsa__DOT____Vcellinp__i_RSAMont__i_in, __VscopeHash, 16009292760899405128ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__pipeline_input__DOT__o_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3239988813989018586ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__pipeline_input__DOT__o_valid_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12427648109553245463ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->Testbench__DOT__i_rsa__DOT__i_dist__DOT__o_valid[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12041502013649294818ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->Testbench__DOT__i_rsa__DOT__i_dist__DOT__o_ready[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12693415299832639525ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->Testbench__DOT__i_rsa__DOT__i_dist__DOT__o_sent[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2344744070463028993ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->Testbench__DOT__i_rsa__DOT__i_dist__DOT__ready_sent[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14448531855083313237ull);
    }
    vlSelf->Testbench__DOT__i_rsa__DOT__i_dist__DOT__unnamedblk4__DOT__i = 0;
    vlSelf->Testbench__DOT__i_rsa__DOT__pipeline_stg1__DOT__i_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6143332141643257389ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__pipeline_stg1__DOT__o_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8177980409204740642ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__pipeline_stg1__DOT__o_valid_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1585059539027859475ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__i_twopower__DOT__data_power = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10947834537482354218ull);
    VL_SCOPED_RAND_RESET_W(257, vlSelf->Testbench__DOT__i_rsa__DOT__i_twopower__DOT__data_modulus, __VscopeHash, 4575412085918398775ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_counter = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15713530149686846431ull);
    VL_SCOPED_RAND_RESET_W(257, vlSelf->Testbench__DOT__i_rsa__DOT__i_twopower__DOT__round_result, __VscopeHash, 3570335447804492947ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__i_twopower__DOT__loop_o_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1406785668428524315ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__i_twopower__DOT__loop_init = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 199617256132319245ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__i_twopower__DOT____Vcellinp__i_filter__i_pass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12005478663477505841ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__i_twopower__DOT__i_loop__DOT__o_cen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5544562666967011147ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__i_twopower__DOT__i_loop__DOT__o_valid_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17295172878904102976ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__i_twopower__DOT__i_filter__DOT__i_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7167078854575539659ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->Testbench__DOT__i_rsa__DOT__i_comb__DOT__i_valid[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15495331890221759716ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->Testbench__DOT__i_rsa__DOT__i_comb__DOT__i_ready[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11185460984607779653ull);
    }
    VL_SCOPED_RAND_RESET_W(256, vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__base, __VscopeHash, 15295355616905186940ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__msg, __VscopeHash, 3856641293343479305ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__key, __VscopeHash, 15990971915448185036ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__modulus, __VscopeHash, 1950724071843039408ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__square, __VscopeHash, 11731194069237884777ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__multiply, __VscopeHash, 11200095281934487217ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__round_counter = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 3164318945275265250ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_init = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15618427882770486400ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_valid[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14522284034540704916ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__dist_o_ready[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6965887628238567997ull);
    }
    vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 308791140585236945ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__loop_o_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5284967015230677073ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__montgomery_in_b, __VscopeHash, 18446018434536995335ull);
    VL_SCOPED_RAND_RESET_W(768, vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellinp__i_montgomery__i_in, __VscopeHash, 6521135461084122587ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT____Vcellout__i_montgomery__i_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5057848565376627505ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_loop__DOT__o_cen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 925258633080304455ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_loop__DOT__o_valid_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8635725230926742995ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__o_valid[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11617234760508765452ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__o_ready[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3086834970569900644ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__o_sent[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12554458100939156784ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__ready_sent[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2505689754638501001ull);
    }
    vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_dist__DOT__unnamedblk4__DOT__i = 0;
    VL_SCOPED_RAND_RESET_W(258, vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__data_a, __VscopeHash, 8176192128446973853ull);
    VL_SCOPED_RAND_RESET_W(258, vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__data_b, __VscopeHash, 13364450647315535547ull);
    VL_SCOPED_RAND_RESET_W(258, vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__data_modulus, __VscopeHash, 17376526403157645689ull);
    VL_SCOPED_RAND_RESET_W(258, vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result, __VscopeHash, 16727439528584542665ull);
    VL_SCOPED_RAND_RESET_W(258, vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_result_next, __VscopeHash, 11637178314316020452ull);
    VL_SCOPED_RAND_RESET_W(258, vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__mod_result, __VscopeHash, 11181012756435858281ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__loop_o_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14661867260398216208ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__loop_init = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16535022978357760723ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__round_counter = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 3299554333262580497ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__i_loop__DOT__o_cen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16605240358524635340ull);
    vlSelf->Testbench__DOT__i_rsa__DOT__i_RSAMont__DOT__i_montgomery__DOT__i_filter__DOT__o_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5976248455084753649ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14803524876191471008ull);
    vlSelf->__Vtrigprevexpr_hda97fe31__1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17230561467977970456ull);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
