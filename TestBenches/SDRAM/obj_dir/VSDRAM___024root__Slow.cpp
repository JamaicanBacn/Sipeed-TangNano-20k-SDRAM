// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSDRAM.h for the primary calling header

#include "VSDRAM__pch.h"

void VSDRAM___024root___ctor_var_reset(VSDRAM___024root* vlSelf);

VSDRAM___024root::VSDRAM___024root(VSDRAM__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    VSDRAM___024root___ctor_var_reset(this);
}

void VSDRAM___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VSDRAM___024root::~VSDRAM___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
