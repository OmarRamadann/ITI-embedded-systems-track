#include "../../MCAL/DIO/DIO_interface.h"
#include"../../common/definitions.h"
#include "DIO_App.h"
#include<stdio.h>


void DIO_test()
{
/*set group A pin 7 as output*/
	ErrState Result1= DIO_ErrStateSetPinDirection(DIO_GroupA, Pin7, DIO_Output);
	printf("pin7 output\n");
/*set groupB pin3 input*/
	ErrState Result2= DIO_ErrStateSetPinDirection(DIO_GroupB, Pin3, DIO_Input);
	printf("pin3 output\n");

	/*turn on internal resistance*/
	DIO_ErrStateSetPinValue(DIO_GroupB, Pin3, DIO_High);
	ErrState Result3;
	u8 Button_State;
	//while(1)
	//{
		if (Result2==NoError)
		{
	ErrState Result3=DIO_ErrStateReadPinValue(DIO_GroupB, Pin3, &Button_State);
	if(Result3==NoError && Button_State==not_pressed)
	{
			DIO_ErrStateSetPinValue(DIO_GroupA, Pin7, DIO_Low);
		}
	else if (Result3==NoError && Button_State==pressed)
	{
		DIO_ErrStateSetPinValue(DIO_GroupA, Pin7, DIO_High);
	}
	//}


}
}
