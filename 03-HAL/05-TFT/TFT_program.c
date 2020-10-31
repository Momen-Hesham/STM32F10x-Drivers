/*****************************/
/* Author  : Mo'men          */
/* Version : V01             */
/*****************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"


static void voidWriteCommand(uint8 Copy_uint8Command)
{
	uint8 Local_uint8Temp;
	// Set TFT A0 Pin to Low
	MGPIO_voidSetPinValue(TFT_A0_PIN,GPIO_LOW);

	// Send Command via SPI
	MSPI1_voidSendReceiveSynch(Copy_uint8Command,&Local_uint8Temp);
}

static void voidWriteData(uint8 Copy_uint8Data)
{
	uint8 Local_uint8Temp;

	// Set TFT A0 Pin to HIGH
	MGPIO_voidSetPinValue(TFT_A0_PIN,GPIO_HIGH);

	// Send Data via SPI
	MSPI1_voidSendReceiveSynch(Copy_uint8Data,&Local_uint8Temp);
}
void HTFT_voidInit(void)
{
	/************ Reset Pulse *****************/
	MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_HIGH);	
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_LOW);	
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_HIGH);	
	MSTK_voidSetBusyWait(100);	
	MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_LOW);	
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_HIGH);	
	MSTK_voidSetBusyWait(120000);	

	/*********** Sleep Out Command ************/
	voidWriteCommand(0x11);
	
	/*********** Wait 150 ms ******************/
	MSTK_voidSetBusyWait(150000);
	
	/*********** Color Mode Command ***********/
	voidWriteCommand(0x3A);
	voidWriteData(0x05);

	/************ Display On Command **********/
	voidWriteCommand(0x29);
}

void HTFT_voidDisplayImage(const uint16* Copy_Image)
{
	uint16 counter;
	/**** Set x Address ****/
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);

	/**** Set y Address ****/
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);
	
	/**** RAM Write *******/

	voidWriteCommand(0x2C);
	
	/* voidWriteData(0x0000); Display color to first bit*/
	/* voidWriteData(0x0A23); Display color to second bit*/

	/* 20480 = Number of pixels=160*128*/
	for(counter =0; counter <20480;counter++)
	{
		voidWriteData(Copy_Image[counter]>>8);/* Write the high byte*/
		voidWriteData(Copy_Image[counter]&0x00ff);/* Write the low byte*/

	}
}

void HTFT_voidFillColor(uint16 Copy_uint16Color)
{
	uint16 counter;
	/**** Set x Address ****/
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);

	/**** Set y Address ****/
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);
	
	/**** RAM Write *******/

	voidWriteCommand(0x2C);
	
	/* voidWriteData(0x0000); Display color to first bit*/
	/* voidWriteData(0x0A23); Display color to second bit*/

	/* 20480 = Number of pixels=160*128*/
	for(counter =0; counter <20480;counter++)
	{
		voidWriteData(Copy_uint16Color>>8);/* Write the high byte*/
		voidWriteData(Copy_uint16Color&0x00ff);/* Write the low byte*/

	}
}

void HTFT_DrawRect(uint8 x1,uint8 x2,uint8 y1,uint8 y2,uint16 Copy_uint16Color)
{
	uint16 counter;
	uint16 size = (x2-x1)*(y2-y1);
	/**** Set x Address ****/
	voidWriteCommand(0x2A);
	voidWriteData(0);// Low byte of start x axis
	voidWriteData(x1);// High byte of start x axis
	voidWriteData(0);// Low byte of end x axis
	voidWriteData(x2);// High byte of end x axis;

	/**** Set y Address ****/
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(y1);
	voidWriteData(0);
	voidWriteData(y2);
	
	/**** RAM Write *******/

	voidWriteCommand(0x2C);
	
	/* voidWriteData(0x0000); Display color to first bit*/
	/* voidWriteData(0x0A23); Display color to second bit*/

	/* 20480 = Number of pixels=160*128*/
	for(counter =0; counter <size;counter++)
	{
		voidWriteData(Copy_uint16Color>>8);/* Write the high byte*/
		voidWriteData(Copy_uint16Color&0x00ff);/* Write the low byte*/

	}
}