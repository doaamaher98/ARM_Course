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
#include "GPIO_config.h"


void MGPIO_voidSetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8MODE)
{
	//Check which port A, B, C, D, E, F, G is selected
	switch(Copy_u8PORT)
	{
		/*After knowing the port, check if the the pin between 0:7 -> CRL
		  or 8:15 -> CRH
		  */
		case GPIO_A:
					if(Copy_u8PIN <= 7)
					{
						GPIOA_CRL &= ~ 	((0b1111) 		<< (Copy_u8PIN * 4));
						GPIOA_CRL |= 	((Copy_u8MODE)  << (Copy_u8PIN * 4));
					}
					else if (Copy_u8PIN <= 15)
					{
						Copy_u8PIN -= 8;
						GPIOA_CRH &= ~ 	((0b1111) 		<< (Copy_u8PIN * 4));
						GPIOA_CRH |= 	((Copy_u8MODE)  << (Copy_u8PIN * 4));
					}
					break;
		case GPIO_B:
					if(Copy_u8PIN <= 7)
					{
						GPIOB_CRL &= ~ 	((0b1111) 		<< (Copy_u8PIN * 4));
						GPIOB_CRL |= 	((Copy_u8MODE)  << (Copy_u8PIN * 4));
					}
					else if (Copy_u8PIN <= 15)
					{
						Copy_u8PIN -= 8;
						GPIOB_CRH &= ~ 	((0b1111) 		<< (Copy_u8PIN * 4));
						GPIOB_CRH |= 	((Copy_u8MODE)  << (Copy_u8PIN * 4));
					}
					break;
		case GPIO_C:
					if(Copy_u8PIN <= 7)
					{
						GPIOC_CRL &= ~ 	((0b1111) 		<< (Copy_u8PIN * 4));
						GPIOC_CRL |= 	((Copy_u8MODE)  << (Copy_u8PIN * 4));
					}
					else if (Copy_u8PIN <= 15)
					{
						Copy_u8PIN -= 8;
						GPIOC_CRH &= ~ 	((0b1111) 		<< (Copy_u8PIN * 4));
						GPIOC_CRH |= 	((Copy_u8MODE)  << (Copy_u8PIN * 4));
					}
					break;
		default:
					break;
	}
}

void MGPIO_voidSetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Value)
{
	//Check on the port Number
	switch(Copy_u8PORT)
	{
		//set or clear the value of that pin
		case GPIO_A:
					if(Copy_u8Value == GPIO_HIGH)
					{
						SET_BIT(GPIOA_ODR, Copy_u8PIN);
					}
					else
					{
						CLR_BIT(GPIOA_ODR, Copy_u8PIN);
					}
					break;
		case GPIO_B:
					if(Copy_u8Value == GPIO_HIGH)
					{
						SET_BIT(GPIOB_ODR, Copy_u8PIN);
					}
					else
					{
						CLR_BIT(GPIOB_ODR, Copy_u8PIN);
					}
					break;
		case GPIO_C:
					if(Copy_u8Value == GPIO_HIGH)
					{
						SET_BIT(GPIOC_ODR, Copy_u8PIN);
					}
					else
					{
						CLR_BIT(GPIOC_ODR, Copy_u8PIN);
					}
					break;
		default:
					break;
	}

}

void MGPIO_VoidTogPin(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	switch(Copy_u8PORT)
	{
		case GPIO_A :
					TOG_BIT(GPIOA_ODR, Copy_u8PIN);
					break;
		case GPIO_B :
					TOG_BIT(GPIOB_ODR, Copy_u8PIN);
					break;
		case GPIO_C :
					TOG_BIT(GPIOC_ODR, Copy_u8PIN);
					break;
		default	:
					break;
	}
}

u8 MGPIO_u8GetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	u8 loc_u8Result = 0;
	switch(Copy_u8PORT)
	{
		case GPIO_A:
					loc_u8Result = GET_BIT(GPIOA_IDR, Copy_u8PIN);
					break;
		case GPIO_B:
					loc_u8Result = GET_BIT(GPIOB_IDR, Copy_u8PIN);
					break;
		case GPIO_C:
					loc_u8Result = GET_BIT(GPIOC_IDR, Copy_u8PIN);
					break;
		default:
					break;
	}
	return loc_u8Result;
}

/* void GPIO_voidSetPinDirection (u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8MODE)
{   	Switching on the port to know A,B,C?
	switch (copy_u8PORT) {
		case GPIO_A :
///	LOW "CRL" [0 --> 7 PINS]
					if (copy_u8PIN <= 7)
					{
 			Reset or Clear the register = 0 -- Shift each 4 bits
			We want to write on only it in CRL register
						GPIOA_CRL &= ~(   0b1111    << (copy_u8PIN *4));
			Now the mode = 0, Write/Set what you want
						GPIOA_CRL |=  ((copy_u8MODE)<< (copy_u8PIN *4));
					}
	HIGH "CRH" [8 --> 15 PINS]
					else if (copy_u8PIN <= 15)
					{
						copy_u8PIN = copy_u8PIN - 8;
 			Reset or Clear the register = 0 -- Shift each 4 bits
			We want to write on only it in CRL register
						GPIOA_CRH &= ~(   0b1111    << (copy_u8PIN *4));
			Now the mode = 0, Write/Set what you want
						GPIOA_CRH |=  ((copy_u8MODE)<< (copy_u8PIN *4));
					}
					break;
 Doing the same with the other PORTS
		case GPIO_B  :
	LOW "CRL" [0 --> 7 PINS]
					if (copy_u8PIN <= 7)
					{
 			Reset or Clear the register = 0 -- Shift each 4 bits
			We want to write on only it in CRL register
						GPIOB_CRL &= ~(   0b1111    << (copy_u8PIN *4));
 			Now the mode = 0, Write/Set what you want
						GPIOB_CRL |=  ((copy_u8MODE)<< (copy_u8PIN *4));
					}
	HIGH "CRH" [8 --> 15 PINS]
					else if (copy_u8PIN <= 15)

 As our 0 is 8 here, so we make sure of that
						copy_u8PIN = copy_u8PIN - 8;
 			Reset or Clear the register = 0 -- Shift each 4 bits
			We want to write on only it in CRL register
						GPIOB_CRH &= ~(   0b1111    << (copy_u8PIN *4));
 			Now the mode = 0, Write/Set what you want
						GPIOB_CRH |=  ((copy_u8MODE)<< (copy_u8PIN *4));
					}
					break;
		case GPIO_C :
	LOW "CRL" [0 --> 7 PINS]
					if (copy_u8PIN <= 7)
					{
 			Reset or Clear the register = 0 -- Shift each 4 bits
			We want to write on only it in CRL register
						GPIOC_CRL &= ~(   0b1111    << (copy_u8PIN *4));
 			Now the mode = 0, Write/Set what you want
						GPIOC_CRL |=  ((copy_u8MODE)<< (copy_u8PIN *4));
					}
					
	HIGH "CRH" [8 --> 15 PINS]
					else if (copy_u8PIN <= 15)
					{
						copy_u8PIN = copy_u8PIN - 8;
 			Reset or Clear the register = 0 -- Shift each 4 bits
			We want to write on only it in CRL register
						GPIOC_CRH &= ~(   0b1111    << (copy_u8PIN *4));
 			Now the mode = 0, Write/Set what you want
						GPIOC_CRH |=  ((copy_u8MODE)<< (copy_u8PIN *4));
					}
					break;
		default : break;
	}
	
	*/
//}

/* 				Here we already knew it's OUTPUT, so is it 0 or 1?       			*/
/*void GPIO_voidSetPinValue (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
 							Using the same switch case
							But here we want to check on the value is it 
							HIGH or LOW in the OUTPUT
		switch (Copy_u8Port) {
			case GPIO_A :
				Going to the interface.h to define the GPIO_HIGH
					if (Copy_u8Value == GPIO_HIGH)
						{
 Setting the bit to give an output in the ODR register with the no. of the pin to be resetted
						SET_BIT(GPIOA_ODR,Copy_u8Pin );
						}
 Now for the LOW condition
					else if (Copy_u8Value == GPIO_LOW)
					{
 				At this case we clear
						CLR_BIT(GPIOA_ODR,Copy_u8Pin );
					}
					break;

			case GPIO_B :
					if (Copy_u8Value == GPIO_HIGH)
						{
						SET_BIT(GPIOB_ODR,Copy_u8Pin );
						}					
					else if (Copy_u8Value == GPIO_LOW)
					{
								
						CLR_BIT(GPIOB_ODR,Copy_u8Pin );
					}
					break;
					
			case GPIO_C :
					if (Copy_u8Value == GPIO_HIGH)
						{
						SET_BIT(GPIOC_ODR ,Copy_u8Pin );
						}					
					else if (Copy_u8Value == GPIO_LOW)
					{
						CLR_BIT(GPIOC_ODR,Copy_u8Pin ); }

					break;
		default : {break;} */




