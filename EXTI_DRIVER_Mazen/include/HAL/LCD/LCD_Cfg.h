/*
 * LCD_Cfg.h
 *
 *  Created on: Jun 14, 2023
 *      Author: mazen
 */

#ifndef INCLUDE_HAL_LCD_LCD_CFG_H_
#define INCLUDE_HAL_LCD_LCD_CFG_H_

#define LCD_DATA_PORT    PORTA
#define LCD_CONTROL_PORT PORTC

#define LCD_RS_PIN PIN0
#define LCD_RW_PIN PIN1
#define LCD_E_PIN  PIN2

// 8-bit => 1
// 4-bit => 0
#define LCD_DL 1

// 1 LINE  => 0
// 2 LINES => 1
#define NO_OF_LINES 1

// 5 * 7  => 0
// 5 * 10 => 1
#define CHAR_FONT 1

// ON  => 1
// OFF => 0
#define DISPLAY_ON 1

// ON  => 1
// OFF => 0
#define CURSOR_DISPLAY 1

// ON  => 1
// OFF => 0
#define CURSOR_BLINK 1

// LEFT TO RIGHT => 1
// RIGHT TO LEFT => 0
#define DATA_DIRECTION 1

// OFF => 0
// ON  => 1
#define DATA_SHIFT 0

#endif /* INCLUDE_HAL_LCD_LCD_CFG_H_ */
