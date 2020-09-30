#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"


void MEXTI_voidInit()
{

#if EXTI_MODE == RISSING_EDGE
	SET_BIT(EXTI ->RTSR,EXTI_LINE);
#elif EXTI_MODE == FALLING_EDGE
	SET_BIT(EXTI ->FTSR,EXTI_LINE);
#elif EXTI_MODE == ON_CHANGE
	SET_BIT(EXTI ->RTSR,EXTI_LINE);
	SET_BIT(EXTI ->FTSR,EXTI_LINE);
#else
#error "Wrong Choise"
#endif
	CLR_BIT(EXTI -> IMR,EXTI_LINE);

}

void MEXTI_voidEnableEXTI(uint8 copy_uint8Line)
{
	SET_BIT(EXTI -> IMR,copy_uint8Line);
}
void MEXTI_voidDisableEXTI(uint8 copy_uint8Line)
{
	CLR_BIT(EXTI -> IMR,copy_uint8Line);	
}
void MEXTI_voidSwTrigger(uint8 copy_uint8Line)
{
	SET_BIT(EXTI -> SWIER,copy_uint8Line);
}

void MEXTI_voidSetCallBack(void (*Func_ptr) (void))
{
#if EXTI_LINE <= 4
	EXTI_CallBack[EXTI_LINE]=Func_ptr;
#elif EXTI_LINE <=9
	EXTI_CallBack[5]=Func_ptr;
#else
	EXTI_CallBack[6]=Func_ptr;
#endif
}

void MEXTI_voidSetCallBackManually(uint8 Copy_uint8Line,void (*Func_ptr) (void))
{
	if(Copy_uint8Line<=4)
		EXTI_CallBack[Copy_uint8Line]=Func_ptr;
	else if(Copy_uint8Line <=9)
		EXTI_CallBack[5]=Func_ptr;
	else
		EXTI_CallBack[6]=Func_ptr;

}

// el function dy 3lshan a2dr a3'yr el exti in run time
void MEXTI_voidSetSignalLatch(uint8 copy_uint8Line, uint8 copy_uint8Mode)
{
	switch(copy_uint8Mode)
	{
	case RISING_EDGE:		SET_BIT(EXTI ->RTSR,copy_uint8Line); break;
	case FALLING_EDGE:		SET_BIT(EXTI ->FTSR,copy_uint8Line); break;
	case ON_CHANGE:			SET_BIT(EXTI ->RTSR,copy_uint8Line);
	SET_BIT(EXTI ->FTSR,copy_uint8Line);break;
	}
	SET_BIT(EXTI->IMR,copy_uint8Line);
}



void EXTI0_IRQHandler(void)
{
	(*EXTI_CallBack[0])();
	// Clear Pending Bit
	SET_BIT(EXTI -> PR,0);
}
void EXTI1_IRQHandler(void)
{
	(*EXTI_CallBack[1])();
	// Clear Pending Bit
	SET_BIT(EXTI -> PR,1);
}void EXTI2_IRQHandler(void)
{
	(*EXTI_CallBack[2])();
	// Clear Pending Bit
	SET_BIT(EXTI -> PR,2);
}
void EXTI3_IRQHandler(void)
{
	(*EXTI_CallBack[3])();
	// Clear Pending Bit
	SET_BIT(EXTI -> PR,3);
}
void EXTI4_IRQHandler(void)
{
	(*EXTI_CallBack[4])();
	// Clear Pending Bit
	SET_BIT(EXTI -> PR,4);
}
void EXTI9_5_IRQHandler(void)
{
	(*EXTI_CallBack[5])();
	// Clear Pending Bit
	SET_BIT(EXTI -> PR,5);
}
void EXTI15_10_IRQHandler(void)
{
	(*EXTI_CallBack[6])();
	// Clear Pending Bit
	SET_BIT(EXTI -> PR,6);
}

