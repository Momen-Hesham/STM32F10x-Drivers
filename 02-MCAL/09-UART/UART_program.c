/******************************/
/* Author  : Mo'men Hesham ****/
/* Version : V01 **************/
/******************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void MUSART1_voidInit(void)
{
	uint16 Local_uint16BaudRateCalc=0;
	Local_uint16BaudRateCalc = FREQ_SYS_CLK/(BAUD_RATE_REQ *16);
	MUSART1 ->BRR = Local_uint16BaudRateCalc << 4;

	Local_uint16BaudRateCalc = (FREQ_SYS_CLK *100 )/(BAUD_RATE_REQ *16);
	Local_uint16BaudRateCalc =Local_uint16BaudRateCalc %100;

	Local_uint16BaudRateCalc = (Local_uint16BaudRateCalc*16)/100;

	MUSART1 ->BRR &= ~(0x000F);
	MUSART1 -> BRR |= (Local_uint16BaudRateCalc & 0x0F);

	#if WORD_LENGTH == START1_DATA8_STOPN
	CLR_BIT(MUSART1->CR1,12);
	#else
	SET_BIT(MUSART1->CR1,12);
	#endif

	#if WAKEUP_METHOD == IDLE_LINE
	CLR_BIT(MUSART1->CR1,11);
	#else
	SET_BIT(MUSART1->CR1,12);
	#endif

	#if PARITY_CONTROL == ENABLE_PARITY
		SET_BIT(MUSART1->CR1,10);
			#if PARITY_SELECTION == EVEN_PARITY
				CLR_BIT(MUSART1->CR1,9);
			#else
				SET_BIT(MUSART1->CR1,9);
			#endif
			#if PARITY_INTERRUPT == DISABLE_PARITY_INTERRUPT
				CLR_BIT(MUSART1->CR1,8);
			#else
				SET_BIT(MUSART1->CR1,8);
			#endif
	#else
		CLR_BIT(MUSART1->CR1,10);
		CLR_BIT(MUSART1->CR1,9);
		CLR_BIT(MUSART1->CR1,8);
	#endif

	#if TRANSFER_REG_EMPTY_INT == DISABLE_TXEIE
		CLR_BIT(MUSART1->CR1,7);
	#else
		SET_BIT(MUSART1->CR1,7);
	#endif

	#if TRANSFER_COMPLETE_INT == DISABLE_TCIE
		CLR_BIT(MUSART1->CR1,6);
	#else
		SET_BIT(MUSART1->CR1,6);
	#endif

	#if RECEIVE_REG_NOT_EMPTY_INT == DISABLE_RXNEIE
		CLR_BIT(MUSART1->CR1,5);
	#else
		SET_BIT(MUSART1->CR1,5);
	#endif

	#if IDLE_LINE_DETECTED_INT == DISABLE_IDLEIE
		CLR_BIT(MUSART1->CR1,4);
	#else
		SET_BIT(MUSART1->CR1,4);
	#endif

	#if TRANSMITTER_CONTROL == ENABLE_TX
		SET_BIT(MUSART1->CR1,3);
	#else
		CLR_BIT(MUSART1->CR1,3);
	#endif

	#if RECEIVER_CONTROL == ENABLE_RX
		SET_BIT(MUSART1->CR1,2);
	#else
		CLR_BIT(MUSART1->CR1,2);
	#endif

	#if RECEIVER_WAKEUP_MODE == RX_IN_ACTIVE_MODE
		CLR_BIT(MUSART1->CR1,1);
	#else
		SET_BIT(MUSART1->CR1,1);
	#endif

	#if SEND_BREAK_CONTROL == NO_BREAK_CHAR_TRANSMITTED
		CLR_BIT(MUSART1->CR1,0);
	#else
		SET_BIT(MUSART1->CR1,0);
	#endif


	#if STOP_BITS_NUMBER == ONE_AND_HALF_STOP_BITS
		SET_BIT(MUSART1 -> CR2,13);
		SET_BIT(MUSART1 -> CR2,12);
	#elif STOP_BITS_NUMBER == TWO_STOP_BITS
		SET_BIT(MUSART1 -> CR2,13);
		CLR_BIT(MUSART1 -> CR2,12);
	#elif STOP_BITS_NUMBER == HALF_STOP_BIT
		CLR_BIT(MUSART1 -> CR2,13);
		SET_BIT(MUSART1 -> CR2,12);
	#else
		CLR_BIT(MUSART1 -> CR2,13);
		CLR_BIT(MUSART1 -> CR2,12);
	#endif
	
	#if LIN_MODE_CONTROL == ENABLE_LIN_MODE
		SET_BIT(MUSART1->CR2,14);
			#if LIN_BREAK_DETECTION_INT == INHIBIT_LBDIE
				CLR_BIT(MUSART1->CR2,6);
			#else
				SET_BIT(MUSART1->CR2,6);
			#endif
			#if LIN_BREAK_DETECTION_LENGTH == LBDL_10_BIT
				CLR_BIT(MUSART1->CR2,5);
			#else
				SET_BIT(MUSART1->CR2,5);
			#endif
	#else
		CLR_BIT(MUSART1->CR2,14);
		CLR_BIT(MUSART1->CR2,6);
		CLR_BIT(MUSART1->CR2,5);
	#endif
	
	#if CLK_PIN_CONTROL == ENABLE_CLK_PIN
		SET_BIT(MUSART1->CR2,11);
			#if CLK_PIN_POLARITY == SET_LOW_VALUE_ON_CLK
				CLR_BIT(MUSART1->CR2,10);
			#else
				SET_BIT(MUSART1->CR2,10);
			#endif
			#if CLK_PIN_PHASE == CAPTURE_AT_FIRST_CLK_TRANSITION
				CLR_BIT(MUSART1->CR2,9);
			#else
				SET_BIT(MUSART1->CR2,9);
			#endif
			#if LAST_BIT_CLK_PULSE == NOT_OUT_LB_ON_CLK_PIN
				CLR_BIT(MUSART1->CR2,8);
			#else
				SET_BIT(MUSART1->CR2,8);
			#endif
	#else
		CLR_BIT(MUSART1->CR2,11);
		CLR_BIT(MUSART1->CR2,10);
		CLR_BIT(MUSART1->CR2,9);
		CLR_BIT(MUSART1->CR2,8);
	#endif

	#if CTS_CONTROL == ENABLE_cts
		SET_BIT(MUSART1->CR3,9);
			#if CTS_INTERRUPT == DISABLE_CTSIE
				CLR_BIT(MUSART1->CR3,10);
			#else
				SET_BIT(MUSART1->CR3,10);
			#endif
	#else
		CLR_BIT(MUSART1->CR3,9);
		CLR_BIT(MUSART1->CR3,10);
	#endif

	#if RTS_CONTROL == DISABLE_RTS
		CLR_BIT(MUSART1->CR3,8);
	#else
		SET_BIT(MUSART1->CR3,8);
	#endif

	#if DMA_TRANSMITTER_CONTROL == DISABLE_DMA_FOR_TRANSMISSION
		CLR_BIT(MUSART1->CR3,7);
	#else
		SET_BIT(MUSART1->CR3,7);
	#endif

	#if DMA_RECEIVER_CONTROL == DISABLE_DMA_FOR_RECEPTION
		CLR_BIT(MUSART1->CR3,6);
	#else
		SET_BIT(MUSART1->CR3,6);
	#endif

	#if SMART_CARD_CONTROL == ENABLE_SMART_CARD_MODE
		SET_BIT(MUSART1->CR3,5);
			#if SMART_CARD_NACK == NACK_TRANSMITTION_AT_PARITY_DISABLED
				CLR_BIT(MUSART1->CR3,4);
			#else
				SET_BIT(MUSART1->CR3,4);
			#endif
	#else
		CLR_BIT(MUSART1->CR3,5);
		CLR_BIT(MUSART1->CR3,4);
	#endif


	#if HALF_DUPLEX_CONTROL == HALF_DUPLEX_NOT_SELECTED
		CLR_BIT(MUSART1->CR3,3);
	#else
		SET_BIT(MUSART1->CR3,3);
	#endif

	#if IRDA_CONTROL == ENABLE_IRDA
		SET_BIT(MUSART1->CR3,1);
			#if IRDA_LOW_POWER == IRLP_NORMAL_MODE
				CLR_BIT(MUSART1->CR3,2);
			#else
				SET_BIT(MUSART1->CR3,2);
			#endif
	#else
		CLR_BIT(MUSART1->CR3,2);
		CLR_BIT(MUSART1->CR3,1);
	#endif
	
	#if ERROR_INTERRUPT_CONTROL == DISABLE_EIE
		CLR_BIT(MUSART1->CR3,0);
	#else
		SET_BIT(MUSART1->CR3,0);
	#endif

	MUSART1 -> CR2 &= ~(0x000F);
	MUSART1 -> CR2 |= (ADDRESS_OF_USART_NODE & 0xF);

	MUSART1 -> GTPR = (GUARD_TIME << 8);

	MUSART1 -> GTPR &= ~(0x00FF);
	MUSART1 -> GTPR |= (USART_PRESCALER & 0xF); 
	
	SET_BIT(MUSART1->CR1,13);
	MUSART1->SR=0;
}
void MUSART1_voidTransmit(uint8 arr[])
{
	uint8 i=0;
	
	while(arr[i] != '\0')
	{
		MUSART1 ->DR =arr[i];
		
		/* Wait till transmission is complete*/
		while((GET_BIT(MUSART1->SR,6)) == 0);

		i++;
	}
	
	
}
uint8 MUSART1_uint8Receive_BusyWait(void)
{
	uint8 Local_uint8ReceivedData=0;

	while((GET_BIT(MUSART1 -> SR,5)) == 0);

	Local_uint8ReceivedData=(0xFF & (MUSART1->DR));
	return Local_uint8ReceivedData;
}

uint8 MUSART1_uint8Receive_Polling(uint32 TimeOut)
{
	uint32 Local_uint32Timeout=0;
	uint8 Local_uint8ReceivedData=0;
	
	while((GET_BIT(MUSART1 -> SR,5)) == 0)
	{
		Local_uint32Timeout++;
		if ( Local_uint32Timeout == TimeOut)
		{
			Local_uint8ReceivedData=255;
			break;
		}
	}
	if(Local_uint8ReceivedData==0)
		Local_uint8ReceivedData=(0xFF & (MUSART1->DR));
	
	return Local_uint8ReceivedData;


}
