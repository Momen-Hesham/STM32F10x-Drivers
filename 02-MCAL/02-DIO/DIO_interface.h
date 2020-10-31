/*******************************************************
**	Author  	:	Mo'men Hesham
**	Date		:	12/8/2020
**	Version		:	V01
**	Description	:	GPIO REGISTERS
*******************************************************/

//	Include Guard
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define GPIO_LOW	0
#define GPIO_HIGH	1

#define GPIOA	0
#define GPIOB	1
#define GPIOC	2

#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7
#define PIN8	8
#define PIN9	9
#define PIN10	10
#define PIN11	11
#define PIN12	12
#define PIN13	13
#define PIN14	14
#define PIN15	15

// [xx,yy] xx refer to CNF bits which tells me what mode of this pin:    Analog,Push pull,Floating (in Input Mode )
//																		 General purpose :Push pull , open drain/
//																		 Alternative function : Push Pull ,open drain(in output mode)

// [xx,yy] yy refers to Speed of pin (in output mode) or =00 (in input mode)

//Input
#define INPUT_ANALOG			0b0000
#define INPUT_FLOATING			0b0100
#define INPUT_PULL_UP_DOWN  	0b1000
//For Speed 10
#define OUTPUT_SPEED_10MHZ_PP     0b0001
#define OUTPUT_SPEED_10MHZ_OD     0b0101
#define OUTPUT_SPEED_10MHZ_AFPP   0b1001
#define OUTPUT_SPEED_10MHZ_AFOD   0b1101

//For Speed 2
#define OUTPUT_SPEED_2MHZ_PP      0b0010	// Output Push Pull 
#define OUTPUT_SPEED_2MHZ_OD      0b0110	// Output Open Drain
#define OUTPUT_SPEED_2MHZ_AFPP    0b1010	// Alternative function Output Push Pull
#define OUTPUT_SPEED_2MHZ_AFOD    0b1110	// Alternative function Output Open Drain

//For Speed 2
#define OUTPUT_SPEED_50MHZ_PP     0b0011
#define OUTPUT_SPEED_50MHZ_OD     0b0111
#define OUTPUT_SPEED_50MHZ_AFPP   0b1011
#define OUTPUT_SPEED_50MHZ_AFOD   0b1111

void MGPIO_voidSetPinDirection(uint8 copy_uint8PORT, uint8 copy_uint8PIN, uint8 copy_uint8Mode); // Mode hena ana a2sod beha input wla output

void MGPIO_voidSetPinValue(uint8 copy_uint8PORT, uint8 copy_uint8_PIN, uint8 copy_uint8Value); // Hena in case en el pin output ba5tar atl3 3leha 0 or 1 

uint8 MGPIO_uint8GetPinValue(uint8 copy_uint8PORT, uint8 copy_uint8PIN); // Hena in case en el pin input fa a2sr bel function dy arg3 el input

void MGPIO_voidSetPORTValue(uint8 copy_uint8PORT, uint16 copy_uint16Value);

void MGPIO_voidSetPORTDirection(uint8 copy_uint8PORT, uint8 copy_uint8Mode);

void MGPIO_voidTogglePinValue(uint8 copy_uint8PORT, uint8 copy_uint8PIN);

#endif
