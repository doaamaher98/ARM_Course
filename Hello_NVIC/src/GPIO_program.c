/****************************************************************************/
/*   Author  : Doaa Maher 													*/
/*   Date 	 : 16/8/2020 													*/
/* 	 Version : 1.0															*/
/*   Type    : GPIO Driver 													*/
/****************************************************************************/

// INCLUDE THE "STD_TYPES AND THE BIT_MATH //
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// INCLUDE THE "INTERFACE FILE"          							  //
#include "GPIO_interface.h"
#include "GPIO_private.h"

/*							Functions Impelemtation	 							*/
void MGPIO_voidSetPinDirection (u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8MODE)
{   /*	Switching on the port to know A,B,C?						*/
	switch (copy_u8PORT) {
		case GPIOA :
///	LOW "CRL" [0 --> 7 PINS]  													*/
					if (copy_u8PIN <= 7)
					{
/* 			Reset or Clear the register = 0 -- Shift each 4 bits
			We want to write on only it in CRL register					*/
						GPIOA_CRL &= ~(   0b1111    << (copy_u8PIN *4));
/* 			Now the mode = 0, Write/Set what you want 						*/
						GPIOA_CRL |=  ((copy_u8MODE)<< (copy_u8PIN *4));
					}
///	HIGH "CRH" [8 --> 15 PINS]  
					else if (copy_u8PIN <= 15)
					{
						copy_u8PIN = copy_u8PIN - 8;
/* 			Reset or Clear the register = 0 -- Shift each 4 bits
			We want to write on only it in CRL register					*/
						GPIOA_CRH &= ~(   0b1111    << (copy_u8PIN *4));
/* 			Now the mode = 0, Write/Set what you want 						*/
						GPIOA_CRH |=  ((copy_u8MODE)<< (copy_u8PIN *4));
					}
					break;
/* Doing the same with the other PORTS 								*/
		case GPIOB :
///	LOW "CRL" [0 --> 7 PINS]  													*/
					if (copy_u8PIN <= 7)
					{
/* 			Reset or Clear the register = 0 -- Shift each 4 bits
			We want to write on only it in CRL register					*/
						GPIOB_CRL &= ~(   0b1111    << (copy_u8PIN *4));
/* 			Now the mode = 0, Write/Set what you want 						*/
						GPIOB_CRL |=  ((copy_u8MODE)<< (copy_u8PIN *4));
					}
///	HIGH "CRH" [8 --> 15 PINS]  
					else if (copy_u8PIN <= 15)
					{
/* As our 0 is 8 here, so we make sure of that 								*/
						copy_u8PIN = copy_u8PIN - 8;
/* 			Reset or Clear the register = 0 -- Shift each 4 bits
			We want to write on only it in CRL register					*/
						GPIOB_CRH &= ~(   0b1111    << (copy_u8PIN *4));
/* 			Now the mode = 0, Write/Set what you want 						*/
						GPIOB_CRH |=  ((copy_u8MODE)<< (copy_u8PIN *4));
					}
					break;
		case GPIOC :
///	LOW "CRL" [0 --> 7 PINS]  													*/
					if (copy_u8PIN <= 7)
					{
/* 			Reset or Clear the register = 0 -- Shift each 4 bits
			We want to write on only it in CRL register					*/
						GPIOC_CRL &= ~(   0b1111    << (copy_u8PIN *4));
/* 			Now the mode = 0, Write/Set what you want 						*/
						GPIOC_CRL |=  ((copy_u8MODE)<< (copy_u8PIN *4));
					}
					
///	HIGH "CRH" [8 --> 15 PINS]  
					else if (copy_u8PIN <= 15)
					{
						copy_u8PIN = copy_u8PIN - 8;
/* 			Reset or Clear the register = 0 -- Shift each 4 bits
			We want to write on only it in CRL register					*/
						GPIOC_CRH &= ~(   0b1111    << (copy_u8PIN *4));
/* 			Now the mode = 0, Write/Set what you want 						*/
						GPIOC_CRH |=  ((copy_u8MODE)<< (copy_u8PIN *4));
					}
					break;
		default : break;
	}
	
	
}

/* 				Here we already knew it's OUTPUT, so is it 0 or 1?       			*/
void MGPIO_voidSetPinValue (u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8Value)
{
/* 							Using the same switch case 		
							But here we want to check on the value is it 
							HIGH or LOW in the OUTPUT								*/
		switch (copy_u8PORT) {
			case GPIOA :
/* 				Going to the interface.h to define the GPIO_HIGH 								*/			
					if (copy_u8Value == GPIO_HIGH)
						{
/* Setting the bit to give an output in the ODR register with the no. of the pin to be resetted 				*/
						SET_BIT(GPIOA_ODR,copy_u8PIN );
						}
/* Now for the LOW condition 											*/
					else if (copy_u8Value == GPIO_LOW)
					{
/* 				At this case we clear 									*/
						CLR_BIT(GPIOA_ODR,copy_u8PIN );
					}
					break;

			case GPIOB :
					if (copy_u8Value == GPIO_HIGH)
						{
						SET_BIT(GPIOB_ODR,copy_u8PIN );
						}					
					else if (copy_u8Value == GPIO_LOW)
					{
								
						CLR_BIT(GPIOB_ODR,copy_u8PIN );
					}
					break;
					
			case GPIOC :
					if (copy_u8Value == GPIO_HIGH)
						{
						SET_BIT(GPIOC_ODR,copy_u8PIN );
						}					
					else if (copy_u8Value == GPIO_LOW)
					{
								
						CLR_BIT(GPIOC_ODR,copy_u8PIN );
					}
			break;
			default : break; }
}

u8 MGPIO_u8GetPinValue (u8 copy_u8PORT , u8 copy_u8PIN)
{
/* Define the LOCAL variable to use it as the RETURN VALUE	*/
	int LOC_u8Result=0 ;
	switch (copy_u8PORT) {
			case GPIOA:
/* GET THE INPUT REGISTER IDR with the PIN number				*/
				{LOC_u8Result = GET_BIT(GPIOA_IDR ,copy_u8PIN);		 }  break ;

			case GPIOB :
				{LOC_u8Result = GET_BIT(GPIOB_IDR ,copy_u8PIN ); 	 } break ;
				
			case GPIOC :
					{LOC_u8Result = GET_BIT(GPIOC_IDR ,copy_u8PIN ); } break ;
	default : break;
						}
return LOC_u8Result ; }

