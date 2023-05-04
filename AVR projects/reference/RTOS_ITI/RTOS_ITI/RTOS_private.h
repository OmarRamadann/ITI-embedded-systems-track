/*
 * RTOS_private.h
 *
 *  Created on: Apr 11, 2023
 *      Author: Abdullah.Abomosallam
 */

#ifndef RTOS_ITI_RTOS_PRIVATE_H_
#define RTOS_ITI_RTOS_PRIVATE_H_

typedef struct
{

	u8 priority;
	u16 periodicity;
    void (*taskFUNC)(void);

}task_type;

static void scheduler (void);

#endif /* RTOS_ITI_RTOS_PRIVATE_H_ */
