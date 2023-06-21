#include<util/delay.h>
#include"../include/LIB/STD_TYPES.h"
#include"../include/LIB/BIT_MATH.h"

#include"../include/MCAL/DIO/DIO_Interface.h"
#include"../include/HAL/LCD/LCD_Interface.h"
#include"../include/HAL/KEYPAD/KEYPAD_Interface.h"

#define F_CPU 8000000UL

/**************
 * Display Keypad Values on LCD
 **************/
//int main ()
//{
//	// SET PORT A from A0 to A3 to O/P High
//	// SET PORT A from A4 to A7 to I/P Pull-up
//	MDIO_voidInit();
//	// Set PORT D as O/P Low
//	// Set PORT C from C0 to C2 to O/P Low
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


int main ()
{
	// SET PORT A from A0 to A3 to O/P High
	// SET PORT A from A4 to A7 to I/P Pull-up
	MDIO_voidInit();
	// Set PORT D as O/P Low
	// Set PORT C from C0 to C2 to O/P Low
	HLCD_voidInit();

	u8 local_u8KeyPadValue = 255;
	while(1)
	{
		local_u8KeyPadValue = HKEYPAD_u8GetPressedKey();
		if (local_u8KeyPadValue == 'C')
		{
			HLCD_voidClearDisplay();
		}
		else if (local_u8KeyPadValue != 255)
		{
			HLCD_voidSendData(local_u8KeyPadValue);
		}
	}
}
