/**************************************************************
// Author  :		Mo'men Hesham
// Date	   :		8/8/2020
//Version	   :		V01
****************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

// Register Definition

#define RCC_CR  		*((uint32 *) 0x40021000)	// choose the source clk to be in to cpu
#define RCC_CFGR  		*((uint32 *) 0x40021004)	//
#define RCC_CIR  		*((uint32 *) 0x40021008)
#define RCC_APB2RSTR  	*((uint32 *) 0x4002100C)
#define RCC_APB1RSTR  	*((uint32 *) 0x40021010)
#define RCC_AHBENR  	*((uint32 *) 0x40021014)	// enable / disable clk on different peripherals
#define RCC_APB2ENR  	*((uint32 *) 0x40021018)	//
#define RCC_APB1ENR  	*((uint32 *) 0x4002101C)	//
#define RCC_BDCR  		*((uint32 *) 0x40021020)
#define RCC_CSR			*((uint32 *) 0x40021024)


// Clock Types
#define RCC_HSE_CRYSTAL		0
#define RCC_HSE_RC			1	
#define	RCC_HSI				2	
#define	RCC_PLL				3

// PLL Options
#define 	RCC_PLL_IN_HSI_DIV_2	0
#define		RCC_PLL_IN_HSE_DIV_2	1
#define		RCC_PLL_IN_HSE			2

// PLL Multiplication Factor
#define		RCC_PLL_MUL_2	0x0000
#define		RCC_PLL_MUL_3	0x0001
#define		RCC_PLL_MUL_4	0x0010
#define		RCC_PLL_MUL_5	0x0011
#define		RCC_PLL_MUL_6	0x0100
#define		RCC_PLL_MUL_7	0x0101
#define		RCC_PLL_MUL_8	0x0110
#define		RCC_PLL_MUL_9	0x0111
#define		RCC_PLL_MUL_10	0x1000
#define		RCC_PLL_MUL_11	0x1001
#define		RCC_PLL_MUL_12	0x1010
#define		RCC_PLL_MUL_13	0x1011
#define		RCC_PLL_MUL_14	0x1100
#define		RCC_PLL_MUL_15	0x1101
#define		RCC_PLL_MUL_16	0x1110

#endif
