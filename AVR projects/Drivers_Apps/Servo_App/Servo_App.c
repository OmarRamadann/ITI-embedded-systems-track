

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

//#define UCSRA  *((volatile u8*)0x2B )
//#define UCSRB  *((volatile u8*)0x2A )
//#define UCSRC  *((volatile u8*)0x40 )
//#define UBRRL  *((volatile u8*)0x29 )
//#define UBRRH  *((volatile u8*)0x40 )
//#define UDR  	*((volatile u8*)0x2C )

#define TCCR1A 		*((volatile u8*)0x4F )
#define TCCR1B 		*((volatile u8*)0x4E )
#define TCNT1 		*((volatile u16*)0x4C )
#define OCR1A 		*((volatile u16*)0x4A )
#define ICR1 		*((volatile u16*)0x46 )//calling the low 8 bits
#define TIMSK 		*((volatile u8*)0x59 )


//void UART_voidInit(void);
//u8 UART_u8Receive(void);
//void UART_voidSend(u8 msg);

void main()
{
//OC1A pin as fast PWM non inverting
Set_Bit(TCCR1A,7);
Clr_Bit(TCCR1A,6);
//select fast PWM not 8bits(256) but controlled using ICR
Clr_Bit(TCCR1A,0);
Set_Bit(TCCR1A,1);
Set_Bit(TCCR1B,3);
Set_Bit(TCCR1B,4);
//ICR1*prescaler=8mhz(clk)*20msec(periodic time of servo)
//.select prescaler 256 for low power consumption -->low value of ICR
//ICR=625
Clr_Bit(TCCR1B,0);
Clr_Bit(TCCR1B,1);
Set_Bit(TCCR1B,2);

//we need to get duty cycle 5%[0deg-1msec],7.5%[90deg-1.5msec],10%[180deg-2msec]
//controlled usin OCRA
ICR1=625;
//OCR1A=62 ;


//enable OC1A pin
//Set_Bit(TIMSK,4);
//Set_Bit(TIMSK,2);

//enable global int
//Set_Bit(SREG,7);
DIO_ErrStateSetPinDirection(DIO_GroupD, Pin5, DIO_Output);

while(1)
{
	//0deg
		OCR1A=31;
		_delay_ms(2000);
		OCR1A=47;
		_delay_ms(3000);
		OCR1A=63;
		_delay_ms(3000);
}
}
