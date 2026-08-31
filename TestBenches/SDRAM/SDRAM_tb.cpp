#include "VSDRAM.h"
#include "verilated.h"
#include "verilated_fst_c.h"
#include <iostream>
#include <stdint.h>


#define NS 1
#define CLK_PERIOD 10
#define CLK_HALF_PERIOD CLK_PERIOD/2

uint32_t FREQ  = 27000000;     // Default freq of tang nano20k
uint32_t T_MRD = 2;      // Mode register set latency   
uint32_t T_RCD = 2;         // RAS to CAS Latency
uint32_t T_RP  = 4;         // RAS Prechrage latency
uint32_t T_CAS = 2;        // Delay until Data appears on output
uint32_t T_WR  = 1;         // Delay until row can be closed follwoing a write
uint32_t T_RC  = 2;         // Delay until RAS can be executed again
uint32_t T_BL  = 8;         // Delay burst length
uint32_t T_CL  = 1;         // delay until data is available


void StartupInput(VerilatedContext* context , VSDRAM* dut , VerilatedFstC* trace);
void ReadInput( VerilatedContext* context , VSDRAM* dut , VerilatedFstC* trace );
void WriteInput( VerilatedContext* context , VSDRAM* dut , VerilatedFstC* trace);

int main( int argc , char** argv )
{
    VerilatedContext* context = new VerilatedContext;
    context->commandArgs(argc , argv);
    
    context->traceEverOn(true);

    VSDRAM* dut = new VSDRAM{context};

    VerilatedFstC* trace = new VerilatedFstC;
    dut->trace(trace , 99);

    trace->open("Waveforms/FSM_verification.fst");
    StartupInput( context , dut , trace );
    trace->close();

    trace->open("Waveforms/Read.fst");
    ReadInput( context , dut , trace);
    trace->close();


    trace->open("Waveforms/Write.fst");
    WriteInput( context , dut , trace);
    trace->close();

    return 0;

    trace->open("Waveforms/Refresh.fst");
    StartupInput( context , dut , trace);
    trace->close();

}

void StartupInput(VerilatedContext* context , VSDRAM* dut , VerilatedFstC* trace)
{
    dut->clk = 0;
    dut->reset = 0;
    dut->clke = 0;

    dut->read = 0;
    dut->write = 0;
    dut->Address_in = 0;
    dut->Data_bus = 0;

    dut->eval();
    trace->dump(context->time());
    context->timeInc(CLK_HALF_PERIOD);

    // begin the setup

    dut->reset = 1;
    dut->clk = 1;
    dut->clke = 1;
    dut->eval();
    trace->dump(context->time());
    context->timeInc(CLK_HALF_PERIOD);
    
    dut->reset = 0;
    dut->clk = 0;
    dut->eval();
    trace->dump(context->time());
    context->timeInc(CLK_HALF_PERIOD);

    for( int i = 0; i < 5410 ; i++ )
    {
        dut->clk = 1;
        dut->eval();
        trace->dump(context->time());
        context->timeInc(CLK_HALF_PERIOD);

        dut->clk = 0;
        dut->eval();
        trace->dump(context->time());
        context->timeInc(CLK_HALF_PERIOD);
    }

    for( int i = 0; i < T_RP + T_RC + T_RC + T_MRD ; i++ )
    {
        dut->clk = 1;
        dut->eval();
        trace->dump(context->time());
        context->timeInc(CLK_HALF_PERIOD);

        dut->clk = 0;
        dut->eval();
        trace->dump(context->time());
        context->timeInc(CLK_HALF_PERIOD);
 
    }

    trace->dump(context->time());

} 

void ReadInput( VerilatedContext* context , VSDRAM* dut , VerilatedFstC* trace )
{
    dut->read = 1;
    dut->Address_in = 0x3BEEF;

    for( int i = 0; i < 1 + T_RCD + T_CAS + T_BL + T_RP ; i++)
    {
        dut->clk = 1;
        dut->eval();
        trace->dump(context->time());
        context->timeInc(CLK_HALF_PERIOD);

        dut->clk = 0;
        dut->eval();
        trace->dump(context->time());
        context->timeInc(CLK_HALF_PERIOD);
    }

    context->timeInc(CLK_PERIOD);
    dut->eval();
    trace->dump(context->time());
}

void WriteInput( VerilatedContext* context , VSDRAM* dut , VerilatedFstC* trace)
{
    dut->read = 0;
    dut->write = 1;
    dut->Address_in = 0x3BEEF;

    for( int i = 0; i < 1 +  T_RCD + T_WR + T_BL + T_RP ; i++)
    {
        dut->clk = 1;
        dut->eval();
        trace->dump(context->time());
        context->timeInc(CLK_HALF_PERIOD);

        dut->clk = 0;
        dut->eval();
        trace->dump(context->time());
        context->timeInc(CLK_HALF_PERIOD);
    }

    context->timeInc(CLK_PERIOD);
    dut->eval();
    trace->dump(context->time());
    context->timeInc(CLK_PERIOD);
}
void RefreshInput();