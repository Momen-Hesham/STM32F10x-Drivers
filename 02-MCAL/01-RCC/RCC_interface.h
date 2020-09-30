/**************************************************************
// Author  :		Mo'men Hesham
// Date	   :		8/8/2020
//Version	   :		V01
****************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB	     0
#define RCC_APB1	 1
#define RCC_APB2	 2

void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(uint8 Copy_uint8BusId, uint8 Copy_uint8PerId);
void RCC_voidDisableClock(uint8 Copy_uint8BusId, uint8 Copy_uint8PerId);

#endif
