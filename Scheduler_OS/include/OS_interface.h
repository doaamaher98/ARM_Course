/*********************************************************************************/
/* Author    : Doaa Maher                                                       */
/* Version   : V01
/* Topic 	 : RTOS OS 	                                                               */
/* Date      : 7 September 2020                                                     */
/*********************************************************************************/
#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H


void SOS_voidCreateTask(u8 Copy_u8PriorityID , u16 Copy_Periodicity , void (*ptr) (void));

void SOS_voidStart(void);
void SOS_voidDeleteTask(void);
void SOS_voidPauseTask (void);






#endif







