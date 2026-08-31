// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSDRAM.h for the primary calling header

#include "VSDRAM__pch.h"

bool VSDRAM___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDRAM___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void VSDRAM___024root___nba_sequent__TOP__0(VSDRAM___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDRAM___024root___nba_sequent__TOP__0\n"); );
    VSDRAM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vdly__SDRAM__DOT__cycle_counter;
    __Vdly__SDRAM__DOT__cycle_counter = 0;
    IData/*31:0*/ __Vdly__SDRAM__DOT__refresh_counter;
    __Vdly__SDRAM__DOT__refresh_counter = 0;
    CData/*2:0*/ __Vdly__SDRAM__DOT__STATE;
    __Vdly__SDRAM__DOT__STATE = 0;
    CData/*0:0*/ __Vdly__SDRAM__DOT__refresh_needed;
    __Vdly__SDRAM__DOT__refresh_needed = 0;
    IData/*22:0*/ __Vdly__SDRAM__DOT__Address_buffer;
    __Vdly__SDRAM__DOT__Address_buffer = 0;
    // Body
    __Vdly__SDRAM__DOT__STATE = vlSelfRef.SDRAM__DOT__STATE;
    __Vdly__SDRAM__DOT__refresh_needed = vlSelfRef.SDRAM__DOT__refresh_needed;
    __Vdly__SDRAM__DOT__Address_buffer = vlSelfRef.SDRAM__DOT__Address_buffer;
    __Vdly__SDRAM__DOT__cycle_counter = vlSelfRef.SDRAM__DOT__cycle_counter;
    __Vdly__SDRAM__DOT__refresh_counter = vlSelfRef.SDRAM__DOT__refresh_counter;
    __Vdly__SDRAM__DOT__cycle_counter = ((IData)(1U) 
                                         + vlSelfRef.SDRAM__DOT__cycle_counter);
    if (vlSelfRef.SDRAM__DOT__startRefreshCount) {
        __Vdly__SDRAM__DOT__refresh_counter = ((IData)(1U) 
                                               + vlSelfRef.SDRAM__DOT__refresh_counter);
    }
    vlSelfRef.DQM_out = 0U;
    if (vlSelfRef.reset) {
        __Vdly__SDRAM__DOT__cycle_counter = 0U;
        vlSelfRef.SDRAM__DOT__startRefreshCount = 0U;
        __Vdly__SDRAM__DOT__STATE = 7U;
    }
    if (((((((((0x0000000700000000ULL == (0x0000000700000000ULL 
                                          & (((QData)((IData)(vlSelfRef.SDRAM__DOT__STATE)) 
                                              << 0x00000020U) 
                                             | (QData)((IData)(vlSelfRef.SDRAM__DOT__cycle_counter))))) 
               | (0x0000000600000000ULL == (((QData)((IData)(vlSelfRef.SDRAM__DOT__STATE)) 
                                             << 0x00000020U) 
                                            | (QData)((IData)(vlSelfRef.SDRAM__DOT__cycle_counter))))) 
              | ((0x0000000600000004ULL == (((QData)((IData)(vlSelfRef.SDRAM__DOT__STATE)) 
                                             << 0x00000020U) 
                                            | (QData)((IData)(vlSelfRef.SDRAM__DOT__cycle_counter)))) 
                 || (0x0000000600000006ULL == (((QData)((IData)(vlSelfRef.SDRAM__DOT__STATE)) 
                                                << 0x00000020U) 
                                               | (QData)((IData)(vlSelfRef.SDRAM__DOT__cycle_counter)))))) 
             | (0x0000000600000008ULL == (((QData)((IData)(vlSelfRef.SDRAM__DOT__STATE)) 
                                           << 0x00000020U) 
                                          | (QData)((IData)(vlSelfRef.SDRAM__DOT__cycle_counter))))) 
            | (0x000000060000000aULL == (((QData)((IData)(vlSelfRef.SDRAM__DOT__STATE)) 
                                          << 0x00000020U) 
                                         | (QData)((IData)(vlSelfRef.SDRAM__DOT__cycle_counter))))) 
           | (0ULL == (0x0000000700000000ULL & (((QData)((IData)(vlSelfRef.SDRAM__DOT__STATE)) 
                                                 << 0x00000020U) 
                                                | (QData)((IData)(vlSelfRef.SDRAM__DOT__cycle_counter)))))) 
          | (0x0000000500000002ULL == (((QData)((IData)(vlSelfRef.SDRAM__DOT__STATE)) 
                                        << 0x00000020U) 
                                       | (QData)((IData)(vlSelfRef.SDRAM__DOT__cycle_counter))))) 
         | (0x0000000500000010ULL == (((QData)((IData)(vlSelfRef.SDRAM__DOT__STATE)) 
                                       << 0x00000020U) 
                                      | (QData)((IData)(vlSelfRef.SDRAM__DOT__cycle_counter)))))) {
        if ((0x0000000700000000ULL == (0x0000000700000000ULL 
                                       & (((QData)((IData)(vlSelfRef.SDRAM__DOT__STATE)) 
                                           << 0x00000020U) 
                                          | (QData)((IData)(vlSelfRef.SDRAM__DOT__cycle_counter)))))) {
            if ((0x00001518U <= vlSelfRef.SDRAM__DOT__cycle_counter)) {
                __Vdly__SDRAM__DOT__STATE = 6U;
                __Vdly__SDRAM__DOT__refresh_counter = 0U;
                __Vdly__SDRAM__DOT__refresh_needed = 0U;
                __Vdly__SDRAM__DOT__cycle_counter = 0U;
            }
        } else if ((0x0000000600000000ULL == (((QData)((IData)(vlSelfRef.SDRAM__DOT__STATE)) 
                                               << 0x00000020U) 
                                              | (QData)((IData)(vlSelfRef.SDRAM__DOT__cycle_counter))))) {
            vlSelfRef.Address_out = (0x00000400U | (IData)(vlSelfRef.Address_out));
            vlSelfRef.RAS = 0U;
            vlSelfRef.CAS = 1U;
            vlSelfRef.WE = 0U;
        } else if (((0x0000000600000004ULL == (((QData)((IData)(vlSelfRef.SDRAM__DOT__STATE)) 
                                                << 0x00000020U) 
                                               | (QData)((IData)(vlSelfRef.SDRAM__DOT__cycle_counter)))) 
                    || (0x0000000600000006ULL == (((QData)((IData)(vlSelfRef.SDRAM__DOT__STATE)) 
                                                   << 0x00000020U) 
                                                  | (QData)((IData)(vlSelfRef.SDRAM__DOT__cycle_counter)))))) {
            vlSelfRef.RAS = 0U;
            vlSelfRef.CAS = 0U;
            vlSelfRef.WE = 1U;
        } else if ((0x0000000600000008ULL == (((QData)((IData)(vlSelfRef.SDRAM__DOT__STATE)) 
                                               << 0x00000020U) 
                                              | (QData)((IData)(vlSelfRef.SDRAM__DOT__cycle_counter))))) {
            vlSelfRef.RAS = 0U;
            vlSelfRef.CAS = 0U;
            vlSelfRef.WE = 0U;
            vlSelfRef.Address_out = 0x0023U;
        } else if ((0x000000060000000aULL == (((QData)((IData)(vlSelfRef.SDRAM__DOT__STATE)) 
                                               << 0x00000020U) 
                                              | (QData)((IData)(vlSelfRef.SDRAM__DOT__cycle_counter))))) {
            __Vdly__SDRAM__DOT__STATE = 0U;
            vlSelfRef.busy = 0U;
            vlSelfRef.SDRAM__DOT__startRefreshCount = 1U;
            __Vdly__SDRAM__DOT__cycle_counter = 0U;
        } else if ((0ULL == (0x0000000700000000ULL 
                             & (((QData)((IData)(vlSelfRef.SDRAM__DOT__STATE)) 
                                 << 0x00000020U) | (QData)((IData)(vlSelfRef.SDRAM__DOT__cycle_counter)))))) {
            if (vlSelfRef.SDRAM__DOT__refresh_needed) {
                __Vdly__SDRAM__DOT__STATE = 1U;
                vlSelfRef.RAS = 0U;
                vlSelfRef.CAS = 0U;
                vlSelfRef.WE = 1U;
                __Vdly__SDRAM__DOT__cycle_counter = 1U;
                vlSelfRef.busy = 1U;
            } else if (((IData)(vlSelfRef.read) | (IData)(vlSelfRef.write))) {
                vlSelfRef.RAS = 0U;
                vlSelfRef.CAS = 1U;
                vlSelfRef.WE = 1U;
                vlSelfRef.Bank_Bits_out = (3U & (vlSelfRef.SDRAM__DOT__Address_buffer 
                                                 >> 0x0000000bU));
                __Vdly__SDRAM__DOT__STATE = ((IData)(vlSelfRef.read)
                                              ? 5U : 4U);
                if (vlSelfRef.write) {
                    vlSelfRef.SDRAM__DOT__Data_buffer = 0U;
                }
                __Vdly__SDRAM__DOT__cycle_counter = 1U;
                vlSelfRef.busy = 1U;
                vlSelfRef.SDRAM__DOT__burst_counter = 0U;
                vlSelfRef.Address_out = (0x000007ffU 
                                         & vlSelfRef.SDRAM__DOT__Address_buffer);
                __Vdly__SDRAM__DOT__Address_buffer 
                    = vlSelfRef.Address_in;
            }
        } else if ((0x0000000500000002ULL == (((QData)((IData)(vlSelfRef.SDRAM__DOT__STATE)) 
                                               << 0x00000020U) 
                                              | (QData)((IData)(vlSelfRef.SDRAM__DOT__cycle_counter))))) {
            vlSelfRef.RAS = 1U;
            vlSelfRef.CAS = 0U;
            vlSelfRef.WE = 1U;
            vlSelfRef.Address_out = (0x00000400U | 
                                     (0x000003ffU & 
                                      (vlSelfRef.SDRAM__DOT__Address_buffer 
                                       >> 0x0000000dU)));
        } else {
            __Vdly__SDRAM__DOT__STATE = 0U;
            __Vdly__SDRAM__DOT__cycle_counter = 0U;
            vlSelfRef.busy = 0U;
        }
    } else if ((0x0000000400000002ULL == (((QData)((IData)(vlSelfRef.SDRAM__DOT__STATE)) 
                                           << 0x00000020U) 
                                          | (QData)((IData)(vlSelfRef.SDRAM__DOT__cycle_counter))))) {
        vlSelfRef.RAS = 1U;
        vlSelfRef.CAS = 0U;
        vlSelfRef.WE = 0U;
        vlSelfRef.Address_out = (0x00000400U | (0x000003ffU 
                                                & (vlSelfRef.SDRAM__DOT__Address_buffer 
                                                   >> 0x0000000dU)));
    } else if ((0x000000040000000fULL == (((QData)((IData)(vlSelfRef.SDRAM__DOT__STATE)) 
                                           << 0x00000020U) 
                                          | (QData)((IData)(vlSelfRef.SDRAM__DOT__cycle_counter))))) {
        __Vdly__SDRAM__DOT__STATE = 0U;
        __Vdly__SDRAM__DOT__cycle_counter = 0U;
        vlSelfRef.busy = 0U;
    } else if ((0x0000000100000002ULL == (((QData)((IData)(vlSelfRef.SDRAM__DOT__STATE)) 
                                           << 0x00000020U) 
                                          | (QData)((IData)(vlSelfRef.SDRAM__DOT__cycle_counter))))) {
        __Vdly__SDRAM__DOT__refresh_counter = (vlSelfRef.SDRAM__DOT__refresh_counter 
                                               - (IData)(0x00000195U));
        __Vdly__SDRAM__DOT__STATE = 0U;
        vlSelfRef.busy = 0U;
        __Vdly__SDRAM__DOT__refresh_needed = 0U;
    }
    __Vdly__SDRAM__DOT__refresh_needed = (0x00000195U 
                                          <= vlSelfRef.SDRAM__DOT__refresh_counter);
    vlSelfRef.SDRAM__DOT__STATE = __Vdly__SDRAM__DOT__STATE;
    vlSelfRef.SDRAM__DOT__refresh_needed = __Vdly__SDRAM__DOT__refresh_needed;
    vlSelfRef.SDRAM__DOT__Address_buffer = __Vdly__SDRAM__DOT__Address_buffer;
    vlSelfRef.SDRAM__DOT__cycle_counter = __Vdly__SDRAM__DOT__cycle_counter;
    vlSelfRef.SDRAM__DOT__refresh_counter = __Vdly__SDRAM__DOT__refresh_counter;
}

void VSDRAM___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDRAM___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VSDRAM___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool VSDRAM___024root___eval_phase__act(VSDRAM___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDRAM___024root___eval_phase__act\n"); );
    VSDRAM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((IData)(vlSelfRef.clk) 
                                                         & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VSDRAM___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    VSDRAM___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void VSDRAM___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDRAM___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool VSDRAM___024root___eval_phase__nba(VSDRAM___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDRAM___024root___eval_phase__nba\n"); );
    VSDRAM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = VSDRAM___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                VSDRAM___024root___nba_sequent__TOP__0(vlSelf);
                vlSelfRef.__Vm_traceActivity[1U] = 1U;
            }
        }
        VSDRAM___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void VSDRAM___024root___eval(VSDRAM___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDRAM___024root___eval\n"); );
    VSDRAM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VSDRAM___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/mnt/c/Repositories/Sipeed-TangNano-20k-SDRAM/fpga_project/src/SDRAM.v", 14, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VSDRAM___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/mnt/c/Repositories/Sipeed-TangNano-20k-SDRAM/fpga_project/src/SDRAM.v", 14, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = VSDRAM___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = VSDRAM___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void VSDRAM___024root___eval_debug_assertions(VSDRAM___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDRAM___024root___eval_debug_assertions\n"); );
    VSDRAM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");
    }
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.clke & 0xfeU)))) {
        Verilated::overWidthError("clke");
    }
    if (VL_UNLIKELY(((vlSelfRef.write & 0xfeU)))) {
        Verilated::overWidthError("write");
    }
    if (VL_UNLIKELY(((vlSelfRef.read & 0xfeU)))) {
        Verilated::overWidthError("read");
    }
    if (VL_UNLIKELY(((vlSelfRef.Address_in & 0xff800000U)))) {
        Verilated::overWidthError("Address_in");
    }
}
#endif  // VL_DEBUG
