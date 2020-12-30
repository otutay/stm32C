/*
 * Gpio.h
 *
 *  Created on: Dec 29, 2020
 *      Author: otutay
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "typedefs.h"

#define GPIO_PIN_0  ((u16)0x0001)
#define GPIO_PIN_1  ((u16)0x0002)
#define GPIO_PIN_2  ((u16)0x0004)
#define GPIO_PIN_3  ((u16)0x0008)
#define GPIO_PIN_4  ((u16)0x0010)
#define GPIO_PIN_5  ((u16)0x0020)
#define GPIO_PIN_6  ((u16)0x0040)
#define GPIO_PIN_7  ((u16)0x0080)
#define GPIO_PIN_8  ((u16)0x0100)
#define GPIO_PIN_9  ((u16)0x0200)
#define GPIO_PIN_10 ((u16)0x0400)
#define GPIO_PIN_11 ((u16)0x0800)
#define GPIO_PIN_12 ((u16)0x1000)
#define GPIO_PIN_13 ((u16)0x2000)
#define GPIO_PIN_14 ((u16)0x4000)
#define GPIO_PIN_14 ((u16)0x8000)

#define GPIOx_MODE_OFFSET 		((u32) 0x00)
#define GPIOx_OUT_TYPE_OFFSET 	((u32)0x04)
#define GPIOx_OUT_SPEED_OFFSET 	((u32)0x08)
#define GPIOx_PUPD_OFFSET 		((u32)0x0C)
#define GPIOx_INDATA_OFFSET 	((u32)0x10)
#define GPIOx_OUTDATA_OFFSET 	((u32)0x14)

typedef enum {
		input = 0x0,
		output = 0x1,
		alterFun = 0x2,
		analog = 0x3
} tGpioModeEnum;

typedef enum {
		pushPull = 0x0,
		openDrain = 0x1
} tGpioOutTypeEnum;

typedef enum {
		low = 0x0,
		medium = 0x1,
		high = 0x2,
		vHigh = 0x3
} tGpioOutSpeedEnum;

typedef enum {
		noPuPd = 0x0,
		pullUp = 0x1,
		pullDown = 0x2
} tGpioPUPDEnum;

typedef struct {
	u32 baseAddr;
	u32 pinNum;
	tGpioModeEnum mode;
	tGpioOutTypeEnum outType;
	tGpioOutSpeedEnum outSpeed;
	tGpioPUPDEnum pUpPDown;

} tGPIO;






#endif /* GPIO_H_ */
