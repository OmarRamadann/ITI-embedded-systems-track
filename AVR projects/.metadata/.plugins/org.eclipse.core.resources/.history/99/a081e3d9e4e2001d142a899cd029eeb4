/*
 * main.c
 *
 *  Created on: Apr 13, 2023
 *      Author: Abdullah.Abomosallam
 */

#include"SERVICES/STD_TYPES.h"
#include"SERVICES/BIT_math.h"
#include"DIO/DIO_interface.h"

#include"FreeRTOS.h"
#include"task.h"
#define NULL 0
void LED1(void *pv);
void LED2(void *pv);
void LED3(void *pv);

void main (void )
{
	DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN1,DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN2,DIO_OUTPUT);
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
	TOG_BIT(DIO_PORTA,DIO_PIN0);
vTaskDelay(1000); //perdiocity & when reach function end  --->exit while(1)
}
}
void LED2(void *pv)
{
	while (1)
	{
	TOG_BIT(DIO_PORTA,DIO_PIN1);
	vTaskDelay(2000); //perdiocity & reach function --->exit while(1)
	}
}
void LED3(void *pv)
{
	while(1)
	{
	TOG_BIT(DIO_PORTA,DIO_PIN2);
	vTaskDelay(3000); //perdiocity & reach function --->exit while(1)
	}
}
