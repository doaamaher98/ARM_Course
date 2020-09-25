/*********************************************/
/* Author  : 									*/
/* Type    :									*/
/* Version :									*/
/* Date    :									*/
/*************************************************/
#ifndef MDMA_INTERFACE_H
#define MDMA_INTERFACE_H


/*************** Functions **********************/
void MDMA_Vid_Channel_Init(void);

void MDMA_Vid_Channel_Start(u32 *Copy_Pu32SourceAddress, u32 *Copy_Pu32DestinationAddress, u16 Copy_u16BlockLength);

#endif


