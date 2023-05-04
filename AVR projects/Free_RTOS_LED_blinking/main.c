/*
 * main.c
 *
 *  Created on: Apr 13, 2023
 *      Author: Abdullah.Abomosallam
 */

#include"Common/Bit_Math.h"
#include"Common/STD_types.h"
#include"DIO/DIO_interface.h"
#include "DIO/DIO_register.h"

#include"FreeRTOS.h"
#include"task.h"
#define NULL 0
void LED1(void *pv);
void LED2(void *pv);
void LED3(void *pv);

void main (void )
{
	DIO_ErrStateSetPinDirection(DIO_GroupD, Pin5, DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupD, Pin6, DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupD, Pin7, DIO_Output);
xTaskCreate(&LED1,NULL,100,NULL,0,NULL);
xTaskCreate(&LED2,NULL,100,NULL,1,NULL);
xTaskCreate(&LED3,NULL,100,NULL,2,NULL);
vTaskStartScheduler();
while(1)
{



}

}

void LED1(void *pv)
{
while(1)
{
	Set_Bit(portd,7);
vTaskDelay(1000); //perdiocity & when reach function end  --->exit while(1)
}
}
void LED2(void *pv)
{
	while (1)
	{
		Tog_Bit(portd,6);
	vTaskDelay(1000); //perdiocity & reach function --->exit while(1)

	}
}
void LED3(void *pv)
{
	while(1)
	{
		Tog_Bit(portd,5);
	vTaskDelay(3000); //perdiocity & reach function --->exit while(1)
	}
}
