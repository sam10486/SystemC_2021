#include "HalfAdder.h"

SC_MODULE(FullAdder){
	sc_in<bool> A;
	sc_in<bool> B;
	sc_in<bool> Cin;

	sc_out<bool> S;
	sc_out<bool> Cout;

	sc_signal<bool> c1,c2,s1;
	HalfAdder *HalfAdder1, *HalfAdder2;

	void runOR();

	SC_CTOR(FullAdder){
		HalfAdder1 = new HalfAdder("HalfAdder1");
		(*HalfAdder1)(A,B,s1,c1);

		HalfAdder2 = new HalfAdder("HalfAdder2");
		(*HalfAdder2)(s1,Cin,S,c2);

		SC_METHOD(runOR);
			sensitive << c1
					  << c2;
		
	}
};