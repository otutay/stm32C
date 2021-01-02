/*
 * main.c
 *
 *  Created on: Dec 27, 2020
 *      Author: otutay
 */

#include "Clock.h"
//#include

int main(){

	// set main clock
	setHSEClock();
	setPllParam();
	setSystemClock();
	// set peripheral Clock
	GPIOClkReset(GPIODLOC);
	GPIOClkEn(GPIODLOC);
	setAhbFreq(div16);




	while(1);
	return 0;

}
