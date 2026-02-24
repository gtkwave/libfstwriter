// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSimple.h for the primary calling header

#include "VSimple__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VSimple___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void VSimple___024root___eval_triggers__act(VSimple___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimple___024root___eval_triggers__act\n"); );
    VSimple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((~ (IData)(vlSelfRef.rst_n)) 
                                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0)) 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.clk) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VSimple___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool VSimple___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimple___024root___trigger_anySet__act\n"); );
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

void VSimple___024root___nba_sequent__TOP__0(VSimple___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimple___024root___nba_sequent__TOP__0\n"); );
    VSimple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    if (vlSelfRef.rst_n) {
        vlSelfRef.Simple__DOT__counter_add = (3U & 
                                              ((IData)(1U) 
                                               + (IData)(vlSelfRef.Simple__DOT__counter_add)));
        __Vtemp_1[1U] = ((vlSelfRef.Simple__DOT__counter_shift[0U] 
                          >> 0x0000001eU) | (vlSelfRef.Simple__DOT__counter_shift[1U] 
                                             << 2U));
        __Vtemp_1[2U] = ((vlSelfRef.Simple__DOT__counter_shift[1U] 
                          >> 0x0000001eU) | (vlSelfRef.Simple__DOT__counter_shift[2U] 
                                             << 2U));
        __Vtemp_1[3U] = ((vlSelfRef.Simple__DOT__counter_shift[2U] 
                          >> 0x0000001eU) | (0x7ffffffcU 
                                             & (vlSelfRef.Simple__DOT__counter_shift[3U] 
                                                << 2U)));
        vlSelfRef.Simple__DOT__counter_shift[0U] = 
            (3U | (vlSelfRef.Simple__DOT__counter_shift[0U] 
                   << 2U));
    } else {
        vlSelfRef.Simple__DOT__counter_add = 0U;
        __Vtemp_1[1U] = 0U;
        __Vtemp_1[2U] = 0U;
        __Vtemp_1[3U] = 0U;
        vlSelfRef.Simple__DOT__counter_shift[0U] = 0U;
    }
    vlSelfRef.Simple__DOT__counter_shift[1U] = __Vtemp_1[1U];
    vlSelfRef.Simple__DOT__counter_shift[2U] = __Vtemp_1[2U];
    vlSelfRef.Simple__DOT__counter_shift[3U] = __Vtemp_1[3U];
}

void VSimple___024root___eval_nba(VSimple___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimple___024root___eval_nba\n"); );
    VSimple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        VSimple___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

void VSimple___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimple___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool VSimple___024root___eval_phase__act(VSimple___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimple___024root___eval_phase__act\n"); );
    VSimple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VSimple___024root___eval_triggers__act(vlSelf);
    VSimple___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void VSimple___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimple___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool VSimple___024root___eval_phase__nba(VSimple___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimple___024root___eval_phase__nba\n"); );
    VSimple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = VSimple___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        VSimple___024root___eval_nba(vlSelf);
        VSimple___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void VSimple___024root___eval(VSimple___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimple___024root___eval\n"); );
    VSimple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VSimple___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/home/johnjohnlin/workspace/verilator_snapshot/src/benchmark/list/simple/Simple.sv", 2, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VSimple___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/home/johnjohnlin/workspace/verilator_snapshot/src/benchmark/list/simple/Simple.sv", 2, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (VSimple___024root___eval_phase__act(vlSelf));
    } while (VSimple___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void VSimple___024root___eval_debug_assertions(VSimple___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimple___024root___eval_debug_assertions\n"); );
    VSimple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");
    }
}
#endif  // VL_DEBUG
