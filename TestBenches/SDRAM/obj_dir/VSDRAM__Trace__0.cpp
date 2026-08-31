// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "VSDRAM__Syms.h"


void VSDRAM___024root__trace_chg_0_sub_0(VSDRAM___024root* vlSelf, VerilatedFst::Buffer* bufp);

void VSDRAM___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDRAM___024root__trace_chg_0\n"); );
    // Body
    VSDRAM___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSDRAM___024root*>(voidSelf);
    VSDRAM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    VSDRAM___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VSDRAM___024root__trace_chg_0_sub_0(VSDRAM___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDRAM___024root__trace_chg_0_sub_0\n"); );
    VSDRAM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgSData(oldp+0,((0x000007ffU & vlSelfRef.SDRAM__DOT__Address_buffer)),11);
        bufp->chgCData(oldp+1,((3U & (vlSelfRef.SDRAM__DOT__Address_buffer 
                                      >> 0x0000000bU))),2);
        bufp->chgSData(oldp+2,((0x000003ffU & (vlSelfRef.SDRAM__DOT__Address_buffer 
                                               >> 0x0000000dU))),10);
        bufp->chgBit(oldp+3,(vlSelfRef.SDRAM__DOT__startRefreshCount));
        bufp->chgBit(oldp+4,(vlSelfRef.SDRAM__DOT__refresh_needed));
        bufp->chgCData(oldp+5,(vlSelfRef.SDRAM__DOT__STATE),3);
        bufp->chgCData(oldp+6,(vlSelfRef.SDRAM__DOT__burst_counter),5);
        bufp->chgIData(oldp+7,(vlSelfRef.SDRAM__DOT__cycle_counter),32);
        bufp->chgIData(oldp+8,(vlSelfRef.SDRAM__DOT__refresh_counter),32);
        bufp->chgIData(oldp+9,(vlSelfRef.SDRAM__DOT__Address_buffer),23);
        bufp->chgIData(oldp+10,(vlSelfRef.SDRAM__DOT__Data_buffer),32);
    }
    bufp->chgBit(oldp+11,(vlSelfRef.reset));
    bufp->chgBit(oldp+12,(vlSelfRef.clk));
    bufp->chgBit(oldp+13,(vlSelfRef.clke));
    bufp->chgBit(oldp+14,(vlSelfRef.CS));
    bufp->chgBit(oldp+15,(vlSelfRef.CAS));
    bufp->chgBit(oldp+16,(vlSelfRef.RAS));
    bufp->chgBit(oldp+17,(vlSelfRef.WE));
    bufp->chgBit(oldp+18,(vlSelfRef.busy));
    bufp->chgCData(oldp+19,(vlSelfRef.DQM_out),4);
    bufp->chgBit(oldp+20,(vlSelfRef.write));
    bufp->chgBit(oldp+21,(vlSelfRef.read));
    bufp->chgIData(oldp+22,(vlSelfRef.Address_in),23);
    bufp->chgCData(oldp+23,(vlSelfRef.Bank_Bits_out),2);
    bufp->chgSData(oldp+24,(vlSelfRef.Address_out),11);
}

void VSDRAM___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDRAM___024root__trace_cleanup\n"); );
    // Body
    VSDRAM___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSDRAM___024root*>(voidSelf);
    VSDRAM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
