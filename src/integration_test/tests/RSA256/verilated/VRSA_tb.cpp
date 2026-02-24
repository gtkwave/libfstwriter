// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VRSA_tb__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

VRSA_tb::VRSA_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VRSA_tb__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VRSA_tb::VRSA_tb(const char* _vcname__)
    : VRSA_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VRSA_tb::~VRSA_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VRSA_tb___024root___eval_debug_assertions(VRSA_tb___024root* vlSelf);
#endif  // VL_DEBUG
void VRSA_tb___024root___eval_static(VRSA_tb___024root* vlSelf);
void VRSA_tb___024root___eval_initial(VRSA_tb___024root* vlSelf);
void VRSA_tb___024root___eval_settle(VRSA_tb___024root* vlSelf);
void VRSA_tb___024root___eval(VRSA_tb___024root* vlSelf);

void VRSA_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VRSA_tb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VRSA_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VRSA_tb___024root___eval_static(&(vlSymsp->TOP));
        VRSA_tb___024root___eval_initial(&(vlSymsp->TOP));
        VRSA_tb___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VRSA_tb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VRSA_tb::eventsPending() { return false; }

uint64_t VRSA_tb::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VRSA_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VRSA_tb___024root___eval_final(VRSA_tb___024root* vlSelf);

VL_ATTR_COLD void VRSA_tb::final() {
    VRSA_tb___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VRSA_tb::hierName() const { return vlSymsp->name(); }
const char* VRSA_tb::modelName() const { return "VRSA_tb"; }
unsigned VRSA_tb::threads() const { return 1; }
void VRSA_tb::prepareClone() const { contextp()->prepareClone(); }
void VRSA_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VRSA_tb::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VRSA_tb___024root__trace_decl_types(VerilatedFst* tracep);

void VRSA_tb___024root__trace_init_top(VRSA_tb___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    VRSA_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VRSA_tb___024root*>(voidSelf);
    VRSA_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VRSA_tb___024root__trace_decl_types(tracep);
    VRSA_tb___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VRSA_tb___024root__trace_register(VRSA_tb___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void VRSA_tb::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VRSA_tb::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VRSA_tb___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
