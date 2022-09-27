#include "systemc.h"


SC_MODULE(HalfAdder){
	sc_in<bool> A;
	sc_in<bool> B;
	sc_out<bool> Sum;
	sc_out<bool> Carry;

	void runHalfAdder();

	SC_CTOR(HalfAdder){
		SC_METHOD(runHalfAdder);
		sensitive << A
				  << B;
	}
};