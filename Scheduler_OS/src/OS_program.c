/*********************************************************************************/
/* Author    : Doaa Maher                                                       */
/* Version   : V01
/* Topic 	 : RTOS OS 	                                                               */
/* Date      : 7 September 2020                                                     */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

#define NULL 			(void*) 0

/*Array of Tasks		Array of Structure*/
static Task OS_Tasks[NUMBER_OF_TASKS] = {NULL};

void SOS_voidCreateTask(u8 Copy_u8PriorityID , u16 Copy_Periodicity , void (*ptr) (void))
{
	OS_Tasks[Copy_u8PriorityID].periodicity = Copy_Periodicity;
	
	OS_Tasks[Copy_u8PriorityID].Fptr = ptr;

}

void SOS_voidStart(void)
{
	/* 			Intialization 			*/
	/* Take time == Systick */
	MSTK_voidInit();
	
	/* Tick 1 => 1msec */
	/* HSE 8Mhz/8 = 1usec ==> 1000usec ===> 1 msec */
	MSTK_voidSetIntervalPeriodic( 1000 ,Scheduler);
	
	
	
}

volatile u16 TickCounts =0;
/* 								Ordering for tasks 							*/
static  void Scheduler(void)
{
	
	for (u8 i=0 ; i<NUMBER_OF_TASKS ; i++)
	{
		if( (TickCounts % OS_Tasks[i].periodicity) == 0 )
		{
			OS_Tasks[i].Fptr();
		}
	}
	TickCounts++;
	
}







