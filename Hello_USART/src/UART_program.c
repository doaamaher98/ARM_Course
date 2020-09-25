/******************************************************/
/* Author    :											*/
/* Date      :											*/
/* Type      :											*/
/* Version   :											*/
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void MUSART_voidInit(void)
{
	/* 9600   BRR = ? = 0x341 */
	MUSART1 -> BRR = 0x341;
	
	/* 115200 BRR = ? = */
	
	/* Enbale 1- RX
	   Enable 2- TX
	   Enable 3- USART*
	With SET_BIT easier */
	SET_BIT(MUSART1 -> CR1, 2);
	SET_BIT(MUSART1 -> CR1, 3);
	SET_BIT(MUSART1 -> CR1, 13);
	
	/* Clear the Status Register */
	MUSART1 -> SR = 0;
}
void MUSART1_voidTransmit(u8 arr[])
{
	u8 i = 0;
	while (arr[i] != '\0')
	{
		MUSART1 -> DR = arr[i];
		/* while(GET_BIT (MUSART1 -> SR , 6) == 0 */ 
		// OR
		/* Wait Till Transmission is Completed */
		while (((MUSART1 -> SR) & 0x40) ==0);
		i++;
	}	
}

u8 MUSART1_u8Recieve(void)
{
	/* Wait till the Recieve is completed (bit 5) */
	while (((MUSART1 -> SR) & 1 << 5) == 0);
	return (0xFF & (MUSART1 -> DR)); // To get the needed 8 bits 
}






