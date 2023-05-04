/*

 * main.c
 *
 *  Created on: Mar 23, 2023
 *      Author: hp
 */
#include "../MCAL/DIO/DIO_interface.h"
#include"../common/definitions.h"
#include"../HAL/LCD_Driver/LCD_interface.h"
#include<util/delay.h>

void main(){
	u8 Switch_Value;
	DIO_ErrStateSetPinDirection(DIO_GroupD, Pin5, DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupD, Pin6, DIO_Input);
	//internal pull up
	DIO_ErrStateSetPinValue(DIO_GroupD, Pin6, DIO_High);
	while(1)
	{
	DIO_ErrStateReadPinValue(DIO_GroupD, Pin6, &Switch_Value);
	if (Switch_Value==0)
	{
	DIO_ErrStateSetPinValue(DIO_GroupD, Pin5, DIO_High);
	}
	else
	{
		DIO_ErrStateSetPinValue(DIO_GroupD, Pin5, DIO_Low);

	}
}
}
