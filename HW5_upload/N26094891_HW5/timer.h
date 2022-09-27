#include "systemc.h"

SC_MODULE(timer){
	sc_in<bool> start;
	sc_out<bool> timeout;
	sc_in<bool> clock;
	sc_out<sc_uint<32> > count_out;


	int count;
	void runtimer();

	SC_CTOR(timer){
		SC_THREAD(runtimer)
		sensitive << clock.pos()
				  << start;
		count = 0;
	}
};