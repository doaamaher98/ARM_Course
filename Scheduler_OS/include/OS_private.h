/*********************************************************************************/
/* Author    : Doaa Maher                                                       */
/* Version   : V01
/* Topic 	 : RTOS OS 	                                                               */
/* Date      : 7 September 2020                                                     */
/*********************************************************************************/
#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

typedef struct 
{
	u16 periodicity		;
	
	void (*Fptr) (void) ;
	
	
} Task;







#endif