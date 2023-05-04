/*
 * RTOS_interface.h
 *
 *  Created on: Apr 15, 2023
 *      Author: hp
 */

#ifndef RTOS_RTOS_INTERFACE_H_
#define RTOS_RTOS_INTERFACE_H_
#include "../Common/Bit_Math.h"
#include "../Common/STD_types.h"
#include "RTOS_private.h"
task_type CreatTask (u8 periority,u16 periodicity,void (*taskPtrFunc)(void));
void RTOS_voidStart(Timer_Prop *Timer1,ModesTimer_Prop *timer);

#endif /* RTOS_RTOS_INTERFACE_H_ */
