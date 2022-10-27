# include "Vsinegen.h"
# include "verilated.h"
# include "verilated_vcd_c.h"
# include "vbuddy.cpp"

int main(int argc, char **argv, char **env){
    int i;
    int clk;
    Verilated::commandArgs(argc, argv);

    // init top verilog instance
    Vsinegen* top = new Vsinegen;

    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open("sinegen.vcd");

    // initialize simulation inputs
    top->clk = 1;
    top->rst = 0;
    top->en = 1;
    top->incr = 1;

    // init vbuddy
    if (vbdOpen()!=1)   return(-1);
    vbdHeader("Lab 2: SigGen");

    // run simulation for many clock cycles
    for (i=0; i<1000000; i++){
        // dump variables into VCD file and toggle clock
        for (clk=0; clk<2; clk++){
            tfp->dump(2*i+clk);
            top->clk = !top->clk; // toggle clock up and down
            top->eval();
        }

        vbdPlot(int(top->dout), 0, 255); // vbdPlot(y, min, max)

        // either simulation finished, or 'q' is pressed
        if ((Verilated::gotFinish()) || (vbdGetkey()=='q')){
            exit(0); // ... exit if finish OR 'q' pressed
        }
    }
    tfp->close();
    exit(0);
}