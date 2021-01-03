/*
 * main.c
 *
 *  Created on: Dec 27, 2020
 *      Author: otutay
 */

#include "Clock.h"
#include "Gpio.h"

int main(){

	// set main clock
	setHSEClock();
	setPllParam();
	// set peripheral Clock
	GPIOClkReset(GPIODLOC);
	GPIOClkEn(GPIODLOC);
	setAhbFreq(div16);
	// system clock set
	setSystemClock();


	// set gpioType
	tGPIOInit gpioLed;
	gpioLed.mode = output;
	gpioLed.outType = pushPull;
	gpioLed.outSpeed = medium;
	gpioLed.pUpPDown = noPuPd;
	gpioLed.pinNum = GPIO_PIN_12 | GPIO_PIN_13;

	gpioInit(&(gpioLed), GPIOD);

	setGpioOut(&gpioLed, GPIOD);
	//resetGpioOut(&gpioLed, GPIOD);
	while(1){
		resetGpioOut(&gpioLed, GPIOD);
		for (int var = 0; var < 1000000; ++var);
		setGpioOut(&gpioLed, GPIOD);
		for (int var = 0; var < 1000000; ++var);
	}
	return 0;

}



