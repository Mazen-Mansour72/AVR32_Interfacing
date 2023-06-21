/*
 * KEYPAD_Cfg.h
 *
 *  Created on: Apr 29, 2023
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_HAL_KEYPAD_KEYPAD_CFG_H_
#define INCLUDE_HAL_KEYPAD_KEYPAD_CFG_H_

#define KEYPAD_PORT PORTA

#define ROWS_NO	4
#define COLS_NO	4

u8 Global_u8KeyValues [ROWS_NO][COLS_NO] = {
											{'1','2','3','+'},
											{'4','5','6','-'},
											{'7','8','9','*'},
											{'C','0','=','/'}
										   };


#define ROW0 PIN0
#define ROW1 PIN1
#define ROW2 PIN2
#define ROW3 PIN3

#define COL0 PIN4
#define COL1 PIN5
#define COL2 PIN6
#define COL3 PIN7

#define KEYPAD_ROWS {ROW0,ROW1,ROW2,ROW3}
#define KEYPAD_COLS {COL0,COL1,COL2,COL3}


#define KEY_NOT_PRESSED 255

#define KEYPAD_DEBOUNCING_DELAY_ms 30
#endif /* INCLUDE_HAL_KEYPAD_KEYPAD_CFG_H_ */
