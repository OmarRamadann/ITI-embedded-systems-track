#include <stdlib.h>
//#include <avr/io.h>
#include"LCD_Register.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_interface.h"
#include<util/delay.h>


void Lcd_VoidSendCommand (u8 Copy_Command,Lcd_Info *Lcd)
{
	//RS->Low(command)
	DIO_ErrStateSetPinValue(Lcd->RS_Group, Lcd->RS_Pin, DIO_Low);
	//RW->Low(write)
	DIO_ErrStateSetPinValue(Lcd->RW_Group, Lcd->RW_Pin, DIO_Low);
	//group command
	DIO_ErrStateSetGroupValue(Lcd->Data_Group,Copy_Command);
	//enable
	DIO_ErrStateSetPinValue(Lcd->E_Group, Lcd->E_Pin, DIO_High);
	_delay_ms(1);
	DIO_ErrStateSetPinValue(Lcd->E_Group, Lcd->E_Pin, DIO_Low);
	_delay_ms(1);
}

void Lcd_VoidSendChar (u8 Copy_Char,Lcd_Info *Lcd)
{
	//RS->High(Data)
	DIO_ErrStateSetPinValue(Lcd->RS_Group, Lcd->RS_Pin, DIO_High);
	//RW->Low(write)
	DIO_ErrStateSetPinValue(Lcd->RW_Group, Lcd->RW_Pin, DIO_Low);
	//group command
	DIO_ErrStateSetGroupValue(Lcd->Data_Group,Copy_Char);
	//enable
	DIO_ErrStateSetPinValue(Lcd->E_Group, Lcd->E_Pin, DIO_High);
	_delay_ms(1);
	DIO_ErrStateSetPinValue(Lcd->E_Group, Lcd->E_Pin, DIO_Low);
	_delay_ms(1);
}


void Lcd_VoidInit(Lcd_Info *Lcd)
{

	//set direction
	DIO_ErrStateSetPinDirection(Lcd->RS_Group, Lcd->RS_Pin, DIO_Output);
	DIO_ErrStateSetPinDirection(Lcd->RW_Group, Lcd->RW_Pin, DIO_Output);
	DIO_ErrStateSetPinDirection(Lcd->E_Group, Lcd->E_Pin, DIO_Output);
	DIO_ErrStateSetGroupDirection(Lcd->Data_Group, 0xff);
	//wait more than 30ms
	_delay_ms(40);
	//send function set
	Lcd_VoidSendCommand(LCD_Set8Bit2Line5x8, Lcd);
	//wait more than 39 us
	_delay_ms(1);
	//sent display on/off
	Lcd_VoidSendCommand(LCD_CursorON, Lcd);
	//wait more than 39 us
	_delay_ms(1);
	//send clear
	Lcd_VoidSendCommand(LCD_ClearDisplay, Lcd);
	//wait more than 39 us
		_delay_ms(2);

}

void Lcd_VoidSendString(u8*Address_String, Lcd_Info* Lcd)
{
	//counter for loop
	u8 Local_Counter=0;

	//loop
			while(Address_String[Local_Counter]!='\0')
			{
				//send char
				Lcd_VoidSendChar(Address_String[Local_Counter], Lcd);
				Local_Counter++;

			}
}


LcdError Lcd_VoidGoXY(Lcd_Info *Lcd,u8 Copy_XLocation,u8 Copy_YLocation)
{
	u8 Local_Address=0;
			if (Copy_XLocation==0)
			{
				Local_Address= Copy_YLocation;

			}
			else if (Copy_XLocation==1)
			{
				Local_Address=Copy_YLocation+0x40;
			}
			else
			{
				//error handling
				return LocationError;
			}
	Lcd_VoidSendCommand(LCD_SetAddressDDRAM +Local_Address , Lcd);
	return NoLcdError;
}


//void Lcd_VoidSendNumber(u8 Copy_Number,Lcd_Info *Lcd)//to do
//{
////	u8 units=0;
////	u8 tens=0;
//	u8 num[2];
//	if (Copy_Number>=10 && Copy_Number<100)
//			{
//		num[1]=Copy_Number%10;
//		num[0]=Copy_Number/10;
//			//RS->Low(command)
//					DIO_ErrStateSetPinValue(Lcd->RS_Group, Lcd->RS_Pin, DIO_High);
//					//RW->Low(write)
//					DIO_ErrStateSetPinValue(Lcd->RW_Group, Lcd->RW_Pin, DIO_Low);
//					//group command
//					//enable
//					DIO_ErrStateSetPinValue(Lcd->E_Group, Lcd->E_Pin, DIO_High);
//					_delay_ms(1);
//					DIO_ErrStateSetPinValue(Lcd->E_Group, Lcd->E_Pin, DIO_Low);
//					_delay_ms(1);
//
//				DIO_ErrStateSetGroupValue(Lcd->Data_Group,num[0]+48);
//				Lcd_VoidGoXY(Lcd, Line0, &num[0]+1);
//				DIO_ErrStateSetGroupValue(Lcd->Data_Group,num[1]+48);
//				//DIO_ErrStateSetGroupValue(Lcd->Data_Group,num[i]+48);
//
//			}
//
//
//}

void Lcd_VoidSendNumber(u8 Copy_Number,Lcd_Info *Lcd)
{
u8 Num_String[8];
//itoa(Copy_Number, Num_String, 10);
dtostrf(Copy_Number, 0, 0, Num_String);
Lcd_VoidSendString(Num_String, Lcd);

}

void Lcd_VoidStoreSpecialCharacter(u16 Copy_SpecChar[][7],CGRAM_Write_Addr write_Addr,u8 No_of_Characters,Lcd_Info*Lcd)
{
	u8 No_of_Rows=7;
	for(u16 i=0;i<No_of_Characters;i++)
		{
	//go to location write of CGRAM
	Lcd_VoidSendCommand(LCD_SetAddressCGRAM +(write_Addr*(8)) , Lcd);
	//write to it special character
	//Arabic special character
	/* here we fill the 8 bytes of the 8  special characters*/

		for(u16 j=0;j<No_of_Rows;j++)//Rows of  each place on screen
			{
			//Lcd_VoidSendChar(0, Lcd);
			Lcd_VoidSendChar(Copy_SpecChar[i][j], Lcd);

			}

		write_Addr++; //increment address in CGRAM
		}


//those are the 8*8 or 5*8 pixels of each location in the CGRAM in the LCD
//	Lcd_VoidSendChar(0, Lcd);
//	Lcd_VoidSendChar(1, Lcd);
//	Lcd_VoidSendChar(1, Lcd);
//	Lcd_VoidSendChar(1, Lcd);
//	Lcd_VoidSendChar(2, Lcd);
//	Lcd_VoidSendChar(2, Lcd);
//	Lcd_VoidSendChar(12, Lcd);


}


void Lcd_DisplaySpecialCharacter(CGRAM_Read_Addr read,u8 Select_Char,Lcd_Info*Lcd)
{

	//go to location read of DDRAM
		Lcd_VoidSendCommand(LCD_SetAddressDDRAM +read , Lcd);
	//read from it the special char
		//print the element selected in the 8 special characters
		Lcd_VoidSendChar(Select_Char, Lcd);

			}


