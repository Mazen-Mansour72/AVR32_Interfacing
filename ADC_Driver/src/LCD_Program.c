/*
 * LCD_Program.c
 *
 *  Created on: May 6, 2023
 *      Author: mazen
 */
#include <util/delay.h>
#include"../include/LIB/STD_TYPES.h"
#include"../include/LIB/BIT_MATH.h"

#include "../include/MCAL/DIO/DIO_Interface.h"

#include"../include/HAL/LCD/LCD_Interface.h"
#include"../include/HAL/LCD/LCD_Private.h"
#include"../include/HAL/LCD/LCD_Cfg.h"

#define F_CPU 8000000UL

void HLCD_voidSendCommand (u8 A_u8Command)
{
	//RS --> 0, RW --> 0
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_RESET);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_RESET);

	//Set Data Port with Command value
	MDIO_voidSetPortValue(LCD_DATA_PORT, A_u8Command);

	//Set Pulse on E Pin
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_SET);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_RESET);
}

void HLCD_voidSendData (u8 A_u8Data)
{
	//RS --> 0, RW --> 0
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_SET);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_RESET);

	//Set Data Port with Data value
	MDIO_voidSetPortValue(LCD_DATA_PORT, A_u8Data);

	//Set Pulse on E Pin
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_SET);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_RESET);
}

void HLCD_voidInit(void)
{
	//Wait more than 30 ms
	_delay_ms(30);

	//Function Set
	HLCD_voidSendCommand(FUNCTION_SET);

	// Wait more than 39 us
	_delay_ms(1);

	//Display ON/OFF Control
	HLCD_voidSendCommand(DISPLAY_ON_OFF_CONTROL);

	// Wait more than 39 us
	_delay_ms(1);

	//Display Clear
	HLCD_voidSendCommand(DISPLAY_CLEAR);

	//Wait more than 1.53 ms
	_delay_ms(2);

	//Entry Mode Set
	HLCD_voidSendCommand(ENTRY_MODE_SET);

	// Wait to check
	_delay_ms(1);
}

void HLCD_voidClearDisplay (void)
{
	//Display Clear
	HLCD_voidSendCommand(DISPLAY_CLEAR);

	//Wait more than 1.53 ms
	_delay_ms(2);
}

void HLCD_voidSendString (u8 *A_u8PtrToString)
{
	while (*A_u8PtrToString > 0)
	{
		HLCD_voidSendData(*A_u8PtrToString++);
	}
}

void HLCD_voidGoToPos (LCD_ROWS A_RowNo, LCD_COLS A_ColNo)
{
	switch(A_RowNo)
	{
	case ROW1: HLCD_voidSendCommand(LCD_ROW1_ADDRESS + A_ColNo); break;
	case ROW2: HLCD_voidSendCommand(LCD_ROW2_ADDRESS + A_ColNo); break;
	}
}

void HLCD_voidDisplayNumber (u32 A_u32Number)
{
	u32 local_u32Number = 1;
	if(local_u32Number == 0)
	{
		HLCD_voidSendData("0");
	}
	else
	{
		while (A_u32Number !=0)
		{
			local_u32Number = ((local_u32Number * 10) + (A_u32Number % 10));
			A_u32Number /=10;
		}
		while (local_u32Number !=1)
		{
			HLCD_voidSendData((local_u32Number % 10) + 48);
			local_u32Number /=10;
		}
	}
}


void HLCD_voidSendSpecialPattern (u8 *A_pu8PatternArr, u8 A_PatternNo, LCD_ROWS A_RowNo, LCD_COLS A_ColNo)
{
	u8 local_u8CGRAMAddress;
	// Command 01ByteAddress
	local_u8CGRAMAddress = A_PatternNo * 8;
	SET_BIT(local_u8CGRAMAddress,6);
	//Send CGRAM write command
	HLCD_voidSendCommand(local_u8CGRAMAddress);

	for(u8 i=0; i<8; i++)
	{
		//Send Custom Pattern to LCD CGRAM
		HLCD_voidSendData(A_pu8PatternArr[i]);
	}
	//Send position to DDRAM
	HLCD_voidGoToPos(A_RowNo,A_ColNo);
	//Display Pattern
	HLCD_voidSendData(A_PatternNo);
}
