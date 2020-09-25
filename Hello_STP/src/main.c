/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DoaaMaher
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "STP_interface.h"

#include "STP_config.h"

void main(void)
{
	/* RCC INIT */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2); // Enable GPIOA

	MGPIO_VidSetPinDirection(GPIOA,0,0b0010 ); /* A0 */
	MGPIO_VidSetPinDirection(GPIOA,1,0b0010 ); /* A1 */
	MGPIO_VidSetPinDirection(GPIOA,2,0b0010 ); /* A2 */

	/* Timer Init */
	MSTK_voidInit();

	//HSTP_voidSendSynchronus(0xAA); /* 1010 1010 */
	u8 i=0;

	while(1)
	{
		for (i=0; i<=7 ; i++)
		{
			HSTP_voidSendSynchronus(1<<i);
			MSTK_voidSetBusyWait(300000); // 300 msec
		}

	}

}


