#include "FIR16.h"

void FIR16::runfilter(){

	//reset
	tmp = 0;
	bi = 0x00000F0F;
	for(int i = 0; i < 16; i++){
		delay[i] = 0; // i-th delay element
	}

	//computation
	while(1){
		wait();
		delay[0] = x;

		for(int i = 1; i < 16; i++){	 //all delay element has the same value
			delay[i] = delay[i-1];
		}

		tmp = x.read() * bi; // first line = x*b

		for(int j = 0; j < 16; j++){
			tmp = tmp + (delay[j].read() * bi);
		}

		y = tmp;
	}





}