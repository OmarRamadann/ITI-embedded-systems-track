/*
 * Timer0_program.c
 *
 *  Created on: Apr 1, 2023
 *      Author: hp
 */
#include "Timer0_interface.h"
#include "../../../Common/Bit_Math.h"
//#include "../../../Common/STD_types.h"
#include "Timer0_config.h"
#include "Timer0_register.h"
#include "../../Ext_INT/INT1/INT1_private.h"
//#define TIMER0_Interrupt 0
#if TIMER0_Usage==TIMER0_Interrupt

void (*Timer0_ptr_fn)(void)=Null;
void (*Timer0_CM_ptr_fn)(void)=Null;
void TIMER0_voidInit(Mode Copy_mode,Clk_Select clk_scaler,u8 Preload_Value)
	{
	if (Copy_mode==Normal)
	{
		Clr_Bit(TCCR0,WGM00);
		Clr_Bit(TCCR0,WGM01);
		//TIMER_CLKSelect(clk_scaler,Clk);
		TCNT0=Preload_Value;
	}

/* else if(  )
 *
 */

	Set_Bit(SREG,I);
	Set_Bit(TIMSK,TOIE0);
	}

void TIMER11_voidSetCallBackfn(void(*ptr)(void))
{
	Timer0_ptr_fn=ptr;
}
void __vector_11(void)


{

	if (Timer0_ptr_fn!=Null)
	{
		Timer0_ptr_fn();
	}
}

void __vector_10(void)

	{

		if (Timer0_CM_ptr_fn!=Null)
		{
			Timer0_CM_ptr_fn();
		}
	}

void TIMER10_voidSetCallBackfn(void(*ptr)(void))
{
	Timer0_CM_ptr_fn=ptr;
}

#endif











//u8 TIMER_CLKSelect(Clk_Select clk_scaler,u8 clk )
//{
//	if (clk_scaler==NoClk)
//	{
//		Clr_Bit(TCCR0_Bits,CS00);
//		Clr_Bit(TCCR0_Bits,CS01);
//		Clr_Bit(TCCR0_Bits,CS02);
//		//return 0;
//	}
//	else if (clk_scaler==Clk1)
//	{
//		Set_Bit(TCCR0_Bits,CS00);
//		Clr_Bit(TCCR0_Bits,CS01);
//		Clr_Bit(TCCR0_Bits,CS02);
//		 return clk/1;
//
//	}
//	else if (clk_scaler==Clk8)
//	{
//		Set_Bit(TCCR0_Bits,CS01);
//		Clr_Bit(TCCR0_Bits,CS00);
//		Clr_Bit(TCCR0_Bits,CS02);
//		return clk/8;
//	}
//}

//u8 Calc_Preload_Value(u8 Clk,u8 Clk_scaler,u8 Resolution,u8 Required_Time)
//{
//	u8 New_Clk=TIMER_CLKSelect(Clk_scaler, Clk);
//	u8 Tick_Time=1/(float)New_Clk;
//	u16 Count=pow(2,(double)Resolution);
//	u16 Timer_OF=Tick_Time*Count;
//	float OF_Number=Required_Time/(float)Timer_OF;
//	u16 Preload_Value=(OF_Number-(u16)OF_Number)*Count;



//}

