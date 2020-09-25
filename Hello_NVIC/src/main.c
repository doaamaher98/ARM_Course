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
#include "NVIC_interface.h"

/* Wanted to turn 3 LEDs on when an interrupt happens */
void main (void)
{
	/* Let's intialize our Clock : on same clock [HSE] with 8MHz*/
	RCC_voidInitSysClock();
	// Enabling the Clock on the RCC peripheral = GPIOA //
	RCC_voidEnableClock(RCC_APB2,2);

	/* Pin Modes */
	/* We'll use 3 LEDS :
	 * Each one would be an output with 2Mhz
	 */
	MGPIO_voidSetPinDirection(GPIOA , 0 ,0b0010 ); /* Output PP 2Mhz */
	MGPIO_voidSetPinDirection(GPIOA , 1 ,0b0010 ); /* Output PP 2Mhz */
	MGPIO_voidSetPinDirection(GPIOA , 2 ,0b0010 ); /* Output PP 2Mhz */

	/* Enable EXTI0 & EXTI1 Interrupt from NVIC, in vector table = 6,7 */
	MNVIC_voidEnableInterrupt(6);
	MNVIC_voidEnableInterrupt(7);
	/* Set it's Pending Flag								 */
	MNVIC_voidSetPendingFlag(6);

	while(1)
	{

	}
}
/* 		As for the External Interrupt; use any one with a special way to write the function "ISR"
	    Just to Set their Pending Flag to enable this Interrupt without even using the peripheral itself 		*/
	void EXTI0_IRQHandler(void)
	{
		/* Light your first LED in A0 in GPIO 																	*/
		MGPIO_voidSetPinValue(GPIOA , 0 , GPIO_HIGH);
		/* Set Pending Flag for EXTI1 																			*/
		MNVIC_voidSetPendingFlag(7); 			// Firing it
		/* Light your second LED in A1 in GPIO 																	*/
		MGPIO_voidSetPinValue(GPIOA , 1 , GPIO_HIGH);
	}

	void EXTI1_IRQHandler(void)
	{
		/* Light your third LED in A0 in GPIO 	*/
		MGPIO_voidSetPinValue(GPIOA , 2 , GPIO_HIGH);

	}
