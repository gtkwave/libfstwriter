// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "VSimple__Syms.h"


void VSimple___024root__trace_chg_0_sub_0(VSimple___024root* vlSelf, VerilatedFst::Buffer* bufp);

void VSimple___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimple___024root__trace_chg_0\n"); );
    // Body
    VSimple___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSimple___024root*>(voidSelf);
    VSimple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    VSimple___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VSimple___024root__trace_chg_0_sub_0(VSimple___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimple___024root__trace_chg_0_sub_0\n"); );
    VSimple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgCData(oldp+0,(vlSelfRef.Simple__DOT__counter_add),2);
        bufp->chgWData(oldp+1,(vlSelfRef.Simple__DOT__counter_shift),127);
    }
    bufp->chgBit(oldp+5,(vlSelfRef.clk));
    bufp->chgBit(oldp+6,(vlSelfRef.rst_n));
}

void VSimple___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimple___024root__trace_cleanup\n"); );
    // Body
    VSimple___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSimple___024root*>(voidSelf);
    VSimple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
