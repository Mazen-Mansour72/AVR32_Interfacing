/*
 * LED_Interface.h
 *
 *  Created on: Jun 14, 2023
 *      Author: mazen
 */

#ifndef INCLUDE_HAL_LED_LED_INTERFACE_H_
#define INCLUDE_HAL_LED_LED_INTERFACE_H_

typedef enum{
	LED_OFF=0,
	LED_ON
}LED_STATUS;

void HLED_voidSetLedStatus(DIO_PORTS A_DIOPort, DIO_PINS A_DIOPinNo, LED_STATUS A_LedStatus);
void HLED_voidToggleLedStatus(DIO_PORTS A_DIOPort, DIO_PINS A_DIOPinNo);

#endif /* INCLUDE_HAL_LED_LED_INTERFACE_H_ */
