/*
 * App.c
 *
 *  Created on: Apr 15, 2023
 *      Author: abdelrahmanhossam
 */



#include <util/delay.h>
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/HAL/LCD/LCD_Interface.h"
#include "../include/HAL/KEYPAD/KEYPAD_Interface.h"
#include "../include/HAL/SSD/SSD_Interface.h"
#define F_CPU 8000000UL


//int main ()
//{
//	// SET PORT A from A0 to A3 to O/P High
//	// SET PORT A from A4 to A7 to I/P Pull-up
//	// Set PORT D as O/P Low
//	// Set PORT C from C0 to C2 to O/P Low
//	MDIO_voidInit();
//	HLCD_voidInit();
//
//	u8 local_u8KeyPadValue = 255;
//	while(1)
//	{
//		local_u8KeyPadValue = HKEYPAD_u8GetPressedKey();
//		if (local_u8KeyPadValue == 'C')
//		{
//			HLCD_voidClearDisplay();
//		}
//		else if (local_u8KeyPadValue != 255)
//		{
//			HLCD_voidSendData(local_u8KeyPadValue);
//		}
//	}
//}

//Perform Certain Actions by Keypad
//int main ()
//{
//	// SET PORT A from A0 to A3 to O/P High
//	// SET PORT A from A4 to A7 to I/P Pull-up
//	// Set PORT D as O/P Low
//	// Set PORT C from C0 to C2 to O/P Low
//	MDIO_voidInit();
//	HLCD_voidInit();
//
//	static u8 i=0;
//	u8 local_u8KeyPadValue = 255;
//	while(1)
//	{
//		local_u8KeyPadValue = HKEYPAD_u8GetPressedKey();
//		//Toggle Led
//		if (local_u8KeyPadValue == '1')
//		{
//
//			MDIO_voidTogglePinValue(PORTB,PIN7);
//		}
//		//Increment SSD
//		else if (local_u8KeyPadValue == '4')
//		{
//
//			HSSD_voidDisplayNumber(PORTB,++i);
//			//i++;
//		}
//		//Decrement SSD
//		else if (local_u8KeyPadValue == '5')
//		{
//			//static u8 i=0;
//			HSSD_voidDisplayNumber(PORTB,--i);
//			//i++;
//		}
//		//Increment Buzzer
//		else if (local_u8KeyPadValue == '7')
//		{
//
//			MDIO_voidTogglePinValue(PORTC,PIN7);
//		}
//	}
//}

// Simple Calculator
//int main(void)
//{
//
//	MDIO_voidInit();
//	HLCD_voidInit();
//
//	s16 Num1 = 0;
//	s16 Num2 = 0;
//	s16 result = 0;
//	s16 calculation = 0;
//	u8 key = 255;
//	while (1)
//	{
//		u8 key = HKEYPAD_u8GetPressedKey();
//		switch (key)
//		{
//			case 1:
//			case 2:
//			case 3:
//			case 4:
//			case 5:
//			case 6:
//			case 7:
//			case 8:
//			case 9:
//			if (calculation == 0)
//			{
//				Num1 =  + key;
//				HLCD_voidDisplayNumber(Num1);
//			}
//
//			else
//			{
//				Num2 =  key;
//				HLCD_voidDisplayNumber(Num2);
//			}
//			break;
//
//			case 10:
//			calculation = '+';
//			HLCD_voidSendData(calculation);
//			break;
//			case 11:
//			calculation = '-';
//			HLCD_voidSendData(calculation);
//			break;
//			case 12:
//			calculation = '*';
//			HLCD_voidSendData(calculation);
//			break;
//			case 13:
//			calculation = '/';
//			HLCD_voidSendData(calculation);
//			break;
//
//			//'='
//			case 14:
//			if (calculation == '+')
//			{
//				result = Num1 + Num2;
//			}
//			else if (calculation == '-')
//			{
//				result = Num1 - Num2;
//			}
//			else if (calculation == '*')
//			{
//				result = Num1 * Num2;
//			}
//			else if (calculation == '/')
//			{
//				if (Num2 != 0)
//				{
//					result = Num1 / Num2;
//				}
//			}
//
//			HLCD_voidSendData('=');
//			HLCD_voidDisplayNumber(result);
//
//
//			calculation = 0;
//			Num1 = 0;
//			Num2 = 0;
//			break;
//			case 15:
//			HLCD_voidClearDisplay();
//			break;
//		}
//	}
//
//}

// Password
int main(void)
{
	MDIO_voidInit();
	HLCD_voidInit();
	HLCD_voidSendString("Password:");
	_delay_ms(2000);

	HLCD_voidGoToPos(2,1);
	u8 x[4] = {'1','2','3','4'};
	u8 password[4];
	u8 i = 0, j = 0;
	u8 flag = 0;
	while (1)
	{

		if ((flag == 0)  && (j < 4))
		{
			for (i = 0; i < 4; i++)
			{
				do
				{
					password[i] = HKEYPAD_u8GetPressedKey();
				} while (password[i] == 0xFF);
				HLCD_voidSendData('*');

			}
			if ((password[0] == x[0]) && (password[1] == x[1]) && (password[2] == x[2]) && (password[3] == x[3]))
			{
				flag = 1;
				HLCD_voidClearDisplay();
				HLCD_voidSendString("Welcome");
				_delay_ms(2000);
			}
			else
			{
				HLCD_voidClearDisplay();
				HLCD_voidSendString("WrongPassword");
				_delay_ms(1000);
				HLCD_voidClearDisplay();
				if(j < 3)
				{
					HLCD_voidSendString("TryAgain:");
					HLCD_voidGoToPos(2,1);
				}
				else
				{
					HLCD_voidSendString("LOCKED!");
					MDIO_voidSetPinDirection(PORTB,PIN0,DIO_OUTPUT);
					MDIO_voidSetPinValue(PORTB,PIN0,DIO_SET);
				}
			}
			j++;
		}
	}
}
