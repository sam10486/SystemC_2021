#include "FIR16.h"
#include "fstream"

int sc_main(int argc, char* argv[]){

	sc_signal<sc_uint<32> > x, y;
	sc_signal<bool> rst;
	sc_clock clock("CLOKL", 5, 0.5);
	int x_Data;
	ifstream inFile;


	//open file
	inFile.open("firData", ios::in);


	// fir filter
	FIR16 f1("FIR16");
	f1.clk(clock);
	f1.rst(rst);
	f1.x(x);
	f1.y(y);
	


	//wave trace
	sc_trace_file *tf = sc_create_vcd_trace_file("RESULT");
	sc_trace(tf, clock, "clk");
	sc_trace(tf, rst, "rst");
	sc_trace(tf, x, "x");
	sc_trace(tf, y, "y");

	sc_start(0, SC_NS);
	rst.write(0);
	sc_start(20, SC_NS);
	rst.write(1);

	while(!inFile.eof()){

		inFile >> x_Data;
		x.write(x_Data);
		sc_start(5, SC_NS);

	}

	sc_close_vcd_trace_file(tf);
	return 0;


}