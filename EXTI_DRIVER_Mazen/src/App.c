#include<util/delay.h>
#include"../include/LIB/STD_TYPES.h"
#include"../include/LIB/BIT_MATH.h"
#include"../include/MCAL/DIO/DIO_Interface.h"
#include"../include/HAL/LED/LED_Interface.h"
#include"../include/HAL/SSD/SSD_Interface.h"
#include"../include/MCAL/EXTI/EXTI_Interface.h"
#include"../include/MCAL/GI/GI_Interface.h"
#include"../include/HAL/LCD/LCD_Interface.h"

#define F_CPU 8000000UL

void APP_FUNC_EXTI0 (void)
{
	HLED_voidToogleLedStatus(PORTA,PIN0);

//	static u8 i=1;
//	HLCD_voidGoToPos(1,1);
//	HLCD_voidDisplayNumber(i);
//	i++;
}

int main(void)
{

	MDIO_voidInit();
	HLCD_voidInit();
	MEXTI_voidConfig(EXTI0,FALLING_EDGE);
	MEXTI_voidSetCallback(EXTI0,APP_FUNC_EXTI0);
	MEXTI_voidEnable(EXTI0);
	MGI_voidEnable();
	while (1)
	{

	}
}
