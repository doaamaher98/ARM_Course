/****************************************************************************/
/*   Author  : Doaa Maher 													*/
/*   Date 	 : 22/8/2020 													*/
/* 	 Version : 1.0															*/
/*   Type    : NVIC driver													*/
/****************************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/* The functions Prototypes goes here 										*/
void MNVIC_voidEnableInterrupt  (u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag	(u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber);
u8   MNVIC_voidGetActiveFlag 	(u8 Copy_u8IntNumber);
void MNVIC_voidSetPriority		(u8 Copy_PeripheralIdx, u8 Copy_u8Priority);
void MNVIC_voidInit(void);


/************** Ahmed Attia ***************/

#define  		GROUP3 				0x05FA0300 // 4 bits for group IPR   => Group
#define  		GROUP4 				0x05FA0400 // 3 bits for group and 1 for SUBgroup
#define  		GROUP5 				0x05FA0500 // 2 bits for group and 2 for SUBgroup
#define  		GROUP6 				0x05FA0600 // 1 bits for group and 3 for SUBgroup
#define  		GROUP7 				0x05FA0400 // 0 bits for group and 4 => SUBgroup

#endif










