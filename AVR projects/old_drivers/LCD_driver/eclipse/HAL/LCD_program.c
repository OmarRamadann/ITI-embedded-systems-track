
#include"LCD_Register.h"
#include "../MCAL/DIO_program.h"
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
	//RS->Low(command)
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
