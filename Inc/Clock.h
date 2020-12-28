#ifndef __CLOCK_H
#define __CLOCK_H

#include "Registers.h"
#include "typedefs.h"

#define fullSpeed 168

#define GPIOALOC (1 << 0)
#define GPIOBLOC (1 << 1)
#define GPIOCLOC (1 << 2)
#define GPIODLOC (1 << 3)
#define GPIOELOC (1 << 4)
#define GPIOFLOC (1 << 5)
#define GPIOGLOC (1 << 6)
#define GPIOHLOC (1 << 7)
#define GPIOILOC (1 << 8)

#define RCC_CR_OFFSET ((u32)0x00)
#define RCC_PLL_CFG_OFFSET ((u32) 0x04)
#define RCC_CLOCK_CFG_OFFSET ((u32) 0x08)
#define RCC_AHB1_PERIPH_RST_OFFSET ((u32) 0x10)
#define RCC_AHB1_PERIPH_EN_OFFSET ((u32) 0x30)

struct sRCC_Control_Reg {
	u32 hsiOn :1;
	u32 hsiRdy :1;
	u32 rsv1 :1;
	u32 hsiTrim :5;
	u32 hsiCal :8;
	u32 hseOn :1;
	u32 hseRdy :1;
	u32 hseByp :1;
	u32 cssOn :1;
	u32 rsv2 :4;
	u32 pllOn :1;
	u32 pllRdy :1;
	u32 pllI2SOn :1;
	u32 pllI2SRdy :1;
	u32 rsv3 :4;
};

struct sRCC_Control_Reg *pRccCR = (struct sRCC_Control_Reg*) (RCC_BASE_ADDR
		+ RCC_CR_OFFSET);

struct sRCC_Cfg_Reg {
	u32 pllM :6;
	u32 pllN :9;
	u32 rsv1 :1;
	u32 pllP :2;
	u32 rsv2 :4;
	u32 pllSrc :1;
	u32 rsv3 :1;
	u32 pllQ :4;
	u32 rsv4 :4;

};
struct sRCC_Cfg_Reg *pRccCfg = (struct sRCC_Cfg_Reg*) (RCC_BASE_ADDR
		+ RCC_PLL_CFG_OFFSET);

struct sRCC_Clk_Cfg_Reg {
	u32 sw :2;
	u32 swS :2;
	u32 ahbPres :4;
	u32 rsv1 :2;
	u32 apb1Pres :3;
	u32 apb2Pres :3;
	u32 rtcPres :5;
	u32 mco1 :2;
	u32 i2sSrc :1;
	u32 mco1Pres :3;
	u32 mco2Pres :3;
	u32 mco2 :2;
};

struct sRCC_Clk_Cfg_Reg *pRccClkCfg = (struct sRCC_Clk_Cfg_Reg*) (RCC_BASE_ADDR
		+ RCC_CLOCK_CFG_OFFSET);

struct sRCC_AHB1_RST_REG {
	u32 gpioRst :9; // A to I
	u32 rsv1 :3;
	u32 crcRst :1;
	u32 rsv2 :8;
	u32 dma1Rst :1;
	u32 dma2Rst :1;
	u32 rsv3 :2;
	u32 ethMacRst :1;
	u32 rsv4 :3;
	u32 otgHRst :1;
	u32 rsv5 :2;
};

struct sRCC_AHB1_RST_REG *pRCCAhb1Rst =
		(struct sRCC_AHB1_RST_REG*) (RCC_BASE_ADDR + RCC_AHB1_PERIPH_RST_OFFSET);

struct sRCC_AHB1_CLK_EN_REG {
	u32 gpioEn :9; // A to I
	u32 rsv1 :3;
	u32 crcEn :1;
	u32 rsv2 :5;
	u32 BckSramEn :1;
	u32 rsv3 :1;
	u32 CcmRamEn :1;
	u32 dma1En :1;
	u32 dma2En :1;
	u32 rsv4 :2;
	u32 ethMacEn :1;
	u32 ethMacTxEn :1;
	u32 ethMacRxEn :1;
	u32 ethMacPtpEn :1;
	u32 otgHsEn :1;
	u32 otgHsUlpiEn :1;
	u32 rsv5 :1;
};
struct sRCC_AHB1_CLK_EN_REG *pRccClkEn =
		(struct sRCC_AHB1_CLK_EN_REG*) (RCC_BASE_ADDR
				+ RCC_AHB1_PERIPH_EN_OFFSET);

void setHSEClock();
void setPllParam();
void setSystemClock();

#endif