#include<util/delay.h>
#include"../include/LIB/STD_TYPES.h"
#include"../include/LIB/BIT_MATH.h"
#include"../include/MCAL/DIO/DIO_Interface.h"
#include"../include/HAL/LED/LED_Interface.h"
#include"../include/MCAL/GI/GI_Interface.h"
#include "../include/MCAL/ADC/ADC_Interface.h"
#include"../include/HAL/LCD/LCD_Interface.h"

#define CPU 8000000UL

//int main(void)
//{
//
//	MDIO_voidInit();
//	MADC_voidInit();
//	HLCD_voidInit();
//	u16 DigitalValue, AnalogValue;
//	while (1)
//	{
//
//		DigitalValue = MADC_u16GetDigitalvalue(ADC0);
//		AnalogValue = (DigitalValue * 5000UL) / 1024;
//		HLCD_voidClearDisplay();
//		HLCD_voidDisplayNumber(AnalogValue/10);
//		_delay_ms(3000);
//	}
//}

// Hamoksha wake and sleep by light intensity
int main(void)
{

	MDIO_voidInit();
	MADC_voidInit();
	HLCD_voidInit();
	u16 DigitalValue, AnalogValue;
	u8 wake[] = {
	  0b00100,
	  0b01010,
	  0b00100,
	  0b00100,
	  0b01110,
	  0b10101,
	  0b01010,
	  0b10001
	};
	u8 sleep[] = {
	  0b00000,
	  0b00000,
	  0b00010,
	  0b11111,
	  0b10110,
	  0b10100,
	  0b00000,
	  0b00000
	};
	while (1)
	{

		DigitalValue = MADC_u16GetDigitalvalue(ADC0);
		AnalogValue = (DigitalValue * 5000UL) / 1024;
		HLCD_voidClearDisplay();
		HLCD_voidDisplayNumber(AnalogValue);
		if(AnalogValue >= 100)
		{

			HLCD_voidSendSpecialPattern(wake,0,2,1);
		}
		else
		{

			HLCD_voidSendSpecialPattern(sleep,1,2,1);
		}
		_delay_ms(3000);
	}
}
