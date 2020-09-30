#include "SevenSegment_private.h"
#include "SevenSegment_interface.h"

void SevenSegment_voidDisplay(uint8 copy_uint8PORT,uint8 copy_uint8COMMON, uint8 copy_uint8NUMBER)
{
	//Determine Which Port is used
	#if copy_uint8PORT == SS_PORT
		#define SS_PORT PORTA
	#elif copy_uint8PORT == PORTB
		#define SS_PORT PORTB
	#else 
		#define SS_PORT INVALID_INPUT
	#endif

	//Determine Common Anode or Cathode
	#if copy_uint8COMMON == COMMON_ANODE
		#define SS_OUTPUT	GPIO_HIGH
		#define NOT_SS_OUTPUT	GPIO_LOW
	#elif copy_uint8COMMON == COMMON_CATHODE
		#define SS_OUTPUT	GPIO_LOW
		#define NOT_SS_OUTPUT	GPIO_HIGH
	#else
		#define SS_OUTPUT	INVALID_INPUT
	#endif

	if(SS_PORT != INVALID_INPUT && SS_OUTPUT != INVALID_INPUT)
	{
		MGPIO_voidSetPinDirection(SS_PORT, PIN0, OUTPUT_SPEED_10MHZ_PP);
		MGPIO_voidSetPinDirection(SS_PORT, PIN1, OUTPUT_SPEED_10MHZ_PP);
		MGPIO_voidSetPinDirection(SS_PORT, PIN2, OUTPUT_SPEED_10MHZ_PP);
		MGPIO_voidSetPinDirection(SS_PORT, PIN3, OUTPUT_SPEED_10MHZ_PP);
		MGPIO_voidSetPinDirection(SS_PORT, PIN4, OUTPUT_SPEED_10MHZ_PP);
		MGPIO_voidSetPinDirection(SS_PORT, PIN5, OUTPUT_SPEED_10MHZ_PP);
		MGPIO_voidSetPinDirection(SS_PORT, PIN6, OUTPUT_SPEED_10MHZ_PP);
		switch (copy_uint8NUMBER)
		{
			case(0):
				MGPIO_voidSet_PinValue(SS_PORT, PIN0, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN1, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN2, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN3, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN4, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN5, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN6, NOT_SS_OUTPUT);
			case(1):
				MGPIO_voidSet_PinValue(SS_PORT, PIN0, NOT_SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN1, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN2, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN3, NOT_SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN4, NOT_SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN5, NOT_SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN6, NOT_SS_OUTPUT);
			case(2):
				MGPIO_voidSet_PinValue(SS_PORT, PIN0, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN1, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN2, NOT_SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN3, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN4, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN5, NOT_SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN6, SS_OUTPUT);
			case(3):
				MGPIO_voidSet_PinValue(SS_PORT, PIN0, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN1, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN2, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN3, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN4, NOT_SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN5, NOT_SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN6, SS_OUTPUT);
			case(4):
				MGPIO_voidSet_PinValue(SS_PORT, PIN0, NOT_SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN1, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN2, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN3, NOT_SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN4, NOT_SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN5, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN6, SS_OUTPUT);
			case(5):
				MGPIO_voidSet_PinValue(SS_PORT, PIN0, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN1, NOT_SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN2, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN3, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN4, NOT_SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN5, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN6, SS_OUTPUT);
			case(6):
				MGPIO_voidSet_PinValue(SS_PORT, PIN0, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN1, NOT_SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN2, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN3, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN4, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN5, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN6, SS_OUTPUT);
			case(7):
				MGPIO_voidSet_PinValue(SS_PORT, PIN0, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN1, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN2, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN3, NOT_SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN4, NOT_SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN5, NOT_SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN6, NOT_SS_OUTPUT);
			case(8):
				MGPIO_voidSet_PinValue(SS_PORT, PIN0, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN1, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN2, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN3, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN4, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN5, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN6, SS_OUTPUT);
			case(9):
				MGPIO_voidSet_PinValue(SS_PORT, PIN0, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN1, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN2, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN3, NOT_SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN4, NOT_SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN5, SS_OUTPUT);
				MGPIO_voidSet_PinValue(SS_PORT, PIN6, SS_OUTPUT);

		}
	}

}