/*
 * main.c
 *
 *  Created on: Mar 21, 2023
 *      Author: hp
 */

#include<avr/io.h>
#include<util/delay.h>


void main ()
{

ddra=0xff;
porta=0x00;
while (1){
 //PORTA ^=0xFF;
	int x=128;
		int y=1;
		int msb=0b10000000;
		int lsb=0b00000001;
	for (int i=0;i<4;i++){
		PORTA=msb|lsb;
		lsb=lsb<<1;
		msb=msb>>1;
		_delay_ms(500);


//	PORTA=(x)+y;
//	y=y*2;
//	x=x/2;
// _delay_ms(1000);
// 	 PORTA=0;
// _delay_ms(1000);
		}

	}
}