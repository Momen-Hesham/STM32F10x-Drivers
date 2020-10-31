/******************************/
/* Author  : Mo'men Hesham ****/
/* Version : V01 **************/
/******************************/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void MUSART1_voidInit(void);
void MUSART1_voidTransmit(uint8 arr[]);
uint8 MUSART1_uint8Receive_BusyWait(void);
uint8 MUSART1_uint8Receive_Polling(uint32 TimeOut);

#endif
