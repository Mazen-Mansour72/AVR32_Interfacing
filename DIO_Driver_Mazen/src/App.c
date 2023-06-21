/* Delay Library */
#include<util/delay.h>
/*************
 * Library Directives
 *****************/
#include"../include/LIB/STD_TYPES.h"
#include"../include/LIB/BIT_MATH.h"
/**************
 * Drivers includes
 ***************/
#include"../include/MCAL/DIO/DIO_Interface.h"
#include"../include/HAL/LED/LED_Interface.h"
#include"../include/HAL/SSD/SSD_Interface.h"

#define F_CPU 8000000UL

/*****************
 * Test DIO Function on a led
 ******************/
//int main(void)
//{
//	MDIO_voidInit();
//	while(1)
//	{
//		MDIO_voidTogglePinValue(PORTA,PIN0);
//		//_delay_ms(1000);
//		MDIO_voidSetPinDirection(PORTA,PIN7,DIO_OUTPUT);
//		MDIO_voidSetPinValue(PORTA,PIN7,DIO_SET);
//		u8 z = MDIO_DIO_VALUEGetPinValue(PORTA,PIN7);
//		if(z == 1)
//		{
//			MDIO_voidSetPortDirection(PORTA,0xFF);
//			MDIO_voidSetPortValue(PORTA,0xFF);
//		}
//	}
//}

/************************
 * Display numbers from 0 to 9 on Seven Segment Display Ascendingly
 ************************/
// int main(void)
// {
// 	MDIO_voidInit();
// 	while(1)
// 	{
// 		MDIO_voidSetPortDirection(PORTA,0xFF);
// 		HSSD_voidDisplayNumberAscending(PORTA,2000);

// 	}

// }
/***************************************
 * Toggle Buzzer Status every 100 msec.
 ***************************************/
int main ()
{

	MDIO_voidSetPinDirection(PORTA,PIN0,DIO_OUTPUT);
	MDIO_voidSetPinValue(PORTA,PIN0,DIO_SET);


	while(1)
	{
		MDIO_voidTogglePinValue(PORTA,PIN0);
		_delay_ms(100);
	}
}
