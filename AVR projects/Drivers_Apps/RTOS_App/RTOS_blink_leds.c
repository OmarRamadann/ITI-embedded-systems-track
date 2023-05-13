#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/DIO/DIO_register.h"
#include "../MCAL/Timers/Timer0/Timer0_register.h"
#include "../Common/definitions.h"
#include "../Common/Bit_Math.h"
#include "../Common/STD_types.h"
#include "../MCAL/Timers/Timer0/Timer0_interface.h"
#include "../RTOS/RTOS_interface.h"
#include <util/delay.h>

//void (*Timer_ptr_fn_Normal)(void)=Null;
//void Isr_Tog_Led(void);
Timer_Prop timer1={CTC,8,Clk64,256,1000000,1000};
////={Normal,8,Clk8,256,1000000,0};
ModesTimer_Prop normal1;
//={0,0,0,0,0,0,184,0};
void led1(void);
void led2(void);
void led3(void);
void Isr_Tog_Led(void);


void main()
{

//	DIO_ErrStateSetPinDirection(DIO_GroupC, Pin7, DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupD, Pin6, DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupD, Pin7, DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupD, Pin5, DIO_Output);

	RTOS_voidStart(&timer1, &normal1);
	CreatTask(0, 2000, &led1);
	CreatTask(1, 4000, &led2);
	CreatTask(2, 6000, &led3);


//	TIMER0_voidInit(&timer1, &normal1);
//		Timer_Enable(&timer1);
//		TIMER0_voidSetCallBackfn(Isr_Tog_Led);
	while(1)
	{

	}
}
void led1(void)
{
//	static u16 counter1;
//			counter1++;
//	if (counter1==1000)
//	{
//	DIO_ErrStateSetPinValue(DIO_GroupD, Pin7, DIO_High);
	Tog_Bit(portd,7); //led 1 stays on each 1 sec
//	_delay_ms(500);
//	Tog_Bit(portd,7);
//	counter1=0;
//	}
}
void led2(void)
{
//	static u16 counter2;
//				counter2++;
//		if (counter2==2000)
//		{
	Tog_Bit(portd,6);
//	_delay_ms(500); //led 2 turns on after 2 sec then turns off
//	Tog_Bit(portd,6);

//	counter2=0;
//		}
}
void led3(void)
{
//	static u16 counter3;
//					counter3++;
//			if (counter3==3000)
//			{
	Tog_Bit(portd,5);
//	_delay_ms(500); //led 3 turns on after 3 sec then turns off
//	Tog_Bit(portd,5);
//	counter3=0;
//			}
}


