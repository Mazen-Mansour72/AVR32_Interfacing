/*
 * DIO_Cfg.h
 *
 *  Created on: Apr 15, 2023
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_MCAL_DIO_DIO_CFG_H_
#define INCLUDE_MCAL_DIO_DIO_CFG_H_

#define DIO_CFG_INPUT 0
#define DIO_CFG_OUTPUT 1

#define DIO_CFG_LOW  0
#define DIO_CFG_HIGH 1

#define DIO_CFG_FLOATING 0
#define DIO_CFG_PULLUP   1


// DIO_CFG_OUTUT or DIO_CFG_INPUT
#define PORTA_PIN0_DIRECTION DIO_CFG_OUTPUT
#define PORTA_PIN1_DIRECTION DIO_CFG_OUTPUT
#define PORTA_PIN2_DIRECTION DIO_CFG_OUTPUT
#define PORTA_PIN3_DIRECTION DIO_CFG_OUTPUT
#define PORTA_PIN4_DIRECTION DIO_CFG_INPUT
#define PORTA_PIN5_DIRECTION DIO_CFG_INPUT
#define PORTA_PIN6_DIRECTION DIO_CFG_INPUT
#define PORTA_PIN7_DIRECTION DIO_CFG_INPUT

#define PORTB_PIN0_DIRECTION DIO_CFG_OUTPUT
#define PORTB_PIN1_DIRECTION DIO_CFG_OUTPUT
#define PORTB_PIN2_DIRECTION DIO_CFG_OUTPUT
#define PORTB_PIN3_DIRECTION DIO_CFG_OUTPUT
#define PORTB_PIN4_DIRECTION DIO_CFG_OUTPUT
#define PORTB_PIN5_DIRECTION DIO_CFG_OUTPUT
#define PORTB_PIN6_DIRECTION DIO_CFG_OUTPUT
#define PORTB_PIN7_DIRECTION DIO_CFG_OUTPUT

#define PORTC_PIN0_DIRECTION DIO_CFG_OUTPUT
#define PORTC_PIN1_DIRECTION DIO_CFG_OUTPUT
#define PORTC_PIN2_DIRECTION DIO_CFG_OUTPUT
#define PORTC_PIN3_DIRECTION DIO_CFG_INPUT
#define PORTC_PIN4_DIRECTION DIO_CFG_INPUT
#define PORTC_PIN5_DIRECTION DIO_CFG_INPUT
#define PORTC_PIN6_DIRECTION DIO_CFG_INPUT
#define PORTC_PIN7_DIRECTION DIO_CFG_OUTPUT

#define PORTD_PIN0_DIRECTION DIO_CFG_OUTPUT
#define PORTD_PIN1_DIRECTION DIO_CFG_OUTPUT
#define PORTD_PIN2_DIRECTION DIO_CFG_OUTPUT
#define PORTD_PIN3_DIRECTION DIO_CFG_OUTPUT
#define PORTD_PIN4_DIRECTION DIO_CFG_OUTPUT
#define PORTD_PIN5_DIRECTION DIO_CFG_OUTPUT
#define PORTD_PIN6_DIRECTION DIO_CFG_OUTPUT
#define PORTD_PIN7_DIRECTION DIO_CFG_OUTPUT
//------------------------------------------------------


// PIN Direction
// I/P --> DIO_CFG_LOW      or DIO_CFG_HIGH
// I/P --> DIO_CFG_FLOATING or DIO_CFG_PULLUP
#define PORTA_PIN0_VALUE DIO_CFG_HIGH
#define PORTA_PIN1_VALUE DIO_CFG_HIGH
#define PORTA_PIN2_VALUE DIO_CFG_HIGH
#define PORTA_PIN3_VALUE DIO_CFG_HIGH
#define PORTA_PIN4_VALUE DIO_CFG_PULLUP
#define PORTA_PIN5_VALUE DIO_CFG_PULLUP
#define PORTA_PIN6_VALUE DIO_CFG_PULLUP
#define PORTA_PIN7_VALUE DIO_CFG_PULLUP

#define PORTB_PIN0_VALUE DIO_CFG_LOW
#define PORTB_PIN1_VALUE DIO_CFG_LOW
#define PORTB_PIN2_VALUE DIO_CFG_LOW
#define PORTB_PIN3_VALUE DIO_CFG_LOW
#define PORTB_PIN4_VALUE DIO_CFG_LOW
#define PORTB_PIN5_VALUE DIO_CFG_LOW
#define PORTB_PIN6_VALUE DIO_CFG_LOW
#define PORTB_PIN7_VALUE DIO_CFG_LOW

#define PORTC_PIN0_VALUE DIO_CFG_LOW
#define PORTC_PIN1_VALUE DIO_CFG_LOW
#define PORTC_PIN2_VALUE DIO_CFG_LOW
#define PORTC_PIN3_VALUE DIO_CFG_FLOATING
#define PORTC_PIN4_VALUE DIO_CFG_FLOATING
#define PORTC_PIN5_VALUE DIO_CFG_FLOATING
#define PORTC_PIN6_VALUE DIO_CFG_FLOATING
#define PORTC_PIN7_VALUE DIO_CFG_LOW

#define PORTD_PIN0_VALUE DIO_CFG_LOW
#define PORTD_PIN1_VALUE DIO_CFG_LOW
#define PORTD_PIN2_VALUE DIO_CFG_LOW
#define PORTD_PIN3_VALUE DIO_CFG_LOW
#define PORTD_PIN4_VALUE DIO_CFG_LOW
#define PORTD_PIN5_VALUE DIO_CFG_LOW
#define PORTD_PIN6_VALUE DIO_CFG_LOW
#define PORTD_PIN7_VALUE DIO_CFG_LOW
#endif /* INCLUDE_MCAL_DIO_DIO_CFG_H_ */
