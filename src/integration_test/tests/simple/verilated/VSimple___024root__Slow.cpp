// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSimple.h for the primary calling header

#include "VSimple__pch.h"

void VSimple___024root___ctor_var_reset(VSimple___024root* vlSelf);

VSimple___024root::VSimple___024root(VSimple__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VSimple___024root___ctor_var_reset(this);
}

void VSimple___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VSimple___024root::~VSimple___024root() {
}
