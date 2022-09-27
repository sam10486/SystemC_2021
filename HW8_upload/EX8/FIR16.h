#include "systemc.h"



SC_MODULE(FIR16){

	sc_in<sc_uint<32> > x;
	sc_out<sc_uint<32> > y;
	sc_in<bool> clk, rst;

	sc_uint<32> tmp, bi;
	sc_signal<sc_uint<32> > delay[16];

	void runfilter();

	SC_CTOR(FIR16){
		SC_CTHREAD(runfilter, clk.pos());
		reset_signal_is(rst, false);

	}
};