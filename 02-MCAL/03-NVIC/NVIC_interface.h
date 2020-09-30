/*********************************************
// Author	: Mo'men Hesham
// Date		: 19/8/2020
// Version	: V01
*********************************************/
// Da el file el wa7ed elly el ayers elly fo2ya momkiin yeshofha
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H_H 

void MNVIC_voidEnableInterrupt(uint8 Copy_uint8IntNumber);
void MNVIC_voidDisableInterrupt(uint8 Copy_uint8IntNumber);

void MNVIC_voidSetPendingFlag(uint8 Copy_uint8IntNumber);
void MNVIC_voidClearPendingFlag(uint8 Copy_uint8IntNumber);

uint8 MNVIC_uint8GetActiveFlag(uint8 Copy_uint8IntNumber);

//void MNVIC_voidSetPriority( int8 copy_int8IntID, uint8 copy_uint8GroupPriority, uint8 copy_uint8SubPriority,uint32 copy_uint32Group );
void MNVIC_voidSetPriority(uint8 Copy_uint8PeripheralIdx,uint8 Copy_uint8Priority);

void MNVIC_voidInit(void);

#define GROUP3	0x05FA0300	// 4 bits for Selecting group
#define GROUP4	0x05FA0400	// 3 bits for Selecting group and 1 for subpriority 
#define GROUP5	0x05FA0500	// 2 bits for Selecting group and 2 for subpriority 
#define GROUP6	0x05FA0600	// 1 bits for Selecting group and 3 for subpriority 
#define GROUP7	0x05FA0700	// 4 bits for subpriority 

#endif
