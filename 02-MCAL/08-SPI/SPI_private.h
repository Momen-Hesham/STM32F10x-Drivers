/******************************/
/* Author  : Mo'men Hesham    */
/* Version : V01              */
/******************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

typedef struct{
	volatile uint32 CR1;
	volatile uint32 CR2;
	volatile uint32 SR;
	volatile uint32 DR;
	volatile uint32 CRCPR;
	volatile uint32 RXCRCR;
	volatile uint32 TXCRCR;
	volatile uint32 I2SCFGR;
	volatile uint32 I2SPR;
}SPI_Register; 

#define MSPI1	((SPI_Register *) 0x40013000)


#define TWO_LINE_UNI_DIR					1
#define ONE_LINE_BI_DIR						2

#define RECEIVE_ONLY						3
#define TRANSMIT_ONLY						4

#define CRC_ENABLE							5
#define CRC_NOT_ENABLE						6

#define DATA_PHASE							7
#define NEXT_PHASE							8

#define DATA_FRAME_8_BIT					9
#define DATA_FRAME_16_BIT					10

#define TRANSMIT_AND_RECEIVE				11
#define ONLY_RECEIVE						12

#define SOFTWARE_SLAVE_MANAGEMENT_ENABLE	13
#define SOFTWARE_SLAVE_MANAGEMENT_DISABLE	14

#define SET_SSI								15
#define CLR_SSI								16

#define MSB_TRANSMITTED_FIRST				17
#define LSB_TRANSMITTED_FIRST				18

#define MASTER_SELECTION					19
#define SLAVE_SELECTION						20

#define SECOND_CLK_TRANSITION				21
#define FIRST_CLK_TRANSITION				22

#define CLK_ZERO_IDLE						23
#define CLK_ONE_IDLE						24

#define SS_OUTPUT_DISABLE					25
#define SS_OUTPUT_ENABLE					26

#define TX_BUFF_DMA_ENABLE					27
#define TX_BUFF_DMA_DISABLE					28

#define RX_BUFF_DMA_ENABLE					29
#define RX_BUFF_DMA_DISABLE					30

#define SYS_CLK_DIV_2		0
#define SYS_CLK_DIV_4		1
#define SYS_CLK_DIV_8		2
#define SYS_CLK_DIV_16		3
#define SYS_CLK_DIV_32		4
#define SYS_CLK_DIV_64		5
#define SYS_CLK_DIV_128		6
#define SYS_CLK_DIV_256		7

#define ERROR_INTERRUPT		0
#define NO_INTERRUPT		1
#define RX_BUFF_NOT_EMPTY	2
#define RX_AND_ERROR		3
#define TX_BUFF_EMPTY		4
#define TX_AND_ERROR		5
#define TX_AND_RX			6
#define TX_RX_ERROR			7


static void (*CallBack)(uint8);

#endif
