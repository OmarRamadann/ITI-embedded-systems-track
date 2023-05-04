/*

 * KeyPad_program.c
 *
 *  Created on: Apr 5, 2023
 *      Author: hp
 */

#include "../../MCAL/DIO/DIO_interface.h"
//#include "KeyPad_interface.h"
#include <util/delay.h>
#include "KeyPad_private.h"
#define KeyPad_Rows  4
#define KeyPad_Columns  4
u8 KeyPad_Values[KeyPad_Rows][KeyPad_Columns]={{'T','S','I','D'},{1,2,3,4},{5,6,7,8},{9,0,'+','='}};

void KeyPad_VoidInit (KeyPad_Info* KeyPad)
{
	//  rows as output
		//DIO_ErrStateSetGroupDirection(DIO_GroupC, 0xf0);
		DIO_ErrStateSetPinDirection(KeyPad->Rows_Group, KeyPad->R1, DIO_Output);
		DIO_ErrStateSetPinDirection(KeyPad->Rows_Group, KeyPad->R2,  DIO_Output);
		DIO_ErrStateSetPinDirection(KeyPad->Rows_Group, KeyPad->R3, DIO_Output);
		DIO_ErrStateSetPinDirection(KeyPad->Rows_Group, KeyPad->R4, DIO_Output);
	//define columns as input
		DIO_ErrStateSetPinDirection(KeyPad->Columns_Group, KeyPad->C1, DIO_Input);
		DIO_ErrStateSetPinDirection(KeyPad->Columns_Group, KeyPad->C2, DIO_Input);
		DIO_ErrStateSetPinDirection(KeyPad->Columns_Group, KeyPad->C3, DIO_Input);
		DIO_ErrStateSetPinDirection(KeyPad->Columns_Group, KeyPad->C4, DIO_Input);
		//select internal pullup
		//DIO_ErrStateSetGroupValue(DIO_GroupC, 0xff);
		DIO_ErrStateSetPinValue(KeyPad->Columns_Group, KeyPad->C1, DIO_High);
		DIO_ErrStateSetPinValue(KeyPad->Columns_Group, KeyPad->C2, DIO_High);
		DIO_ErrStateSetPinValue(KeyPad->Columns_Group, KeyPad->C3, DIO_High);
		DIO_ErrStateSetPinValue(KeyPad->Columns_Group, KeyPad->C4, DIO_High);
		//initialize rows with vcc
		DIO_ErrStateSetPinValue(KeyPad->Rows_Group, KeyPad->R1, DIO_High);
		DIO_ErrStateSetPinValue(KeyPad->Rows_Group, KeyPad->R2, DIO_High);
		DIO_ErrStateSetPinValue(KeyPad->Rows_Group, KeyPad->R3, DIO_High);
		DIO_ErrStateSetPinValue(KeyPad->Rows_Group, KeyPad->R4, DIO_High);
}

   KeyPad_U8SwitchPressed(KeyPad_Info *KeyPad,KeyPad_status* Status)
{
		u8 Row=0;
		u8 Column=0;
		static u8 Switch;
		//u8 Sw=0;
		u8 Column_Value=0;
		 u8 flag=0;
		  //KeyPad_status *Status;
		//loop
		for(Row=0;Row<KeyPad_Rows;Row++)
					{
				 flag=0;
				 Status->flag=flag;

				DIO_ErrStateSetPinValue(KeyPad->Rows_Group, Row, DIO_Low);
				for (Column=0;Column<KeyPad_Columns;Column++)
				{

					DIO_ErrStateReadPinValue(KeyPad->Columns_Group, Column, &Column_Value);
					//read value function overwrites the value (garbage) of column_value
					if (Column_Value==DIO_Low)
					{
						//check bouncing effect
						_delay_ms(15);
						DIO_ErrStateReadPinValue(KeyPad->Columns_Group, Column, &Column_Value);
						if (Column_Value==DIO_Low)
						{
							//DIO_ErrStateReadPinValue(DIO_GroupC, Column, &Column_Value);
							Switch=KeyPad_Values[Row][Column];
							flag=1;
							Status->flag=flag;
							Status->Switchpressed=Switch;


						}
							while(Column_Value==DIO_Low)
								{

									DIO_ErrStateReadPinValue(KeyPad->Columns_Group, Column, &Column_Value);
								}
							//prevents multiple effect for long press
							//_delay_ms(300);

							break;
						//}

						//DIO_ErrStateSetPinValue(DIO_GroupC, Row+4, DIO_High);
						//return KeyPad_Value[Row][Column];

						//_delay_ms(300);
					}
				}
				DIO_ErrStateSetPinValue(KeyPad->Rows_Group, Row, DIO_High);

				if (flag==1){break;}
			}


		//return Status;
}
