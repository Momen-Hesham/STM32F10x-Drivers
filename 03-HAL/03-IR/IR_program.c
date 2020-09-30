/*
 * IR_program.c
 *
 *  Created on: Sep 30, 2020
 *      Author: Mo'men
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"

#include "IR_config.h"
#include "IR_private.h"
#include "IR_interface.h"

void IR_voidInit(void)
{
	MGPIO_voidSetPinDirection(IR_INPUT_PORT,IR_INPUT_PIN,INPUT_FLOATING);
	MEXTI_voidSetCallBackManually(IR_INPUT_PIN,voidGetFrame);

	MNVIC_voidInit();
	MSTK_voidInit();
#if IR_INPUT_PORT == GPIOA
	MAFIO_voidSetEXTIConfiguration(IR_INPUT_PIN,EXTI_PORTA);
#elif IR_INPUT_PORT == GPIOB
	MAFIO_voidSetEXTIConfiguration(IR_INPUT_PIN,EXTI_PORTB);
#else
	MAFIO_voidSetEXTIConfiguration(IR_INPUT_PIN,EXTI_PORTC);
#endif


}


void IR_voidGetData(void(*Copy_FuncPointer) (uint8 DataIn))
{
	Func_Ptr=Copy_FuncPointer;
#if IR_INPUT_PIN < PIN5
	MNVIC_voidEnableInterrupt(IR_INPUT_PIN+6);
#elif IR_INPUT_PIN < PIN10
	MNVIC_voidEnableInterrupt(23);
#else
	MNVIC_voidEnableInterrupt(40);
#endif

	MEXTI_voidSetSignalLatch(IR_INPUT_PIN,FALLING_EDGE);

}


