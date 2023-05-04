/*
d * main.c
 *
 *  Created on: Mar 21, 2023
 *      Author: Abdullah.Abomosallam
 */


#include"util/delay.h"
#include"STD_TYPES.h"
#include"BIT_math.h"
#include"dio_reg.h"
#include"togLED.h"
#include"warda.h"

#define PRESSED     0
#define NOT_PRESSED 1
#define SW0           0
#define SW1           1
#define SW2           2

int main ()
{


	DDRA=255; //output 8leds
	DDRB=0;  //INPUT
	PORTB=255; //internal pull up  switch 0--> pin0 switch 2--> pin1 switch 2 pin2


	while(1)
	{
		if(GET_BIT(PINB,SW0)==PRESSED)
		{

			warda_start();


		}

		else if(GET_BIT(PINB,SW1)==PRESSED)
		{

		toggleLED();


		}

		else if(GET_BIT(PINB,SW2)==PRESSED)
		{




		}






	}

	return 0;
}
