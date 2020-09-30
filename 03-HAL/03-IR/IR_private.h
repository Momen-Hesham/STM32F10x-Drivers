/*
 * IR_program.c
 *
 *  Created on: Sep 30, 2020
 *      Author: Mo'men
 */

#ifndef IR_PRIVATE_H
#define IR_PRIVATE_H

#define NULL (void *)0

volatile uint8 uint8StartFlag=0;
volatile uint32 uint32FrameData[50]={0};
volatile uint8 uint8EdgeCounter=0;
volatile uint8 uint8Data =0;



void (*Func_Ptr) (uint8 DataIn)=NULL;

void voidTakeAction(void)
{
	uint8 i;
	uint8Data=0;
	if ((uint32FrameData[0] >=10000) && (uint32FrameData[0]<15000))
	{
		for(i=0;i<8;i++)
		{
			if((uint32FrameData[17+i] >= 2000)  && (uint32FrameData[17+i]<=2300))
			{
				SET_BIT(uint8Data,i);
			}
			else
			{
				CLR_BIT(uint8Data,i);
			}
		}
	}
	else
	{
		//Invalid Frame
	}
	Func_Ptr(uint8Data);
	uint8StartFlag=0;
	uint32FrameData[0]=0;
	uint8EdgeCounter=0;
}
static void voidGetFrame(void)
{
	if(uint8StartFlag==0)
	{
		//start timer
		MSTK_voidSetIntervalSingle(1000000,voidTakeAction);
		uint8StartFlag=1;
	}
	else
	{
		uint32FrameData[uint8EdgeCounter]=MSTK_uint32GetElapsedTime();
		MSTK_voidSetIntervalSingle(1000000,voidTakeAction);
		uint8EdgeCounter++;
	}
}



#endif
