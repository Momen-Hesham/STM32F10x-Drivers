/******************************/
/* Author  : Mo'men Hesham    */
/* Version : V01              */
/******************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void MSPI1_voidInit(void);
void MSPI1_voidSendReceiveSynch(uint8 Copy_uint8DataToTransmit,uint8 *Copy_DataToReceive);
void MSPI1_voidSendReceiveASynch(uint8 Copy_uint8DataToTransmit,void (*CallBack_Func)(uint8));


#endif