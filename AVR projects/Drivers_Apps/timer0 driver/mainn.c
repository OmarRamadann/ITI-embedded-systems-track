#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/DIO/DIO_register.h"
#include "../MCAL/Timers/Timer0/Timer0_register.h"
#include "../Common/definitions.h"
#include "../Common/Bit_Math.h"
#include "../Common/STD_types.h"
#include "../MCAL/Timers/Timer0/Timer0_interface.h"

//void (*Timer_ptr_fn_Normal)(void)=Null;
void Isr_Tog_Led(void);
Timer_Prop timer1={Normal,8,Clk64,256,1000000};
//={Normal,8,Clk8,256,1000000,0};
NormalTimer_Prop normal1;
//={0,0,0,0,0,0,184,0};


void main()
{
	DIO_ErrStateSetPinDirection(DIO_GroupC, Pin7, DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupC, Pin4, DIO_Output);
//	timer1->Mode=Normal;
//	timer1->Clk=8;
//	timer1->Clk_Scaler=Clk8;
//	timer1->Count_Max=256;


	TIMER0_voidInit(&timer1, &normal1);
	Timer_Enable(&timer1);
	TCNT0=normal1.TCNT_First_Value;

//		Set_Bit(SREG,7);
//					Clr_Bit(TCCR0,3);
//					Clr_Bit(TCCR0,6);
//		//			Clr_Bit(TCCR0,4);
//		//			Clr_Bit(TCCR0,5);
//					Set_Bit(TCCR0,0);
//					Set_Bit(TCCR0,1);
//					Clr_Bit(TCCR0,2);
//					Set_Bit(TIMSK,0);
//					TCNT0=184;
	TIMER0_voidSetCallBackfn(Isr_Tog_Led);
//	Timer2_ptr_fn=Isr_Tog_Led;



//	Set_Bit(SREG,7);
//			Clr_Bit(TCCR0,3);
//			Clr_Bit(TCCR0,6);
////			Clr_Bit(TCCR0,4);
////			Clr_Bit(TCCR0,5);
//			Set_Bit(TCCR0,0);
//			Set_Bit(TCCR0,1);
//			Clr_Bit(TCCR0,2);
//			Set_Bit(TIMSK,0);
//			TCNT0=184;
//		TIMER10_voidSetCallBackfn(Isr_Tog_Led);
		while(1)
		{

		}



}


void Isr_Tog_Led(void)
//ISR(TIMER0_OVF_vect)
{
	static u16 counter;
	counter++;
	if (counter==489)
//	if (counter==5)
	{
//		DIO_ErrStateSetPinValue(DIO_GroupC, Pin7, DIO_High);
//		TCNT0=184;
	TCNT0=normal1.TCNT_Value;
	Tog_Bit(portc,7);
	//Led_LedErrStateTurnOn(Led1);
//		DIO_ErrStateSetPinValue(DIO_GroupC, Pin3, DIO_Low);
	counter=0;
	}
//	if (counter==20)
//	{
//		counter=0;
//	}
}


//void __vector_11(void)
//	{
//
//		if (Timer_ptr_fn_Normal!=Null)
//		{
//			Timer_ptr_fn_Normal();
//		}
//	}
//void TIMER0_voidSetCallBackfn(void(*ptr)(void))
//		{
//
//			Timer_ptr_fn_Normal=ptr;
//		//	Timer_ptr_fn_CM=ptr;
//		}
//
