/*********************************************/
/* Author  : 									*/
/* Type    :									*/
/* Version :									*/
/* Date    :									*/
/*************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MDMA_interface.h"
#include "MDMA_config.h"
#include "MDMA_private.h"


void MDMA_Vid_Channel_Init(void)
{
	/* 
	1- Memory to Memory
	2- Very High
	3- Source Size , Destination Size = 32 bit
	4- MINC & PINC ACTIVATED
	5- No Circular
	6- Direction :
	7- Transfer Interrupt Enable
	*/
	if (Channel_ID == 1)
	{DMA -> Channel[0].CCR = 0x0007AC2 ;}
	
}

void MDMA_Vid_Channel_Start(u32 *Copy_Pu32SourceAddress, u32 *Copy_Pu32DestinationAddress, u16 Copy_u16BlockLength)
{
	/* Make sure that the Channel is disabled */
	CLR_BIT(DMA -> Channel[0].CCR ,0);
	
	/* Write the Address */
	
	// Source :
	DMA -> Channel[0].CPAR = Copy_Pu32SourceAddress;
	// Destination
	DMA -> Channel[0].CMAR = Copy_Pu32DestinationAddress;
	/* Block Length */
	DMA -> Channel[0].CNDTR = Copy_u16BlockLength;
	
	/* Make sure that the Channel is ENABLE */
	SET_BIT(DMA -> Channel[0].CCR ,0);

}
