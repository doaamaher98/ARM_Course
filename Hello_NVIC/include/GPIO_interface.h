/****************************************************************************/
/*   Author  : Doaa Maher 													*/
/*   Date 	 : 16/8/2020 													*/
/* 	 Version : 1.0															*/
/*   Type    : GPIO Driver 													*/
/****************************************************************************/

// PROTOTYPES FOR USER'S USAGE //

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/*				Defining the Output Value : HIGH or LOW		   */
#define 		GPIO_HIGH				1
#define 		GPIO_LOW 				0

/* 				Defining the PORTS 	A,B,C				*/
#define 		GPIOA             0
#define 		GPIOB             1
#define 		GPIOC             2

/*				Defining the PINS	0 --> 15			*/
#define 		PIN0 			   0
#define 		PIN1			   1
#define 		PIN2 			   2
#define 		PIN3 			   3
#define 		PIN4 			   4
#define 		PIN5 			   5
#define 		PIN6 			   6
#define 		PIN7 			   7
#define 		PIN8 			   8
#define 		PIN9 			   9
#define 		PIN10 			   10
#define 		PIN11			   11
#define 		PIN12			   12
#define 		PIN13			   13
#define 		PIN14			   14
#define 		PIN15			   15

/*				Defining both the 1- Config & 2- Mode	I]Output
				First with the 10 MHz							*/							
#define 		OUTPUT_SPEED_10MHZ_PP	0b0001	 // 10mhz push pull
#define 		OUTPUT_SPEED_10MHZ_OD	0b0101	 // 10mhz open drain
#define 		OUTPUT_SPEED_10MHZ_AFPP	0b1001	 // 10mhz alternative function push pull
#define 		OUTPUT_SPEED_10MHZ_AFOD	0b1101	 // 10mhz alternative function open drain

/*						Second with the 2MHz					*/
#define 		OUTPUT_SPEED_2MHZ_PP	0b0010	 // 2mhz push pull
#define 		OUTPUT_SPEED_2MHZ_OD	0b0010	 // 2mhz open drain
#define 		OUTPUT_SPEED_2MHZ_AFPP	0b1010	 // 2mhz alternative function push pull
#define 		OUTPUT_SPEED_2MHZ_AFOD	0b1110	 // 2mhz alternative function open drain

/*						Third with the 50MHz					*/
#define 		OUTPUT_SPEED_50MHZ_PP	0b0011	 // 2mhz push pull
#define 		OUTPUT_SPEED_50MHZ_OD	0b0111	 // 2mhz open drain
#define 		OUTPUT_SPEED_50MHZ_AFPP	0b1011	 // 2mhz alternative function push pull
#define 		OUTPUT_SPEED_50MHZ_AFOD	0b1111	 // 2mhz alternative function open drain

/*				Defining both the 1- Config & 2- Mode	
				II] INPUT  									   */
#define 		INPUT_ANALOG			0b0000	 
#define 		INPUT_FLOATING			0b0100
#define 		INPUT_PULLDOWN			0b1000
#define 		INPUT_PULLUP			0b1000



/*				Functions for GPIO 				*/
// Mode decides INPUT OR OUTPUT PORTS (A,B,C)?
void MGPIO_voidSetPinDirection  (u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8MODE);
// OUTPUT and it's Value and case
void MGPIO_voidSetPinValue 		(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8Value);
// INPUT to Get value
u8 MGPIO_u8GetPinValue 			(u8 copy_u8PORT , u8 copy_u8PIN);






#endif
