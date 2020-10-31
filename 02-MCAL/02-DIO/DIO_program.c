/*******************************************************
**	Author  	:	Mo'men Hesham
**	Date		:	12/8/2020
**	Version		:	V01
**	Description	:	GPIO REGISTERS
*******************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_config.h"

// M for MCAL 3lshan amyz benha w ben el libraries el gahza
void MGPIO_voidSetPinDirection(uint8 copy_uint8PORT, uint8 copy_uint8PIN, uint8 copy_uint8Mode)
{
	switch (copy_uint8PORT)
	{
	case GPIOA:
		if (copy_uint8PIN <= 7)
		{
			GPIOA_CRL &= ~((0b1111) << (copy_uint8PIN * 4));// To reset 4 bits for every pin
			GPIOA_CRL |= ((copy_uint8Mode) << (copy_uint8PIN * 4));// el Mode da el user el mafrod yedeny makano wa7ed men el macros beto3 el modes 
		}
		else if (copy_uint8PIN <= 15)
		{
			GPIOA_CRH &= ~((0b1111) << ((copy_uint8PIN - 8) * 4));// To reset 4 bits for every pin
			GPIOA_CRH |= ((copy_uint8Mode) << ((copy_uint8PIN - 8) * 4));//
		}
		else {

			//#error("INVALID PIN");
		}
		break;
	case GPIOB:
		if (copy_uint8PIN <= 7)
		{
			GPIOB_CRL &= ~((0b1111) << (copy_uint8PIN * 4));// To reset 4 bits for every pin
			GPIOB_CRL |= ((copy_uint8Mode) << (copy_uint8PIN * 4));// el Mode da el user el mafrod yedeny makano wa7ed men el macros beto3 el modes 
		}
		else if (copy_uint8PIN <= 15)
		{
			GPIOB_CRH &= ~((0b1111) << ((copy_uint8PIN - 8) * 4));// To reset 4 bits for every pin
			GPIOB_CRH |= ((copy_uint8Mode) << ((copy_uint8PIN - 8) * 4));//
		}
		else {

			//#error("INVALID PIN");
		}
		break;
	case GPIOC:
		if (copy_uint8PIN <= 7)
		{
			GPIOC_CRL &= ~((0b1111) << (copy_uint8PIN * 4));// To reset 4 bits for every pin
			GPIOC_CRL |= ((copy_uint8Mode) << (copy_uint8PIN * 4));// el Mode da el user el mafrod yedeny makano wa7ed men el macros beto3 el modes 
		}
		else if (copy_uint8PIN <= 15)
		{
			GPIOC_CRH &= ~((0b1111) << ((copy_uint8PIN - 8) * 4));// To reset 4 bits for every pin
			GPIOC_CRH |= ((copy_uint8Mode) << ((copy_uint8PIN - 8) * 4));//
		}
		else {

			//#error("INVALID PIN");
		}
		break;
	default:
		break;
	}
}

void MGPIO_voidSetPORTDirection(uint8 copy_uint8PORT, uint8 copy_uint8Mode)
{
	switch(copy_uint8PORT)
	{
	case GPIOA:
	{
		GPIOA_CRL=0;
		GPIOA_CRH=0;
		GPIOA_CRL |= ((copy_uint8Mode) << (0*4));
		GPIOA_CRL |= ((copy_uint8Mode) << (1*4));
		GPIOA_CRL |= ((copy_uint8Mode) << (2*4));
		GPIOA_CRL |= ((copy_uint8Mode) << (3*4));
		GPIOA_CRL |= ((copy_uint8Mode) << (4*4));
		GPIOA_CRL |= ((copy_uint8Mode) << (5*4));
		GPIOA_CRL |= ((copy_uint8Mode) << (6*4));
		GPIOA_CRL |= ((copy_uint8Mode) << (7*4));
		GPIOA_CRH |= ((copy_uint8Mode) << (0*4));
		GPIOA_CRH |= ((copy_uint8Mode) << (1*4));
		GPIOA_CRH |= ((copy_uint8Mode) << (2*4));
		GPIOA_CRH |= ((copy_uint8Mode) << (3*4));
		GPIOA_CRH |= ((copy_uint8Mode) << (4*4));
		GPIOA_CRH |= ((copy_uint8Mode) << (5*4));
		GPIOA_CRH |= ((copy_uint8Mode) << (6*4));
		GPIOA_CRH |= ((copy_uint8Mode) << (7*4));
	}break;
	case GPIOB:
	{
		GPIOB_CRL=0;
		GPIOB_CRH=0;
		GPIOB_CRL |= ((copy_uint8Mode) << (0*4));
		GPIOB_CRL |= ((copy_uint8Mode) << (1*4));
		GPIOB_CRL |= ((copy_uint8Mode) << (2*4));
		GPIOB_CRL |= ((copy_uint8Mode) << (3*4));
		GPIOB_CRL |= ((copy_uint8Mode) << (4*4));
		GPIOB_CRL |= ((copy_uint8Mode) << (5*4));
		GPIOB_CRL |= ((copy_uint8Mode) << (6*4));
		GPIOB_CRL |= ((copy_uint8Mode) << (7*4));
		GPIOB_CRH |= ((copy_uint8Mode) << (0*4));
		GPIOB_CRH |= ((copy_uint8Mode) << (1*4));
		GPIOB_CRH |= ((copy_uint8Mode) << (2*4));
		GPIOB_CRH |= ((copy_uint8Mode) << (3*4));
		GPIOB_CRH |= ((copy_uint8Mode) << (4*4));
		GPIOB_CRH |= ((copy_uint8Mode) << (5*4));
		GPIOB_CRH |= ((copy_uint8Mode) << (6*4));
		GPIOB_CRH |= ((copy_uint8Mode) << (7*4));
	}break;
	case GPIOC:
	{
		GPIOC_CRL=0;
		GPIOC_CRH=0;
		GPIOC_CRL |= ((copy_uint8Mode) << (0*4));
		GPIOC_CRL |= ((copy_uint8Mode) << (1*4));
		GPIOC_CRL |= ((copy_uint8Mode) << (2*4));
		GPIOC_CRL |= ((copy_uint8Mode) << (3*4));
		GPIOC_CRL |= ((copy_uint8Mode) << (4*4));
		GPIOC_CRL |= ((copy_uint8Mode) << (5*4));
		GPIOC_CRL |= ((copy_uint8Mode) << (6*4));
		GPIOC_CRL |= ((copy_uint8Mode) << (7*4));
		GPIOC_CRH |= ((copy_uint8Mode) << (0*4));
		GPIOC_CRH |= ((copy_uint8Mode) << (1*4));
		GPIOC_CRH |= ((copy_uint8Mode) << (2*4));
		GPIOC_CRH |= ((copy_uint8Mode) << (3*4));
		GPIOC_CRH |= ((copy_uint8Mode) << (4*4));
		GPIOC_CRH |= ((copy_uint8Mode) << (5*4));
		GPIOC_CRH |= ((copy_uint8Mode) << (6*4));
		GPIOC_CRH |= ((copy_uint8Mode) << (7*4));
	}break;
	default:
	{
		// INVALID PORT

	}break;
	}

}

void MGPIO_voidSetPinValue(uint8 copy_uint8PORT, uint8 copy_uint8PIN, uint8 copy_uint8Value)
{
	//
	switch (copy_uint8PORT)
	{
	case GPIOA:
		if (copy_uint8Value == GPIO_HIGH)
		{
			SET_BIT(GPIOA_ODR, copy_uint8PIN);
		}
		else if (copy_uint8Value == GPIO_LOW)
		{
			CLR_BIT(GPIOA_ODR, copy_uint8PIN);
		}
		else
		{
			//#error("INVALID Value");
		}
		break;
	case GPIOB:
		if (copy_uint8Value == GPIO_HIGH)
		{
			SET_BIT(GPIOB_ODR, copy_uint8PIN);
		}
		else if (copy_uint8Value == GPIO_LOW)
		{
			CLR_BIT(GPIOB_ODR, copy_uint8PIN);
		}
		else
		{
			//#error("INVALID Value");
		}
		break;
	case GPIOC:
		if (copy_uint8Value == GPIO_HIGH)
		{
			SET_BIT(GPIOC_ODR, copy_uint8PIN);
		}
		else if (copy_uint8Value == GPIO_LOW)
		{
			CLR_BIT(GPIOC_ODR, copy_uint8PIN);
		}
		else
		{
			//#error("INVALID Value")
		}
		break;
	default:
		break;
	}
	//
}

void MGPIO_voidSetPORTValue(uint8 copy_uint8PORT, uint16 copy_uint16Value)
{
	switch(copy_uint8PORT)
	{
	case GPIOA:
	{
		GPIOA_ODR = copy_uint16Value;
	}break;
	case GPIOB:
	{
		GPIOB_ODR = copy_uint16Value;
	}break;
	case GPIOC:
	{
		GPIOC_ODR = copy_uint16Value;
	}break;
	default:
	{
		// INVALID PORT
	}break;


	}

}

uint8 MGPIO_uint8GetPinValue(uint8 copy_uint8PORT, uint8 copy_uint8PIN)
{
	//
	uint8 LOC_uint8Result = 0;
	switch (copy_uint8PORT)
	{
	case GPIOA:
		LOC_uint8Result = GET_BIT(GPIOA_IDR, copy_uint8PIN);
		break;
	case GPIOB:
		LOC_uint8Result = GET_BIT(GPIOB_IDR, copy_uint8PIN);
		break;
	case GPIOC:
		LOC_uint8Result = GET_BIT(GPIOC_IDR, copy_uint8PIN);
		break;
	default:
		break;
	}
	return LOC_uint8Result;
	//
}

void MGPIO_voidTogglePinValue(uint8 copy_uint8PORT, uint8 copy_uint8PIN)
{
	switch(copy_uint8PORT)
	{
	case GPIOA:
	{
		TOG_BIT(GPIOA_ODR,copy_uint8PIN);
	}break;
	case GPIOB:
	{
		TOG_BIT(GPIOB_ODR,copy_uint8PIN);
	}break;
	case GPIOC:
	{
		TOG_BIT(GPIOC_ODR,copy_uint8PIN);
	}break;
	default:
	{
		//error
	}break;
	}

}
