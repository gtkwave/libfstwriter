// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VRSA_tb.h for the primary calling header

#ifndef VERILATED_VRSA_TB___024UNIT_H_
#define VERILATED_VRSA_TB___024UNIT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class VRSA_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) VRSA_tb___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    VRSA_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    VRSA_tb___024unit(VRSA_tb__Syms* symsp, const char* v__name);
    ~VRSA_tb___024unit();
    VL_UNCOPYABLE(VRSA_tb___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
