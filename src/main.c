/*
 * main.c
 *
 *  Created on: Dec 27, 2020
 *      Author: otutay
 */

//#include "Clock.h"

int main(){

	// set main clock
	setHSEClock();
	setPllParam();
	setSystemClock();
	// set peripheral Clock


	while(1);
	return 0;

}
