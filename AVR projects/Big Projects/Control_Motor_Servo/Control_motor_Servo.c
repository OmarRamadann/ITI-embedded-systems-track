/*project
 * control duty cycle of MOTOR and SERVO
 * by varying the shape of the triggering signal
 * connecting MOTOR on OC0 pin and SERVO on OC1 pin
 */

#include "../MCAL/DIO/DIO_interface.h"

#include"../common/definitions.h"
#include "../HAL/KeyPad_Driver/KeyPad_interface.h"
#include"../HAL/LCD_Driver/LCD_interface.h"
#include "../MCAL/DIO/DIO_register.h"
#include "../MCAL/Timers/Timer0/Timer0_interface.h"
#include "../HAL/Led_Driver/Led_Configuration.h"
#include "../Common/Bit_Math.h"
#include "../MCAL/Timers/Timer0/Timer0_register.h"
//#include "../HAL/KeyPad_Driver/KeyPad_private.h"

#include<util/delay.h>
/****************************************Timer1 REGs******************************************************************/

#define TCCR1A *( ( volatile u8*)0x4F)
#define TCCR1B *( ( volatile u8*)0x4E)
#define TCNT1 *( ( volatile u16*)0x4C)
#define OCR1A *( ( volatile u16*)0x4A)
#define ICR1 *( ( volatile u16*)0x46)
/****************************************Timer1 REGs******************************************************************/

//#define KeyPad_Rows  4
//#define KeyPad_Columns  4
//u8 KeyPad_Values[KeyPad_Rows][KeyPad_Columns]={{'T','S','I','D'},{1,2,3,4},{5,6,7,8},{9,0,'+','='}};
//u8 Column_Value;
//u8 Switchpressed
 u8 arr_value[3];//array to carry the values pressed on Keypad
 u8 iterator=-1;
 u8 flag_fill;//flag shows that the user finished entering values and ready to record the number
 u8 Mode_Motor;
 u8 Mode_Servo;
 u8 chk;
Lcd_Info lcd1={DIO_GroupD,DIO_GroupD,DIO_GroupD,Pin0,Pin1,Pin2,DIO_GroupA};
KeyPad_Info keypad1={DIO_GroupB,DIO_GroupB,DIO_GroupB,DIO_GroupB,DIO_GroupC,Pin0,Pin1,Pin2,Pin4,Pin0,Pin1,Pin2,Pin3};
static KeyPad_status Status;
void Isr_Time(void);
void Welcome (void);
void main()
{
/************************************************timer0 init********************************************************/
		Set_Bit(SREG,7);
		//fast pwm mode
			Set_Bit(TCCR0,3);
			Set_Bit(TCCR0,6);
			//prescaler 64
			Set_Bit(TCCR0,0);
			Set_Bit(TCCR0,1);
			Clr_Bit(TCCR0,2);
			//compare match interrupt enable
			//Set_Bit(TIMSK,1);
			//make pin OC0 non_inv
			Clr_Bit(TCCR0,COM00);
			Set_Bit(TCCR0,COM01);
		//OCR0 =125;//count for 1000usec(1msec) of 256
		//TIMER10_voidSetCallBackfn(Isr_Time);
			DIO_ErrStateSetPinDirection(DIO_GroupB, Pin3, DIO_Output);
			DIO_ErrStateSetPinDirection(DIO_GroupD, Pin5, DIO_Output);//make OC1A pin output
		OCR0=0;//default for motor not working
/************************************************timer0 init********************************************************/


/****************************************Timer1 init******************************************************************/
		//OC1A pin as fast PWM non inverting
		Set_Bit(TCCR1A,7);
		Clr_Bit(TCCR1A,6);
		//select fast PWM not 8bits(256) but controlled using ICR
		Clr_Bit(TCCR1A,0);
		Set_Bit(TCCR1A,1);
		Set_Bit(TCCR1B,3);
		Set_Bit(TCCR1B,4);
		//ICR1*prescaler=8mhz(clk)*20msec(periodic time of servo)
		//.select prescaler 256 for low power consumption -->low value of ICR
		ICR1=625;
		Clr_Bit(TCCR1B,0);
		Clr_Bit(TCCR1B,1);
		Set_Bit(TCCR1B,2);
		OCR1A=31;

/****************************************Timer1 init******************************************************************/

		Lcd_VoidInit(&lcd1);
		KeyPad_VoidInit(&keypad1);
		//Lcd_VoidGoXY(&lcd1, 0, 0x5);
		DIO_ErrStateSetPinDirection(DIO_GroupC, Pin5, DIO_Output);
		DIO_ErrStateSetPinDirection(DIO_GroupC, Pin6, DIO_Output);
		DIO_ErrStateSetPinValue(DIO_GroupC, Pin5, DIO_Low);
		DIO_ErrStateSetPinValue(DIO_GroupC, Pin6, DIO_High);
		Welcome();

	while(1)
		{
		KeyPad_U8SwitchPressed(&keypad1,&Status);

		 if(Status.Switchpressed=='M')
		{

			Mode_Motor=Status.Switchpressed;
			Lcd_VoidSendCommand(LCD_ClearDisplay, &lcd1);
			Lcd_VoidSendString("Enter DutyCycle:", &lcd1);
			Lcd_VoidGoXY(&lcd1, 0, 0x40);
			Lcd_VoidSendString("from 0% to 100%", &lcd1);
			_delay_ms(250);

		}

		else if(Status.Switchpressed=='S')
		{
			Mode_Servo=Status.Switchpressed;
			Lcd_VoidSendCommand(LCD_ClearDisplay, &lcd1);
			Lcd_VoidSendString("Enter Angle:", &lcd1);
			Lcd_VoidGoXY(&lcd1, 0, 0x40);
			Lcd_VoidSendString("from 0,90,180", &lcd1);
			_delay_ms(250);
		}




		else if(Status.Switchpressed==1||Status.Switchpressed==0||Status.Switchpressed==2||Status.Switchpressed==3||Status.Switchpressed==4||Status.Switchpressed==5||Status.Switchpressed==6||Status.Switchpressed==7||Status.Switchpressed==8||Status.Switchpressed==9)//else only is danger as th ekeypad reads high as else not presed case
						{
							if(Mode_Motor=='M')

							{
							flag_fill=1;
							if (Status.flag==1)
							{
								iterator++;

								if (iterator==3)//need only 3 numbers to represent duty cycle
								{
									iterator=0;

								}
							}
							//Lcd_VoidSendCommand(LCD_ClearDisplay, &lcd1);
							Lcd_VoidGoXY(&lcd1, 0, 0x00);

							arr_value[iterator] =Status.Switchpressed;
							Lcd_VoidSendString("Duty Cycle:", &lcd1);
							Lcd_VoidSendNumber(arr_value[0], &lcd1);
							Lcd_VoidSendNumber(arr_value[1], &lcd1);
							Lcd_VoidSendNumber(arr_value[2], &lcd1);
							Lcd_VoidSendString("%", &lcd1);
							//_delay_ms(300);
						}

							else if(Mode_Servo=='S')

							{
							flag_fill=1;
							if (Status.flag==1)
							{
								iterator++;

								if (iterator==3)//need only 3 numbers to represent duty cycle
								{
									iterator=0;

								}
							}
							//Lcd_VoidSendCommand(LCD_ClearDisplay, &lcd1);
							Lcd_VoidGoXY(&lcd1, 0, 0x00);

							arr_value[iterator] =Status.Switchpressed;
							Lcd_VoidSendString("Angle:", &lcd1);
							Lcd_VoidSendNumber(arr_value[0], &lcd1);
							Lcd_VoidSendNumber(arr_value[1], &lcd1);
							Lcd_VoidSendNumber(arr_value[2], &lcd1);
							Lcd_VoidSendString(" Degree", &lcd1);
							//_delay_ms(300);
						}







						}


		else if (Status.Switchpressed=='T')//if trigger switch pressewd
		{
			if(Mode_Motor=='M')
			{
				u16 DC=arr_value[0]*100+arr_value[1]*10+arr_value[2];
				if (DC==0)
				{
					OCR0=0;
				}
				else
				{
					OCR0=(DC*256)/100-1;
				}

				Lcd_VoidSendCommand(LCD_ClearDisplay, &lcd1);
				Lcd_VoidSendString("Motor ON", &lcd1);
				Lcd_VoidGoXY(&lcd1, 0, 0x40);
				Lcd_VoidSendString("speed=", &lcd1);
				Lcd_VoidSendNumber(DC, &lcd1);
				Lcd_VoidSendString("%", &lcd1);
				Mode_Motor='i';
			}
			else if (Mode_Servo=='S')
			{
				u8 Angle=arr_value[0]*100+arr_value[1]*10+arr_value[2];
				switch (Angle)
				{
				case 0:
				OCR1A=31;
				break;
				case 90:
				OCR1A=47;
				break;
				case 180:
				OCR1A=63;
				break;
				}
				Lcd_VoidSendCommand(LCD_ClearDisplay, &lcd1);
				Lcd_VoidSendString("Servo ON", &lcd1);
				Lcd_VoidGoXY(&lcd1, 0, 0x40);
				Lcd_VoidSendString("Angle=", &lcd1);
				Lcd_VoidSendNumber(Angle, &lcd1);
				Lcd_VoidSendString("degree", &lcd1);
				Mode_Servo='u';
			}
		}


		else if(Status.Switchpressed=='E')//emergency stop
		{
			OCR0=0;//motor stops
			Lcd_VoidSendCommand(LCD_ClearDisplay, &lcd1);
			Lcd_VoidSendString("Motor Stopped", &lcd1);
			_delay_ms(1000);
			Lcd_VoidSendCommand(LCD_ClearDisplay, &lcd1);
			Welcome();
			Status.Switchpressed='i';
		}

		else if (Status.Switchpressed=='D')
		{
			Tog_Bit(portc,6);
			Tog_Bit(portc,5);
			Status.Switchpressed='i';
//			DIO_ErrStateSetPinValue(DIO_GroupC, Pin6, DIO_Low);
//			DIO_ErrStateSetPinValue(DIO_GroupC, Pin5, DIO_High);
		}
		}
}



void Welcome (void)
		{
		Lcd_VoidSendString("Hello! Omar", &lcd1);
		_delay_ms(2000);
		Lcd_VoidSendCommand(LCD_ClearDisplay, &lcd1);
		Lcd_VoidSendString("Select Mode", &lcd1);
		Lcd_VoidGoXY(&lcd1, 0, 0x40);
		Lcd_VoidSendString("1.Motor  2.Servo", &lcd1);
		//_delay_ms(1000);
		}
