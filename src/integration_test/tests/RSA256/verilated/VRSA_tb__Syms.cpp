// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VRSA_tb__pch.h"
#include "VRSA_tb.h"
#include "VRSA_tb___024root.h"
#include "VRSA_tb___024unit.h"

// FUNCTIONS
VRSA_tb__Syms::~VRSA_tb__Syms()
{
}

VRSA_tb__Syms::VRSA_tb__Syms(VerilatedContext* contextp, const char* namep, VRSA_tb* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(1384);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
