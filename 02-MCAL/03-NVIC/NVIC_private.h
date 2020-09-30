/*********************************************
// Author	: Mo'men Hesham
// Date		: 19/8/2020
// Version	: V01
*********************************************/
// Da gwah el data elly mayenf3sh 7d yeshofha aw ye3dl 3leha 3'ery
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H_H

// Registers Definition
// 0xE000E100 Base address
#define NVIC_BASE_ADDRESS	0xE000E100

#define NVIC_ISER0 	*((uint32 *) (NVIC_BASE_ADDRESS+0x00)) //Enable Externalinterrupts from 0 to 31
#define NVIC_ISER1 	*((uint32 *) (NVIC_BASE_ADDRESS+0x04)) //Enable Externalinterrupts from 32 to 63

#define NVIC_ICER0 	*((uint32 *) (NVIC_BASE_ADDRESS+0x80))
#define NVIC_ICER1 	*((uint32 *) (NVIC_BASE_ADDRESS+0x84))

#define NVIC_ISPR0 	*((uint32 *) (NVIC_BASE_ADDRESS+0x100))
#define NVIC_ISPR1 	*((uint32 *) (NVIC_BASE_ADDRESS+0x104))

#define NVIC_ICPR0 	*((uint32 *) (NVIC_BASE_ADDRESS+0x180))
#define NVIC_ICPR1 	*((uint32 *) (NVIC_BASE_ADDRESS+0x184))

#define NVIC_IABR0 	*( (volatile uint32 *) (NVIC_BASE_ADDRESS+0x200))
#define NVIC_IABR1 	*( (volatile uint32 *) (NVIC_BASE_ADDRESS+0x204))
#define NVIC_IPR   	( (volatile uint8 * ) (NVIC_BASE_ADDRESS+0X300))// hena ana ma3mltsh dereference 3shan na hast5dmo hena ka pointer aw array indexer'
																	// fa lma hagy aklmo ha3mel keda *(NVIC_IPR) w elly hatsawy *((volatile (uint8 *) (NVIC_BASE_ADDRESS+0x300)))
																	// aw ashally hast5dmo keda NVIC_IPR[0],NVIC_IPR[1]....

#define MNVIC_GROUP_4_SUB_0	0x05FA0300
#define MNVIC_GROUP_3_SUB_1	0x05FA0400
#define MNVIC_GROUP_2_SUB_2	0x05FA0500
#define MNVIC_GROUP_1_SUB_3	0x05FA0600
#define MNVIC_GROUP_0_SUB_4	0x05FA0700


#define SCB_AIRCR	*( volatile (uint32 *)	0x E000ED000C)
#endif
