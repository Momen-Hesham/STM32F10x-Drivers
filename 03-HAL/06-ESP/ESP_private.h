/**************************************/
/* Author  : Mo'men Hesham            */
/* Version : V01                      */
/**************************************/

#ifndef ESP_PRIVATE_H
#define ESP_PRIVATE_H


static uint8 voidEspValidateCmd(uint8 Wifi_Connection)
{
    uint8 Local_uint8Response[100]={0};
    uint8 Dummy=0;
    uint8 i=0;
    uint8 Result =0;
    while(Dummy != 255 && i<100)
    {
    	if(Wifi_Connection)
    		Dummy=MUSART1_uint8Receive_Polling(700000); /* In case of WIFI Connection Command which take longer time */
    	else
            Dummy=MUSART1_uint8Receive_Polling(50000); /* at other Commands */

        Local_uint8Response[i]=Dummy;

        i++;
    }

    /* Check 'OK' Message after all Transmission */
    if(Local_uint8Response[i-2]=='\n' && Local_uint8Response[i-3]=='\r' && Local_uint8Response[i-4]=='K'&&Local_uint8Response[i-5]=='O')
    {
        Result=1;
    }
    /* Check 'OK' Message before transmit URL to ESP */
    else if(Local_uint8Response[i-4]=='\n' && Local_uint8Response[i-5]=='\r' && Local_uint8Response[i-6]=='K'&&Local_uint8Response[i-7]=='O')
    {
        Result=1;
    }

    return Result;
}

#endif
