/******************************/
/* Author  : Mo'men Hesham    */
/* Version : V01              */
/******************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"



void MSPI1_voidInit(void)
{
	// CPOL =1 ,CPHA =1, Prescaller =clk/2, SPI Enable, MSB First
	#if	BI_DIR_MODE == ONE_LINE_BI_DIR
	SET_BIT(MSPI1 -> CR1,15);
		#if BI_DIR_OUT_ENABLE == TRANSMIT_ONLY
		SET_BIT(MSPI1 -> CR1,14);
		#else
		CLR_BIT(MSPI1 -> CR1,14);
		#endif
	#else
	CLR_BIT(MSPI1 -> CR1,15);
	CLR_BIT(MSPI1 -> CR1,14);
	#endif

	#if CRC_MODE == CRC_ENABLE
	SET_BIT(MSPI1 -> CR1,13);
	MSPI1->CRCPR=CRC_POLYNOMINAL_REG;
#if CRC_NEXT == NEXT_PHASE
	SET_BIT(MSPI1 -> CR1,12);
#else
	CLR_BIT(MSPI1 -> CR1,12);
#endif
#else
	CLR_BIT(MSPI1 -> CR1,13);
	SET_BIT(MSPI1 -> CR1,12);
#endif

#if DATA_FRAME == DATA_FRAME_8_BIT
	CLR_BIT(MSPI1-> CR1,11);
#else
	SET_BIT(MSPI1-> CR1,11);
#endif

#if RECEIVE_ONLY_MODE == TRANSMIT_AND_RECEIVE
	CLR_BIT(MSPI1-> CR1,10);
#else
	SET_BIT(MSPI1-> CR1,10);
#endif

#if SOFTWARE_SLAVE_MANAGEMENT_MODE == SOFTWARE_SLAVE_MANAGEMENT_DISABLE
	CLR_BIT(MSPI1-> CR1,9);
#else
	SET_BIT(MSPI1-> CR1,9);
#endif

#if INTERNAL_SLAVE_SELECT == CLR_SSI
	CLR_BIT(MSPI1-> CR1,8);
#else
	SET_BIT(MSPI1-> CR1,8);
#endif

#if FRAME_FORMAT == MSB_TRANSMITTED_FIRST
	CLR_BIT(MSPI1-> CR1,7);
#else
	SET_BIT(MSPI1-> CR1,7);
#endif

MSPI1->CR1 &= ~(0x00000038);
MSPI1->CR1 |= (BAUD_RATE_CONTROL<<3);

#if MASTER_SLAVE_SELECTION == SLAVE_SELECTION
	CLR_BIT(MSPI1-> CR1,2);
#else
	SET_BIT(MSPI1-> CR1,2);
#endif

#if CLK_POLARITY == CLK_ZERO_IDLE
	CLR_BIT(MSPI1-> CR1,1);
#else
	SET_BIT(MSPI1-> CR1,1);
#endif

#if CLK_PHASE == FIRST_CLK_TRANSITION
	CLR_BIT(MSPI1-> CR1,0);
#else
	SET_BIT(MSPI1-> CR1,0);
#endif


	MSPI1->CR2 &= ~(0x000000E0);
#if SLAVE_SELECT_OUTPUT == SS_OUTPUT_DISABLE
	CLR_BIT(MSPI1-> CR2,2);
#else
	SET_BIT(MSPI1-> CR2,2);
#endif

#if TX_BUFF_DMA_MODE == TX_BUFF_DMA_DISABLE
	CLR_BIT(MSPI1-> CR2,1);
#else
	SET_BIT(MSPI1-> CR2,1);
#endif

#if RX_BUFF_DMA_MODE == RX_BUFF_DMA_DISABLE
	CLR_BIT(MSPI1-> CR2,0);
#else
	SET_BIT(MSPI1-> CR2,0);
#endif

	SET_BIT(MSPI1->CR1,6);
//MSPI1-> CR1 =0x0347;
}

void MSPI1_voidSendReceiveSynch(uint8 Copy_uint8DataToTransmit,uint8 *Copy_DataToReceive)
{
	MSPI1->CR2 &= ~(0x000000E0);
	// Clear For Slave Select Pin
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN,GPIO_LOW);
	
	// Send Data
	MSPI1 ->DR=Copy_uint8DataToTransmit;
	
	// Wait Busy Flag to finish
	while(GET_BIT(MSPI1-> SR,7)==1);
	
	//Return to the received data
	*Copy_DataToReceive=MSPI1->DR;
	
	
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN,GPIO_HIGH);
	MSPI1->CR2 |= (SPI_INTERRUPT_ENABLE<<3);

}

void MSPI1_voidSendReceiveASynch(uint8 Copy_uint8DataToTransmit,void (*CallBack_Func)(uint8))
{
	MSPI1->CR2 &= ~(0x000000E0);
	// Clear For Slave Select Pin
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN,GPIO_LOW);
	CallBack=CallBack_Func;
	// Send Data
	MSPI1 ->DR=Copy_uint8DataToTransmit;
	MSPI1->CR2 |= (SPI_INTERRUPT_ENABLE<<3);
}

void SPI1_IRQHandler(void)
{
	CallBack(MSPI1->DR);
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN,GPIO_HIGH);
}

