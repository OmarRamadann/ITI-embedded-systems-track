

#include "../MCAL/DIO/DIO_interface.h"
#include"../common/definitions.h"
#include"../HAL/LCD_Driver/LCD_interface.h"
#include "../MCAL/DIO/DIO_register.h"
#include "../MCAL/Timers/Timer0/Timer0_interface.h"
#include "../HAL/Led_Driver/Led_Configuration.h"
#include "../Common/Bit_Math.h"
#include<util/delay.h>

#define GIFR   *((volatile u8 *)0x5A)
#define GICR   *((volatile u8 *)0x5B)
#define SREG   *((volatile u8 *)0x5F)

#define TCCR2 *((volatile u8 *)0x45)
#define TCNT2 *((volatile u8 *)0x44)
#define TIMSK *((volatile u8 *)0x59)
#define TCCR0 *((volatile u8 *)0x53)
#define TCNT0 *((volatile u8 *)0x52)
#define OCR0 	*((volatile u8 *)0x5C)
//void __vector_10(void)__attribute__((signal));
//void TIMER10_voidSetCallBackfn(void(*ptr)(void));

void Isr_Tog_Led(void);
void (*Timer2_ptr_fn)(void)=Null;

void main()
{

	Set_Bit(SREG,7);
//ctc mode
	Clr_Bit(TCCR0,6);
	Set_Bit(TCCR0,3);
	//pwm mode
//	Clr_Bit(TCCR0,3);
//	Set_Bit(TCCR0,6);

	Set_Bit(TCCR0,0);
	Set_Bit(TCCR0,1);
	Clr_Bit(TCCR0,2);
	Set_Bit(TIMSK,1);
	//OCR0=125;//to compare for 1000usec
	OCR0=50;
	//TCNT0=184;


	DIO_ErrStateSetPinDirection(DIO_GroupC, Pin3, DIO_Output);
	DIO_ErrStateSetPinValue(DIO_GroupC, Pin3, DIO_High);
	//Timer2_ptr_fn=(Isr_Tog_Led);
	TIMER10_voidSetCallBackfn(Isr_Tog_Led);
	while(1)
	{
	}

	}
void Isr_Tog_Led(void)
{
	static u16 counter;
		counter++;
		//if (counter==3907)//1 sec,8 scaler,normal
		//if (counter==489)//1sec ,64 scaler,normal
		if (counter==5000)//we need 1000 overflows to do 1 sec ioe:5000 for 5sec
		{
			//TCNT0=184;
		//Tog_Bit(portc,7);
		//Led_LedErrStateTurnOn(Led1);
			Tog_Bit(portc,7);
			DIO_ErrStateSetPinValue(DIO_GroupC, Pin3, DIO_Low);
			//_delay_ms(50000);
		//counter=0;
		}
		else if (counter==20000)
		{
			counter=0;
			DIO_ErrStateSetPinValue(DIO_GroupC, Pin3, DIO_High);
		}
	}


//void TIMER10_voidSetCallBackfn(void(*ptr)(void))
//{
//	Timer2_ptr_fn=ptr;
//}
//void __vector_10(void)
//
//{
//
//	if (Timer2_ptr_fn!=Null)
//	{
//		Timer2_ptr_fn();
//	}
//}

