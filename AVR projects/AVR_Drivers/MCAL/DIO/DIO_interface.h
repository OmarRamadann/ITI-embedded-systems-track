/*
 * DIO_program.h
 *
 *  Created on: Mar 21, 2023
 *      Author: hp
 */
//decleration of functions in c

#ifndef MCAL_DIO_PROGRAM_H_
#define MCAL_DIO_PROGRAM_H_
#include"DIO_private.h"
#include"../../Common/STD_types.h"


ErrState DIO_ErrStateSetPinDirection (DIO_GroupNumber Copy_GroupNumber,DIO_PinNumber Copy_PinNumber,DIO_DirectionState Copy_DirectionState);
ErrState DIO_ErrStateSetGroupDirection (DIO_GroupNumber Copy_GroupNumber,DIO_DirectionState Copy_DirectionState);

ErrState DIO_ErrStateSetPinValue (DIO_GroupNumber Copy_GroupNumber,DIO_PinNumber Copy_PinNumber,  DIO_ValueState Copy_ValueState);
ErrState DIO_ErrStateSetGroupValue (DIO_GroupNumber Copy_GroupNumber,DIO_ValueState Copy_ValueState);

ErrState DIO_ErrStateReadPinValue (DIO_GroupNumber Copy_GroupNumber,DIO_PinNumber Copy_PinNumber,  u8 *Result);
ErrState DIO_ErrStateReadGroupValue (DIO_GroupNumber Copy_GroupNumber,u8 *Result);

#endif /* MCAL_DIO_PROGRAM_H_ */
