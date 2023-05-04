#include "../MCAL/DIO/DIO_interface.h"
#include"../common/definitions.h"
#include "../Common/Bit_Math.h"
#include <util/delay.h>
#define  MCUCSR		(*(volatile u8*)0x54)
#define  WDTCR		(*(volatile u8*)0x41)
void WDT_Disable (void);
void WDT_Eable (void);
void WDT_Prescaler();

void main()
{
	WDT_Prescaler();
	WDT_Eable();
	DIO_ErrStateSetPinDirection(DIO_GroupD, Pin1, DIO_Output);
	DIO_ErrStateSetPinValue(DIO_GroupD, Pin1, DIO_High);
	_delay_ms(1000);
	DIO_ErrStateSetPinValue(DIO_GroupD, Pin1, DIO_Low);
	WDT_Disable();
	while(1)
	{
		//asm("WDR");//refresh timer

	}
}

void WDT_Disable (void)
{
	Set_Bit(WDTCR,3);
	Set_Bit(WDTCR,4);
	WDTCR=0;

}
void WDT_Eable (void)
{
	Set_Bit(WDTCR,3);


}
void WDT_Prescaler()
{
	Set_Bit(WDTCR,0);
	Set_Bit(WDTCR,1);
	Set_Bit(WDTCR,2);
}
