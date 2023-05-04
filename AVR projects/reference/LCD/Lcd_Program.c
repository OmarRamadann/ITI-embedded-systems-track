/*
 * Lcd_Program.c
 *
 *  Created on: Mar 25, 2023
 *      Author: hisha
 */

#include <util/delay.h>
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Lcd_Interface.h"


void Lcd_VoidSendCommand(u8 Copy_Command, Lcd_Info * Lcd)
{
	/*RS->LOW*/
	DIO_ErrStateSetPinValue(Lcd->RS_Group , Lcd->RS_Pin , DIO_Low);
	/*RW-> LOW*/
	DIO_ErrStateSetPinValue(Lcd->RW_Group , Lcd-> RW_Pin , DIO_Low) ;
	/*Group = COmmand */
	DIO_ErrStateSetGroupValue(Lcd->Data_Group , Copy_Command) ;
	/*Enable*/
	DIO_ErrStateSetPinValue(Lcd->E_Group , Lcd-> E_Pin , DIO_High) ;
	_delay_ms(1);
	DIO_ErrStateSetPinValue(Lcd->E_Group , Lcd-> E_Pin , DIO_Low) ;
	_delay_ms(1);
}
void Lcd_VoidSendChar(u8 Copy_Char, Lcd_Info * Lcd)
{
	/*RS->High*/
	DIO_ErrStateSetPinValue(Lcd->RS_Group , Lcd->RS_Pin , DIO_High);
	/*RW-> LOW*/
	DIO_ErrStateSetPinValue(Lcd->RW_Group , Lcd-> RW_Pin , DIO_Low) ;
	/*Group = COmmand */
	DIO_ErrStateSetGroupValue(Lcd->Data_Group , Copy_Char) ;
	/*Enable*/
	DIO_ErrStateSetPinValue(Lcd->E_Group , Lcd-> E_Pin , DIO_High) ;
	_delay_ms(1);
	DIO_ErrStateSetPinValue(Lcd->E_Group , Lcd-> E_Pin , DIO_Low) ;
	_delay_ms(1);
}

void Lcd_VoidInit(Lcd_Info * Lcd)
{
	/*Set Directions*/
	DIO_ErrStateSetPinDirection(Lcd->RS_Group,Lcd->RS_Pin,DIO_Output);
	DIO_ErrStateSetPinDirection(Lcd->RW_Group,Lcd->RW_Pin,DIO_Output);
	DIO_ErrStateSetPinDirection(Lcd->E_Group,Lcd->E_Pin,DIO_Output);
	DIO_ErrStateSetGroupDirection(Lcd->Data_Group,0xFF);
	/*Wait More than 30 ms */
	_delay_ms(40);
	/*Sent Function Set*/
	Lcd_VoidSendCommand(LCD_Set8Bit2Line5x8,Lcd) ;
	/*wait more than 39us*/
	_delay_ms(1);
	/*Sent Displayon/off*/
	Lcd_VoidSendCommand(LCD_CursorON,Lcd) ;
	/*wait more than 39us*/
	_delay_ms(1);
	/*Sent Clear*/
	Lcd_VoidSendCommand(LCD_ClearDisplay,Lcd) ;
	/*wait more than 39us*/
	_delay_ms(2);

}

void Lcd_VoidSendString(u8 *Address_String ,Lcd_Info * Lcd)
{
	/*Counter For Loop */
	u8 Local_Counter = 0 ;
	/*Loop*/
	while (Address_String[Local_Counter]!='\0')
	{
		/*Send Char */
		Lcd_VoidSendChar(Address_String[Local_Counter],Lcd) ;
		/*Increment Counter */
		Local_Counter++;
	}
}

void Lcd_VoidGoXY(Lcd_Info * Lcd ,u8 Copy_XLocation ,u8 Copy_YLocation )
{
	u8 Local_Address = 0 ;
	if (Copy_XLocation == 0)
	{
		Local_Address = Copy_YLocation ;
	}
	else if (Copy_XLocation == 1)
	{
		Local_Address = Copy_YLocation + LCD_SecondLine ;
	}
	else
	{

	}
	Lcd_VoidSendCommand((LCD_SetAddressDDRAM + Local_Address),Lcd);
}
