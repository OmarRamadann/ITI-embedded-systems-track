/*
 * DIO_program.c
 *
 *  Created on: Oct 4, 2022
 *      Author: abdullah
 */
#include "../../SERVICES/BIT_math.h"
#include "../../SERVICES/STD_TYPES.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_Pcfg.h"

void DIO_voidSetPortDirection(u8 Copyu8_port, u8 Copy_u8Direction )
{
 switch (Copyu8_port)
 {

 case DIO_PORTA :
	 DDRA=Copy_u8Direction;

	 break;
 case DIO_PORTB :

	 DDRB=Copy_u8Direction;



 break;
 case DIO_PORTC:

	 DDRC=Copy_u8Direction;





	 break;
 case DIO_PORTD :
	 DDRD=Copy_u8Direction;

 break;

 default:
 		break;


 }



}

void DIO_voidSetPinDirection (u8 Copyu8_port,  u8 Copyu8_pin , u8 Copyu8_Direction)
{


switch (Copyu8_port)

{


case DIO_PORTA:



if(Copyu8_Direction==DIO_OUTPUT)
{
	SET_BIT(DDRA, Copyu8_pin);



}
else if(Copyu8_Direction==DIO_INPUT)
{


	CLR_BIT(DDRA,Copyu8_pin);

}
break;

case DIO_PORTB :

	if(Copyu8_Direction==DIO_OUTPUT)
	{
		SET_BIT(DDRB, Copyu8_pin);



	}
	else if(Copyu8_Direction==DIO_INPUT)
	{


		CLR_BIT(DDRB,Copyu8_pin);

	}


break;

case DIO_PORTC :

	if(Copyu8_Direction==DIO_OUTPUT)
	{
		SET_BIT(DDRC, Copyu8_pin);



	}
	else if(Copyu8_Direction==DIO_INPUT)
	{


		CLR_BIT(DDRC,Copyu8_pin);

	}

	break;


case DIO_PORTD :

	if(Copyu8_Direction==DIO_OUTPUT)
	{
		SET_BIT(DDRD, Copyu8_pin);



	}
	else if(Copyu8_Direction==DIO_INPUT)
	{


		CLR_BIT(DDRD,Copyu8_pin);

	}


	break;

default:
		break;

}
















}
void DIO_voidSetPinValue(u8 Copyu8_port,u8 Copyu8_Pin, u8 Copyu8_value)
{
	switch ( Copyu8_port)
	{

	case DIO_PORTA:

		if(Copyu8_value==DIO_HIGH)
		{
			SET_BIT(PORTA,Copyu8_Pin);

		}
		else if (Copyu8_value==DIO_LOW)
		{

			CLR_BIT(PORTA,Copyu8_Pin);

		}




		break;
	case DIO_PORTB:

		if(Copyu8_value==DIO_HIGH)
			{
				SET_BIT(PORTB,Copyu8_Pin);

			}
			else if (Copyu8_value==DIO_LOW)
			{

				CLR_BIT(PORTB,Copyu8_Pin);

			}
			break;
	case DIO_PORTC:

		if(Copyu8_value==DIO_HIGH)
			{
				SET_BIT(PORTC,Copyu8_Pin);

			}
			else if (Copyu8_value==DIO_LOW)
			{

				CLR_BIT(PORTC,Copyu8_Pin);

			}


			break;
	case DIO_PORTD:

		if(Copyu8_value==DIO_HIGH)
			{
				SET_BIT(PORTD,Copyu8_Pin);

			}
			else if (Copyu8_value==DIO_LOW)
			{

				CLR_BIT(PORTD,Copyu8_Pin);

			}
			break;
	default:
			break;





	}




}
void DIO_voidSetPortValue(u8 Copyu8_Port, u8 Copyu8Value)
{


	switch (Copyu8_Port)
	{

	case DIO_PORTA:
		PORTA=Copyu8Value;
		break;
	case DIO_PORTB:
			PORTB=Copyu8Value;
			break;
	case DIO_PORTC:
			PORTC=Copyu8Value;
			break;
	case DIO_PORTD:
			PORTD=Copyu8Value;
			break;

	default:
			break;



	}





}
u8 DIO_u8GetPortValue(u8 Copyu8_port)
{
	u8 LOC_u8Portvalue; /* we use a local variable bec. mesra rule
	says do not use more than one return*/

	switch (Copyu8_port)
		{

		case DIO_PORTA:
			 LOC_u8Portvalue=PINA;
			break;
		case DIO_PORTB:
				LOC_u8Portvalue=PINB;
				break;
		case DIO_PORTC:
				LOC_u8Portvalue=PINC;
				break;
		case DIO_PORTD:
				LOC_u8Portvalue=PIND;
				break;

		default:
				break;
		}
return LOC_u8Portvalue;



}
u8 DIO_u8GetPinValue(u8 Copyu8_port, u8 Copyu8_Pin)
{
	u8 LOC_u8PinValue;
	switch (Copyu8_port)
			{

			case DIO_PORTA:
				 LOC_u8PinValue=GET_BIT(PINA,Copyu8_Pin);
				break;
			case DIO_PORTB:
				 LOC_u8PinValue=GET_BIT(PINB,Copyu8_Pin);
					break;
			case DIO_PORTC:
				 LOC_u8PinValue=GET_BIT(PINC,Copyu8_Pin);
					break;
			case DIO_PORTD:
				 LOC_u8PinValue=GET_BIT(PIND,Copyu8_Pin);
					break;
			default:
					break;
			}

return LOC_u8PinValue;


}

void DIO_voidtogglePIN(u8 copy_u8port,u8 copy_u8pin)
{
	if(copy_u8port==DIO_PORTA)
	{

		TOG_BIT(PORTA,copy_u8pin);

	}
	else if(copy_u8port==DIO_PORTB)
		{

			TOG_BIT(PORTB,copy_u8pin);

		}
	else if(copy_u8port==DIO_PORTC)
		{

			TOG_BIT(PORTC,copy_u8pin);

		}
	else if(copy_u8port==DIO_PORTD)
		{

			TOG_BIT(PORTD,copy_u8pin);

		}



}




