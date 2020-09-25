/**************************************************/
/* Author 		: Doaa Maher					  */
/* Date   		: 12/8/2020                       */
/* Version 		: V01							  */
/**************************************************/
// Header guard
#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H

// Writing the config. of Initializing the system clock depending on user's choice
/* 3 types of config. : 1- Pre build  config.
                        2- Link time  config.
						3- Post build config.   		    */
						
/* Options :        RCC_HSE_CRYSTAL ,
					RCC_HSE_RC ,
					RCC_HSI , 
					RCC_PLL 								*/
#define RCC_CLOCK_TYPE        RCC_HSE_CRYSTAL // < Type the desierd type here.

/* Options :        RCC_PLL_INPUT_HSI_DIV_2
					RCC_PLL_INPUT_HSE
					RCC_PLL_INPUT_HSE_DIV_2			
															 */
/* Note : Select value if only you have PLL clock source	 */
// If HSE_CRYSTAL was selected, there will be no use to PLL 
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT         RCC_PLL_INPUT_HSE_DIV_2
#endif

/* PLL Multiplexer value                                     */
// Options 2 to 16 with the same #if statement
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL       4
#endif




#endif