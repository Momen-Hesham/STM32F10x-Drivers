/**************************************/
/* Author  : Mo'men Hesham            */
/* Version : V01                      */
/**************************************/
#include "stdio.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"

#include "ESP_private.h"
#include "ESP_config.h"
#include "ESP_interface.h"

void ESP_voidInit(void)
{
    uint8 Local_uint8Result =0;
    
    /* Reset ESP */
    MUSART1_voidTransmit("AT+RST\r\n");

    while (Local_uint8Result != 1)
    {
        /* Stop Echo */
        MUSART1_voidTransmit("ATE0\r\n");
        Local_uint8Result=voidEspValidateCmd(0);
    }

    Local_uint8Result =0;

    while (Local_uint8Result != 1)
    {
        /* Transmit the Normal Mode */
       MUSART1_voidTransmit("AT+CWMODE=1\r\n");
        Local_uint8Result=voidEspValidateCmd(0);
    }

}

void ESP_voidConnect(uint8 *WIFI_name,uint8 *WIFI_Password)
{
	uint8 local_uint8Return=0;

    while (local_uint8Return != 1)
    {
      /* Connect to WIFI and got an IP */
       MUSART1_voidTransmit("AT+CWJAP_CUR=\"");
       MUSART1_voidTransmit(WIFI_name);
       MUSART1_voidTransmit("\",\"");
       MUSART1_voidTransmit(WIFI_Password);
       MUSART1_voidTransmit("\"\r\n");
       local_uint8Return=voidEspValidateCmd(1);
    }



}


uint8 ESP_uint8GetStatus(uint8 *Length,uint8 *URL,uint8 *IP,uint8 *PORT)
{
	uint8 Local_uint8TempStatus[50]={0};
	uint8 local_uint8Return=0;
    uint8 Dummy=0;
    uint8 Status ='2';
    uint8 i=0,j;


    while (local_uint8Return != 1)
    {
        /* Transmit IP & PORT Numbers */
        MUSART1_voidTransmit("AT+CIPSTART=\"TCP\",\"");
        MUSART1_voidTransmit(IP);
        MUSART1_voidTransmit("\",");
        MUSART1_voidTransmit(PORT);
        MUSART1_voidTransmit("\r\n");
        local_uint8Return=voidEspValidateCmd(0);
    }
    local_uint8Return=0;

    while (local_uint8Return != 1)
    {
       /* Transmit the Length of URL+6 */
        MUSART1_voidTransmit("AT+CIPSEND=");
        MUSART1_voidTransmit(Length);
        MUSART1_voidTransmit("\r\n");
        local_uint8Return=voidEspValidateCmd(0);
    }

    /* Transmit the given URL */
    MUSART1_voidTransmit("GET ");
    MUSART1_voidTransmit(URL);
    MUSART1_voidTransmit("\r\n");

    /*Storing data came by ESP */
    while(Dummy != 255)
    {

        Dummy=MUSART1_uint8Receive_Polling(600000);
        Local_uint8TempStatus[i]=Dummy;
        i++;
    }
    /* Get the status from the received data*/
    for(j=0;j<i;j++)
    {
    	if(Local_uint8TempStatus[j]==':')
    	{
    		Status=Local_uint8TempStatus[j+1];
    		break;
    	}
    }
	return Status;
}
