/*

 * main.c
 *
 *  Created on: Mar 23, 2023
 *      Author: hp
 */
#include "../../../MCAL/DIO/DIO_interface.h"
#include"../../../Common/definitions.h"
#include<util/delay.h>
#define SevSegCA_0   0x3F
#define SevSegCA_1   0x06
#define SevSegCA_2   0x5B
#define SevSegCA_3   0x4F
#define SevSegCA_4   0x66
#define SevSegCA_5   0x6D
#define SevSegCA_6   0x7D
#define SevSegCA_7   0x07
#define SevSegCA_8   0x7F
#define SevSegCA_9   0x6F
#define SevSeg_Arrize 10

void SevSeg_App2()
{
ErrState Res[5];
ErrState Switch1,Switch2,Switch3;
u8 SevSegArr[SevSeg_Arrize]=
{
		SevSegCA_0,
		SevSegCA_1,
		SevSegCA_2,
		SevSegCA_3,
		SevSegCA_4,
		SevSegCA_5,
		SevSegCA_6,
		SevSegCA_7,
		SevSegCA_8,
		SevSegCA_9
};
Res[0]=DIO_ErrStateSetGroupDirection(DIO_GroupC,0xff);
//set  pins of group D as output
Res[1]=DIO_ErrStateSetGroupDirection(DIO_GroupD, 0xff);
//enable internal pullup
//DIO_ErrStateSetGroupValue(DIO_GroupD, 0xff);
u8 counter=0;
u8 units=0;
u8 tens=0;
while(1)
{
	tens=0;
	for(counter=0;counter<100;counter++)
	{

	units=counter/10;


	DIO_ErrStateSetPinValue(DIO_GroupD, Pin3, DIO_Low);//made tens work
	DIO_ErrStateSetPinValue(DIO_GroupD, Pin4, DIO_High);//made units stop
	DIO_ErrStateSetGroupValue(DIO_GroupC, SevSegArr[tens]);
	_delay_ms(50);
	DIO_ErrStateSetPinValue(DIO_GroupD, Pin3, DIO_High);//made tens stop
	DIO_ErrStateSetPinValue(DIO_GroupD, Pin4, DIO_Low);//made units work
	DIO_ErrStateSetGroupValue(DIO_GroupC,SevSegArr[counter%10] );
	_delay_ms(50);
	if  (counter%10==9)
	{
		tens+=1;
	}
//	DIO_ErrStateSetPinValue(DIO_GroupD, Pin4, DIO_High);//made units stop
//	_delay_ms(1000);
	}
	}
}
