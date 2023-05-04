/*
 * Led_Program.c
 *
 *  Created on: Mar 24, 2023
 *      Author: hisha
 */
#include "../common/definitions.h"
#include "../MCAL/DIO_program.h"
#include "Led_Interface.h"

LedErrState	Led_LedErrStateTurnOn(Led_info *Led)// takes input pointer of type struct(Led_info)
{
	if (Led->ConnectionType==Sink_Connection)
	{
		ErrState Res1=DIO_ErrStateSetPinDirection(Led->Led_Group, Led->Led_Pin,DIO_Output);
		if (Res1==NoError)
		{
			ErrState Res2=DIO_ErrStateSetPinValue(Led->Led_Group, Led->Led_Pin, DIO_Low);
		}

	}
	else if (Led->ConnectionType==Source_Connection)
	{
		ErrState Res1=DIO_ErrStateSetPinDirection(Led->Led_Group, Led->Led_Pin,DIO_Output);
		if (Res1==NoError)
		{
			ErrState Res2=DIO_ErrStateSetPinValue(Led->Led_Group, Led->Led_Pin, DIO_High);
		}

	}
	else {
		return ConnectionError;
	}
	return NoLedError;
}


LedErrState	Led_LedErrStateTurnOff(Led_info *Led)
{
	if (Led->ConnectionType==Sink_Connection)
	{
		ErrState Res1=DIO_ErrStateSetPinDirection(Led->Led_Group, Led->Led_Pin,DIO_Output);
		if (Res1==NoError)
		{
			ErrState Res2=DIO_ErrStateSetPinValue(Led->Led_Group, Led->Led_Pin, DIO_High);
		}

	}
	else if (Led->ConnectionType==Source_Connection)
	{
		ErrState Res1=DIO_ErrStateSetPinDirection(Led->Led_Group, Led->Led_Pin,DIO_Output);
		if (Res1==NoError)
		{
			ErrState Res2=DIO_ErrStateSetPinValue(Led->Led_Group, Led->Led_Pin, DIO_Low);
		}

	}
	else {
		return ConnectionError;
	}
return NoLedError;
}


