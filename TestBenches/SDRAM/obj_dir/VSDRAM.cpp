// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VSDRAM__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

VSDRAM::VSDRAM(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VSDRAM__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , CS{vlSymsp->TOP.CS}
    , CAS{vlSymsp->TOP.CAS}
    , RAS{vlSymsp->TOP.RAS}
    , WE{vlSymsp->TOP.WE}
    , busy{vlSymsp->TOP.busy}
    , DQM_out{vlSymsp->TOP.DQM_out}
    , write{vlSymsp->TOP.write}
    , read{vlSymsp->TOP.read}
    , ReadReady{vlSymsp->TOP.ReadReady}
    , WriteReady{vlSymsp->TOP.WriteReady}
    , Bank_Bits_out{vlSymsp->TOP.Bank_Bits_out}
    , Address_out{vlSymsp->TOP.Address_out}
    , Address_in{vlSymsp->TOP.Address_in}
    , Data_in{vlSymsp->TOP.Data_in}
    , Data_bus{vlSymsp->TOP.Data_bus}
    , Read_data{vlSymsp->TOP.Read_data}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VSDRAM::VSDRAM(const char* _vcname__)
    : VSDRAM(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VSDRAM::~VSDRAM() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VSDRAM___024root___eval_debug_assertions(VSDRAM___024root* vlSelf);
#endif  // VL_DEBUG
void VSDRAM___024root___eval_static(VSDRAM___024root* vlSelf);
void VSDRAM___024root___eval_initial(VSDRAM___024root* vlSelf);
void VSDRAM___024root___eval_settle(VSDRAM___024root* vlSelf);
void VSDRAM___024root___eval(VSDRAM___024root* vlSelf);

void VSDRAM::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VSDRAM::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VSDRAM___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VSDRAM___024root___eval_static(&(vlSymsp->TOP));
        VSDRAM___024root___eval_initial(&(vlSymsp->TOP));
        VSDRAM___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VSDRAM___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VSDRAM::eventsPending() { return false; }

uint64_t VSDRAM::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VSDRAM::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VSDRAM___024root___eval_final(VSDRAM___024root* vlSelf);

VL_ATTR_COLD void VSDRAM::final() {
    contextp()->executingFinal(true);
    VSDRAM___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VSDRAM::hierName() const { return vlSymsp->name(); }
const char* VSDRAM::modelName() const { return "VSDRAM"; }
unsigned VSDRAM::threads() const { return 1; }
void VSDRAM::prepareClone() const { contextp()->prepareClone(); }
void VSDRAM::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VSDRAM::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false}};
};

//============================================================
// Trace configuration

void VSDRAM___024root__trace_decl_types(VerilatedFst* tracep);

void VSDRAM___024root__trace_init_top(VSDRAM___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    VSDRAM___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSDRAM___024root*>(voidSelf);
    VSDRAM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    VSDRAM___024root__trace_decl_types(tracep);
    VSDRAM___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VSDRAM___024root__trace_register(VSDRAM___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void VSDRAM::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VSDRAM::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP), name(), false, 47);
    VSDRAM___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
