/*
 * UART_Interface.h
 *
 *  Created on: Jul 17, 2023
 *      Author: mazen
 */

#ifndef INCLUDE_MCAL_UART_UART_INTERFACE_H_
#define INCLUDE_MCAL_UART_UART_INTERFACE_H_

typedef enum{
	INTERRUPT_DISABLE=0,
	INTERRUPT_ENABLE
}INTERRUPT_E;

typedef enum{
	FIVE_BITS=0,
	SIX_BITS,
	SEVEN_BITS,
	EIGHT_BITS=7
}DATA_BITS_E;

void MUART_voidInit(void);
void MUART_voidSendByteSyncBlocking (u8 A_u8DataByte);
void MUART_voidSendByteSyncNonBlocking (u8 A_u8DataByte);
void MUART_voidSendStringSyncNonBlocking (u8 *A_pu8String);
void MUART_voidSendByteAsync (u8 A_u8DataByte);
u8 MUART_u8ReadByteSyncBlocking (void);
u8 MUART_u8ReadByteAsync (void);
u8 MUART_u8ReadByteSyncNonBlocking (void);

#endif /* INCLUDE_MCAL_UART_UART_INTERFACE_H_ */
