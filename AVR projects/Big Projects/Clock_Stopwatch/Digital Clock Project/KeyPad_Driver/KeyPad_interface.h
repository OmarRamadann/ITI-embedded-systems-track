/*
 * KeyPad_interface.h
 *
 *  Created on: Apr 5, 2023
 *      Author: hp
 */

#ifndef HAL_KEYPAD_DRIVER_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_DRIVER_KEYPAD_INTERFACE_H_
#include "KeyPad_private.h"
//typedef struct
//{
//	DIO_GroupNumber 	Rows_Group;
//	DIO_GroupNumber 	Columns_Group;
//
//	DIO_PinNumber R1;
//	DIO_PinNumber R2;
//	DIO_PinNumber R3;
//	DIO_PinNumber R4;
//	DIO_PinNumber C1;
//	DIO_PinNumber C2;
//	DIO_PinNumber C3;
//	DIO_PinNumber C4;
//}KeyPad_Info;
//#define KeyPad_Rows  4
//#define KeyPad_Columns  4
//u8 KeyPad_Values[KeyPad_Rows][KeyPad_Columns]={{'T','S','I','D'},{1,2,3,4},{5,6,7,8},{9,0,'+','='}};

void KeyPad_VoidInit (KeyPad_Info* KeyPad);

  KeyPad_U8SwitchPressed(KeyPad_Info *KeyPad,KeyPad_status* Status);


#endif /* HAL_KEYPAD_DRIVER_KEYPAD_INTERFACE_H_ */
