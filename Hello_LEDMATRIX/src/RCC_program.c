/**************************************************/
/* Author 		: Doaa Maher					  */
/* Date   		: 12/8/2020                       */
/* Version 		: V01							  */
/**************************************************/
// Including the needed drivers We'll use

// First: Libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// Second: Interfaces of lower files
/* But here there are no lower layers below the MCAL */

// Third: Driver Files : 1- Interface files
/*                       2- Private or Config files */
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
// Function choose which clock would be on the processor --> CR Register 
//Intializing in config file.
void RCC_voidInitSysClock (void) 
{
		#if     RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
			RCC_CR   = 0x00010000; /* Enable HSE with no bypass */
			RCC_CFGR = 0x00000001;

		#elif   RCC_CLOCK_TYPE == RCC_HSE_RC
			RCC_CR   = 0x00050000; /* Enable HSE with bypass */
			RCC_CFGR = 0x00000001;

		#elif   RCC_CLOCK_TYPE == RCC_HSI
			RCC_CR   = 0x00000081; /* Enable HSI + Trimming = 0 */
			RCC_CFGR = 0x00000000;

		#elif   RCC_CLOCK_TYPE == RCC_PLL
			#if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2

			#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2

			#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE

			#endif

		#else
			#error("You choosed Wrong Clock type")
		#endif

}


// Functions 1- Set bit -- Enabling the Clock is a MUST
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
	{
		if (Copy_u8PerId <= 31)
		{
			switch (Copy_u8BusId)
			{
				case RCC_AHB  : SET_BIT(RCC_AHBENR  ,Copy_u8PerId);   break;
				case RCC_APB1 : SET_BIT(RCC_APB1ENR ,Copy_u8PerId);   break;
				case RCC_APB2 : SET_BIT(RCC_APB2ENR ,Copy_u8PerId);   break;
			}
		}

		else
		{
			/* Return Error */
		}

	}
	
// Function 2- Clear bitvoid RCC_voidEnableClock  (u8 Copy_u8BusId , u8 Copy_u8PerId)
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
	{
		if (Copy_u8PerId <= 31)
		{
			switch (Copy_u8BusId)
			{
				case RCC_AHB  : CLR_BIT(RCC_AHBENR  ,Copy_u8PerId);   break;
				case RCC_APB1 : CLR_BIT(RCC_APB1ENR ,Copy_u8PerId);   break;
				case RCC_APB2 : CLR_BIT(RCC_APB2ENR ,Copy_u8PerId);   break;
				default : break;
			}
		}

		else
		{
			/* Return Error */
		}
	}

