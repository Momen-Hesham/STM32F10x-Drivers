#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define LINE0	0
#define LINE1	1
#define LINE2	2
#define LINE3	3
#define LINE4	4
#define LINE5	5
#define LINE6	6
#define LINE7	7
#define LINE8	8
#define LINE9	9
#define LINE10	10
#define LINE11	11
#define LINE12	12
#define LINE13	13
#define LINE14	14
#define LINE15	15

#define RISING_EDGE			0
#define FALLING_EDGE		1
#define ON_CHANGE			2


/* Line and Mode */
void MEXTI_voidInit  ();

void MEXTI_voidEnableEXTI(uint8 copy_uint8Line);
void MEXTI_voidDisableEXTI(uint8 copy_uint8Line);
void MEXTI_voidSwTrigger(uint8 copy_uint8Line);
void MEXTI_voidSetSignalLatch(uint8 copy_uint8Line, uint8 copy_uint8Mode);// 3shan a7wl el Sense Mode fel run time fa badl maho rissing edge masln a5leh falling 

void MEXTI_voidSetCallBack(void (*Func_ptr) (void));// Lma yegy el interrupt aro7 le anhy function
void MEXTI_voidSetCallBackManually(uint8 Copy_uint8Line,void (*Func_ptr) (void));

#endif 
