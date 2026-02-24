// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VSimple__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

VSimple::VSimple(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VSimple__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VSimple::VSimple(const char* _vcname__)
    : VSimple(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VSimple::~VSimple() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VSimple___024root___eval_debug_assertions(VSimple___024root* vlSelf);
#endif  // VL_DEBUG
void VSimple___024root___eval_static(VSimple___024root* vlSelf);
void VSimple___024root___eval_initial(VSimple___024root* vlSelf);
void VSimple___024root___eval_settle(VSimple___024root* vlSelf);
void VSimple___024root___eval(VSimple___024root* vlSelf);

void VSimple::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VSimple::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VSimple___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VSimple___024root___eval_static(&(vlSymsp->TOP));
        VSimple___024root___eval_initial(&(vlSymsp->TOP));
        VSimple___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VSimple___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VSimple::eventsPending() { return false; }

uint64_t VSimple::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VSimple::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VSimple___024root___eval_final(VSimple___024root* vlSelf);

VL_ATTR_COLD void VSimple::final() {
    VSimple___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VSimple::hierName() const { return vlSymsp->name(); }
const char* VSimple::modelName() const { return "VSimple"; }
unsigned VSimple::threads() const { return 1; }
void VSimple::prepareClone() const { contextp()->prepareClone(); }
void VSimple::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VSimple::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VSimple___024root__trace_decl_types(VerilatedFst* tracep);

void VSimple___024root__trace_init_top(VSimple___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    VSimple___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSimple___024root*>(voidSelf);
    VSimple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VSimple___024root__trace_decl_types(tracep);
    VSimple___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VSimple___024root__trace_register(VSimple___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void VSimple::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VSimple::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VSimple___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
