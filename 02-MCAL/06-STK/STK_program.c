#include "BIT_MATH.h"
#include "STD_TYPES.h"



#include "STK_private.h"
#include "STK_config.h"
#include "STK_interface.h"

int x=0;

void MSTK_voidInit(void)
{

	#if STK_CLOCK_SOURCE == AHB_CLK_DIV_8
	STK_CTRL=0;
	#elif STK_CLOCK_SOURCE == AHB_CLK
	STK_CTRL=4;
	#else
		// error
	#endif
}

void MSTK_voidSetBusyWait(uint32 Copy_uint32Ticks)
{
	/* Load ticks to load register */
	STK_LOAD = Copy_uint32Ticks;
	x=STK_LOAD;
	/* Start Timer */
	SET_BIT(STK_CTRL, 0);

	/* Wait till flag is raised */
	while( (GET_BIT(STK_CTRL,16)) == 0)
	{
		x=STK_VAL;

	}

	/* Stop Timer */
	SET_BIT(STK_CTRL, 0);
	STK_LOAD = 0;
	STK_VAL  = 0;
}

void MSTK_voidSetIntervalSingle(uint32 Copy_uint32Ticks, void (*Copy_ptr) (void))
{
	CLR_BIT(STK_CTRL,0);
	CLR_BIT(STK_CTRL,1);
	STK_LOAD=Copy_uint32Ticks;
	CallBack_Function=Copy_ptr;
	SET_BIT(STK_CTRL,0);
	SET_BIT(STK_CTRL,1);
	SingleOrPeridoic=SINGLE_INTERVAL;

}

void MSTK_voidSetIntervalPeriodic(uint32 Copy_uint32Ticks, void (*Copy_ptr) (void))
{
	CLR_BIT(STK_CTRL,0);
	CLR_BIT(STK_CTRL,1);
	STK_LOAD=Copy_uint32Ticks;
	CallBack_Function=Copy_ptr;
	SET_BIT(STK_CTRL,0);
	SET_BIT(STK_CTRL,1);
	SingleOrPeridoic=PERIODIC_INTERVAL;
}

void MSTK_voidStopInterval(void)
{
	CLR_BIT(STK_CTRL,0);
}

uint32 MSTK_uint32GetElapsedTime(void)
{
	return STK_VAL;
}

uint32 MSTK_uint32GetRemainingTime(void)
{
	return (STK_LOAD-STK_VAL);
}
void SysTick_Handler(void)
{
	if(SingleOrPeridoic==SINGLE_INTERVAL)
		CLR_BIT(STK_CTRL,0);
	CallBack_Function();
}
