/*
 * RTOS_inertface.h
 *
 *  Created on: Apr 11, 2023
 *      Author: Abdullah.Abomosallam
 */

#ifndef RTOS_ITI_RTOS_INERTFACE_H_
#define RTOS_ITI_RTOS_INERTFACE_H_
#include"../SERVICES/BIT_math.h"
#include"../SERVICES/STD_TYPES.h"
#include"RTOS_private.h"

task_type CreateTask(u8 priority, u16 periodicity,void (*taskPTRfunc)(void));
void RTOS_start(void);

#endif /* RTOS_ITI_RTOS_INERTFACE_H_ */
