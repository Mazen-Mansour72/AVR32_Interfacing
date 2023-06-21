/*
 * GI_Program.c
 *
 *  Created on: Jun 7, 2023
 *      Author: mazen
 */
#include"../include/LIB/STD_TYPES.h"
#include"../include/LIB/BIT_MATH.h"

#include"../include/MCAL/GI/GI_Interface.h"
#include"../include/MCAL/GI/GI_Private.h"
#include"../include/MCAL/GI/GI_Cfg.h"

void MGI_voidEnable (void)
{
	SET_BIT(SREG,GLOBAL_INTERRUPT_ENABLE_BIT);
}

void MGI_voidDisable (void)
{
	CLR_BIT(SREG,GLOBAL_INTERRUPT_ENABLE_BIT);
}
