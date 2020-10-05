/********************************/
/* Author  : Mo'men Hesham		*/
/* Version : V01				*/
/********************************/

#ifndef MDMA_PRIVATE_H
#define MDMA_PRIVATE_H

#define TRANSFER_COMPLETE_HALF_ERROR	14
#define TRANSFER_HALF_ERROR				12
#define TRANSFER_COMPLETE_ERROR			10
#define TRANSFER_ERROR					8
#define TRANSFER_COMPLETE_HALF			6
#define TRANSFER_HALF					4
#define TRANSFER_COMPLETE				2
#define NO_FLAGS_SET					0


#define CHANNEL_1		0
#define CHANNEL_2		1
#define CHANNEL_3		2
#define CHANNEL_4		3
#define CHANNEL_5		4
#define CHANNEL_6		5
#define CHANNEL_7		6

#define ENABLE_MEMORY_TO_MEMORY			0
#define DISABL_MEMORY_TO_MEMORY 		1

#define PRIORITY_LOW			0b00
#define	PRIORITY_MEDIUM			0b01
#define	PRIORITY_HIGH			0b10
#define	PRIORITY_VERY_HIGH		0b11

#define SIZE_8_BIT		0b00
#define SIZE_16_BIT		0b01
#define SIZE_32_BIT		0b10

#define INCREMENT_MODE		0
#define NO_INCREMENT_MODE	1

#define ENABLE_CIRCULAR_MODE	0
#define DISABLE_CIRCULAR_MODE	1

#define READ_FROM_MEMORY		0
#define READ_FROM_PERIPHERAL	1




// struct represent one channel registers
typedef struct
{
	volatile uint32 CCR;
	volatile uint32 CNDTR;
	volatile uint32 CPAR;
	volatile uint32 CMAR;
	volatile uint32 Reserved;
}DMA_Channel;


typedef struct 
{
	// ISR & IFCR control all channels
	volatile uint32 ISR;
	volatile uint32 IFCR;
	DMA_Channel Channel[7];
}DMA_t;

static void (*DMA_CallBack[7]) (void) ;


#define DMA		((volatile DMA_t *)0x40020000)



#endif
