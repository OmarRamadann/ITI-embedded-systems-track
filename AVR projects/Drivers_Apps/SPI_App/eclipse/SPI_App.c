

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


#define SPCR 		*((volatile u8*)0x2D )
#define SPDR 		*((volatile u8*)0x2F )
#define SPSR 		*((volatile u8*)0x2E )
/****************************slave***********************************/
void SPI_voidInit()
{


	//slave init
//		DIO_ErrStateSetPinDirection(DIO_GroupB, Pin5, DIO_Input);//MOSI PIN INPUT
//		DIO_ErrStateSetPinDirection(DIO_GroupB, Pin6, DIO_Output);//MISO PIN  OUTPUT
//		DIO_ErrStateSetPinDirection(DIO_GroupB, Pin7, DIO_Input);//Clk PIN
//		DIO_ErrStateSetPinDirection(DIO_GroupD, Pin4, DIO_Input);//SS PIN



	//enable SPI
Set_Bit(SPCR,6);

//select master
Set_Bit(SPCR,4);
//selecct polarity (1)
Set_Bit(SPCR,3);
//select phase (1)
Set_Bit(SPCR,2);
//select prescaler (/16)
Set_Bit(SPCR,0);
Clr_Bit(SPCR,1);
Clr_Bit(SPSR,0);

//select slave
//Clr_Bit(SPCR,4);
//no prescaler for slave



}




u8 SPI_u8SendReceive(u8 data)
{
	//the DIO pin that is connected to slave select of slave
	//DIO_ErrStateSetPinValue(DIO_GroupD, Pin5, DIO_Low);
	SPDR=data;
	while(Get_Bit(SPSR,7)==0);
	//DIO_ErrStateSetPinValue(DIO_GroupD, Pin5, DIO_High);
	return SPDR;

}
Lcd_Info lcd1={DIO_GroupD,DIO_GroupD,DIO_GroupD,Pin5,Pin4,Pin6,DIO_GroupA};



void main()
{
	DIO_ErrStateSetPinDirection(DIO_GroupB, Pin5, DIO_Output);//MOSI PIN OUTPUT
		DIO_ErrStateSetPinDirection(DIO_GroupB, Pin6, DIO_Input);//MISO PIN INPUT
		DIO_ErrStateSetPinDirection(DIO_GroupB, Pin7, DIO_Output);//Clk PIN
Lcd_VoidInit(&lcd1);
SPI_voidInit();
u8 x;
while(1)
{
	//send data from master
	//data=SPI_u8SendReceive('O');
	//receive data from master
	x=SPI_u8SendReceive('w');
	//_delay_ms(1000);
	Lcd_VoidSendChar(x, &lcd1);
	//_delay_ms(1000);
}
}
