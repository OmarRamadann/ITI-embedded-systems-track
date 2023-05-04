/*

 * main.c
 *
 *  Created on: Mar 26, 2023
 *      Author: hp
 */

#include "../MCAL/DIO_program.h"
#include"../common/definitions.h"

void main(){
	u8 Switch_Value;
	DIO_ErrStateSetPinDirection(DIO_GroupA, Pin0, DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupA, Pin1, DIO_Input);
	//internal pull up
	DIO_ErrStateSetPinValue(DIO_GroupA, Pin1, DIO_High);
	DIO_ErrStateReadPinValue(DIO_GroupA, Pin1, &Switch_Value);
	if (Switch_Value==0)
	{
	DIO_ErrStateSetPinValue(DIO_GroupA, Pin0, DIO_High);
	}
}
