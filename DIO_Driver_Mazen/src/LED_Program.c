/*
 * LED_Program.c
 *
 *  Created on: Jun 14, 2023
 *      Author: mazen
 */
#include"../include/LIB/STD_TYPES.H"
#include"../include/LIB/BIT_MATH.h"

#include"../include/MCAL/DIO/DIO_Interface.h"

#include"../include/HAL/LED/LED_Interface.h"
#include"../include/HAL/LED/LED_Private.h"
#include"../include/HAL/LED/LED_Cfg.h"

void HLED_voidSetLedStatus(DIO_PORTS A_DIOPort, DIO_PINS A_DIOPinNo, LED_STATUS A_LedStatus)
{
	MDIO_voidSetPinValue(A_DIOPort,A_DIOPinNo,A_LedStatus);
}

void HLED_voidToggleLedStatus(DIO_PORTS A_DIOPort, DIO_PINS A_DIOPinNo)
{
	MDIO_voidTogglePinValue(A_DIOPort,A_DIOPinNo);
}
