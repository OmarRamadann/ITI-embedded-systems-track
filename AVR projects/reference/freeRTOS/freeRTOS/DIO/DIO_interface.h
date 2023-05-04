/*
 * DIO_interface.h
 *
 *  Created on: Oct 4, 2022
 *      Author: abdullah
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_
#include"../../SERVICES/BIT_math.h"
#include"../../SERVICES/STD_TYPES.h"

#define DIO_OUTPUT 0
#define DIO_INPUT  1
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0  0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7


#define DIO_HIGH   1
#define DIO_LOW    0

void DIO_voidSetPortDirection(u8 Copyu8_port, u8 Copy_u8Direction );
void DIO_voidSetPinDirection (u8 Copyu8_port,  u8 Copyu8_pin , u8 Copyu8_Direction);
void DIO_voidSetPinValue(u8 Copyu8_port,u8 Copyu8_Pin, u8 Copyu8_value);
void DIO_voidSetPortValue(u8 Copyu8_Port, u8 Copyu8Value);
u8 DIO_u8GetPortValue(u8 Copyu8_port);
u8 DIO_u8GetPinValue(u8 Copyu8_port, u8 Copyu8_Pin);
void DIO_voidtogglePIN(u8 copy_u8port,u8 copy_u8pin);

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
