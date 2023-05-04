/*project
 * normal clock:counter each second for 59 seconds,then 59minutes,then 24 hours
 //1.uses ctc counter to count 1 second
 //2.each 1 second increment seconds counter u8 counter 0
 //3.when it reaches 59 ,clear it and increment minutes counter
 //4.same till the hours counter
 //5.send on LCD this form Hcounter':'Mconter':'Scounter
 * Stopwatch:gets a number from user ,the starts to count down each 1 second
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
//#include "../HAL/EEPROM_Driver/EEPROM_interface.h"//for EEProm if used


#include<util/delay.h>

 u8 Spcounter;
 u8 Mpcounter;
 u8 Hpcounter;
//counts for stopwatch (must be u8 as 0-1=255,but for u16 (0-1 !=255) (more than 8 ones .16 ones))
 u8 Smcounter;
 u8 Mmcounter;
 u8 Hmcounter;
 u8 arr_num[6]={0};
 u8 iterator=-1;
  //static u8 flag;
 u8 flag_FillDecrement=0;
 u8 flag_FillIncrement=0;
 u8 XLoc=0;
 u8 YLoc=0x00;
 u8 Clk_Adjust;
 u8 Stp_Adjust;
 Timer_Prop timer0={CTC,8,Clk64,256,1000000,1000};
 ModesTimer_Prop CTC0;
Lcd_Info lcd1={DIO_GroupB,DIO_GroupB,DIO_GroupB,Pin5,Pin4,Pin6,DIO_GroupA};
KeyPad_Info keypad1={DIO_GroupC,DIO_GroupC,DIO_GroupC,DIO_GroupC,DIO_GroupD,Pin2,Pin3,Pin4,Pin5,Pin0,Pin1,Pin2,Pin3};
static KeyPad_status Status;
void Isr_Time(void);
void (*Timer2_ptr_fn)(void)=Null;

void main()
{
/******************************************External EEPROM message at beginning******************************************************/
//	u8 arr[13]="Welcome OMAR";
//	EEPROM_voidInit();
//	_delay_ms(100);

//	for (u8 i=0;i<13;i++) //function to save string
//	{
//		EEPROM_Write_Byte(i, arr[i]);
//		_delay_ms(100);
//	}
//
//	for (u8 i=0;i<13;i++) //function to display string
//	{
//		Lcd_VoidSendChar(EEPROM_Read_Byte(i), &lcd1);
//	//	_delay_ms(100);
//	}
/******************************************Code start******************************************************/

	TIMER0_voidInit(&timer0, &CTC0);
	Timer_Enable(&timer0);
	Lcd_VoidInit(&lcd1);
	KeyPad_VoidInit(&keypad1);
	Lcd_VoidSendString("Hello Omar Essam", &lcd1);//welcoming message
	_delay_ms(1000);
		OCR0 =CTC0.OCR_Value;//count for 1000usec
		TIMER0_voidSetCallBackfn(Isr_Time);

	while(1)
		{
		KeyPad_U8SwitchPressed(&keypad1,&Status);


		if (Status.Switchpressed=='T')
			{
			if (flag_FillIncrement==1)
			{

				Clk_Adjust=0;//disable the adjust stopwatch button
						Hpcounter=arr_num[0]*10+arr_num[1];
						Mpcounter=arr_num[2]*10+arr_num[3];
						if (Mpcounter>59)
						{
							Lcd_VoidSendString("enter minutes in range 0:59", &lcd1);
							Mpcounter=59;
						}
						Spcounter=arr_num[4]*10+arr_num[5];
						if (Spcounter>59)
							{
							Lcd_VoidSendString("enter seconds in range 0:59", &lcd1);
							Spcounter=59;
									}
						flag_FillIncrement=0;
					}



					Lcd_VoidGoXY(&lcd1, 0, 0x00);
					Lcd_VoidSendNumber(Hpcounter, &lcd1);
					Lcd_VoidSendChar(':', &lcd1);
					//Lcd_VoidGoXY(&lcd1, XLoc, 0x02);
					Lcd_VoidSendNumber(Mpcounter, &lcd1);
					Lcd_VoidSendChar(':', &lcd1);
					Lcd_VoidSendNumber(Spcounter, &lcd1);
				}
				else if (Status.Switchpressed=='S')
				{
//					
					if (flag_FillDecrement==1)//this flag to make the following IF condition run one time only
					{
						Stp_Adjust=0;//disable the adjust stopwatch button
						Hmcounter=arr_num[0]*10+arr_num[1];
						Mmcounter=arr_num[2]*10+arr_num[3];
						if (Mmcounter>59)
						{
							Lcd_VoidSendString("enter minutes in range 0:59", &lcd1);
							Mmcounter=59;
						}
						Smcounter=arr_num[4]*10+arr_num[5];
						if (Smcounter>59)
							{
							Lcd_VoidSendString("enter seconds in range 0:59", &lcd1);
							Smcounter=59;
									}
						flag_FillDecrement=0;
					}
					//display the stopwatch values
					Lcd_VoidGoXY(&lcd1, 0, 0x00);
					Lcd_VoidSendNumber(Hmcounter, &lcd1);
					Lcd_VoidSendChar(':', &lcd1);
					Lcd_VoidSendNumber(Mmcounter, &lcd1);
					Lcd_VoidSendChar(':', &lcd1);
					Lcd_VoidSendNumber(Smcounter, &lcd1);

				}
					else if(Status.Switchpressed=='I')
					{
						Clk_Adjust=Status.Switchpressed;
						Lcd_VoidSendString("Adjst CLK/STPWCH", &lcd1);
						_delay_ms(100);
						Lcd_VoidSendCommand(LCD_ClearDisplay, &lcd1);
//						
					}

					else if(Status.Switchpressed=='D')
					{
						Stp_Adjust=Status.Switchpressed;
						Lcd_VoidSendString("Adjust TIMER", &lcd1);
						_delay_ms(100);
						Lcd_VoidSendCommand(LCD_ClearDisplay, &lcd1);
//						
					}




				else if(Status.Switchpressed==1||Status.Switchpressed==0||Status.Switchpressed==2||Status.Switchpressed==3||Status.Switchpressed==4||Status.Switchpressed==5||Status.Switchpressed==6||Status.Switchpressed==7||Status.Switchpressed==8||Status.Switchpressed==9)//else only is danger as th ekeypad reads high as else not presed case
				{
					//Lcd_VoidSendChar(Clk_Adjust, &lcd1);
					if(Stp_Adjust=='D')

					{
					flag_FillDecrement=1;
					//Lcd_VoidSendNumber(flag, &lcd1);
					//Lcd_VoidSendString("D is presses", &lcd1);

					if (Status.flag==1)//if i pushed any  button
					{
						//YLoc+=2;
						iterator++;

						//flag_switched=0;
						if (iterator==6)
						{
							iterator=0;

						}
					}
					Lcd_VoidGoXY(&lcd1, 0, 0x00);

					arr_num[iterator] =Status.Switchpressed;

					Lcd_VoidSendNumber(arr_num[0], &lcd1);
					Lcd_VoidSendNumber(arr_num[1], &lcd1);
					Lcd_VoidSendChar(':', &lcd1);
					Lcd_VoidSendNumber(arr_num[2], &lcd1);
					Lcd_VoidSendNumber(arr_num[3], &lcd1);
					Lcd_VoidSendChar(':', &lcd1);
					Lcd_VoidSendNumber(arr_num[4], &lcd1);
					Lcd_VoidSendNumber(arr_num[5], &lcd1);

				}

					else if(Clk_Adjust=='I')
					{
						flag_FillIncrement=1;
						if (Status.flag==1)
						{
							iterator++;
							if (iterator==6)
							{
								iterator=0;

							}
						}
						Lcd_VoidGoXY(&lcd1, 0, 0x00);

						arr_num[iterator] =Status.Switchpressed;

						Lcd_VoidSendNumber(arr_num[0], &lcd1);
						Lcd_VoidSendNumber(arr_num[1], &lcd1);
						Lcd_VoidSendChar(':', &lcd1);
						Lcd_VoidSendNumber(arr_num[2], &lcd1);
						Lcd_VoidSendNumber(arr_num[3], &lcd1);
						Lcd_VoidSendChar(':', &lcd1);
						Lcd_VoidSendNumber(arr_num[4], &lcd1);
						Lcd_VoidSendNumber(arr_num[5], &lcd1);
					}






				}



	}
}
void Isr_Time(void)
{
	static u32 counter;


		counter++;
		//if (counter==3907)//1 sec,8 scaler,normal
		//if (counter==489)//1sec ,64 scaler,normal
		if (counter==1000)//counted 1 sec
			{
			//TCNT0=184;
			Smcounter--;
			Spcounter++;




			if (Spcounter==60)
			{
				Spcounter=0x00;
				Mpcounter++;

				if(Mpcounter==60)
				{
					Mpcounter=0;
					Hpcounter++;
					if (Hpcounter==24)
					{
						Hpcounter=0;
					}
				}
			}


			 if(Smcounter==255)
						{
				 	 	 	 Smcounter=59;
							Mmcounter--;
							if(Mmcounter==255)
							{
								Mmcounter=0;
								Hmcounter--;
								if(Hmcounter==255)
								{
									Hmcounter=0;

								}
								Mmcounter=59;
							}
						}



			counter=0;
			Lcd_VoidSendCommand(LCD_ClearDisplay, &lcd1);

			}
}
