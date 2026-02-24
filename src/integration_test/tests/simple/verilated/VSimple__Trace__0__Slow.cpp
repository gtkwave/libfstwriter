// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "VSimple__Syms.h"


VL_ATTR_COLD void VSimple___024root__trace_init_sub__TOP__0(VSimple___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimple___024root__trace_init_sub__TOP__0\n"); );
    VSimple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+6,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("Simple", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+6,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"counter_add_enum_version",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1,0,"counter_add",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declArray(c+2,0,"counter_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 126,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void VSimple___024root__trace_init_top(VSimple___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimple___024root__trace_init_top\n"); );
    VSimple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VSimple___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VSimple___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void VSimple___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void VSimple___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void VSimple___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void VSimple___024root__trace_register(VSimple___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimple___024root__trace_register\n"); );
    VSimple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VSimple___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&VSimple___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&VSimple___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&VSimple___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VSimple___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimple___024root__trace_const_0\n"); );
    // Body
    VSimple___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSimple___024root*>(voidSelf);
    VSimple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void VSimple___024root__trace_full_0_sub_0(VSimple___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void VSimple___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimple___024root__trace_full_0\n"); );
    // Body
    VSimple___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSimple___024root*>(voidSelf);
    VSimple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VSimple___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VSimple___024root__trace_full_0_sub_0(VSimple___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimple___024root__trace_full_0_sub_0\n"); );
    VSimple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullCData(oldp+1,(vlSelfRef.Simple__DOT__counter_add),2);
    bufp->fullWData(oldp+2,(vlSelfRef.Simple__DOT__counter_shift),127);
    bufp->fullBit(oldp+6,(vlSelfRef.clk));
    bufp->fullBit(oldp+7,(vlSelfRef.rst_n));
}
