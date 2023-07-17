/*
 * DIO_Interface.h
 *
 *  Created on: May 1, 2023
 *      Author: mazen
 */

#ifndef INCLUDE_MCAL_DIO_INTERFACE_H_
#define INCLUDE_MCAL_DIO_INTERFACE_H_

typedef enum {
	DIO_INPUT=0,
	DIO_OUTPUT
}PIN_DIRECTION;

typedef enum {
	DIO_RESET=0,
	DIO_SET,
	DIO_FLOATING=0,
	DIO_PULLUP
}DIO_VALUE;

typedef enum {
	PORTA=0,
	PORTB,
	PORTC,
	PORTD
}DIO_PORTS;

typedef enum {
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
}DIO_PINS;

void MDIO_voidInit(void);
void MDIO_voidSetPinDirection(DIO_PORTS A_DIOPort, DIO_PINS A_DIOPinNo, PIN_DIRECTION A_DIOPinDirection);
void MDIO_voidSetPinValue(DIO_PORTS A_DIOPort, DIO_PINS A_DIOPinNo, DIO_VALUE A_DIOPinValue);
void MDIO_voidTogglePinValue(DIO_PORTS A_DIOPort, DIO_PINS A_DIOPinNo);
DIO_VALUE MDIO_DIO_VALUEGetPinValue(DIO_PORTS A_DIOPort, DIO_PINS A_DIOPinNo);
void MDIO_voidSetPortDirection(DIO_PORTS A_DIOPort, u8 A_PortDirection);
void MDIO_voidSetPortValue(DIO_PORTS A_DIOPort, u8 A_PortValue);

#endif /* INCLUDE_MCAL_DIO_INTERFACE_H_ */
