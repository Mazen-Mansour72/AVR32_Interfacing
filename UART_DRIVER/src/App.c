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
#include"../include/MCAL/GI/GI_Interface.h"
#include"../include/MCAL/UART/UART_Interface.h"
#include"../include/HAL/LED/LED_Interface.h"
#include"../include/HAL/SSD/SSD_Interface.h"

#define F_CPU 8000000UL

int main(void)
{
	MDIO_voidInit();
	MUART_voidInit();

	u8 local_u8Value = 0;
	MUART_voidSendStringSyncNonBlocking("Hello from MicroController \r\n");
	MUART_voidSendStringSyncNonBlocking("To turn on LED press O and to turn off press F \r\n");
	while(1)
	{
		local_u8Value = MUART_u8ReadByteSyncBlocking();
		if(local_u8Value == 'O' || local_u8Value == 'o')
		{
			HLED_voidSetLedStatus(PORTA,PIN0,LED_ON);
		}
		else if (local_u8Value == 'F' || local_u8Value == 'f')
		{
			HLED_voidSetLedStatus(PORTA,PIN0,LED_OFF);
		}
	}
}
