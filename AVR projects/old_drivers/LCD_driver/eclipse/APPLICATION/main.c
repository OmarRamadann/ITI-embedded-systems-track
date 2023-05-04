/*

 * main.c
 *
 *  Created on: Mar 23, 2023
 *      Author: hp
 */
#include "../MCAL/DIO_program.h"
#include"../common/definitions.h"
#include"../HAL/LCD_interface.h"
//void main()
//{
//Lcd_Info lcd1={DIO_GroupB,DIO_GroupB,DIO_GroupB,Pin2,Pin1,Pin0,DIO_GroupA};
//Lcd_VoidInit(&lcd1);

u8 KeyPad_Value[4][4]={{'A','B','C','D'},{'E','F','G','H'},{'I','J','K','L'},{'M','N','O','P'}};


u8 Rows_Number=4;
u8 Columns_Number=4;
u8 Column_Value;

void main()
{
	u8 Row;
	u8 Column;
	u8 flag=0;

	Lcd_Info lcd1={DIO_GroupB,DIO_GroupB,DIO_GroupB,Pin2,Pin1,Pin0,DIO_GroupA};
	Lcd_VoidInit(&lcd1);
	//define columns as input and rows as output
	DIO_ErrStateSetGroupDirection(DIO_GroupC, 0xf0);
	//select internal pullup &initialize rows with vcc
	DIO_ErrStateSetGroupValue(DIO_GroupC, 0xff);
	while(1)
	{
	//loop
	for(Row=0;Row<Rows_Number;Row++)
	{
		DIO_ErrStateSetPinValue(DIO_GroupC, Row+4, DIO_Low);
		for (Column=0;Column<Columns_Number;Column++)
		{

			DIO_ErrStateReadPinValue(DIO_GroupC, Column, &Column_Value);
			//read value function overwrites the value (garbage) of column_value
			if (Column_Value==DIO_Low)
			{
				//DIO_ErrStateSetPinValue(DIO_GroupC, Row+4, DIO_High);
				//return KeyPad_Value[Row][Column];
				Lcd_VoidSendChar(KeyPad_Value[Row][Column], &lcd1);
				flag=1;
				break;
			}
		}
		DIO_ErrStateSetPinValue(DIO_GroupC, Row+4, DIO_High);
		if (flag==1){break;}
	}

}
}
////while(1)
////{
//	//Lcd_VoidGoXY(&lcd1, Line1, column5);
//	//Lcd_VoidSendString("Omar Essam", &lcd1);
//	Lcd_VoidSendNumber(17, &lcd1);
////}


















///*set group A pin 7 as output*/
//	ErrState Result1= DIO_ErrStateSetPinDirection(DIO_GroupA, Pin7, DIO_Output);
///*set groupB pin3 input*/
//	ErrState Result2= DIO_ErrStateSetPinDirection(DIO_GroupB, Pin3, DIO_Input);
//	/*turn on internal resistance*/
//	DIO_ErrStateSetPinValue(DIO_GroupB, Pin3, DIO_High);
//	ErrState Result3;
//	u8 Button_State;
//	while(1)
//	{
//		if (Result2==NoError)
//		{
//	ErrState Result3=DIO_ErrStateReadPinValue(DIO_GroupB, Pin3, &Button_State);
//	if(Result3==NoError && Button_State==not_pressed)
//	{
//			DIO_ErrStateSetPinValue(DIO_GroupA, Pin7, DIO_Low);
//		}
//	else if (Result3==NoError && Button_State==pressed)
//	{
//		DIO_ErrStateSetPinValue(DIO_GroupA, Pin7, DIO_High);
//	}
//	}
//
//
//}
//}
