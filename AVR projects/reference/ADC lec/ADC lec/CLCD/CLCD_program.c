/*
 * CLCD_program.c


 *
 *  Created on: Oct 11, 2022
 *      Author: abdullah
 */



#include<util\delay.h>
#include"../../SERVICES/BIT_math.h"
#include"../../SERVICES/STD_TYPES.h"
#include"../../MCAL/DIO/DIO_interface.h"

#include"CLCD_Pcfg.h"

#include"CLCD_private.h"
#include"CLCD_interface.h"

void CLCD_voidInit(void)
{

_delay_ms(50);
DIO_voidSetPinDirection(CLCD_CONTROL_PORT,CLCD_RS,DIO_OUTPUT);


DIO_voidSetPinDirection(CLCD_CONTROL_PORT,CLCD_RW,DIO_OUTPUT);

DIO_voidSetPinDirection(CLCD_CONTROL_PORT,CLCD_EN,DIO_OUTPUT);


DIO_voidSetPortDirection(CLCD_DATA_PORT,255);
//from data sheet
CLCD_SendCommand(0b00111100);
_delay_ms(1);
CLCD_SendCommand(0b00001100);
_delay_ms(1);
CLCD_SendCommand(0b00000001);
_delay_ms(2);

CLCD_SendCommand(0b00000110);
_delay_ms(2);

















}
void CLCD_voidSendData(u8 Copy_u8Number)
{

	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RS,DIO_HIGH);

		DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RW,DIO_LOW);

		DIO_voidSetPortValue(CLCD_DATA_PORT,Copy_u8Number);

		DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_EN,DIO_HIGH);
		_delay_ms(1);
		DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_EN,DIO_LOW);
		_delay_ms(1);





}
void CLCD_SendCommand(u8 Copy_u8ommand)
{

	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RS,DIO_LOW);


	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RW,DIO_LOW);

	DIO_voidSetPortValue(CLCD_DATA_PORT,Copy_u8ommand);


	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_EN,DIO_HIGH);
	_delay_ms(1);


	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_EN,DIO_LOW);
	_delay_ms(1);


}
void CLCD_voidSendNumber(u32 Copy_u64Number)
{
 u32 reverse= 0 ;
u8 count=0;//this counter is for the case of 1000 for example
 if(Copy_u64Number==0)
 {
	 CLCD_voidSendData('0');




 }
 else if(Copy_u64Number<=9)

 {

	 CLCD_voidSendData(Copy_u64Number+48);



 }

 else{

 while(Copy_u64Number!=0)//delete the zeros on the left
 {
	 reverse= (reverse*10)+(Copy_u64Number%10) ;
	 if(reverse==0)
	 {

		 count++;

	 }
	 Copy_u64Number=Copy_u64Number/10;




 }

 while(reverse!=0)
 {
	 u8 reminder=reverse%10;
	 CLCD_voidSendData(reminder+48);// for the ASCII code of the number

	 reverse=reverse/10;
 }

 while(count!=0)
 {
	 CLCD_voidSendData('0');
	 count--;


 }


 }



}
void CLCD_voidSendString(u8* ptr)
{
	u8 i=0 ;
	while(ptr[i]!='\0') ////refers to a null character that is created automaically in the memeory after the strings

	{
		CLCD_voidSendData(ptr[i]);
		i++;




	}


}
void CLCD_voidSetPosition(u8 Copy_u8Row, u8 Copy_u8Col)
{

	if(Copy_u8Row==CLCD_ROW1)

	{
		CLCD_SendCommand(0x80+Copy_u8Col); //Set CG ram address in page 19


	}
	else if(Copy_u8Row==CLCD_ROW2)
	{
		CLCD_SendCommand(0x80+64+Copy_u8Col);



	}




}


void CLCD_voidSendExtraCharAndDiplay(u8*ptr,u8 Copy_u8NumberOfChar,u8 Copy_u8row, u8 Copy_u8Col)

{
//Copy_u8size is the number of characters
CLCD_SendCommand(0b01000000); //set pointer at CG ram



   for(u8 i=0;i<Copy_u8NumberOfChar*8;i++)
    {
	//dad

	CLCD_voidSendData(ptr[i]);




      }

CLCD_voidSetPosition(Copy_u8row,Copy_u8Col);//to set the pointer of LCD processor to DD RAM


     for(s8 i=(Copy_u8NumberOfChar-1);i<=0;i--)
      {

	// you can reverse the order if the char are not arabic
	CLCD_voidSendData(i);// sending the address of CG ram  to DD ram to fetch it from the CG ram


      }
}








void CLCD_voidClearDisplay(void)
	{


	CLCD_SendCommand(0b00000001);


	}



void CLCD_voidSendFloatNumber(f32 number)
{

	f32 check=-1*number;
	if(check>0)
	{


		CLCD_voidSendData('-');
		number=number*-1;
	}


	u32 intpart=number; //casting
	CLCD_voidSendNumber(intpart);
u32 decpart;

	//f32 number3=number2;
	decpart=(number-(f32)intpart)*10000;//decimal part
	//decpart=decpart*10000;
	CLCD_voidSendData('.');
	CLCD_voidSendNumber(decpart);






}















