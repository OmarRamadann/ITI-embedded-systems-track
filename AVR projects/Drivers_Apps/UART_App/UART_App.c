

#include "../MCAL/DIO/DIO_interface.h"

#include"../common/definitions.h"
#include "../HAL/KeyPad_Driver/KeyPad_interface.h"
#include"../HAL/LCD_Driver/LCD_interface.h"
#include "../MCAL/DIO/DIO_register.h"
#include "../MCAL/Timers/Timer0/Timer0_interface.h"
#include "../HAL/Led_Driver/Led_Configuration.h"
#include "../Common/Bit_Math.h"
#include "../MCAL/Timers/Timer0/Timer0_register.h"
//#include "../HAL/KeyPad_Driver/KeyPad_private.h"

#include<util/delay.h>

#define UCSRA  *((volatile u8*)0x2B )
#define UCSRB  *((volatile u8*)0x2A )
#define UCSRC  *((volatile u8*)0x40 )
#define UBRRL  *((volatile u8*)0x29 )
#define UBRRH  *((volatile u8*)0x40 )
#define UDR  *((volatile u8*)0x2C )
void UART_voidInit(void);
u8 UART_u8Receive(void);
void UART_voidSend(u8 msg);

void main()
{
DIO_ErrStateSetPinDirection(DIO_GroupD, Pin0, DIO_Input);
DIO_ErrStateSetPinDirection(DIO_GroupD, Pin1, DIO_Output);
DIO_ErrStateSetPinDirection(DIO_GroupD, Pin2, DIO_Output);
DIO_ErrStateSetPinDirection(DIO_GroupD, Pin3, DIO_Output);

u8 msg;
while(1)
{
	UART_voidInit() ;

	msg=UART_u8Receive();
	if (msg=='a')
	{
		DIO_ErrStateSetPinValue(DIO_GroupD, Pin2, DIO_High);
		_delay_ms(1000);
	}
	else if(msg=='b')
	{
		DIO_ErrStateSetPinValue(DIO_GroupD, Pin2, DIO_Low);
				_delay_ms(1000);
	}

	UART_voidSend('s');
		_delay_us(1000);
}
}
void UART_voidInit(void)
{
		UCSRA=0b00000000;
		UCSRB=0b00011000;
		UCSRC=0b10000110;
			UBRRL=51;
			UBRRH=0;
}
void UART_voidSend(u8 msg)
{
	//Clr_Bit(UCSRC,7);
	while(Get_Bit(UCSRA,5)==0); //wait till the udr is ready to have a value

	//Set_Bit(UCSRB,3);//DIO_ErrStateSetPinValue(DIO_GroupD, Pin3, DIO_High);
UDR=msg;
	while(Get_Bit(UCSRA,6)==0);//wait till transmit is complete
	//DIO_ErrStateSetPinValue(DIO_GroupD, Pin3, DIO_High);

	//Set_Bit(UCSRA,6);//clear flag

}
u8 UART_u8Receive(void)
{

	while(Get_Bit(UCSRA,7)==0);
	return UDR;

}
