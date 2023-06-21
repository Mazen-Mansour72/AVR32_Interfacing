/*
 * SSD_Interface.h
 *
 *  Created on: May 6, 2023
 *      Author: mazen
 */

#ifndef INCLUDE_HAL_SSD_SSD_INTERFACE_H_
#define INCLUDE_HAL_SSD_SSD_INTERFACE_H_

void HSSD_voidDisplayNumber (DIO_PORTS A_DIOPORT, u8 A_u8Number);
void HSSD_voidDisplayNumberAscending (DIO_PORTS A_DIOPORT, u16 A_u16DelayinMS);
void HSSD_voidDisplayNumberDescending (DIO_PORTS A_DIOPORT, u16 A_u16DelayinMS);

#endif /* INCLUDE_HAL_SSD_SSD_INTERFACE_H_ */
