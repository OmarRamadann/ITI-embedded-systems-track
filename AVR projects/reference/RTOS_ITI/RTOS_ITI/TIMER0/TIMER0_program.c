/*
 * TIMERS_program.c

 *
 *  Created on: Dec 6, 2022
 *      Author: abdullah
 */
#include"../../SERVICES/BIT_math.h"
#include"../../SERVICES/STD_TYPES.h"
#include"../../MCAL/DIO/DIO_interface.h"
#include "TIMER0_interface.h"
#include "TIMER0_pcfg.h"
#include "TIMER0_private.h"
void (*ptr_funcc)(void)=NULL;
void TIMER0_voidTimer0Init(u8 copyu8_prescaler,u8 copyu8_intialzeTCNT0,u8 copy_inializeOCR0)
{

	CLR_BIT(TCCR0,7);
	if(TIMER0_TYPE==TIMERS_OVERFLOW_NORMAL)
	{
		CLR_BIT(TCCR0,6);
		CLR_BIT(TCCR0,3);
	}
	else if(TIMER0_TYPE==TIMER_CTC)
	{
		CLR_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);
	}

	/*else if (copyu8_type==PWM_PHASE_CORRECT)
{
	SET_BIT(TCCR0,6);
	    CLR_BIT(TCCR0,3);


}
else if (copyu8_type==PWM_FAST)
{

	SET_BIT(TCCR0,6);
		    SET_BIT(TCCR0,3);

}*/

	CLR_BIT(TCCR0,5);
	CLR_BIT(TCCR0,4);
	if(copyu8_prescaler==PRESCALER_1)
	{
		CLR_BIT(TCCR0,2);
		CLR_BIT(TCCR0,1);
		SET_BIT(TCCR0,0);

	}
	else if(copyu8_prescaler==PRESCALER_8)
	{
		CLR_BIT(TCCR0,2);
		SET_BIT(TCCR0,1);
		CLR_BIT(TCCR0,0);

	}

	else if(copyu8_prescaler==PRESCALER_64)
	{
		CLR_BIT(TCCR0,2);
		SET_BIT(TCCR0,1);
		SET_BIT(TCCR0,0);


	}
	else if(copyu8_prescaler==PRESCALER_256)
	{
		SET_BIT(TCCR0,2);
		CLR_BIT(TCCR0,1);
		CLR_BIT(TCCR0,0);


	}
	else if(copyu8_prescaler==PRESCALER_1024)
	{
		SET_BIT(TCCR0,2);
		CLR_BIT(TCCR0,1);
		SET_BIT(TCCR0,0);

	}

	///
	else if(copyu8_prescaler==EXTERNAL_CLK_FALLING_EDGE)
	{
		SET_BIT(TCCR0,2);
		SET_BIT(TCCR0,1);
		CLR_BIT(TCCR0,0);

	}
	else if(copyu8_prescaler==EXTERNAL_CLK_RISING_EDGE)
	{
		SET_BIT(TCCR0,2);
		SET_BIT(TCCR0,1);
		SET_BIT(TCCR0,0);

	}

	TCNT0=copyu8_intialzeTCNT0;
	if(TIMER0_TYPE==TIMER_CTC)
	{
		OCR0=copy_inializeOCR0;


	}
	if(TIMER0_USAGE==INTERRUPT)
	{
		if(TIMER0_TYPE==TIMERS_OVERFLOW_NORMAL)
		{
			SET_BIT(TIMSK,0);

		}
		else if(TIMER0_TYPE==TIMER_CTC)
		{
			SET_BIT(TIMSK,1);

		}

	}


}


#if TIMER0_USAGE  ==  INTERRUPT
void TIMER0_voidTimer0Disable(void)

{
	if(TIMER0_TYPE==TIMERS_OVERFLOW_NORMAL)
	{
		CLR_BIT(TIMSK,0);

	}
	else if(TIMER0_TYPE==TIMER_CTC)
	{
		CLR_BIT(TIMSK,1);

	}







}

void TIMER0_voidSetCallBack(void (*ptr_fn)(void))
{

if(ptr_funcc==NULL)
{

	ptr_funcc=ptr_fn;

}

}
#endif

#if TIMER0_USAGE  ==  POLLING
void TIMERS_voidTimer0Disable(void)  //disable by prescaler
{

	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
}
#endif


#if TIMER0_USAGE  ==  POLLING
u8 TIMERS_voidTimer0CheckFlag(void)
{

	if(TIMER0_TYPE==TIMER_CTC)
	{

		return GET_BIT(TIFR,1);
	}
	else if(TIMER0_TYPE==TIMERS_OVERFLOW_NORMAL)
	{

		return GET_BIT(TIFR,0);
	}


}
#endif




#if TIMER0_USAGE==INTERRUPT&& TIMER0_TYPE==TIMERS_OVERFLOW_NORMAL

void __vector_11(void) //Timer0 overflow mode
{


if(ptr_func!=NULL)
{
	ptr_func();

}



}
#endif
#if TIMER0_USAGE==INTERRUPT&& TIMER0_TYPE==TIMER_CTC
void __vector_10(void)//Timer0 CTC
{
	if(ptr_funcc!=NULL)
	{
		ptr_funcc();

	}




}
#endif

