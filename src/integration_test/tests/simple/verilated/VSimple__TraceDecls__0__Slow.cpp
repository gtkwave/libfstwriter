// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing declarations
#include "verilated_fst_c.h"


void VSimple___024root__traceDeclTypesSub0(VerilatedFst* tracep) {
    {
        const char* __VenumItemNames[]
        = {"ZERO", "ONE", "TWO", "THREE"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11"};
        tracep->declDTypeEnum(1, "Simple.counter_add_e", 4, 2, __VenumItemNames, __VenumItemValues);
    }
}

void VSimple___024root__trace_decl_types(VerilatedFst* tracep) {
    VSimple___024root__traceDeclTypesSub0(tracep);
}
