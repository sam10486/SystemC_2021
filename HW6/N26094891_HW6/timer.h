#include "systemc.h"

SC_MODULE(timer){
	sc_in<bool> start;
	sc_out<bool> timeout;
	sc_in<bool> clock;
	sc_out<sc_uint<32> > count_out;


	int count;
	void runtimer();

	SC_CTOR(timer){
		SC_CTHREAD(runtimer, clock.pos());
		reset_signal_is(start, true);
		count = 0;
	}
};