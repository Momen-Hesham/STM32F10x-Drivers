/**************************************************************
// Author  :		Mo'men Hesham
// Date	   :		8/8/2020
//Version	   :		V01
****************************************************************/

#ifndef RCC_CONFIG_H //Include guard written in capital
#define RCC_CONFIG_H

/* Options :	RCC_HSE_CRYSTAL
				RCC_HSE_RC
				RCC_HSI
				RCC_PLL	*/
#define RCC_CLOCK_TYPE RCC_HSE_CRYSTAL // Lazem a7otlo el options 2abl kol config parameter 


				// Note: Select Value only if you have chaoose PLL as input clock source
#if RCC_CLOCK_TYPE == RCC_PLL

	/*Options :		RCC_PLL_IN_HSI_DIV_2
				RCC_PLL_IN_HSE_DIV_2
				RCC_PLL_IN_HSE	*/
#define	RCC_PLL_INPUT	RCC_HSE_CRYSTAL// Default value w lw el user 7ab ye3'ero bera7to

				// Options :	RCC_PLL_MUL_x ,Where x: 2 to 16
#define RCC_PLL_MUL_VAL	RCC_PLL_MUL_2
#endif

#endif
