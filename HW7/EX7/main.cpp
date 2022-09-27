#include "FullAdder.h"

int sc_main(int argc, char* argv[]){
	sc_signal<bool> HA_A, HA_B, HA_Sum, HA_Carry, FA_A, FA_B, FA_Cin, FA_S, FA_Cout;
	sc_clock CLK("CLK", 10, 0.5);

	FullAdder FA1("FA1");
	FA1.A(FA_A);
	FA1.B(FA_B);
	FA1.Cin(FA_Cin);
	FA1.S(FA_S);
	FA1.Cout(FA_Cout);


	HalfAdder HA1("HA1");
	HA1.A(HA_A);
	HA1.B(HA_B);
	HA1.Sum(HA_Sum);
	HA1.Carry(HA_Carry);

	sc_trace_file *tf = sc_create_vcd_trace_file("RESULT");

	sc_trace(tf, HA_A, "Half-adder_A");
    sc_trace(tf, HA_B, "Half-adder_B");
	sc_trace(tf, HA_Sum, "Half-adder_Sum");
	sc_trace(tf, HA_Carry, "Half-adder_Carry");

	sc_trace(tf, FA_A, "Full-adder_A");
	sc_trace(tf, FA_B, "Full-adder_B");
	sc_trace(tf, FA_Cin, "Full-adder_Cin");
	sc_trace(tf, FA_S, "Full-adder_S");
	sc_trace(tf, FA_Cout, "Full-adder_Cout");


	sc_time t10(10, SC_NS);


	HA_A.write(0);
	HA_B.write(0);
	sc_start(t10);

	HA_A.write(0);
	HA_B.write(1);
	sc_start(t10);

	HA_A.write(1);
	HA_B.write(0);
	sc_start(t10);

	HA_A.write(1);
	HA_B.write(1);
	sc_start(t10);	



	FA_A.write(0);
	FA_B.write(0);
	FA_Cin.write(0);
	sc_start(t10);

	FA_A.write(0);
	FA_B.write(0);
	FA_Cin.write(1);
	sc_start(t10);

	FA_A.write(0);
	FA_B.write(1);
	FA_Cin.write(0);
	sc_start(t10);

	FA_A.write(0);
	FA_B.write(1);
	FA_Cin.write(1);
	sc_start(t10);

	FA_A.write(1);
	FA_B.write(0);
	FA_Cin.write(0);
	sc_start(t10);	

	FA_A.write(1);
	FA_B.write(0);
	FA_Cin.write(1);
	sc_start(t10);

	FA_A.write(1);
	FA_B.write(1);
	FA_Cin.write(0);
	sc_start(t10);

	FA_A.write(1);
	FA_B.write(1);
	FA_Cin.write(1);
	sc_start(t10);


	sc_time tfinal(10, SC_NS);
	sc_start(tfinal);

	sc_close_vcd_trace_file(tf);
}