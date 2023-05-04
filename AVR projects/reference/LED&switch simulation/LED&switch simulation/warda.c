/*
 * warda.c

 *
 *  Created on: Mar 22, 2023
 *      Author: Abdullah.Abomosallam
 */

#include"warda.h"
#include"dio_reg.h"
#include"STD_TYPES.h"
#include"util/delay.h"
void warda_start(void)
{

	u8 LSB=0b00000001;
	u8 MSB=0b10000000;

	for(u8 i=0;i<4;i++)
	{


		PORTA=MSB|LSB;
		MSB=MSB>>1;
		LSB=LSB<<1;
		_delay_ms(1000);

	}


	for(u8 j=0;j<4;j++)
	{



		MSB=MSB<<1;
		LSB=LSB>>1;

		PORTA=MSB|LSB;
		_delay_ms(1000);

	}






}
