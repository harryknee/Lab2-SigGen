// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vrom.h"
#include "Vrom__Syms.h"

//============================================================
// Constructors

Vrom::Vrom(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vrom__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , addr{vlSymsp->TOP.addr}
    , dout{vlSymsp->TOP.dout}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vrom::Vrom(const char* _vcname__)
    : Vrom(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vrom::~Vrom() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vrom___024root___eval_initial(Vrom___024root* vlSelf);
void Vrom___024root___eval_settle(Vrom___024root* vlSelf);
void Vrom___024root___eval(Vrom___024root* vlSelf);
#ifdef VL_DEBUG
void Vrom___024root___eval_debug_assertions(Vrom___024root* vlSelf);
#endif  // VL_DEBUG
void Vrom___024root___final(Vrom___024root* vlSelf);

static void _eval_initial_loop(Vrom__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vrom___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vrom___024root___eval_settle(&(vlSymsp->TOP));
        Vrom___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vrom::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vrom::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vrom___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vrom___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vrom::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vrom::final() {
    Vrom___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vrom::hierName() const { return vlSymsp->name(); }
const char* Vrom::modelName() const { return "Vrom"; }
unsigned Vrom::threads() const { return 1; }
