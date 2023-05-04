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

u16 SpecChar[2][7]={
		{0,0,1,1,2,2,12},
		{4,0,17,17,17,13,0}
};
//u16 SpecChar[7]={
//		0,0,1,1,2,2,12
//};



void main()
{
	


	Lcd_Info lcd1={DIO_GroupB,DIO_GroupB,DIO_GroupB,Pin2,Pin1,Pin0,DIO_GroupA};
	Lcd_VoidInit(&lcd1);
	
	while(1)
	{


		Lcd_VoidSendNumber(150, &lcd1);
		Lcd_VoidStoreSpecialCharacter(SpecChar, Loc_W0,2,&lcd1);

		//go to location 1 of read for CGRAM
		Lcd_DisplaySpecialCharacter(Loc_R0, 0, &lcd1);
		Lcd_DisplaySpecialCharacter(Loc_R1, 1, &lcd1);
		

}
}
