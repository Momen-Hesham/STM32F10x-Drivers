/**********************************/
/* Author  :	Mo'men Hesham	  */
/* Version :	V1				  */
/**********************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "LEDMATRIX_private.h"
#include "LEDMATRIX_interface.h"
#include "LEDMATRIX_config.h"

uint8 Animation[8]={0};
void HLEDMRX_voidInit(void)
{
	MGPIO_voidSetPinDirection(LED_MATRIX_ROW0_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LED_MATRIX_ROW1_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LED_MATRIX_ROW2_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LED_MATRIX_ROW3_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LED_MATRIX_ROW4_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LED_MATRIX_ROW5_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LED_MATRIX_ROW6_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LED_MATRIX_ROW7_PIN,OUTPUT_SPEED_2MHZ_PP);

	MGPIO_voidSetPinDirection(LED_MATRIX_COL0_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LED_MATRIX_COL1_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LED_MATRIX_COL2_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LED_MATRIX_COL3_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LED_MATRIX_COL4_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LED_MATRIX_COL5_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LED_MATRIX_COL6_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LED_MATRIX_COL7_PIN,OUTPUT_SPEED_2MHZ_PP);


}

static void InsetElement(uint8 Data)
{
	uint8 i;
	for(i=0;i<7;i++)
	{
		Animation[i]=Animation[i+1];
	}
	Animation[7]=Data;
}
static void DisableAllCols(void)
{
	MGPIO_voidSet_PinValue(LED_MATRIX_COL0_PIN,GPIO_HIGH);
	MGPIO_voidSet_PinValue(LED_MATRIX_COL1_PIN,GPIO_HIGH);
	MGPIO_voidSet_PinValue(LED_MATRIX_COL2_PIN,GPIO_HIGH);
	MGPIO_voidSet_PinValue(LED_MATRIX_COL3_PIN,GPIO_HIGH);
	MGPIO_voidSet_PinValue(LED_MATRIX_COL4_PIN,GPIO_HIGH);
	MGPIO_voidSet_PinValue(LED_MATRIX_COL5_PIN,GPIO_HIGH);
	MGPIO_voidSet_PinValue(LED_MATRIX_COL6_PIN,GPIO_HIGH);
	MGPIO_voidSet_PinValue(LED_MATRIX_COL7_PIN,GPIO_HIGH);
}
void HLEDMRX_voidDisplay(uint8 *Copy_uint8Data)
{
	while(1)
	{
		//Column 0
		DisableAllCols();
		SetRowValues(Copy_uint8Data[0]);
		MGPIO_voidSet_PinValue(LED_MATRIX_COL0_PIN,GPIO_LOW);
		MSTK_voidSetBusyWait(2500);

		//Column 1
		DisableAllCols();
		SetRowValues(Copy_uint8Data[1]);
		MGPIO_voidSet_PinValue(LED_MATRIX_COL1_PIN,GPIO_LOW);
		MSTK_voidSetBusyWait(2500);

		//Column 2
		DisableAllCols();
		SetRowValues(Copy_uint8Data[2]);
		MGPIO_voidSet_PinValue(LED_MATRIX_COL2_PIN,GPIO_LOW);
		MSTK_voidSetBusyWait(2500);

		//Column 3
		DisableAllCols();
		SetRowValues(Copy_uint8Data[3]);
		MGPIO_voidSet_PinValue(LED_MATRIX_COL3_PIN,GPIO_LOW);
		MSTK_voidSetBusyWait(2500);

		//Column 4
		DisableAllCols();
		SetRowValues(Copy_uint8Data[4]);
		MGPIO_voidSet_PinValue(LED_MATRIX_COL4_PIN,GPIO_LOW);
		MSTK_voidSetBusyWait(2500);

		//Column 5
		DisableAllCols();
		SetRowValues(Copy_uint8Data[5]);
		MGPIO_voidSet_PinValue(LED_MATRIX_COL5_PIN,GPIO_LOW);
		MSTK_voidSetBusyWait(2500);

		//Column 6
		DisableAllCols();
		SetRowValues(Copy_uint8Data[6]);
		MGPIO_voidSet_PinValue(LED_MATRIX_COL6_PIN,GPIO_LOW);
		MSTK_voidSetBusyWait(2500);

		//Column 7
		DisableAllCols();
		SetRowValues(Copy_uint8Data[7]);
		MGPIO_voidSet_PinValue(LED_MATRIX_COL7_PIN,GPIO_LOW);
		MSTK_voidSetBusyWait(2500);
	}
}

void HLEDMRX_voidDisplayAnimation(uint8 *Copy_uint8Data,uint8 size)
{
	uint8 i=0,j=0;
	while(1)
	{
		InsetElement(Copy_uint8Data[(i%size)]);

		for(j=0;j<255;j++)
		{
			DisableAllCols();
			SetRowValues(Animation[7-(j%8)]);
			if((j%8)==0)
			{MGPIO_voidSet_PinValue(LED_MATRIX_COL7_PIN,GPIO_LOW);}
			else if ((j%8)==1)
			{MGPIO_voidSet_PinValue(LED_MATRIX_COL6_PIN,GPIO_LOW);}
			else if ((j%8)==2)
			{MGPIO_voidSet_PinValue(LED_MATRIX_COL5_PIN,GPIO_LOW);}
			else if ((j%8)==3)
			{MGPIO_voidSet_PinValue(LED_MATRIX_COL4_PIN,GPIO_LOW);}
			else if ((j%8)==4)
			{MGPIO_voidSet_PinValue(LED_MATRIX_COL3_PIN,GPIO_LOW);}
			else if ((j%8)==5)
			{MGPIO_voidSet_PinValue(LED_MATRIX_COL2_PIN,GPIO_LOW);}
			else if ((j%8)==6)
			{MGPIO_voidSet_PinValue(LED_MATRIX_COL1_PIN,GPIO_LOW);}
			else
			{MGPIO_voidSet_PinValue(LED_MATRIX_COL0_PIN,GPIO_LOW);}
			MSTK_voidSetBusyWait(2500);
		}
		i++;
	}
}

static void SetRowValues(uint8 Copy_uint8Value)
{
	uint8 Local_uint8BIT;
	Local_uint8BIT = GET_BIT(Copy_uint8Value,0);
	MGPIO_voidSet_PinValue(LED_MATRIX_ROW0_PIN,Local_uint8BIT);
	Local_uint8BIT = GET_BIT(Copy_uint8Value,1);
	MGPIO_voidSet_PinValue(LED_MATRIX_ROW1_PIN,Local_uint8BIT);
	Local_uint8BIT = GET_BIT(Copy_uint8Value,2);
	MGPIO_voidSet_PinValue(LED_MATRIX_ROW2_PIN,Local_uint8BIT);
	Local_uint8BIT = GET_BIT(Copy_uint8Value,3);
	MGPIO_voidSet_PinValue(LED_MATRIX_ROW3_PIN,Local_uint8BIT);
	Local_uint8BIT = GET_BIT(Copy_uint8Value,4);
	MGPIO_voidSet_PinValue(LED_MATRIX_ROW4_PIN,Local_uint8BIT);
	Local_uint8BIT = GET_BIT(Copy_uint8Value,5);
	MGPIO_voidSet_PinValue(LED_MATRIX_ROW5_PIN,Local_uint8BIT);
	Local_uint8BIT = GET_BIT(Copy_uint8Value,6);
	MGPIO_voidSet_PinValue(LED_MATRIX_ROW6_PIN,Local_uint8BIT);
	Local_uint8BIT = GET_BIT(Copy_uint8Value,7);
	MGPIO_voidSet_PinValue(LED_MATRIX_ROW4_PIN,Local_uint8BIT);



}
