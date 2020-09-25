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
/* Song */
#include "file.h"

#include "DIO_private.h" // Wrong

volatile u16 i= 0;

void SetDAC (void)
{
	GPIOA_ODR = stillworth_raw[i];
	i++;
	if (i == 42797)
	{
		i=0;
	}
}


void main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2 ,2);

	MGPIO_VidSetPinDirection(GPIOA,0,0b0010);
	MGPIO_VidSetPinDirection(GPIOA,1,0b0010);
	MGPIO_VidSetPinDirection(GPIOA,2,0b0010);
	MGPIO_VidSetPinDirection(GPIOA,3,0b0010);
	MGPIO_VidSetPinDirection(GPIOA,4,0b0010);
	MGPIO_VidSetPinDirection(GPIOA,5,0b0010);
	MGPIO_VidSetPinDirection(GPIOA,6,0b0010);

	MSTK_voidInit();

	MSTK_voidSetIntervalPeriodic(125,SetDAC );

	while(1)
	{


	}


}
