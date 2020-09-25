/*********************************************/
/* Author  : 									*/
/* Type    :									*/
/* Version :									*/
/* Date    :									*/
/*************************************************/
#ifndef MDMA_PRIVATE_H
#define MDMA_PRIVATE_H

// Array with it's index
typedef struct
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 Reserved; //
} DMA_Channel;

typedef struct 
{
	volatile u32 ISR;
	volatile u32 IFCR;
	DMA_Channel Channel[7];
} DMA_t;

// Base Address
#define DMA 			((volatile DMA_t *) 0x40020000)


#endif


