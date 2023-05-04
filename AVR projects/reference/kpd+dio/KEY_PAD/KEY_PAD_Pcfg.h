/*
 * KEY_PAD_Pcfg.h
 *
 *  Created on: Oct 24, 2022
 *      Author: abdullah
 */

#ifndef HAL_KEY_PAD_KEY_PAD_PCFG_H_
#define HAL_KEY_PAD_KEY_PAD_PCFG_H_
#include"../SERVICES/STD_TYPES.h"
#include"../SERVICES/BIT_math.h"

#include"../DIO/DIO_interface.h"

#define KEY_PAD_ROWSIZE  4
#define KEY_PAD_COLSIZE  4

#define TRUE                       1
#define FALSE                       0



u8 KEY_PAD_values[KEY_PAD_ROWSIZE][KEY_PAD_COLSIZE]={

		                                          //col0 col1 col2 col3
		                                          {'1','2','3','+'},//row0
		                                          {'4','5','6','-'},//row1
		                                          {'7','8','9','*'},//row2
		                                          {'=','0','.','/'}//row3   //s for select







};


//in case I dont have a complete port for the KEYPAD
//WE CREATE A 2D ARRAY TO PLACE THE PORT AND PIN FOR EACH SWITCH

#define KEY_PAD_ROW0  {DIO_PORTA,DIO_PIN0}
#define KEY_PAD_ROW1  {DIO_PORTA,DIO_PIN1}
#define KEY_PAD_ROW2  {DIO_PORTA,DIO_PIN2}
#define KEY_PAD_ROW3  {DIO_PORTA,DIO_PIN3}
#define KEY_PAD_COL0  {DIO_PORTA,DIO_PIN4}
#define KEY_PAD_COL1  {DIO_PORTA,DIO_PIN5}
#define KEY_PAD_COL2  {DIO_PORTA,DIO_PIN6}
#define KEY_PAD_COL3  {DIO_PORTA,DIO_PIN7}


#define KEY_PAD_ARRAY  {KEY_PAD_ROW0,\
	                    KEY_PAD_ROW1,\
                         KEY_PAD_ROW2,\
                         KEY_PAD_ROW3,\
                         KEY_PAD_COL0,\
                          KEY_PAD_COL1,\
                           KEY_PAD_COL2,\
                           KEY_PAD_COL3}\








#endif /* HAL_KEY_PAD_KEY_PAD_PCFG_H_ */
