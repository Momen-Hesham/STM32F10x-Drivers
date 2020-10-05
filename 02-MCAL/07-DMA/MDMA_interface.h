/********************************/
/* Author  : Mo'men Hesham		*/
/* Version : V01				*/
/********************************/

#ifndef MDMA_INTERFACE_H
#define MDMA_INTERFACE_H

void MDMA_voidChannelInit(void);

void MDMA_voidChannelStart(void (*Copy_FuncPtr)(void),uint32 * Copy_Ptruint32SourceAddress,uint32 * Copy_Ptruint32DestinationAddress,uint16 Copy_uint16BlockLength);

uint8 MDMA_voidReadFlags(void);


#endif
