/*

 * main.c
 *
 *  Created on: Mar 23, 2023
 *      Author: hp
 */
#include "../MCAL/DIO_program.h"
#include"../common/definitions.h"
char KeyPad_Value[4][4]={{'A','B','C','D'},{'E','F','G','H'},{'I','J','K','L'},{'M','N','O','O'}};

u8 Row;
u8 Column;
u8 Rows_Number=4;
u8 Columns_Number=4;
u8 Column_Value=8;
int main()
{
	//define columns as input and rows as output
	DIO_ErrStateSetGroupDirection(DIO_GroupC, 0xf0);
	//select internal pullup &initialize rows with vcc
	DIO_ErrStateSetGroupValue(DIO_GroupC, 0xff);
	//loop
	for(Row=0;Row<Rows_Number;Row++)
	{
		DIO_ErrStateSetPinValue(DIO_GroupC, Row+4, DIO_Low);
		for (Column=0;Column<Columns_Number;Column++)
		{

			DIO_ErrStateReadPinValue(DIO_GroupC, Column, &Column_Value);
			if (Column_Value==DIO_Low)
			{
				DIO_ErrStateSetPinValue(DIO_GroupC, Row+4, DIO_High);
				return KeyPad_Value[Row][Column];
			}
		}
		DIO_ErrStateSetPinValue(DIO_GroupC, Row+4, DIO_High);
	}

}
