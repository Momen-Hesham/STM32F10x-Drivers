/*********************************/
/* Author	: Mo'men Hesham 	 */
/* Version	: V01				 */
/*********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

#include "STK_interface.h"

#define NULL (void*)0

volatile uint16 TickCounts=0;

// Array of Structures each one consider as a Task
static Task OS_Tasks[NUMBER_OF_TASKS]={NULL};



void SOS_voidCreateTask(uint8 Copy_uint8ID,uint16 Copy_uint16Priodicity,void (*Copy_ptr)(void),uint8 Copy_uint8FirstDelay)
{
	OS_Tasks[Copy_uint8ID].priodicity=Copy_uint16Priodicity;
	OS_Tasks[Copy_uint8ID].Func_ptr=Copy_ptr;
	OS_Tasks[Copy_uint8ID].FirstDelay=Copy_uint8FirstDelay;
	OS_Tasks[Copy_uint8ID].State=TASK_READY;
	
}
static void OS_Scheduler_First_Delay(void)
{
	uint8 i;
	for(i=0;i<NUMBER_OF_TASKS;i++)
	{
		if((OS_Tasks[i].Func_ptr != NULL) && (OS_Tasks[i].State == TASK_READY))
		{
			if(OS_Tasks[i].FirstDelay ==0)
			{
				OS_Tasks[i].FirstDelay=OS_Tasks[i].priodicity-1;
				OS_Tasks[i].Func_ptr();
			}
			else
			{
				OS_Tasks[i].FirstDelay--;
			}
		}
	}
	TickCounts++;
}

static void OS_Scheduler(void)
{
	uint8 i;
	for(i=0;i<NUMBER_OF_TASKS;i++)
	{
		if((TickCounts % OS_Tasks[i].priodicity)==0)
		{
			OS_Tasks[i].Func_ptr();

		}
	}
	TickCounts++;
}
void SOS_voidStart(void)
{
	MSTK_voidInit();	// Initialization
	MSTK_voidSetIntervalPeriodic(1000,OS_MODE);
	
}

void SOS_voidSuspendTask(uint8 Copy_uint8ID)
{
	OS_Tasks[Copy_uint8ID].State=TASK_SUSPEND;
}
void SOS_voidResumeTask(uint8 Copy_uint8ID)
{
	OS_Tasks[Copy_uint8ID].State=TASK_READY;
}
void SOS_voidClearTask(uint8 Copy_uint8ID)
{
	OS_Tasks[Copy_uint8ID].State=TASK_DELETED;
}
