// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSDRAM.h for the primary calling header

#include "VSDRAM__pch.h"

VL_ATTR_COLD void VSDRAM___024root___eval_static(VSDRAM___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDRAM___024root___eval_static\n"); );
    VSDRAM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void VSDRAM___024root___eval_initial(VSDRAM___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDRAM___024root___eval_initial\n"); );
    VSDRAM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_initial__TOP
        vlSelfRef.Data_bus = 0U;
        vlSelfRef.CS = 0U;
    }
}

VL_ATTR_COLD void VSDRAM___024root___eval_final(VSDRAM___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDRAM___024root___eval_final\n"); );
    VSDRAM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VSDRAM___024root___eval_settle(VSDRAM___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDRAM___024root___eval_settle\n"); );
    VSDRAM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool VSDRAM___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VSDRAM___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDRAM___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(VSDRAM___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VSDRAM___024root___ctor_var_reset(VSDRAM___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDRAM___024root___ctor_var_reset\n"); );
    VSDRAM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->clke = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1453809407809404384ull);
    vlSelf->CS = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14785431503188483138ull);
    vlSelf->CAS = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 265847901687743287ull);
    vlSelf->RAS = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17696472645597807471ull);
    vlSelf->WE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4668325564236645225ull);
    vlSelf->busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6386567572483775230ull);
    vlSelf->DQM_out = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9677929853207410092ull);
    vlSelf->write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6996823270756637333ull);
    vlSelf->read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13916498648420597437ull);
    vlSelf->Address_in = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 9245149198625336765ull);
    vlSelf->Data_bus = 0U;
    ;
    vlSelf->Bank_Bits_out = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9871599908034693044ull);
    vlSelf->Address_out = VL_SCOPED_RAND_RESET_I(11, __VscopeHash, 6896564754821198462ull);
    vlSelf->SDRAM__DOT__startRefreshCount = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9473659338985177980ull);
    vlSelf->SDRAM__DOT__refresh_needed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16180371318887901747ull);
    vlSelf->SDRAM__DOT__STATE = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16579946647372524431ull);
    vlSelf->SDRAM__DOT__burst_counter = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2183520257247295148ull);
    vlSelf->SDRAM__DOT__cycle_counter = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17127305226738451548ull);
    vlSelf->SDRAM__DOT__refresh_counter = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10920925430909216753ull);
    vlSelf->SDRAM__DOT__Address_buffer = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 10670635933032542943ull);
    vlSelf->SDRAM__DOT__Data_buffer = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1611064639072982200ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
