/*
 * main.c
 *
 *  Created on: Mar 21, 2023
 *      Author: hp
 */

#include<avr/io.h>
#include<util/delay.h>
#include"register.h"
#include "bit_math.h" //ctrl&space to suggest
#define pressed 0
#define not_pressed 1

void main ()
{
set(ddrb,0);//make B0 output
clear(ddra,0);//A0 input
//to enable internal pullup,write 1 to portA

set(porta,0);
u8 result;
while(1)
{
	result=get(pina,0);
	if   (result==not_pressed)
	{
		clear(portb,0);
	}


	else if(result==pressed)
	{
		set(portb,0);
	}

}




}
