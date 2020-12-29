/*
 * Gpio.h
 *
 *  Created on: Dec 29, 2020
 *      Author: otutay
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "typedefs.h"

typedef enum {
		input = 0x0,
		output = 0x1,
		alterFun = 0x2,
		analog = 0x3
} tGpioModeEnum;

typedef enum{
	pushPull = 0x0,
	openDrain = 0x1
}tGpioOutType;



typedef struct tGPIO {
	u32 pinNum;
	tGpioModeEnum gpioMode;

};

#endif /* GPIO_H_ */
