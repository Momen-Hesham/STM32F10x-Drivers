

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "MSTK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"





void HSTP_voidSendSynchronus(uint8 Copy_uint8DataToSend)
{
	sint8 Local_sint8Counter;
	uint8 Local_uint8Bit;
	
	for(Local_sint8Counter=7;Local_sint8Counter>=0;Local_sint8Counter--)
	{
		/* Send bit by bit Starting from MSB*/
		
		Local_uint8Bit = GET_BIT(Copy_uint8DataToSend,Local_sint8Counter);
		
		MGPIO_voidSetPinValue(HSTP_SERIAL_DATA,Local_uint8Bit);
		
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,GPIO_HIGH);
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,GPIO_LOW);
		MSTK_voidSetBusyWait(1);
	}
	
	MGPIO_voidSetPinValue(HSTP_STORE_CLOCK,GPIO_HIGH);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(HSTP_STORE_CLOCK,GPIO_LOW);
	MSTK_voidSetBusyWait(1);
	
	
}