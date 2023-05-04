/*
 * DIO_private.h
 *
 *  Created on: Mar 21, 2023
 *      Author: hp
 */
//write any thing we dont other modules to use it
//the member here (func.,object,..)specific for DIO model
#ifndef MCAL_DIO_PRIVATE_H_
#define MCAL_DIO_PRIVATE_H_
typedef enum
{
	NoError,
	GroupError,
	PinNumberError,
	DirectionError,
	DirectionRangError,
	AddressError,
	ValueError,
	ValueRangError

}ErrState;

typedef enum
{
	DIO_Input,
	DIO_Output
}DIO_DirectionState ;


typedef enum
{
	DIO_Low,
	DIO_High
}DIO_ValueState ;


typedef enum
{
	DIO_GroupA,
	DIO_GroupB,
	DIO_GroupC,
	DIO_GroupD
}DIO_GroupNumber;


typedef enum
{
Pin0,
Pin1,
Pin2,
Pin3,
Pin4,
Pin5,
Pin6,
Pin7
}DIO_PinNumber;
#endif /* MCAL_DIO_PRIVATE_H_ */

