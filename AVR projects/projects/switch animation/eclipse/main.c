/*
 * main.c
 *
 *  Created on: Mar 22, 2023
 *      Author: hp
 */

#include<avr/io.h>
#include<util/delay.h>
#include"DIO_register.h"
#include "bit_math.h"
#define pressed  0
#define not_pressed  1
void main ()
{
ddrb=0xff;//make groupB output
ddrd=0xff;//make groupd output
clear(ddra,0);//A0 input
clear(ddra,1);//A1 input
clear(ddrc,1);//C1 input
clear(ddrc,0);//C0 input
clear(ddrc,2);//C2 input
//to enable internal pullup,write 1 to portA

set(porta,0);
set(porta,1);
set(portc,1);
set(portc,0);
set(portc,2);
u8 result0;
u8 result1;

u8 pinc0;
u8 pinc1;
u8 pinc2;
u8 x;
while(1)
{

	result0=get(pina,0);
	result1=get(pina,1);
	 pinc0=get(pinc,0);
	 pinc1=get(pinc,1);
	 pinc2=get(pinc,2);
	if  ( (result0 == pressed) && (result1 == not_pressed) )
	{
		portb=0;
		for(int i=0;i<8;i++){

				portb=portb+1;
				_delay_ms(1000);

			}
	}
	else if((result0==pressed)&&(result1==pressed))
	{
		u8 lsb=0b00000001;
				u8 msb=0b10000000;
		 x=0;
		portb=0;
		for (int i=0;i<8;i++)
		{
			portb=lsb<<x;
			_delay_ms(1000);
			portb=msb>>x;
			x++;
		}


	}
	else
			{
				portb=0x00;
			}

	if (pinc0==pressed)
	{
		u8 lsb=0b00000001;
		u8 msb=0b10000000;
	for (int i=0;i<4;i++)
	{

		portd=msb|lsb;
		msb=msb>>1;
		lsb=lsb<<1;
		_delay_ms(500);

	}
	for (int i=0;i<4;i++)
		{

			portd=msb|lsb;
			msb=msb<<1;
			lsb=lsb>>1;
			_delay_ms(500);

		}
}
	else if(pinc1==pressed)//move light from left to right and vice versa
	{
		u8 lsb=0b00000001;
		u8 msb=0b10000000;
		for (int i=0;i<8;i++)
			{
				portd=lsb<<i;
				_delay_ms(500);
			}
		for (int i=0;i<8;i++)
			{
				portd=msb>>i;
				_delay_ms(500);

			}
	}

	else if (pinc2==pressed)//toggle all pins
	{
		portd=0xff;
		_delay_ms(500);
		portd=0x00;
	}

	else
				{
					portd=0x00;
				}


}
}


