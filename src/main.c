/*
 * main.c
 *
 *  Created on: Dec 27, 2020
 *      Author: otutay
 */

//#include "Clock.h"

int main(){
	setHSEClock();
	setPllParam();
	setSystemClock();
	while(1);
	return 0;

}
