/*
 * EXTI_Program.c
 *
 *  Created on: Jun 7, 2023
 *      Author: mazen
 */
#include"../include/LIB/STD_TYPES.h"
#include"../include/LIB/BIT_MATH.h"

#include"../include/MCAL/EXTI/EXTI_Interface.h"
#include"../include/MCAL/EXTI/EXTI_Private.h"
#include"../include/MCAL/EXTI/EXTI_Cfg.h"

#define NULL 0
void (*EXTI0_Callback) (void) = NULL;
void (*EXTI1_Callback) (void) = NULL;
void (*EXTI2_Callback) (void) = NULL;

void MEXTI_voidConfig (EXTI_ID A_EXTI_ID, EXTI_SENSE_MODE A_EXTISenseMode)
{
	//Input Validation
	if ( (A_EXTI_ID <= EXTI2) && (A_EXTISenseMode <= RISING_EDGE) )
	{
		switch (A_EXTI_ID)
		{
		case EXTI0:
					MCUCR &= ~(SENSE_MODE_MASK << EXTI0_SENSE_MODE_BITS);
					MCUCR |= (A_EXTISenseMode << EXTI0_SENSE_MODE_BITS);
					break;
		case EXTI1:
					MCUCR &= ~(SENSE_MODE_MASK << EXTI1_SENSE_MODE_BITS);
					MCUCR |= (A_EXTISenseMode << EXTI1_SENSE_MODE_BITS);
					break;
		case EXTI2:
					switch (A_EXTISenseMode)
					{
					case FALLING_EDGE:
									  CLR_BIT(MCUCSR,EXTI2_SENSE_MODE_BITS);
									  break;
					case RISING_EDGE:
									  SET_BIT(MCUCSR,EXTI2_SENSE_MODE_BITS);
									  break;
					default: break;
					}
					break;

		default: break;

		}
	}
}
void MEXTI_voidEnable (EXTI_ID A_EXTI_ID)
{
	//Input Validation
	if ( (A_EXTI_ID <= EXTI2))
	{
		switch (A_EXTI_ID)
		{
		case EXTI0: SET_BIT(GICR,EXTI0_ENABLE_MODE_BITS); break;
		case EXTI1: SET_BIT(GICR,EXTI1_ENABLE_MODE_BITS); break;
		case EXTI2: SET_BIT(GICR,EXTI2_ENABLE_MODE_BITS); break;
		default: break;
		}
	}
}
void MEXTI_voidDisable (EXTI_ID A_EXTI_ID)
{
	//Input Validation
	if ( (A_EXTI_ID <= EXTI2))
	{
		switch (A_EXTI_ID)
		{
		case EXTI0: CLR_BIT(GICR,EXTI0_ENABLE_MODE_BITS); break;
		case EXTI1: CLR_BIT(GICR,EXTI1_ENABLE_MODE_BITS); break;
		case EXTI2: CLR_BIT(GICR,EXTI2_ENABLE_MODE_BITS); break;
		default: break;
		}
	}
}
void MEXTI_voidClearFlag (EXTI_ID A_EXTI_ID)
{
	//Input Validation
	if ( (A_EXTI_ID <= EXTI2))
	{
		switch (A_EXTI_ID)
		{
		case EXTI0: SET_BIT(GIFR,EXTI0_ENABLE_MODE_BITS); break;
		case EXTI1: SET_BIT(GIFR,EXTI1_ENABLE_MODE_BITS); break;
		case EXTI2: SET_BIT(GIFR,EXTI2_ENABLE_MODE_BITS); break;
		default: break;
		}
	}
}

void MEXTI_voidSetCallback(EXTI_ID A_EXTI_ID, void(*A_ptrToFunc)(void))
{
	//Input Validation
	if ( (A_EXTI_ID <= EXTI2) && (A_ptrToFunc != NULL))
	{
		switch (A_EXTI_ID)
		{
		case EXTI0: EXTI0_Callback = A_ptrToFunc; break;
		case EXTI1: EXTI1_Callback = A_ptrToFunc; break;
		case EXTI2: EXTI2_Callback = A_ptrToFunc; break;
		default: break;
		}
	}
}

void __vector_1(void) __attribute((signal));
void __vector_1(void)
{
	if (EXTI0_Callback != NULL)
	{
		EXTI0_Callback();
	}

}

void __vector_2(void) __attribute((signal));
void __vector_2(void)
{
	if (EXTI1_Callback != NULL)
	{
		EXTI1_Callback();
	}
}

void __vector_3(void) __attribute((signal));
void __vector_3(void)
{
	if (EXTI2_Callback != NULL)
	{
		EXTI2_Callback();
	}
}