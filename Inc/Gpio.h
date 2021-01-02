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
#define GPIO_PIN_15 ((u16)0x8000)

#define GPIOx_MODE_OFFSET 		((u32)0x00)
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
	u16 pinNum;
	tGpioModeEnum mode;
	tGpioOutTypeEnum outType;
	tGpioOutSpeedEnum outSpeed;
	tGpioPUPDEnum pUpPDown;
} tGPIOInit;

typedef struct {
	u32 moder;
	u32 outType;
	u32 outSpeed;
	u32 pupd;
	u32 inData;
	u32 outData;
} tGPIORegs;

tGPIORegs *GPIOA = (tGPIORegs*) (GPIOA_BASE_ADDR);
tGPIORegs *GPIOB = (tGPIORegs*) (GPIOB_BASE_ADDR);
tGPIORegs *GPIOC = (tGPIORegs*) (GPIOC_BASE_ADDR);
tGPIORegs *GPIOD = (tGPIORegs*) (GPIOD_BASE_ADDR);
tGPIORegs *GPIOE = (tGPIORegs*) (GPIOE_BASE_ADDR);
tGPIORegs *GPIOF = (tGPIORegs*) (GPIOF_BASE_ADDR);
tGPIORegs *GPIOG = (tGPIORegs*) (GPIOG_BASE_ADDR);
tGPIORegs *GPIOH = (tGPIORegs*) (GPIOH_BASE_ADDR);
tGPIORegs *GPIOI = (tGPIORegs*) (GPIOI_BASE_ADDR);
tGPIORegs *GPIOJ = (tGPIORegs*) (GPIOJ_BASE_ADDR);
tGPIORegs *GPIOK = (tGPIORegs*) (GPIOK_BASE_ADDR);

void gpioMode(u32 *reg, u16 pinPos, tGpioModeEnum mode) {
	*reg |= (mode) << (pinPos * 2);
}

void gpioOutType(u32 *reg, u16 pinPos, tGpioOutTypeEnum outType) {
	*reg |= (outType) << (pinPos);
}

void gpioOutSpeed(u32 *reg, u16 pinPos, tGpioOutSpeedEnum outSpeed) {
	*reg |= (outSpeed) << (pinPos * 2);
}

void gpioPuPd(u32 *reg, u16 pinPos, tGpioPUPDEnum pupd) {
	*reg |= (pupd) << (pinPos * 2);
}

void gpioOutData(u32 *reg, u16 pinPos, u32 data){
	*reg |= (data) << (pinPos);
}

void gpioInit(tGPIOInit *gpioX, tGPIORegs *gpioReg) {
	int pinPos = 1, currentPos = 0;

	for (int i = 0; i < 16; i++) {
		currentPos = (gpioX->pinNum & (pinPos << i));
		if (currentPos) {
			gpioMode(&(gpioReg->moder), i, gpioX->mode);
			if (gpioX->mode == output) {
				gpioOutType(&(gpioReg->outType), i, gpioX->outType);
				gpioOutSpeed(&(gpioReg->outSpeed), i, gpioX->outSpeed);
			}
		}

	}

}

void setGpioOut(tGPIOInit *gpioX,tGPIORegs *gpioReg, u32 data) {
	int pinPos = 1, currentPos = 0;

	for (int i = 0; i < 16; i++) {
		currentPos = (gpioX->pinNum & (pinPos << i));
		if (currentPos) {

		}
	}
}
//struct sGpio2Bit{
//	u32 p0 :2;
//	u32 p1 :2;
//	u32 p2 :2;
//	u32 p3 :2;
//	u32 p4 :2;
//	u32 p5 :2;
//	u32 p6 :2;
//	u32 p7 :2;
//	u32 p8 :2;
//	u32 p9 :2;
//	u32 p10 :2;
//	u32 p11 :2;
//	u32 p12 :2;
//	u32 p13 :2;
//	u32 p14 :2;
//	u32 p15 :2;
//};
//
//struct sGpio1Bit{
//	u32 p0 :1;
//	u32 p1 :1;
//	u32 p2 :1;
//	u32 p3 :1;
//	u32 p4 :1;
//	u32 p5 :1;
//	u32 p6 :1;
//	u32 p7 :1;
//	u32 p8 :1;
//	u32 p9 :1;
//	u32 p10 :1;
//	u32 p11 :1;
//	u32 p12 :1;
//	u32 p13 :1;
//	u32 p14 :1;
//	u32 p15 :1;
//	u32 rsv : 16;
//};

//typedef struct {
//	struct sGpio2Bit* moder;
//	struct sGpio1Bit* outType;
//	struct sGpio2Bit* outSpeed;
//	struct sGpio2Bit* pupd;
//	struct sGpio1Bit* inData;
//	struct sGpio1Bit* outData;
//} tGPIORegs;

#endif /* GPIO_H_ */
