/*
 * main.c

 *
 *  Created on: Dec 22, 2020
 *      Author: Khaled
 */

#include "STD_Types.h"
#include "BIT_Math.h"
#include "USART_interface.h"

void main(void)
{

LCD_VidInit();
LCD_VidClearDisplay();
USART_voidINIT();
u8 data;

while(1)
{

	data= USART_u8Receive();
	LCD_VidSendData(data);
	USART_voidtransmit(data);

 // if 2 mc the 1st mc will receive data and 2nd send data

}


}



