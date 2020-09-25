/***********************************************************************************/
/*   Author  : Doaa Maher 													       */
/*   Date 	 : 16/8/2020 														   */
/* 	 Version : 1.0															   	   */
/*   Type    : GPIO Driver 														   */
/****************************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H
		
/* 			Defining the base addresses of each pin we'll use (A,B AND C)          */
#define GPIO_PORTA_BASE_ADDRESS				0x40010800	
#define GPIO_PORTB_BASE_ADDRESS				0x40010C00
#define GPIO_PORTC_BASE_ADDRESS				0x40011000

/* 				     	Registers Defenitions for PORTA							   */
#define GPIOA_CRL 							*((u32 *)(GPIO_PORTA_BASE_ADDRESS + 0x00))   
#define GPIOA_CRH							*((u32 *)(GPIO_PORTA_BASE_ADDRESS + 0x04))   
#define GPIOA_IDR							*((u32 *)(GPIO_PORTA_BASE_ADDRESS + 0x08))   
#define GPIOA_ODR 							*((u32 *)(GPIO_PORTA_BASE_ADDRESS + 0x0C))   
#define GPIOA_BSR							*((u32 *)(GPIO_PORTA_BASE_ADDRESS + 0x10))   
#define GPIOA_BRR 							*((u32 *)(GPIO_PORTA_BASE_ADDRESS + 0x14))   
#define GPIOA_LCK 							*((u32 *)(GPIO_PORTA_BASE_ADDRESS + 0x18))   

/* 				     	Registers Defenitions for PORTB							   */
#define GPIOB_CRL 							*((u32 *)(GPIO_PORTB_BASE_ADDRESS + 0x00))   
#define GPIOB_CRH							*((u32 *)(GPIO_PORTB_BASE_ADDRESS + 0x04))   
#define GPIOB_IDR							*((u32 *)(GPIO_PORTB_BASE_ADDRESS + 0x08))   
#define GPIOB_ODR 							*((u32 *)(GPIO_PORTB_BASE_ADDRESS + 0x0C))   
#define GPIOB_BSR							*((u32 *)(GPIO_PORTB_BASE_ADDRESS + 0x10))   
#define GPIOB_BRR 							*((u32 *)(GPIO_PORTB_BASE_ADDRESS + 0x14))   
#define GPIOB_LCK 							*((u32 *)(GPIO_PORTB_BASE_ADDRESS + 0x18)) 

/* 				     	Registers Defenitions for PORTC							   */
#define GPIOC_CRL 							*((u32 *)(GPIO_PORTC_BASE_ADDRESS + 0x00))   
#define GPIOC_CRH							*((u32 *)(GPIO_PORTC_BASE_ADDRESS + 0x04))   
#define GPIOC_IDR							*((u32 *)(GPIO_PORTC_BASE_ADDRESS + 0x08))   
#define GPIOC_ODR 							*((u32 *)(GPIO_PORTC_BASE_ADDRESS + 0x0C))   
#define GPIOC_BSR							*((u32 *)(GPIO_PORTC_BASE_ADDRESS + 0x10))   
#define GPIOC_BRR 							*((u32 *)(GPIO_PORTC_BASE_ADDRESS + 0x14))   
#define GPIOC_LCK 							*((u32 *)(GPIO_PORTC_BASE_ADDRESS + 0x18)) 



#endif



