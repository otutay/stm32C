/*
 * Clock.c
 *
 *  Created on: Dec 27, 2020
 *      Author: otutay
 */
#include "Clock.h"

// activate HSE and wait for ready indicator.
void setHSEClock(){
	pRccCR -> hsiOn  = 0;
	pRccCR -> hseByp = 0;
	pRccCR -> hseOn  = 1;
	while(!(pRccCR-> hseRdy));
}


void setPllParam(){
	// HSE is used and 168 Mhz is set
	// vco is around 336
	// pllN/pllM = 42

	pRccCfg -> pllP = 0; // 0 means 2 -> ref pg 168
	pRccCfg -> pllM = 4;
	pRccCfg -> pllN = 168;
	// calculations are as follows
	// 8*168/4 = vcoOut -> vcoOut/2 = frequency = 168;

	// set usb freq as 48 Mhz
	pRccCfg -> pllQ = 7;

	pRccCfg-> pllSrc = 1; // HSE is selected as pllSource;

}

void setSystemClock(){
	pRccCR-> pllOn = 1;
	while(!(pRccCR-> pllRdy)); // wait until pll ready
	pRccClkCfg -> sw = 2; // set pll as system clock
}




