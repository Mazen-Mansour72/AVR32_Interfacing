/*
 * KEYPAD_Program.c
 *
 *  Created on: Apr 29, 2023
 *      Author: abdelrahmanhossam
 */



#include <util/delay.h>
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/DIO/DIO_Interface.h"

#include "../include/HAL/KEYPAD/KEYPAD_Interface.h"
#include "../include/HAL/KEYPAD/KEYPAD_Private.h"
#include "../include/HAL/KEYPAD/KEYPAD_Cfg.h"

#define F_CPU 8000000UL

u8 static Global_u8ArrofRows [ROWS_NO] = KEYPAD_ROWS;
u8 static Global_u8ArrofCols [COLS_NO] = KEYPAD_COLS;


u8 HKEYPAD_u8GetPressedKey (void)
{
	u8 local_u8KeyValue = KEY_NOT_PRESSED;

	u8 local_u8RowCounter=0, local_u8ColCounter=0, local_u8PinValue, local_u8Flag=FLAG_DOWN;

	// Loop for ROWs
	for (local_u8RowCounter=0; local_u8RowCounter<ROWS_NO; local_u8RowCounter++)
	{
		// Activate One Row
		MDIO_voidSetPinValue(KEYPAD_PORT, Global_u8ArrofRows[local_u8RowCounter], DIO_RESET);

		// Loop for COLs check
		for (local_u8ColCounter=0; local_u8ColCounter<COLS_NO; local_u8ColCounter++)
		{
			// Read one Col
			local_u8PinValue = MDIO_DIO_VALUEGetPinValue(KEYPAD_PORT, Global_u8ArrofCols[local_u8ColCounter]);
			// Check if COL button is pressed
			if (local_u8PinValue == KEY_PRESSED)
			{
				// Delay for Bouncing Effect
				_delay_ms(KEYPAD_DEBOUNCING_DELAY_ms);

				// Read same COL again to verify Pressing
				local_u8PinValue = MDIO_DIO_VALUEGetPinValue(KEYPAD_PORT, Global_u8ArrofCols[local_u8ColCounter]);

				// Check if COL button is pressed
				if (local_u8PinValue == KEY_PRESSED)
				{
					// Wait till you stop pressing the button
					while (local_u8PinValue == KEY_PRESSED)
					{
						// Read same COL again to verify Pressing
						local_u8PinValue = MDIO_DIO_VALUEGetPinValue(KEYPAD_PORT, Global_u8ArrofCols[local_u8ColCounter]);
					}

					// Get the Pressed Button Value
					local_u8KeyValue = Global_u8KeyValues[local_u8RowCounter][local_u8ColCounter];

					// Raise ROWs Loop Break Flag
					local_u8Flag = FLAG_UP;

					// Break COLs loop
					break;
				}
			}
		}// End of COL loop

		// DeActivate One Row
		MDIO_voidSetPinValue(KEYPAD_PORT, Global_u8ArrofRows[local_u8RowCounter], DIO_SET);

		// check if Flag is up
		if (local_u8Flag==FLAG_UP)
		{
			// Break ROWs Loop
			break;
		}
	}// End of ROW loop

	// Return Pressed Key value
	return local_u8KeyValue;
}
