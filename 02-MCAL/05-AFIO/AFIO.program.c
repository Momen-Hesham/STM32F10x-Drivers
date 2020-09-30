#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_config.h"
#include "AFIO_private.h"

void MAFIO_voidSetEXTIConfiguration(uint8 copy_uint8Line, uint8 copy_uint8PortMap)
{
	uint8 Local_uint8RegIndex = 0;
	if(copy_uint8Line <=3)
	{
		Local_uint8RegIndex =0;
	}
	else if (copy_uint8Line <=7)
	{
		Local_uint8RegIndex =1;
		copy_uint8Line -=4;
	}
	else if (copy_uint8Line <=11)
	{
		Local_uint8RegIndex =2;
		copy_uint8Line -=8;
	}
	else if (copy_uint8Line <=15)
	{
		Local_uint8RegIndex =3;
		copy_uint8Line -=12;
	}
	else 
	{
		
		//error
	}
	
		AFIO ->EXTICR[Local_uint8RegIndex] &= ((0b1111) << (copy_uint8Line *4)); // b3ml reset aw basfr el 4 bits 2abl ma akteb fehom 7aga
		AFIO ->EXTICR[Local_uint8RegIndex] |= ((copy_uint8PortMap) << (copy_uint8Line *4));
	
}
