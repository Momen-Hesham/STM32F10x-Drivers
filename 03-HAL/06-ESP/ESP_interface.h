/**************************************/
/* Author  : Mo'men Hesham            */
/* Version : V01                      */
/**************************************/

#ifndef ESP_INTERFACE_H
#define ESP_INTERFACE_H

void ESP_voidInit(void);
void ESP_voidConnect(uint8 *WIFI_name,uint8 *WIFI_Password);
uint8 ESP_uint8GetStatus(uint8 *Length,uint8 *URL,uint8 *IP,uint8 *PORT);

#endif
