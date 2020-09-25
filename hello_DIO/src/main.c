/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DoaaMaher
 */

// First include Libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

// Defining Registers
#define PORTA_CRL     *((u32*)0x40010800)
#define PORTA_ODR     *((u32*)0x4001080C)

void main (void) {
	/* Intialize clock system is a MUST */
	RCC_voidInitSysClock();

	/* Enable Peripheral 2 on APB2      */
	RCC_voidEnableClock(RCC_APB2 , 2 );

	/* Configure A0 as output Push Pull */
	PORTA_CRL = 0x00000002;
	/* Set A0 output High               */
	PORTA_ODR = 0x00000001;

	while (1) {



	}

}
