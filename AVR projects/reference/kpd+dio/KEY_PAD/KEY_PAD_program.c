/*
 * KEY_PAD.c
 *
 *  Created on: Oct 24, 2022
 *      Author: abdullah
 */

#include"../SERVICES/STD_TYPES.h"
#include"../SERVICES/BIT_math.h"

#include"../DIO/DIO_interface.h"
#include<util\delay.h>

#include"KEY_PAD_interface.h"
#include"KEY_PAD_private.h"
#include"KEY_PAD_Pcfg.h"

u8 KEY_PAD_array[8][2]=KEY_PAD_ARRAY;



void KEY_pad_voidinit(void)
{
	u8 LOC_u8_iterator;


	for( LOC_u8_iterator=0;LOC_u8_iterator<KEY_PAD_ROWSIZE;LOC_u8_iterator++)
	{
		DIO_voidSetPinDirection(KEY_PAD_array[LOC_u8_iterator][0],KEY_PAD_array[LOC_u8_iterator][1],DIO_INPUT);

		DIO_voidSetPinValue(KEY_PAD_array[LOC_u8_iterator][0],KEY_PAD_array[LOC_u8_iterator][1],DIO_HIGH);// for internal pull up resistor


	}


	for(u8 LOC_u8_iterator=4;LOC_u8_iterator<(KEY_PAD_COLSIZE+KEY_PAD_ROWSIZE);LOC_u8_iterator++)
	{

		DIO_voidSetPinDirection(KEY_PAD_array[LOC_u8_iterator][0],KEY_PAD_array[LOC_u8_iterator][1],DIO_OUTPUT);

        DIO_voidSetPinValue(KEY_PAD_array[LOC_u8_iterator][0],KEY_PAD_array[LOC_u8_iterator][1],DIO_HIGH);

	}





}
u8 Key_Pad_u8GetButtonPressed() // returns the ascii code of the button pressed in the keypad values array
{

	u8 LOC_u8coliterator=0;
	u8 LOC_u8rowiterator=0;
	u8 LOC_u8SW_state =0;
	u8 LOC_u8switchpressed=0;
	u8 LOC_u8flag=0;


	for(LOC_u8coliterator=KEY_PAD_ROWSIZE;LOC_u8coliterator<(KEY_PAD_ROWSIZE+KEY_PAD_COLSIZE)&&LOC_u8flag==0;LOC_u8coliterator++)
	{
		DIO_voidSetPinValue(KEY_PAD_array[LOC_u8coliterator][0],KEY_PAD_array[LOC_u8coliterator][1],DIO_LOW);


		for(LOC_u8rowiterator=0;LOC_u8rowiterator<KEY_PAD_ROWSIZE&&LOC_u8flag==0;LOC_u8rowiterator++)
		{
			LOC_u8SW_state=DIO_u8GetPinValue(KEY_PAD_array[LOC_u8rowiterator][0],KEY_PAD_array[LOC_u8rowiterator][1]);

		if(LOC_u8SW_state==DIO_LOW)//becasuse of internal pullup
		{
			_delay_ms(15);//check for bouncing effect

			LOC_u8SW_state=DIO_u8GetPinValue(KEY_PAD_array[LOC_u8rowiterator][0],KEY_PAD_array[LOC_u8rowiterator][1]);

			if(LOC_u8SW_state==DIO_LOW)
			{

				LOC_u8switchpressed=KEY_PAD_values[LOC_u8rowiterator][LOC_u8coliterator-KEY_PAD_COLSIZE];//3SHAN msh bad2 mn 0



				while(LOC_u8SW_state==DIO_LOW) //this prevents to multiple effect for long  press at the same time ;
				{



					LOC_u8SW_state=DIO_u8GetPinValue(KEY_PAD_array[LOC_u8rowiterator][0],KEY_PAD_array[LOC_u8rowiterator][1]);



				}





                LOC_u8flag=1;





			}




		}
		}






		 DIO_voidSetPinValue(KEY_PAD_array[LOC_u8coliterator][0],KEY_PAD_array[LOC_u8coliterator][1],DIO_HIGH);//at the end for each col set it at 5V

	}


return LOC_u8switchpressed;


}



















