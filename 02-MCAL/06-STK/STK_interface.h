/************************************************/
/* Author 	:	Mo'men Hesham					*/
/* Version 	: 	v1								*/
/* Date 	:	26/8/2020						*/
/************************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


/* Apply Clk Choice from config file
	Disable Systick interrupt
	Disable SysTick*/
void MSTK_voidInit(void);

void MSTK_voidSetBusyWait(uint32 Copy_uint32Ticks);

void MSTK_voidSetIntervalSingle(uint32 Copy_uint32Ticks, void (*Copy_ptr) (void));

void MSTK_voidSetIntervalPeriodic(uint32 Copy_uint32Ticks, void (*Copy_ptr) (void));
void MSTK_voidStopInterval(void);

uint32 MSTK_uint32GetElapsedTime(void);
uint32 MSTK_uint32GetRemainingTime(void);


#endif
