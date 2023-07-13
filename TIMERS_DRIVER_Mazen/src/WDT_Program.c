/*
 * WDT_Program.c
 *
 *  Created on: Jul 13, 2023
 *      Author: mazen
 */

#include"../include/LIB/STD_TYPES.h"
#include"../include/LIB/BIT_MATH.h"

#define WDTCR (*(volatile u8 *)0x41)

void MWDT_voidEnable(void);
void MWDT_voidDisable(void);

void MWDT_voidEnable(void)
{
	WDTCR = 0b00001111;
}

void MWDT_voidDisable(void)
{
	CLR_BIT(WDTCR,3);
	SET_BIT(WDTCR,4);
	WDTCR = 0x00;
}
