/******************************/
/* Author  : Mo'men Hesham ****/
/* Version : V01 **************/
/******************************/

#ifndef UART_CONFIG_H
#define UART_CONFIG_H

#define FREQ_SYS_CLK    8000000
#define BAUD_RATE_REQ   115200

/* Options : START1_DATA8_STOPN
             START1_DATA9_STOPN
*/
#define WORD_LENGTH     START1_DATA8_STOPN

/* Options : HALF_STOP_BIT
             ONE_STOP_BIT
             ONE_AND_HALF_STOP_BITS
             TWO_STOP_BITS

*/
#define STOP_BITS_NUMBER    ONE_STOP_BIT

/* Options : IDLE_LINE
             ADDRESS_MARK
*/
#define WAKEUP_METHOD   IDLE_LINE

/* Options : DISABLE_PARITY
             ENABLE_PARITY
*/
#define PARITY_CONTROL  DISABLE_PARITY

/* Options : EVEN_PARITY
             ODD_PARITY
*/
#define PARITY_SELECTION    EVEN_PARITY // ONLY valuable when parity is enabled

/* Options : DISABLE_PARITY_INTERRUPT
             ENABLE_PARITY_INTERRUPT
*/
#define PARITY_INTERRUPT    DISABLE_PARITY_INTERRUPT // ONLY valuable when parity is enabled

/* Options : DISABLE_TXEIE
             ENABLE_TXEIE
*/
#define TRANSFER_REG_EMPTY_INT  DISABLE_TXEIE

/* Options : DISABLE_TCIE
             ENABLE_TCIE
*/
#define TRANSFER_COMPLETE_INT   DISABLE_TCIE

/* Options : DISABLE_RXNEIE
             ENABLE_RXNEIE
*/
#define RECEIVE_REG_NOT_EMPTY_INT  DISABLE_RXNEIE

/* Options : DISABLE_IDLEIE
             ENABLE_IDLEIE
*/
#define IDLE_LINE_DETECTED_INT  DISABLE_IDLEIE

/* Options : ENABLE_TX
             DISABLE_TX
*/
#define TRANSMITTER_CONTROL     ENABLE_TX

/* Options : ENABLE_RX
             DISABLE_RX
*/
#define RECEIVER_CONTROL     ENABLE_RX

/* Options : RX_IN_ACTIVE_MODE
             RX_IN_MUTE_MODE  
*/
#define RECEIVER_WAKEUP_MODE    RX_IN_ACTIVE_MODE

/* Options : NO_BREAK_CHAR_TRANSMITTED
             BREAK_CHAR_TRANSMITTED
*/
#define SEND_BREAK_CONTROL      NO_BREAK_CHAR_TRANSMITTED

/* Options : DISABLE_LIN_MODE
             ENABLE_LIN_MODE
*/
#define LIN_MODE_CONTROL    DISABLE_LIN_MODE

/* Options : INHIBIT_LBDIE
             ENABLE_LBDIE
*/
#define LIN_BREAK_DETECTION_INT INHIBIT_LBDIE // ONLY valuable when LIN_MODE_CONTROL is enabled

/* Options : LBDL_10_BIT
             LBDL_11_BIT
*/
#define LIN_BREAK_DETECTION_LENGTH  LBDL_10_BIT // ONLY valuable when LIN_MODE_CONTROL is enabled

/* Options : DISABLE_CLK_PIN
             ENABLE_CLK_PIN
*/
#define CLK_PIN_CONTROL DISABLE_CLK_PIN

/* Options : SET_LOW_VALUE_ON_CLK
             SET_HIGH_VALUE_ON_CLK
*/
#define CLK_PIN_POLARITY    SET_LOW_VALUE_ON_CLK // ONLY valuable when CLK_PIN_CONTROL is enabled

/* Options : CAPTURE_AT_FIRST_CLK_TRANSITION
             CAPTURE_AT_SECOND_CLK_TRANSITION
*/
#define CLK_PIN_PHASE   CAPTURE_AT_FIRST_CLK_TRANSITION // ONLY valuable when CLK_PIN_CONTROL is enabled

/* Options : OUT_LB_ON_CLK_PIN
             NOT_OUT_LB_ON_CLK_PIN
*/
#define LAST_BIT_CLK_PULSE  NOT_OUT_LB_ON_CLK_PIN // ONLY valuable when CLK_PIN_CONTROL is enabled

/* Options : DISABLE_CTS
             ENABLE_CTS
*/
#define CTS_CONTROL DISABLE_CTS

/* Options : DISABLE_CTSIE
             ENABLE_CTSIE
*/
#define CTS_INTERRUPT   DISABLE_CTSIE // ONLY valuable when CTS_CONTROL is enabled

/* Options : DISABLE_RTS
             ENABLE_RTS
*/
#define RTS_CONTROL DISABLE_RTS

/* Options : DISABLE_DMA_FOR_TRANSMISSION
             ENABLE_DMA_FOR_TRANSMISSION
*/
#define DMA_TRANSMITTER_CONTROL DISABLE_DMA_FOR_TRANSMISSION

/* Options : DISABLE_DMA_FOR_RECEPTION
             ENABLE_DMA_FOR_RECEPTION
*/
#define DMA_RECEIVER_CONTROL DISABLE_DMA_FOR_RECEPTION

/* Options : DISABLE_SMART_CARD_MODE
             ENABLE_SMART_CARD_MODE
*/
#define SMART_CARD_CONTROL     DISABLE_SMART_CARD_MODE

/* Options : NACK_TRANSMITTION_AT_PARITY_DISABLED
             NACK_TRANSMITTION_AT_PARITY_ENABLED
*/
#define SMART_CARD_NACK     NACK_TRANSMITTION_AT_PARITY_DISABLED // ONLY valuable when SMART_CARD_CONTROL is enabled

/* Options : HALF_DUPLEX_NOT_SELECTED
             HALF_DUPLEX_SELECTED
*/
#define HALF_DUPLEX_CONTROL HALF_DUPLEX_NOT_SELECTED

/* Options : DISABLE_IRDA
             ENABLE_IRDA
*/
#define IRDA_CONTROL    DISABLE_IRDA

/* Options : IRLP_NORMAL_MODE
             IRLP_LOW_POWER_MODE
*/
#define IRDA_LOW_POWER  IRLP_NORMAL_MODE // ONLY valuable when IRDA_CONTROL is enabled

/* Options : DISABLE_EIE
             ENABLE_EIE
*/
#define ERROR_INTERRUPT_CONTROL DISABLE_EIE

#define ADDRESS_OF_USART_NODE   0

#define GUARD_TIME  0

#define USART_PRESCALER 0

#endif
