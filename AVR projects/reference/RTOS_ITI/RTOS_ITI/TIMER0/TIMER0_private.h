/*
 * TIMERS_private.h
 *
 *  Created on: Dec 6, 2022
 *      Author: abdullah
 */

#ifndef MCAL_TIMERS_TIMERS_PRIVATE_H_
#define MCAL_TIMERS_TIMERS_PRIVATE_H_

#define TCCR1A *( ( volatile u8*)0x4F)
#define TCCR1B *( ( volatile u8*)0x4E)
#define TCNT1 *( ( volatile u16*)0x4C)
#define OCR1A *( ( volatile u16*)0x4A)
#define OCR1B *( ( volatile u16*)0x48)
#define ICR1 *( ( volatile u16*)0x46)
#define TIMSK *( ( volatile u8*)0x59)
#define TIFR *( ( volatile u8*)0x58)
#define SREG *( ( volatile u8*)0x5F)
//////
#define TCCR0  *((volatile u8*)0x53 )
#define TCNT0  *((volatile u8*)0x52 )
#define OCR0   *((volatile u8*)0x5C )

#define TCCR2  *((volatile u8*)0x45 )
#define TCNT2  *((volatile u8*)0x44 )
#define OCR2   *((volatile u8*)0x43 )


#define ENABLED   1
#define DISABLED  0

#define PWM      3
#define TIMERS_OVERFLOW_NORMAL       0     /*     for timer*/
#define  TIMER_CTC                   1  /*for timer*/

#define PWM_PHASE_CORRECT            2
#define PWM_FAST                     3                    //for PWM

////for timer1:
#define PWM1_FAST_8_BIT           4
#define PWM1_FAST_9_BIT           5
#define PWM1_FAST_10_BIT           6

#define PWM1_PHASE_CORRECT_8_BIT  7
#define PWM1_PHASE_CORRECT_9_BIT  8
#define PWM1_PHASE_CORRECT_10_BIT  9

#define PWM1_PHASE_CORRECT_ICR1  10
#define PWM1_PHASE_CORRECT_OCR1  11
#define PWM1_FAST_ICR1           12
#define PWM1_FAST_OCR1           13



#define INVERTED   0
#define NON_INVERTED 1


#define ICU 0 //input capture


#define POLLING  0
#define INTERRUPT 1

#define NULL 0



#endif /* MCAL_TIMERS_TIMERS_PRIVATE_H_ */
