/**************************************************************
// Author  :		Mo'men Hesham
// Date	   :		8/8/2020
//Version	   :		V01
****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
// left a space between libraries & Own Driver files
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
#if	RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL//hena ben7ot #if mesh if cond 3alshan awfr frl memory
	RCC_CR = 0x00010000; //Enable Crystal External clock
	RCC_CFGR = 0x00000001;
	while (!(RCC_CR & 0x00020000)) {}
#elif	RCC_CLOCK_TYPE == RCC_HSE_RC
	RCC_CR = 0x00050000; //Enable RC Circuit External clock
	RCC_CFGR = 0x00000001;
#elif 	RCC_CLOCK_TYPE == RCC_RCC_HSI
	RCC_CR = 0x00000001; //Enable Internal Clock
	RCC_CFGR = 0x00000000;
#elif	RCC_CLOCK_TYPE == RCC_PLL

#if RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
	CLR_BIT(RCC_CFGR, 16);
#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
	SET_BIT(RCC_CFGR, 16);
	SET_BIT(RCC_CFGR, 17);
#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
	SET_BIT(RCC_CFGR, 16);
	CLR_BIT(RCC_CFGR, 17);
#else 
#error("Wrong Input")
#endif
	RCC_CFGR = (RCC_CFGR & 0xFFC3FFFF) + (RCC_PLL_MUL_VAL << 16);
	SET_BIT(RCC_CR, 24);

#else
#error("You Chosed Wrong Clock Type");
#endif

}

void RCC_voidEnableClock(uint8 Copy_uint8BusId, uint8 Copy_uint8PerId)
{
	if (Copy_uint8PerId <= 31)//Number of peripheral *Per for Peripheral*
	{
		switch (Copy_uint8BusId)// check whether bus 
		{
		case RCC_AHB: SET_BIT(RCC_AHBENR, Copy_uint8PerId); break;
		case RCC_APB1: SET_BIT(RCC_APB1ENR, Copy_uint8PerId); break;
		case RCC_APB2: SET_BIT(RCC_APB2ENR, Copy_uint8PerId); break;
			//default	removed to NOT get an error from compiler		: //return error

		}

	}

	else
	{
		//return error

	}



}
void RCC_voidDisableClock(uint8 Copy_uint8BusId, uint8 Copy_uint8PerId)
{
	if (Copy_uint8PerId <= 31)//Number of peripheral *Per for Peripheral*
	{
		switch (Copy_uint8BusId)// check whether bus 
		{
		case RCC_AHB: CLR_BIT(RCC_AHBENR, Copy_uint8PerId); break;
		case RCC_APB1: CLR_BIT(RCC_APB1ENR, Copy_uint8PerId); break;
		case RCC_APB2: CLR_BIT(RCC_APB2ENR, Copy_uint8PerId); break;
			//default	removed to NOT get an error from compiler		: //return error

		}

	}

	else
	{
		//return error

	}



}
