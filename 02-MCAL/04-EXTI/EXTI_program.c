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
	EXTI_CallBack[EXTI_LINE]=Func_ptr;
	
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
}void EXTI3_IRQHandler(void)
{
	(*EXTI_CallBack[3])();
	// Clear Pending Bit
	SET_BIT(EXTI -> PR,3);
}void EXTI4_IRQHandler(void)
{
	(*EXTI_CallBack[4])();
	// Clear Pending Bit
	SET_BIT(EXTI -> PR,4);
}void EXTI5_IRQHandler(void)
{
	(*EXTI_CallBack[5])();
	// Clear Pending Bit
	SET_BIT(EXTI -> PR,5);
}
void EXTI6_IRQHandler(void)
{
	(*EXTI_CallBack[6])();
	// Clear Pending Bit
	SET_BIT(EXTI -> PR,6);
}void EXTI7_IRQHandler(void)
{
	(*EXTI_CallBack[7])();
	// Clear Pending Bit
	SET_BIT(EXTI -> PR,7);
}
void EXTI8_IRQHandler(void)
{
	(*EXTI_CallBack[8])();
	// Clear Pending Bit
	SET_BIT(EXTI -> PR,8);
}
void EXTI9_IRQHandler(void)
{
	(*EXTI_CallBack[9])();
	// Clear Pending Bit
	SET_BIT(EXTI -> PR,9);
}
void EXTI10_IRQHandler(void)
{
	(*EXTI_CallBack[10])();
	// Clear Pending Bit
	SET_BIT(EXTI -> PR,10);
}
void EXTI11_IRQHandler(void)
{
	(*EXTI_CallBack[11])();
	// Clear Pending Bit
	SET_BIT(EXTI -> PR,11);
}
void EXTI12_IRQHandler(void)
{
	(*EXTI_CallBack[12])();
	// Clear Pending Bit
	SET_BIT(EXTI -> PR,12);
}
void EXTI13_IRQHandler(void)
{
	(*EXTI_CallBack[13])();
	// Clear Pending Bit
	SET_BIT(EXTI -> PR,13);
}
void EXTI14_IRQHandler(void)
{
	(*EXTI_CallBack[14])();
	// Clear Pending Bit
	SET_BIT(EXTI -> PR,14);
}
void EXTI15_IRQHandler(void)
{
	(*EXTI_CallBack[15])();
	// Clear Pending Bit
	SET_BIT(EXTI -> PR,15);
}
