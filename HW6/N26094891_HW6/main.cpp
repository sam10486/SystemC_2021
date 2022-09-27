#include "timer.h"

int sc_main(int argc, char* argv[]){

	sc_signal<bool> TIMEOUT, START;
	sc_signal<sc_uint<32> > COUNT_OUT;
	sc_clock CLK("CLK", 10, 0.5);


	timer t1("timer"); //timer instantiation
	t1.clock(CLK);
	t1.start(START);
	t1.timeout(TIMEOUT);
	t1.count_out(COUNT_OUT);


	//tracing
	//trace file creation, with vcd type output
	sc_trace_file *tf = sc_create_vcd_trace_file("RESULT");
	//External signals

	sc_trace(tf, CLK, "clock");
	sc_trace(tf, COUNT_OUT, "count");
	sc_trace(tf, START, "start");
	sc_trace(tf, TIMEOUT, "timeout");


	//reset the timer for 3 cycles before it is released for counting
	START.write(0);
	sc_start(30, SC_NS);

	START.write(1);
	sc_start(10, SC_NS);
	START.write(0);
	

	//during counting reset the timer before count reaches 0
	sc_start(40, SC_NS);
	START.write(1);
	sc_start(10, SC_NS);
	START.write(0);

	//during counting reset the timer after count reaches 0
	sc_start(60, SC_NS);
	START.write(1);
	sc_start(10, SC_NS);
	START.write(0);

	sc_start(140, SC_NS);
	sc_close_vcd_trace_file(tf);

	return(0);

}