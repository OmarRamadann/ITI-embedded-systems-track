/*
 * KeyPad_private.h
 *
 *  Created on: Apr 5, 2023
 *      Author: hp
 */

#ifndef HAL_KEYPAD_DRIVER_KEYPAD_PRIVATE_H_
#define HAL_KEYPAD_DRIVER_KEYPAD_PRIVATE_H_

//DIO_GroupNumber Rw_Group[4]={DIO_GroupD,DIO_GroupD,DIO_GroupD,DIO_GroupD};
// DIO_PinNumber Rw[4]={Pin0,Pin1,Pin2,Pin4};
//#define KeyPad_Rows  	4
//#define KeyPad_Columns  4
//u8 KeyPad_Values[KeyPad_Rows][KeyPad_Columns]={{'T','S','I','D'},{1,2,3,4},{5,6,7,8},{9,0,'+','='}};
typedef struct
{

	DIO_GroupNumber 	Row1_Group;
	DIO_GroupNumber 	Row2_Group;
	DIO_GroupNumber 	Row3_Group;
	DIO_GroupNumber 	Row4_Group;
	DIO_GroupNumber	Columns_Group;

	DIO_PinNumber R1;
	DIO_PinNumber R2;
	DIO_PinNumber R3;
	DIO_PinNumber R4;
	DIO_PinNumber C1;
	DIO_PinNumber C2;
	DIO_PinNumber C3;
	DIO_PinNumber C4;
}KeyPad_Info;

typedef  struct
{
	u8 Switchpressed;
	 u8 flag;
}KeyPad_status;

#endif /* HAL_KEYPAD_DRIVER_KEYPAD_PRIVATE_H_ */
