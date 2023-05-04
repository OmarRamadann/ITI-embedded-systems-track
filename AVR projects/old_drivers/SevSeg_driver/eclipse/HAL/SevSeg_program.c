/*
 * SevSeg_program.c
 *
 *  Created on: Mar 23, 2023
 *      Author: hisha
 */
#include "../common/definitions.h"
#include "../MCAL/DIO_program.h"
#include "SevSeg_Interface.h"

SevErrState SevSeg_SevErrStateSetNumber(u8 Copy_Number , SevSeg_info * SevenSegment1)//if we add more than one SevSeg
{
	if (SevenSegment1->SevSeg_Type==CAnode)
	{
	DIO_ErrStateSetGroupDirection(SevenSegment1->SevSeg_Group,0xff);
	DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group, SevSeg_Arr_CA[Copy_Number]);
	DIO_ErrStateSetPinDirection(SevenSegment1->SevSeg_EnablePort, SevenSegment1->SevSeg_EnablePin, DIO_Output);
	DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort, SevenSegment1->SevSeg_EnablePin, DIO_High);

	}
	else if (SevenSegment1->SevSeg_Type==CCathode)
	{
	DIO_ErrStateSetGroupDirection(SevenSegment1->SevSeg_Group,0xff);
	DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group, SevSeg_Arr_CC[Copy_Number]);
	DIO_ErrStateSetPinDirection(SevenSegment1->SevSeg_EnablePort, SevenSegment1->SevSeg_EnablePin, DIO_Output);
	DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort, SevenSegment1->SevSeg_EnablePin, DIO_Low);

	}
	else
	{
		return InitializationError;
	}
	return NoError;
}


SevErrState SevSeg_SevErrStateDisplayRange(SevSeg_info * SevenSegment1 , u8 Copy_start , u8 Copy_End )//show first and last number
{
SevSeg_SevErrStateSetNumber(Copy_start, SevenSegment1);
SevSeg_SevErrStateSetNumber(Copy_End, SevenSegment1);

}


SevErrState SevSeg_SevErrStateDisplayMax(SevSeg_info * SevenSegment1)//count from start to max
{
	SevSeg_SevErrStateSetNumber(SevSeg_ArrSize, SevenSegment1);

}
