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


u8 KeyPad_Value[4][4]={{'A','B','C','D'},{'E','F','I','H'},{'S','J','K','L'},{'M','N','O','R'}};


u8 Rows_Number=4;
u8 Columns_Number=4;
u8 Column_Value;

void main()
{
	u8 Row;
	u8 Column;


	Lcd_Info lcd1={DIO_GroupB,DIO_GroupB,DIO_GroupB,Pin2,Pin1,Pin3,DIO_GroupA};
	Lcd_VoidInit(&lcd1);
	//define columns as input and rows as output
	DIO_ErrStateSetGroupDirection(DIO_GroupC, 0xf0);
	//select internal pullup &initialize rows with vcc
	DIO_ErrStateSetGroupValue(DIO_GroupC, 0xff);
	//DIO_ErrStateSetPinDirection(DIO_GroupD, Pin1, DIO_Input);
	//DIO_ErrStateSetPinValue(DIO_GroupD, Pin1, DIO_High);
	while(1)
	{

		//loop
			for(Row=0;Row<Rows_Number;Row++)
			{
				u8 flag=0;
				//Lcd_VoidSendString("i was here1", &lcd1);
				DIO_ErrStateSetPinValue(DIO_GroupC, Row+4, DIO_Low);
				for (Column=0;Column<Columns_Number;Column++)
				{

					DIO_ErrStateReadPinValue(DIO_GroupC, Column, &Column_Value);
					//read value function overwrites the value (garbage) of column_value
					if (Column_Value==DIO_Low)
					{
						//check bouncing effect
						_delay_ms(15);
						DIO_ErrStateReadPinValue(DIO_GroupC, Column, &Column_Value);
						if (Column_Value==DIO_Low)
						{
							flag=1;
							u8 SwitchPressed=KeyPad_Value[Row][Column];
							//prevents multiple effect for long press
							while(Column_Value==DIO_Low)
							{
								DIO_ErrStateReadPinValue(DIO_GroupC, Column, &Column_Value);
							}
							Lcd_VoidSendChar(KeyPad_Value[Row][Column], &lcd1);
							break;
						}
						
						//DIO_ErrStateSetPinValue(DIO_GroupC, Row+4, DIO_High);
						//return KeyPad_Value[Row][Column];
						
						//_delay_ms(300);
					}
				}
				DIO_ErrStateSetPinValue(DIO_GroupC, Row+4, DIO_High);

				if (flag==1){break;}
			}
		//Lcd_VoidSendChar('a', &lcd1);

}
}
