/*
 * DIO_program.c
 *
 *  Created on: Mar 21, 2023
 *      Author: hp
 */
#include"DIO_interface.h"
#include"../Common/Bit_Math.h"
#include"DIO_register.h"
#include"../Common/definitions.h"
#include "../Common/STD_types.h"
#include "DIO_private.h"
ErrState DIO_ErrStateSetPinDirection (DIO_GroupNumber Copy_GroupNumber,DIO_PinNumber Copy_PinNumber,DIO_DirectionState Copy_DirectionState)
{
	if(Copy_PinNumber>=Pin0 &&Copy_PinNumber<=Pin7)
	{
		if(Copy_DirectionState==DIO_Input)
		{
		switch (Copy_GroupNumber) {
			case DIO_GroupA:
						Clr_Bit(ddra,Copy_PinNumber);
						break;
			case DIO_GroupB:
						Clr_Bit(ddrb,Copy_PinNumber);
						break;
			case DIO_GroupC:
						Clr_Bit(ddrc,Copy_PinNumber);
						break;
			case DIO_GroupD:
						Clr_Bit(ddrd,Copy_PinNumber);
						break;
			default:
				return GroupError;
				break;
		}
		}

		else if(Copy_DirectionState==DIO_Output)
			{
			switch (Copy_GroupNumber) {
				case DIO_GroupA:
							Set_Bit(ddra,Copy_PinNumber);
							break;
				case DIO_GroupB:
							Set_Bit(ddrb,Copy_PinNumber);
							break;
				case DIO_GroupC:
							Set_Bit(ddrc,Copy_PinNumber);
							break;
				case DIO_GroupD:
							Set_Bit(ddrd,Copy_PinNumber);
							break;
				default:
					return GroupError;
					break;
			}
			}
			else
			{
				return DirectionError;
			}
			return NoError;
	}
	return PinNumberError;
}

ErrState DIO_ErrStateSetGroupDirection (DIO_GroupNumber Copy_GroupNumber,DIO_DirectionState Copy_DirectionState)
{
if (Copy_DirectionState<=0xff &&Copy_DirectionState>=0x00)
{
	switch(Copy_GroupNumber)
	{
	case DIO_GroupA: ddra=Copy_DirectionState; break;
	case DIO_GroupB: ddrb=Copy_DirectionState; break;
	case DIO_GroupC: ddrc=Copy_DirectionState; break;
	case DIO_GroupD: ddrd=Copy_DirectionState; break;
	default:
		return GroupError;
	}
	return NoError;
}
else
{
	return DirectionRangError;
}


}


ErrState DIO_ErrStateSetPinValue (DIO_GroupNumber Copy_GroupNumber,DIO_PinNumber Copy_PinNumber,  DIO_ValueState Copy_ValueState)
{
	if(Copy_PinNumber>=Pin0 &&Copy_PinNumber<=Pin7)
		{
			if(Copy_ValueState==DIO_Low)
			{
			switch (Copy_GroupNumber) {
				case DIO_GroupA:
							Clr_Bit(porta,Copy_PinNumber);
							break;
				case DIO_GroupB:
							Clr_Bit(portb,Copy_PinNumber);
							break;
				case DIO_GroupC:
							Clr_Bit(portc,Copy_PinNumber);
							break;
				case DIO_GroupD:
							Clr_Bit(portd,Copy_PinNumber);
							break;
				default:
					return GroupError;
					break;
			}
			}

			else if(Copy_ValueState==DIO_High)
				{
				switch (Copy_GroupNumber) {
					case DIO_GroupA:
								Set_Bit(porta,Copy_PinNumber);
								break;
					case DIO_GroupB:
								Set_Bit(portb,Copy_PinNumber);
								break;
					case DIO_GroupC:
								Set_Bit(portc,Copy_PinNumber);
								break;
					case DIO_GroupD:
								Set_Bit(portd,Copy_PinNumber);
								break;
					default:
						return GroupError;
						break;
				}
				}
				else
				{
					return ValueError;
				}
				return NoError;
		}
		return PinNumberError;
}

ErrState DIO_ErrStateSetGroupValue (DIO_GroupNumber Copy_GroupNumber,DIO_ValueState Copy_ValueState)
{
	if (Copy_ValueState<=0xff &&Copy_ValueState>=0x00)
	{
		switch(Copy_GroupNumber)
		{
		case DIO_GroupA: porta=Copy_ValueState; break;
		case DIO_GroupB: portb=Copy_ValueState; break;
		case DIO_GroupC: portc=Copy_ValueState; break;
		case DIO_GroupD: portd=Copy_ValueState; break;
		default:
			return GroupError;
		}
		return NoError;
	}
	else
	{
		return ValueRangError;
	}
}

ErrState DIO_ErrStateReadPinValue (DIO_GroupNumber Copy_GroupNumber,DIO_PinNumber Copy_PinNumber,  u8 *Result)
{
	if(Copy_PinNumber>=Pin0 &&Copy_PinNumber<=Pin7)
			{
				switch (Copy_GroupNumber) {
					case DIO_GroupA:
								*Result=Get_Bit(pina,Copy_PinNumber);
								break;
					case DIO_GroupB:
						*Result=Get_Bit(pinb,Copy_PinNumber);
								break;
					case DIO_GroupC:
						*Result=Get_Bit(pinc,Copy_PinNumber);
								break;
					case DIO_GroupD:
						*Result=Get_Bit(pind,Copy_PinNumber);
								break;
					default:
						return GroupError;
						break;
				}
				return NoError;
			}
	else
	{
		return PinNumberError;
	}

}

ErrState DIO_ErrStateReadGroupValue (DIO_GroupNumber Copy_GroupNumber,u8 *Result)
{

	if (Result!=Null)
			{
				switch (Copy_GroupNumber) {
					case DIO_GroupA:
						*Result=pina;
								break;
					case DIO_GroupB:
						*Result=pinb;
								break;
					case DIO_GroupC:
						*Result=pinc;
								break;
					case DIO_GroupD:
						*Result=pind;
								break;
					default:
						return GroupError;
						break;
				}
				return NoError;
			}
	else
	{
		return AddressError;
	}

}
