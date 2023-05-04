/*
 * toggled.c
 *
 *  Created on: Mar 22, 2023
 *      Author: Abdullah.Abomosallam
 */


/*
 * togLED.C
 *
 *  Created on: Mar 22, 2023
 *      Author: Abdullah.Abomosallam
 */

#include"dio_reg.h"
#include"togLED.h"
#include"STD_TYPES.h"
#include"BIT_math.h"
#include"util/delay.h"
void toggleLED(void)
{


	for(u8 i=0;i<8;i++)
	{

		SET_BIT(PORTA,i);
		_delay_ms(1000);
		CLR_BIT(PORTA,i);


	}

	for(s8 i=7;i!=-1;i--)
	{
		SET_BIT(PORTA,i);
		_delay_ms(1000);
		CLR_BIT(PORTA,i);



	}




}
