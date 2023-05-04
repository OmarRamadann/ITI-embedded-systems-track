/*
 * program.c
 *
 *  Created on: Mar 30, 2023
 *      Author: hp
 */

#include "INT1_interface.h"
#include "../../../Common/Bit_Math.h"
#include "INT1_config.h"
#include "INT1_register.h"
//#define INT1_Interrupt 0
#if INT1_Usage==INT1_Interrupt

void (*ptr_fn)(void)=Null;
void INT1_voidInit(Event Copy_signal )
{
	if (Copy_signal==INT1_FallingEdge)
	{
		Set_Bit(MCUCR_Reg,ISC11);
		Clr_Bit(MCUCR_Reg,ISC10);
	}
	else if (Copy_signal==INT1_RisingEdge)
	{
		Set_Bit(MCUCR_Reg,ISC11);
		Set_Bit(MCUCR_Reg,ISC10);
	}
	else if (Copy_signal==INT1_LowLevel)
	{
		Clr_Bit(MCUCR_Reg,ISC11);
		Clr_Bit(MCUCR_Reg,ISC10);
	}
	else if (Copy_signal==INT1_OnChange)
	{
		Clr_Bit(MCUCR_Reg,ISC11);
		Set_Bit(MCUCR_Reg,ISC10);

	}
	Set_Bit(GICR_Reg,INT1);
	Set_Bit(SREG_Reg,I);
}



/*function that has the address for the func
 * that the developer in App. layer wrote as
 * a response to the interrupt
 */
void INT1_voidSetCallBackfn(void(*ptr)(void))
{
	ptr_fn=ptr;
}
void __vector_2(void)

{

	if (ptr_fn!=Null)
	{
		ptr_fn();
	}
}

#elif INT1_Usage ==INT1_Polling
u8 INT1_u8CheckFlag(void)
{
	u8 flag=Get_Bit(GIFR_Reg,INTF1);
	return flag;
}

void INT1_u8ClearFlag(void)
{
	Set_Bit(GIFR_Reg,INTF1);


}

#endif
