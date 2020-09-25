
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "UART_interface.h"

int main (void)
{
	/* Init the System Clock to 8Mhz */
	RCC_voidInitSysClock();
	
	RCC_voidEnableClock(RCC_APB2,2); // GPIOA
	
	/* RCC for USART = 14 */
	RCC_voidEnableClock(RCC_APB2,14);
	

	/* A9 = TX OUT Transmit */
	MGPIO_VidSetPinDirection(GPIOA , PIN9, OUTPUT_SPEED_50MHZ_PP);
	/* A10 = RX IN Recieve */
	MGPIO_VidSetPinDirection(GPIOA , PIN10, INPUT_FLOATING);
	
	// OUTPUT
	MGPIO_VidSetPinDirection(GPIOA , PIN9, OUTPUT_SPEED_2MHZ_PP);

	
	MUSART_voidInit();
	
	u8 x;
	while (1)
	{
		MUSART1_voidTransmit(97);
		x = MUSART1_u8Recieve();
		if (x == '5')
		{
			MGPIO_VidSetPinValue (GPIOA, PIN0 , HIGH);
		}
		else if (x == 'R')
		{
			MGPIO_VidSetPinValue (GPIOA , PIN0 , LOW);
		}
		
	}

	
	
	
	
	
	
	
	return 0;
}
