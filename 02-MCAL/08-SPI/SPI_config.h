/******************************/
/* Author  : Mo'men Hesham    */
/* Version : V01              */
/******************************/

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#define MSPI1_SLAVE_PIN		GPIOA,0

/* Options : TWO_LINE_UNI_DIR
 * 			 ONE_LINE_BI_DIR
 */
#define BI_DIR_MODE			TWO_LINE_UNI_DIR

/* Options : RECEIVE_ONLY
 * 			 TRANSMIT_ONLY
 * Hint : 	 it combined with BI_DIR_MODE in case ONE_LINE_BI_DIR
 * 			 to SELECT the direction of transfer in bi-direction mode
 */
#define BI_DIR_OUT_ENABLE	RECIEVE_ONLY // Only Valuable when Bi-directional mode is enabled


/* Options : CRC_ENABLE
 * 			 CRC_NOT_ENABLE
 */
#define CRC_MODE	CRC_NOT_ENABLE

/* Options : DATA_PHASE
 * 			 NEXT_PHASE
 */
#define CRC_NEXT	DATA_PHASE	// Only Valuable when crc is enabled

/* Options : This register contains the polynomial for the CRC calculation.
 */
#define CRC_POLYNOMINAL_REG		0x0007 // Only Valuable when crc is enabled
/* Options : DATA_FRAME_8_BIT
 * 			 DATA_FRAME_16_BIT
 */
#define DATA_FRAME	DATA_FRAME_8_BIT


/* Options : TRANSMIT_AND_RECEIVE
 * 			 ONLY_RECEIVE
 */
#define RECEIVE_ONLY_MODE	TRANSMIT_AND_RECEIVE


/* Options : SOFTWARE_SLAVE_MANAGEMENT_ENABLE
 * 			 SOFTWARE_SLAVE_MANAGEMENT_DISABLE
 */
#define SOFTWARE_SLAVE_MANAGEMENT_MODE	SOFTWARE_SLAVE_MANAGEMENT_ENABLE

/* Options : SET_SSI
 * 			 CLR_SSI
 */

#define INTERNAL_SLAVE_SELECT	SET_SSI

/* Options : MSB_TRANSMITTED_FIRST
 * 			 LSB_TRANSMITTED_FIRST
 */
#define FRAME_FORMAT	MSB_TRANSMITTED_FIRST

/* Options : SYS_CLK_DIV_2
 * 			 SYS_CLK_DIV_4
 * 			 SYS_CLK_DIV_8
 * 			 SYS_CLK_DIV_16
 * 			 SYS_CLK_DIV_32
 * 			 SYS_CLK_DIV_64
 * 			 SYS_CLK_DIV_128
 * 			 SYS_CLK_DIV_256
 */
#define BAUD_RATE_CONTROL	SYS_CLK_DIV_2

/* Options : MASTER_SELECTION
 * 			 SLAVE_SELECTION
 */

#define MASTER_SLAVE_SELECTION	MASTER_SELECTION

/* Options : SECOND_CLK_TRANSITION
 * 			 FIRST_CLK_TRANSITION
 */
#define CLK_PHASE	SECOND_CLK_TRANSITION

/* Options : CLK_ZERO_IDLE
 * 			 CLK_ONE_IDLE
 */
#define CLK_POLARITY	CLK_ONE_IDLE

/* Options : TX_BUFF_EMPTY
 * 			 RX_BUFF_NOT_EMPTY
 * 			 ERROR_INTERRUPT
 * 			 TX_AND_RX
 * 			 TX_AND_ERROR
 * 			 RX_AND_ERROR
 * 			 TX_RX_ERROR
 * 			 NO_INTERRUPT
 */
#define SPI_INTERRUPT_ENABLE	NO_INTERRUPT

/* Options : SS_OUTPUT_DISABLE
 * 			 SS_OUTPUT_ENABLE
 */
#define SLAVE_SELECT_OUTPUT		SS_OUTPUT_DISABLE

/* Options : TX_BUFF_DMA_ENABLE
 * 			 TX_BUFF_DMA_DISABLE
 */
#define TX_BUFF_DMA_MODE		TX_BUFF_DMA_DISABLE

/* Options : RX_BUFF_DMA_ENABLE
 * 			 RX_BUFF_DMA_DISABLE
 */
#define RX_BUFF_DMA_MODE		RX_BUFF_DMA_DISABLE

#endif
