#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "MDMA_interface.h"
#include "NVIC_interface.h"
#include "DIO_interface.h"

#include "MDMA_private.h"

int main(void)
{
	/* Between the Processor and the DMA */
	u32 Arr1[1000] = {0};
	u32 Arr2[1000];
	
	u32 Arr3[1000] = {0};
	u32 Arr4[1000];
	
	/* RCC Init */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_AHB, 0); // for DMA1 = 0
	
	/* DMA Init */
	MDMA_Vid_Channel_Init();
	
	/* NVIC Enabled */
	MNVIC_voidEnableInterrupt(11); // for DMA = 11
	
////////////////////////////////////////////////////////
	
	/* for DMA */
	MDMA_Vid_Channel_Start(Arr1, Arr2 ,1000);
	
	/* for processor */
	for (u16 i=0 ; i<1000 ; i++)
	{
		Arr4[i] = Arr3[i];	
	}	
	
	while (1)
	{

	}
	
	return 0;
}

/* To Put a break point here to test which one was faster the processor or the DMA */
void DMA1_Channel1_IRQHandler(void)
{
	DMA -> IFCR = 1<<0; // CLR GIF
	
	DMA -> IFCR = 1<<1; //CLR TC
}
