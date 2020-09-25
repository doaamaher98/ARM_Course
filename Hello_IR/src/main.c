/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DoaaMaher
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "EXTI_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"

volatile u8 u8StartFlag = 0; /* To know if the Falling edge was the frist one from the start bit or was another falling edge */

volatile u32 u32FrameData[50] = {0}; // Intiazling an array
volatile u8 u8EdgeCounter 	 =  0;

volatile u8 u8Data 			= 	0; /* To gather all your data here */

void voidPlay(void)
{
	switch (u8Data)
	{
	case 69: MGPIO_voidSetPinValue(GPIO_A ,PIN2, GPIO_HIGH); break;
	case 71: MGPIO_voidSetPinValue(GPIO_A ,PIN2, GPIO_LOW); break;

	}
}

/* Take Action function is called after the interrupt was fired */
void voidTakeAction(void)
{
	u8Data = 0;					   /* To ensure the value if i clicked on the remote by mistake */
	u8 	i  = 0;

	/* First checking if it passed on the Start byte */
	if ( (u32FrameData[0] >= 10000) && (u32FrameData[0] <= 14000) )
	{
		/* Loop through your next bits to know if they are "1" or "0" */
		// Bit 17 = LEAST SIGNIFICANT BIT
		for (i=0 ; i<8 ; i++)
		{	if ( (u32FrameData[17+i] >= 2000) && (u32FrameData[17+i] <= 2300 ) )
			{
				SET_BIT(u8Data,i);
			}
			else
			{CLR_BIT(u8Data,i);}
		}
		/* Calling the play function to control LED with remote */
		voidPlay();
	}
	else
	{/* Invalid Frame */}

	/* Reset your values */
	u8StartFlag 	=0;
	u32FrameData[0] =0;
	u8EdgeCounter   =0;
	/* NOW, IAM READY TO RECIEVE ANOTHER CLICK FROM THE REMOTE */
}

void voidGetFrame(void)
{
	/* First we check the StartFlag was the first or not --> Start bit
	 * If it was the first, START THE TIMER TO CALCULATE IT */
	if (u8StartFlag ==0 )
	{
		/* Start Timer by counting 1 sec = 10**6 uSec
		 * After the timer finished the 1 sec, call the TakeAction Function */
		MSTK_voidSetIntervalSingle(1000000, voidTakeAction); // Choosed "1 sec" to be as much large as we could to prevent any overflow on the timer

		// Now make your FLAG =1 to enter the else as it's sure now it's from zero
		u8StartFlag = 1;
	}
	else
	{
		/* Now checking how much time did it count */
		u32FrameData[u8EdgeCounter] = MSTK_u32GetElapsedTime();
		/* for the start bit = 13,500Usec */

		// Then Reset the timer and go again
		MSTK_voidSetIntervalSingle(1000000, voidTakeAction);
		u8EdgeCounter++; // To save in the array's new lcoation by incrementing it
	}
}

void main(void)
{
	/* First Step Every time 				*/
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, 2);

	/* I/O Pins Intialization 				*/
	MGPIO_voidSetPinDirection(GPIO_A , 0, INPUT_FLOATING);		 // A0 Input Floating from IR Transmitter
	MGPIO_voidSetPinDirection(GPIO_A , 1, OUTPUT_SPEED_2MHZ_PP); // A1 Output PP --> "BLUE"
	MGPIO_voidSetPinDirection(GPIO_A , 2, OUTPUT_SPEED_2MHZ_PP); // A2 Output PP --> "GREEN"
	MGPIO_voidSetPinDirection(GPIO_A , 3, OUTPUT_SPEED_2MHZ_PP); // A3 Output PP --> "RED"

	/* Intialize Drivers 														*/
	/* EXTI Intialization at interrupt A0 										*/
	/* First "SetCallBack" function before any setting any Interrupt	 		*/
	MEXTI_voidSetCallBack(voidGetFrame);

	MEXTI_voidInit(); /* EXTI0 ENABLED AT A0 as a FALLING_EGDE 	*/

	/* 						Enable the EXTI0 from NVIC			*/
	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt(6); 				// EXTI0

	/* Intialize SysTick */
	MSTK_voidInit(); // Enable Systick on AHB/8 1Mhz --> 1uSec for each

	while (1)
	{

	}
}


