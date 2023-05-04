/*
 * RTOS_private.h
 *
 *  Created on: Apr 15, 2023
 *      Author: hp
 */

#ifndef RTOS_RTOS_PRIVATE_H_
#define RTOS_RTOS_PRIVATE_H_
#include "../Common/Bit_Math.h"
#include "../Common/STD_types.h"

typedef struct
{
	u8 priority;
	u16 periodicity;
	void (*taskFUNC)(void);
}task_type;



#endif /* RTOS_RTOS_PRIVATE_H_ */
