// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VSDRAM.h for the primary calling header

#ifndef VERILATED_VSDRAM___024ROOT_H_
#define VERILATED_VSDRAM___024ROOT_H_  // guard

#include "verilated.h"


class VSDRAM__Syms;

class alignas(VL_CACHE_LINE_BYTES) VSDRAM___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(clke,0,0);
    VL_OUT8(CS,0,0);
    VL_OUT8(CAS,0,0);
    VL_OUT8(RAS,0,0);
    VL_OUT8(WE,0,0);
    VL_OUT8(busy,0,0);
    VL_OUT8(DQM_out,3,0);
    VL_IN8(write,0,0);
    VL_IN8(read,0,0);
    VL_OUT8(Bank_Bits_out,1,0);
    CData/*0:0*/ SDRAM__DOT__startRefreshCount;
    CData/*0:0*/ SDRAM__DOT__refresh_needed;
    CData/*2:0*/ SDRAM__DOT__STATE;
    CData/*4:0*/ SDRAM__DOT__burst_counter;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    VL_OUT16(Address_out,10,0);
    VL_IN(Address_in,22,0);
    VL_INOUT(Data_bus,31,0);
    IData/*31:0*/ SDRAM__DOT__cycle_counter;
    IData/*31:0*/ SDRAM__DOT__refresh_counter;
    IData/*22:0*/ SDRAM__DOT__Address_buffer;
    IData/*31:0*/ SDRAM__DOT__Data_buffer;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    VSDRAM__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    VSDRAM___024root(VSDRAM__Syms* symsp, const char* namep);
    ~VSDRAM___024root();
    VL_UNCOPYABLE(VSDRAM___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
