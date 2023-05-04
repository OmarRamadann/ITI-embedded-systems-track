/*
 * INT1_interface.h
 *
 *  Created on: Mar 30, 2023
 *      Author: hp
 */

#ifndef MCAL_EXT_INT_INT1_INT1_INTERFACE_H_
#define MCAL_EXT_INT_INT1_INT1_INTERFACE_H_
#include"INT1_private.h"
#include"../../../Common/STD_types.h"
#include "INT1_config.h"

void INT1_voidInit(Event Copy_signal );
void __vector_2(void)__attribute__((signal));
void INT1_voidSetCallBackfn(void(*ptr)(void));
#if INT1_Usage==INT1_Polling
u8 INT1_u8CheckFlag(void);
void INT1_u8ClearFlag(void);

#endif


#endif /* MCAL_EXT_INT_INT1_INT1_INTERFACE_H_ */
