/******************************/
/* Author  : Mo'men Hesham ****/
/* Version : V01 **************/
/******************************/

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

typedef struct
{
	volatile uint32 SR;
	volatile uint32 DR;
	volatile uint32 BRR;
	volatile uint32 CR1;
	volatile uint32 CR2;
	volatile uint32 CR3;
	volatile uint32 GTPR;
}MUART_Type;


#define MUSART1	((volatile MUART_Type *) 0x40013800)


#define START1_DATA8_STOPN						1
#define START1_DATA9_STOPN						2
	
#define HALF_STOP_BIT							3
#define ONE_STOP_BIT							4
#define ONE_AND_HALF_STOP_BITS					5
#define TWO_STOP_BITS							6
	
#define IDLE_LINE								7
#define ADDRESS_MARK							8
	
#define DISABLE_PARITY							9
#define ENABLE_PARITY							10
	
#define EVEN_PARITY								11
#define ODD_PARITY								12
	
#define DISABLE_PARITY_INTERRUPT				13
#define ENABLE_PARITY_INTERRUPT					14
	
#define DISABLE_TXEIE							15
#define ENABLE_TXEIE							16
	
#define DISABLE_TCIE							17
#define ENABLE_TCIE								18
	
#define DISABLE_RXNEIE							19
#define ENABLE_RXNEIE							20
	
#define DISABLE_IDLEIE							21
#define ENABLE_IDLEIE							22
	
#define ENABLE_TX								23
#define DISABLE_TX								24
	
#define ENABLE_RX								25
#define DISABLE_RX								26
	
#define RX_IN_ACTIVE_MODE						27
#define RX_IN_MUTE_MODE							28
	
#define NO_BREAK_CHAR_TRANSMITTED				29
#define BREAK_CHAR_TRANSMITTED					30
	
#define DISABLE_LIN_MODE						31
#define ENABLE_LIN_MODE							32
	
#define INHIBIT_LBDIE							33
#define ENABLE_LBDIE							34
	
#define LBDL_10_BIT								35
#define LBDL_11_BIT								36
	
#define DISABLE_CLK_PIN							37
#define ENABLE_CLK_PIN							38
	
#define SET_LOW_VALUE_ON_CLK					39
#define SET_HIGH_VALUE_ON_CLK					40
	
#define CAPTURE_AT_FIRST_CLK_TRANSITION			41
#define CAPTURE_AT_SECOND_CLK_TRANSITION		42
	
#define OUT_LB_ON_CLK_PIN						43
#define NOT_OUT_LB_ON_CLK_PIN					44
	
#define DISABLE_CTS								45
#define ENABLE_CTS								46
	
#define DISABLE_CTSIE							47
#define ENABLE_CTSIE							48
	
#define DISABLE_RTS								49
#define ENABLE_RTS								50
	
#define DISABLE_DMA_FOR_TRANSMISSION			51
#define ENABLE_DMA_FOR_TRANSMISSION				52
	
#define DISABLE_DMA_FOR_RECEPTION				53
#define ENABLE_DMA_FOR_RECEPTION				54
	
#define DISABLE_SMART_CARD_MODE					55
#define ENABLE_SMART_CARD_MODE					56
	
#define NACK_TRANSMITTION_AT_PARITY_DISABLED	57
#define NACK_TRANSMITTION_AT_PARITY_ENABLED		58

#define HALF_DUPLEX_NOT_SELECTED				59
#define HALF_DUPLEX_SELECTED					60

#define DISABLE_IRDA							61
#define ENABLE_IRDA								62

#define IRLP_NORMAL_MODE						63
#define IRLP_LOW_POWER_MODE						64

#define DISABLE_EIE								65
#define ENABLE_EIE								66



#endif
