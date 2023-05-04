/*
 * PWM_SERVO.c
 *
 *  Created on: Nov 26, 2022
 *      Author: abdullah
 */

/*
 * PWM.c
 *
 *  Created on: Nov 26, 2022
 *      Author: abdullah
 */

/*
 * Timer1TUT.c
 *
 *  Created on: Nov 25, 2022
 *      Author: abdullah
 */
/*#include"../SERVICES/STD_TYPES.h"
#include"../SERVICES/BIT_math.h"
#include"../HAL/LED/LED_interface.h"
#include"../MCAL/DIO/DIO_interface.h"
#include<util\delay.h>

#define TCCR0  *((volatile u8*)0x53 )
#define TCNT0  *((volatile u8*)0x52 )
#define OCR0   *((volatile u8*)0x5C )
#define TIMSK *((volatile u8*)0x59 )
#define TIFR   *((volatile u8*)0x58 )
#define SREG   *((volatile u8 *)0x5F)
#define PORTA *( ( volatile u8*)0x3B)
///////////////////////////////////////////////
#define TCCR1A *( ( volatile u8*)0x4F)
#define TCCR1B *( ( volatile u8*)0x4E)
#define TCNT1 *( ( volatile u16*)0x4C)
#define OCR1A *( ( volatile u16*)0x4A)
#define ICR1 *( ( volatile u16*)0x46)
#define NULL 0;



int main ()
{
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);
	TCCR1A=0b10000010;
	TCCR1B=0b00011100;
	ICR1=625;


	while(1)
	{
		OCR1A=31;
		_delay_ms(3000);
		OCR1A=47;
		_delay_ms(3000);
		OCR1A=63;
		_delay_ms(3000);





	}
	return 0;
}*/

