/*
 * Timer0_interface.h
 *
 *  Created on: Apr 1, 2023
 *      Author: hp
 */

#ifndef MCAL_TIMERS_TIMER0_TIMER0_INTERFACE_H_
#define MCAL_TIMERS_TIMER0_TIMER0_INTERFACE_H
#include "Timer0_private.h"
#include "../../../Common/STD_types.h"
#include "Timer0_config.h"

void TIMER0_voidInit(Mode Copy_mode,Clk_Select clk_scaler,u8 Preload_Value);
void __vector_11(void)__attribute__((signal));
void TIMER11_voidSetCallBackfn(void(*ptr)(void));
void __vector_10(void)__attribute__((signal));
void TIMER10_voidSetCallBackfn(void(*ptr)(void));
u8 Calc_Preload_Value(u8 Clk,u8 Clk_scaler,u8 Resolution,u8 Required_Time);
u8 TIMER_CLKSelect(Clk_Select clk_scaler,u8 clk );




#if TIMER0_Usage==TIMER0_Polling
u8 TIMER0_u8CheckFlag(void);
void TIMER0_u8ClearFlag(void);

#endif

#endif /* MCAL_TIMERS_TIMER0_TIMER0_INTERFACE_H_ */