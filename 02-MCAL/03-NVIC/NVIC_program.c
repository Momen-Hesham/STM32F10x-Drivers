/*********************************************
// Author	: Mo'men Hesham
// Date		: 19/8/2020
// Version	: V01
*********************************************/
//General libraries then above layers then my files
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidInit(void)
{
	// ana hena 3amlt el define gwa el func 3shan na asln el mafrod ma access el SCB regs hena fel nvic fa ana odam hashelha aslun
	#define SCB_AIRCR	*( (volatile uint32 *) 0xE000ED0C) 
	SCB_AIRCR=MNVIC_GROUP_SUB_DISTRIBUTION;
	
}

void MNVIC_voidSetPriority(uint8 Copy_uint8PeripheralIdx,uint8 Copy_uint8Priority)
{
	if(Copy_uint8PeripheralIdx < 60)
	{
		NVIC_IPR[Copy_uint8PeripheralIdx]=Copy_uint8Priority;
	}
	else
	{
		//error
	}
	
	
}

void MNVIC_voidEnableInterrupt(uint8 Copy_uint8IntNumber)
{
	//hena ana 7atet el INT Number be uint8 3lshan ana m3ndesh 3'er 59 INT peripherlas bs
	if( Copy_uint8IntNumber <=31 )
	{
		NVIC_ISER0=(1<<Copy_uint8IntNumber);
	}
	else if( Copy_uint8IntNumber <=59 )
	{
		NVIC_ISER1=(1<<(Copy_uint8IntNumber-32));
	}
	else
	{
			// return Error
	}
}

void MNVIC_voidDisableInterrupt(uint8 Copy_uint8IntNumber)
{
	//hena ana 7atet el INT Number be uint8 3lshan ana m3ndesh 3'er 59 INT peripherlas bs
	if( Copy_uint8IntNumber <=31 )
	{
		NVIC_ICER0 = (1<<Copy_uint8IntNumber);
	}
	else if( Copy_uint8IntNumber <=59 )
	{
		NVIC_ICER1 = (1<<(Copy_uint8IntNumber-32));
	}
	else
	{
			// return Error
	}
}

void MNVIC_voidSetPendingFlag(uint8 Copy_uint8IntNumber)
{
	//hena ana 7atet el INT Number be uint8 3lshan ana m3ndesh 3'er 59 INT peripherlas bs
	if( Copy_uint8IntNumber <=31 )
	{
		NVIC_ISPR0=(1<<Copy_uint8IntNumber);
	}
	else if( Copy_uint8IntNumber <=59 )
	{
		NVIC_ISPR1=(1<<(Copy_uint8IntNumber-32));
	}
	else
	{
			// return Error
	}
}

void MNVIC_voidClearPendingFlag(uint8 Copy_uint8IntNumber)
{
	//hena ana 7atet el INT Number be uint8 3lshan ana m3ndesh 3'er 59 INT peripherlas bs
	if( Copy_uint8IntNumber <=31 )
	{
		NVIC_ICPR0=(1<<Copy_uint8IntNumber);
	}
	else if( Copy_uint8IntNumber <=59 )
	{
		NVIC_ICPR1=(1<<(Copy_uint8IntNumber-32));
	}
	else
	{
			// return Error
	}
}

uint8 MNVIC_uint8GetActiveFlag(uint8 Copy_uint8IntNumber)
{
	//hena ana 7atet el INT Number be uint8 3lshan ana m3ndesh 3'er 59 INT peripherlas bs
	uint8 Local_uint8Result;
	if( Copy_uint8IntNumber <=31 )
	{
		Local_uint8Result = GET_BIT(NVIC_IABR0,Copy_uint8IntNumber);
	}
	else if( Copy_uint8IntNumber <=59 )
	{
		Copy_uint8IntNumber-=32;
		Local_uint8Result = GET_BIT(NVIC_IABR1,Copy_uint8IntNumber);
	}
	else
	{
		Local_uint8Result=0;
			// return Error
	}
	return Local_uint8Result;
}
/*
void MNVIC_voidSetPriority( int8 copy_int8IntID, uint8 copy_uint8GroupPriority, uint8 copy_uint8SubPriority,uint32 copy_uint32Group )
{	
	uint8 Local_uint8Priority = copy_uint8SubPriority| copy_uint8GroupPriority<<((copy_uint32Group -0x05FA0300) /256)  // 256 equivalent to 0x100
	
	SCB_AIRCR =copy_uint32Group;
	
	/* core peripheral */
	
	/* External peripheral */
	/*
	if(copy_int8IntID >= 0)
	{
		IPR[copy_int8IntID] = Local_uint8Priority << 4;
	}
}
*/
