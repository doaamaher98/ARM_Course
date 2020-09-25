/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DoaaMaher
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "LEDMRX_interface.h"


u8 DataArray[30] = {0, 126, 66, 66, 60, 0, 124, 68, 68, 124, 0, 124, 68, 68, 124, 64, 0, 124, 68, 68, 124, 64, 0, 0, 0, 0, 0, 0, 0, 0};

int main(void)
{
	/* Intializing System clock to be sure it's 8Mhz */
	RCC_voidInitSysClock() ;

	/* Enable System Clock */
	RCC_voidEnableClock(RCC_APB2 , RCC_PORTA) ; // GPIO A
	RCC_voidEnableClock(RCC_APB2 , RCC_PORTB) ; // GPIO B

	/* Init SysTick */
	MSTK_voidInit();

	/* Init Led Matrix */
	LEDMRX_voidInit();

	/* Send Data to LED Matrix */
	HLEDMRX_voidAnimation(DataArray);


	return 0;
}
