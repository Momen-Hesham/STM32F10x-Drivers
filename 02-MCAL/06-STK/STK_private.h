/************************************************/
/* Author 	:	Mo'men Hesham					*/
/* Version 	: 	v1								*/
/* Date 	:	26/8/2020						*/
/************************************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

void (*CallBack_Function)(void);

#define STK_BASE_ADDRESS	0xE000E010
#define SINGLE_INTERVAL		0
#define PERIODIC_INTERVAL	1

uint8 SingleOrPeridoic=SINGLE_INTERVAL;

#define STK_CTRL		*((volatile uint32 *) STK_BASE_ADDRESS)
#define STK_LOAD		*((volatile uint32 *) (STK_BASE_ADDRESS + 0x04) )
#define STK_VAL			*((volatile uint32 *) (STK_BASE_ADDRESS + 0x08) )
#define STK_CALIB		*((volatile uint32 *) (STK_BASE_ADDRESS + 0x0C) )




#endif
