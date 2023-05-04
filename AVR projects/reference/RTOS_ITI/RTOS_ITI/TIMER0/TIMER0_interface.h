/*
 * TIMERS_interface.h
 *
 *  Created on: Dec 6, 2022
 *      Author: abdullah
 */

#ifndef MCAL_TIMERS_TIMERS_INTERFACE_H_
#define MCAL_TIMERS_TIMERS_INTERFACE_H_
#include"../../SERVICES/BIT_math.h"
#include"../../SERVICES/STD_TYPES.h"

#include "TIMER0_pcfg.h"
#include"TIMER0_private.h"


#define PRESCALER_1    0
#define PRESCALER_8    1
#define PRESCALER_32   2
#define PRESCALER_64   3
#define PRESCALER_128  4
#define PRESCALER_256  5
#define PRESCALER_1024 6
#define EXTERNAL_CLK_FALLING_EDGE 5
#define EXTERNAL_CLK_RISING_EDGE  6



void TIMER0_voidTimer0Init(u8 copyu8_prescaler,u8 copyu8_intialzeTCNT0,u8 copy_inializeOCR0);

#if TIMER0_USAGE  ==  INTERRUPT
void TIMER0_voidTimer0Disable(void);
void TIMER0_voidSetCallBack(void (*ptr_fn)(void));
#endif

#if TIMER0_USAGE  ==  POLLING
void TIMERS_voidTimer0Disable(void);
#endif

#if TIMER0_USAGE  ==  POLLING
u8 TIMERS_voidTimer0CheckFlag(void);
#endif


void TIMER0_voidTimer0INTEnable(void);
#if TIMER0_USAGE==INTERRUPT&& TIMER0_TYPE==TIMERS_OVERFLOW_NORMAL
void __vector_11(void)__attribute((signal));//Timer0 overflow mode
#endif
#if TIMER0_USAGE==INTERRUPT&& TIMER0_TYPE==TIMER_CTC
void __vector_10(void)__attribute((signal)); //Timer0 CTC
#endif
#endif /* MCAL_TIMERS_TIMERS_INTERFACE_H_ */
