/*
 * Timer0_private.h
 *
 *  Created on: Apr 1, 2023
 *      Author: hp
 */

#ifndef MCAL_TIMERS_TIMER0_TIMER0_PRIVATE_H_
#define MCAL_TIMERS_TIMER0_TIMER0_PRIVATE_H_



typedef enum
{
	TIMER0_Polling,
	TIMER0_Interrupt
}Usage;

//typedef enum
//{
//	I=7
//}SREG_Bits;
typedef enum
{
	Normal,
	PWM,
	CTC,
	FastPWM
}Mode;

typedef enum
{
	Mhz8,
	Mhz12
}Clk_time;
typedef enum
{
	NoClk,
	Clk1,
	Clk8,
	Clk64,
	Clk256,
	Clk1024
}Clk_Select;
typedef enum
{
	CS00,
	CS01,
	CS02,
	WGM01,
	COM00,
	COM01,
	WGM00,
	FOC0
}TCCR0_Bits;

typedef enum
{
TOIE0,
OCIE
}TIMSK_Bits;

typedef enum
{
	TOV0
}TIFR_Bits;



#endif /* MCAL_TIMERS_TIMER0_TIMER0_PRIVATE_H_ */
