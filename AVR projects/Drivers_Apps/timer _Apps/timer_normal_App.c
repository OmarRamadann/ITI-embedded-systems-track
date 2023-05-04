#define TCCR2 *((volatile u8 *)0x45)
#define TCNT2 *((volatile u8 *)0x44)
#define TIMSK *((volatile u8 *)0x59)

#define TCCR0 *((volatile u8 *)0x53)
#define TCNT0 *((volatile u8 *)0x52)
#define OCR0 	*((volatile u8 *)0x5C)
void __vector_11(void)__attribute__((signal));

void TIMER10_voidSetCallBackfn(void(*ptr)(void));
void (*Timer2_ptr_fn)(void)=Null;
void Isr_Tog_Led(void);
void main()
{
	DIO_ErrStateSetPinDirection(DIO_GroupC, Pin7, DIO_Output);


	Set_Bit(SREG,7);
			Clr_Bit(TCCR0,3);
			Clr_Bit(TCCR0,6);
//			Clr_Bit(TCCR0,4);
//			Clr_Bit(TCCR0,5);
			Set_Bit(TCCR0,0);
			Set_Bit(TCCR0,1);
			Clr_Bit(TCCR0,2);
			Set_Bit(TIMSK,0);
			//Timer2_ptr_fn=Isr_Tog_Led;
			TCNT0=184;
		TIMER10_voidSetCallBackfn(Isr_Tog_Led);
		while(1)
		{

		}

//	TIMER0_voidInit(timer1, normal1);
//	Timer_Enable(timer1);
//	Timer2_ptr_fn=Isr_Tog_Led;
//	TIMER0_voidSetCallBackfn(Timer2_ptr_fn);
//	TCNT0=normal1->TCNT_First_Value;

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
		TCNT0=184;
//		TCNT0=normal1->TCNT_Value;
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


void TIMER10_voidSetCallBackfn(void(*ptr)(void))
{
	Timer2_ptr_fn=ptr;
}
void __vector_11(void)

{

	if (Timer2_ptr_fn!=Null)
	{
		Timer2_ptr_fn();
	}
}

//void Isr_Tog_Led(void)
////ISR(TIMER0_OVF_vect)
//{
//	static u16 counter;
//	counter++;
//	//if (counter==3907)
//	if (counter==5)
//	{
//		//TCNT0=192;
//	//Tog_Bit(portc,7);
//	//Led_LedErrStateTurnOn(Led1);
//		DIO_ErrStateSetPinValue(DIO_GroupC, Pin3, DIO_Low);
//	//counter=0;
//	}
//	if (counter==20)
//	{
//		counter=0;
//	}
//}
//
//void TIMER11_voidSetCallBackfn(void(*ptr)(void))
//{
//	Timer2_ptr_fn=ptr;
//}
//void __vector_11(void)
//
//{
//
//	if (Timer2_ptr_fn!=Null)
//	{
//		Timer2_ptr_fn();
//	}
}

