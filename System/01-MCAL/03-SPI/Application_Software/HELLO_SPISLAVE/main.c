/*

 * main.c
 *
 *  Created on: Jan 21, 2021
 *      Author: Khaled
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "util/delay.h"
void main(void)
{
	LCD_VidInit();
	SPI_VoidInit();
u8 y;


while(1)
{

y=SPI_u8Receive();
LCD_VidSendData(y);
_delay_ms(1000);


}


}

