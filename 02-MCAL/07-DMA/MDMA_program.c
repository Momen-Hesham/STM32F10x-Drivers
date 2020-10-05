#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MDMA_private.h"
#include "MDMA_config.h"
#include "MDMA_interface.h"



void MDMA_voidChannelInit(void)
{

	#if CHANNEL_ID >= CHANNEL_1 && CHANNEL_ID <= CHANNEL_7

		DMA ->Channel[CHANNEL_ID].CCR =0;
		#if MEMORY_TO_MEMORY_MODE == ENABLE_MEMORY_TO_MEMORY

			DMA-> Channel[CHANNEL_ID].CCR |= 0x00004000;
		#else
			DMA-> Channel[CHANNEL_ID].CCR &= ~(0x00004000);
		#endif

		#if MEMORY_MODE == INCREMENT_MODE

			DMA-> Channel[CHANNEL_ID].CCR |= 0x00000080;
		#else
			DMA-> Channel[CHANNEL_ID].CCR &= ~(0x00000080);
		#endif

		#if PERIPHERAL_MODE == INCREMENT_MODE

			DMA-> Channel[CHANNEL_ID].CCR |= 0x00000040;
		#else
			DMA-> Channel[CHANNEL_ID].CCR &= ~(0x00000040);
		#endif

		#if CIRCULAR_MODE == ENABLE_CIRCULAR_MODE


			DMA-> Channel[CHANNEL_ID].CCR |= 0x00000020;
		#else
			DMA-> Channel[CHANNEL_ID].CCR &= ~(0x00000020);
		#endif

		#if DATA_TRANSFER_DIRECTION == READ_FROM_MEMORY

			DMA-> Channel[CHANNEL_ID].CCR |= 0x00000010;
		#else
			DMA-> Channel[CHANNEL_ID].CCR &= ~(0x00000010);
		#endif

	
		DMA->Channel[CHANNEL_ID].CCR &= ~(0x00003000);
		DMA->Channel[CHANNEL_ID].CCR |= (CHANNEL_PRIORITY_LEVEL <<12);

		DMA->Channel[CHANNEL_ID].CCR &= ~(0x00000C00);
		DMA->Channel[CHANNEL_ID].CCR |= (MEMORY_SIZE <<10);

		DMA->Channel[CHANNEL_ID].CCR &= ~(0x00000300);
		DMA->Channel[CHANNEL_ID].CCR |= (PERIPHERAL_SIZE<<8);

		DMA->Channel[CHANNEL_ID].CCR &= ~(0x0000000F);
		DMA->Channel[CHANNEL_ID].CCR |= INTERUPT_FLAGS;

	#endif
	
}

void MDMA_voidChannelStart(void (*Copy_FuncPtr)(void),uint32 * Copy_Ptruint32SourceAddress,uint32 * Copy_Ptruint32DestinationAddress,uint16 Copy_uint16BlockLength)
{
	#if CHANNEL_ID >= CHANNEL_1 && CHANNEL_ID <= CHANNEL_7
	DMA_CallBack[CHANNEL_ID]=Copy_FuncPtr;
	//Disabled Channel
	CLR_BIT(DMA->Channel[CHANNEL_ID].CCR,0);
	
	// Set Block Length
	
	DMA -> Channel[CHANNEL_ID].CNDTR=Copy_uint16BlockLength;

	// Write Addresses
	DMA->Channel[CHANNEL_ID].CPAR= Copy_Ptruint32SourceAddress;
	DMA->Channel[CHANNEL_ID].CMAR =Copy_Ptruint32DestinationAddress;


	// Enable Channel
	SET_BIT(DMA->Channel[CHANNEL_ID].CCR,0);

		
	#endif
}

uint8 MDMA_voidReadFlags(void)
{
	uint8 Local_uint8Result = DMA->ISR;
	Local_uint8Result &= ( 0xF << (4*CHANNEL_ID));
	return (Local_uint8Result>> (4*CHANNEL_ID));
}


void DMA1_Channel1_IRQHandler(void)
{
	(*DMA_CallBack[0])();
	DMA->IFCR |= ((0x0F)<< (4*0));
}
void DMA1_Channel2_IRQHandler(void)
{
	(*DMA_CallBack[1])();
	DMA->IFCR |= ((0x0F)<< (4*1));
}
void DMA1_Channel3_IRQHandler(void)
{
	(*DMA_CallBack[2])();
	DMA->IFCR |= ((0x0F)<< (4*2));
}
void DMA1_Channel4_IRQHandler(void)
{
	(*DMA_CallBack[3])();
	DMA->IFCR |= ((0x0F)<< (4*3));
}
void DMA1_Channel5_IRQHandler(void)
{
	(*DMA_CallBack[4])();
	DMA->IFCR |= ((0x0F)<< (4*4));
}
void DMA1_Channel6_IRQHandler(void)
{
	(*DMA_CallBack[5])();
	DMA->IFCR |= ((0x0F)<< (4*5));
}
void DMA1_Channel7_IRQHandler(void)
{
	(*DMA_CallBack[6])();
	DMA->IFCR |= ((0x0F)<< (4*6));
}
