/**************************************************/
/* Author 		: Doaa Maher					  */
/* Date   		: 12/8/2020                       */
/* Version 		: V01							  */
/**************************************************/
// Header guard
#ifndef _RCC_INTERFACE_H
#define _RCC_INTERFACE_H

// Macros used in .c program
#define 	RCC_AHB     0
#define	    RCC_APB1    1
#define	    RCC_APB2    2


#define 	RCC_PORTA   2
#define 	RCC_PORTB   3
#define 	RCC_PORTC   4


void RCC_voidInitSysClock (void);

void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);







#endif

