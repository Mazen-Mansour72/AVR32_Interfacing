/*
 * LCD_Private.h
 *
 *  Created on: Apr 9, 2023
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_HAL_LCD_LCD_PRIVATE_H_
#define INCLUDE_HAL_LCD_LCD_PRIVATE_H_

#define DONT_CARE_BIT 0

#define FUNCTION_SET CONC_BIT(0,0,1,LCD_DL,NO_OF_LINES,CHAR_FONT,DONT_CARE_BIT,DONT_CARE_BIT)

#define DISPLAY_ON_OFF_CONTROL CONC_BIT(0,0,0,0,1,DISPLAY_ON,CURSOR_DISPLAY,CURSOR_BLINK)

#define DISPLAY_CLEAR 1

#define ENTRY_MODE_SET CONC_BIT(0,0,0,0,0,1,DATA_DIRECTION,0)

#define LCD_ROW1_ADDRESS 127
#define LCD_ROW2_ADDRESS 191
#endif /* INCLUDE_HAL_LCD_LCD_PRIVATE_H_ */
