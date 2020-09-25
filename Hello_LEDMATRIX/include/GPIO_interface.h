/****************************************************************************/
/*   Author  : Doaa Maher 													*/
/*   Date 	 : 16/8/2020 													*/
/* 	 Version : 1.0															*/
/*   Type    : GPIO Driver 													*/
/****************************************************************************/

// PROTOTYPES FOR USER'S USAGE //

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H



/* 				Defining the PORTS 	A,B,C				*/
#define 		GPIO_A             0
#define 		GPIO_B             1
#define 		GPIO_C             2

#define			GPIO_HIGH				1
#define			GPIO_LOW				0


//PIN MODES
#define INPUT_ANLOG               0b0000
#define INPUT_FLOATING            0b0100
#define INPUT_PULLUP_PULLDOWN     0b1000



#define		PIN0		0
#define		PIN1		1
#define		PIN2		2
#define		PIN3		3
#define		PIN4		4
#define		PIN5		5
#define		PIN6		6
#define		PIN7		7
#define		PIN8		8
#define		PIN9		9
#define		PIN10		10
#define		PIN11		11
#define		PIN12		12
#define		PIN13		13
#define		PIN14		14
#define		PIN15		15

#define		INPUT_ANALOG				0b0000
#define		INPUT_FLOATING				0b0100
#define		INPUT_PULL_UP_DOWN			0b1000

#define		OUTPUT_SPEED_10MHZ_PP		0b0001
#define		OUTPUT_SPEED_10MHZ_OD		0b0101
#define		OUTPUT_SPEED_10MHZ_AFPP		0b1001
#define		OUTPUT_SPEED_10MHZ_AFOD		0b1101

#define		OUTPUT_SPEED_2MHZ_PP		0b0010
#define		OUTPUT_SPEED_2MHZ_OD		0b0110
#define		OUTPUT_SPEED_2MHZ_AFPP		0b1010
#define		OUTPUT_SPEED_2MHZ_AFOD		0b1110

#define		OUTPUT_SPEED_50MHZ_PP		0b0011
#define		OUTPUT_SPEED_50MHZ_OD		0b0111
#define		OUTPUT_SPEED_50MHZ_AFPP		0b1011
#define		OUTPUT_SPEED_50MHZ_AFOD		0b1111


/*				Functions for GPIO 				*/
// Mode decides INPUT OR OUTPUT PORTS (A,B,C)?

/*void MGPIO_voidSetPinDirection  ( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode  );
void MGPIO_voidSetPinValue      ( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value );
u8   MGPIO_u8GetPinValue        ( u8 Copy_u8Port , u8 Copy_u8Pin );
*/

void MGPIO_voidSetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8MODE);

void MGPIO_voidSetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Value);

void MGPIO_VoidTogPin(u8 Copy_u8PORT, u8 Copy_u8PIN);

u8 MGPIO_u8GetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN);


/*
// PORT specific APIs
void GPIO_voidSetPortDirection		(u8 Copy_u8Port, u32 u32Copy_u32PortMode);
void GPIO_voidSetPortValue			(u8 Copy_u8Port, u32 u32Copy_u8Value);
u32 GPIO_u32GetPortValue			(u8 Copy_u8Port);
u8 GPIO_u8LockPortMode				(u8 Copy_u8Port);
// PIN specific APIs
void GPIO_voidSetPinDirection		(u8 Copy_u8Pin, u8 u8Copy_u8Mode);
void GPIO_voidSetPinValue			(u8 Copy_u8Pin, u8 u8Copy_u8Value);
u8 GPIO_u8GetPinValue				(u8 Copy_u8Pin);
u8 GPIO_u8LockPinMode				(u8 Copy_u8Pin);*/
#endif
