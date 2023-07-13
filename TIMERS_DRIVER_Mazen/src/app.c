/*
 * app.c
 *
 *  Created on: Jul 3, 2023
 *      Author: mazen
 */
#include <util/delay.h>
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

#include"../include/MCAL/DIO/DIO_Interface.h"
#include"../include/MCAL/TIMERS/TIMERS_Interface.h"
#include "../include/MCAL/GI/GI_Interface.h"
#include"../include/HAL/LED/LED_Interface.h"

#define F_CPU 8000000UL

void TIMER0_OVF_FUNC (void)
{
	static u16 counter =0;
	counter++;
	if (counter == 3907)
	{
		MTIMER0_voidSetPreloadValue(192);
		counter=0;
		HLED_voidToggleLedStatus(PORTA, PIN0);
	}
}

void TIMER0_CTC_FUNC (void)
{
	static u16 counter =0;
	counter++;
	if (counter == 10000)
	{
		counter=0;
		HLED_voidToggleLedStatus(PORTA, PIN0);
	}
}
// OVF Main
//int main (void)
//{
//	MDIO_voidInit();
//	MTIMER0_voidSetOVFCallback(TIMER0_OVF_FUNC);
//	MTIMER0_voidInit();
//	MTIMER0_voidSetPreloadValue(192);
//	MGI_voidEnable();
//	while(1)
//	{
//
//	}
//}

// CTC Main
//int main(void)
//{
//	MDIO_voidInit();
//	MTIMER0_voidSetCTCCallback(TIMER0_CTC_FUNC);
//	MTIMER0_voidInit();
//	MGI_voidEnable();
//	while(1)
//	{
//
//	}
//}

//// Fast PWM Main
//int main (void)
//{
//	MDIO_voidInit();
//	MTIMER0_voidInit();
//	while(1)
//	{
//		for (u8 i=0; i<250; i+=10)
//		{
//			MTIMER0_voidSetOCR0Value(i);
//			_delay_ms (300);
//		}
//		for (u8 i=250; i>0; i -=10)
//		{
//			MTIMER0_voidSetOCR0Value(i);
//			_delay_ms (300);
//		}
//	}
//}


//// Servo Motor using Fast PWM , TIMER1
//int main(void)
//{
//	MDIO_voidInit();
//	MTIMER1_voidInit();
//	//MTIMER1_voidSetServoAngle(90);
//	while(1)
//	{
////		for (u16 i=1000; i<2500; i+=500)
////		{
////			MTIMER1_voidSetOCR1AValue(i);
////			_delay_ms (1000);
////		}
////		for (u16 i=2000; i>500; i -=500)
////		{
////			MTIMER1_voidSetOCR1AValue(i);
////			_delay_ms (1000);
////		}
//		for(u8 i=0; i<181; i++)
//		{
//			MTIMER1_voidSetServoAngle(i);
//			_delay_ms(50);
//		}
//
//	}
//}


// WDT main
int main(void)
{
//	_delay_ms(1000);
//	MDIO_voidInit();
//	MWDT_voidEnable();
	while(1)
	{
		_delay_ms(1000);
		MWDT_voidEnable();
		MDIO_voidInit();
		_delay_ms(5000);
		MWDT_voidDisable();
	}
}
