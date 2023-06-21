#include<util/delay.h>
#include"../include/LIB/STD_TYPES.h"
#include"../include/LIB/BIT_MATH.h"

#include"../include/MCAL/DIO/DIO_Interface.h"
#include"../include/HAL/LCD/LCD_Interface.h"

#define F_CPU 8000000UL

int main(void)
{
	MDIO_voidInit();
	HLCD_voidInit();

	HLCD_voidSendString("Mazen");

	u8 customChar[] = {
	  0b00000,
	  0b01010,
	  0b10101,
	  0b10001,
	  0b10001,
	  0b10001,
	  0b01010,
	  0b00100
	};

	HLCD_voidSendSpecialCharacter (customChar, 0, 1, 6);
	HLCD_voidDisplayNumber(2023);
	while(1)
	{
	}
}


