/*
 * Timer0_register.h
 *
 *  Created on: Apr 1, 2023
 *      Author: hp
 */

#ifndef MCAL_TIMERS_TIMER0_TIMER0_REGISTER_H_
#define MCAL_TIMERS_TIMER0_TIMER0_REGISTER_H_

#define TIMSK 	*((volatile u8 *)0x59)
#define TCCR0 	*((volatile u8 *)0x53)
#define TCNT0 	*((volatile u8 *)0x52)
#define SREG   *((volatile u8 *)0x5F)
#define TIFR   *((volatile u8 *)0x58)
#define OCR0 	*((volatile u8 *)0x5C)

#endif /* MCAL_TIMERS_TIMER0_TIMER0_REGISTER_H_ */
