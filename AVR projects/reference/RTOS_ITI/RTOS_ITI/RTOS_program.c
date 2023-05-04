/*
 * RTOS_program.c
 *
 *  Created on: Apr 11, 2023
 *      Author: Abdullah.Abomosallam
 */

#include"RTOS_private.h"
#include"RTOS_pcfg.h"
#include"RTOS_inertface.h"
#include"../MCAL/GIE/GIE_interface.h"
#include"TIMER0/TIMER0_interface.h"
void CreateTask(u8 priorityy, u16 periodicityy,void (*taskPTRfunc)(void))
{

task_type task;
task.priority=priorityy;
task.periodicity=periodicityy;
task.taskFUNC=taskPTRfunc;
//assume task priorty is the inddex on array &each task has single priorty
System_task[priorityy]=task;

}
void RTOS_start(void)
{
GIE_voidEnable();
TIMER0_voidTimer0INTEnable();
TIMER0_voidTimer0Init(PRESCALER_64,0,125);
TIMER0_voidSetCallBack(&scheduler);


}
static void scheduler (void)
{

static u16 systemtickCounter=0;
systemtickCounter++;

for(u8 taskCounter=0;taskCounter<TASK_NUM;TASK_NUM++)
{

	if(systemtickCounter%System_task[taskCounter].periodicity==0)
	{
		if(System_task[taskCounter].taskFUNC!=NULL)
		{
		System_task[taskCounter].taskFUNC();
		}

	}



}





}
