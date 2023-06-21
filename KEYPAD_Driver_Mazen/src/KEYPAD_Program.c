/*
 * KEYPAD_Program.c
 *
 *  Created on: Jun 15, 2023
 *      Author: mazen
 */
#include<util/delay.h>
#include"../include/LIB/BIT_MATH.h"
#include"../include/LIB/STD_TYPES.h"

#include"../include/MCAL/DIO/DIO_Interface.h"

#include"../include/HAL/KEYPAD/KEYPAD_Interface.h"
#include"../include/HAL/KEYPAD/KEYPAD_Private.h"
#include"../include/HAL/KEYPAD/KEYPAD_Cfg.h"

#define F_CPU 8000000UL

u8 static Global_u8ArrofRows [ROWS_NO] = KEYPAD_ROWS;
u8 static Global_u8ArrofCols[COLS_NO] = KEYPAD_COLS;

u8 HKEYPAD_u8GetPressedKey (void)
{
	u8 local_u8KeyValue = KEYPAD_NOT_PRESSED;
	u8 local_u8RowCounter=0, local_u8ColCounter=0, local_u8PinValue, local_u8Flag = FLAG_DOWN;

	//Loop for Rows
	for(local_u8RowCounter=0; local_u8RowCounter<ROWS_NO; local_u8RowCounter++)
	{
		//Activate One Row
		MDIO_voidSetPinValue(KEYPAD_PORT, Global_u8ArrofRows[local_u8RowCounter], DIO_RESET);

		//Loop for Cols
		for(local_u8ColCounter=0; local_u8ColCounter<COLS_NO; local_u8ColCounter++)
		{
			//Read One Col
			local_u8PinValue = MDIO_DIO_VALUEGetPinValue(KEYPAD_PORT,Global_u8ArrofCols[local_u8ColCounter]);

			//Check if Col button is Pressed
			if(local_u8PinValue == KEYPAD_PRESSED)
			{
				//Delay for Bouncing Effect
				_delay_ms(KEYPAD_DEBOUNCING_DELAY_ms);

				//Read Same Col again to Verfiy
				local_u8PinValue = MDIO_DIO_VALUEGetPinValue(KEYPAD_PORT,Global_u8ArrofCols[local_u8ColCounter]);

				//Check if Col button is still Pressed
				if(local_u8PinValue == KEYPAD_PRESSED)
				{
					//Wait till you stop Pressing
					while(local_u8PinValue == KEYPAD_PRESSED)
					{
						//Read Same Col again to Verfiy
						local_u8PinValue = MDIO_DIO_VALUEGetPinValue(KEYPAD_PORT,Global_u8ArrofCols[local_u8ColCounter]);
					}

					//Get Pressed Key Value
					local_u8KeyValue =  Global_u8KeyValues[local_u8RowCounter][local_u8ColCounter];

					//Raise Row loop break Flag
					local_u8Flag = FLAG_UP;

					//break Col loop
					break;
				}

			}
		}//End of col loop

		//Deactivate one Row
		MDIO_voidSetPinValue(KEYPAD_PORT, Global_u8ArrofRows[local_u8RowCounter], DIO_SET);

		//Check if Row loop Flag is Up
		if(local_u8Flag == FLAG_UP)
		{
			//break Row loop
			break;
		}
	}//End of Row Loop

	//Return Pressed Key Value
	return local_u8KeyValue;
}
