
#include<util/delay.h>
#include"../include/LIB/STD_TYPES.h"
#include"../include/LIB/BIT_MATH.h"

#include"../include/MCAL/DIO/DIO_Interface.h"

#include"../include/HAL/SSD/SSD_Interface.h"
#include"../include/HAL/SSD/SSD_Private.h"
#include"../include/HAL/SSD/SSD_Cfg.h"

#define F_CPU 8000000UL

void HSSD_voidDisplayNumber (DIO_PORTS A_DIOPORT, u8 A_u8Number)
{
	switch (A_u8Number)
	{
	case 0: MDIO_voidSetPortValue (A_DIOPORT,ZERO);  break;
	case 1: MDIO_voidSetPortValue (A_DIOPORT,ONE);   break;
	case 2: MDIO_voidSetPortValue (A_DIOPORT,TWO);   break;
	case 3: MDIO_voidSetPortValue (A_DIOPORT,THREE); break;
	case 4: MDIO_voidSetPortValue (A_DIOPORT,FOUR);  break;
	case 5: MDIO_voidSetPortValue (A_DIOPORT,FIVE);  break;
	case 6: MDIO_voidSetPortValue (A_DIOPORT,SIX);   break;
	case 7: MDIO_voidSetPortValue (A_DIOPORT,SEVEN); break;
	case 8: MDIO_voidSetPortValue (A_DIOPORT,EIGHT); break;
	case 9: MDIO_voidSetPortValue (A_DIOPORT,NINE);  break;
	default: break;
	}
}

void HSSD_voidDisplayNumberAscending (DIO_PORTS A_DIOPORT, u16 A_u16DelayinMS)
{
	for (u8 i=0; i<10; i++)
	{
		HSSD_voidDisplayNumber(A_DIOPORT,i);
		_delay_ms(A_u16DelayinMS);
	}
}

void HSSD_voidDisplayNumberDescending (DIO_PORTS A_DIOPORT, u16 A_u16DelayinMS)
{
	for (s8 i=9; i>=0; i--)
	{
		HSSD_voidDisplayNumber(A_DIOPORT,i);
		_delay_ms(A_u16DelayinMS);
	}
}
