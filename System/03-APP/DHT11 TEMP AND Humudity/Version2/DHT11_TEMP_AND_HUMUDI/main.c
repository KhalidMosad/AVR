/*

 * main.c
 *
 *  Created on: Apr 20, 2021
 *      Author: Khaled
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_Interface.h"
#include <stdlib.h>
#include <stdio.h>
#include "DHT11_interface.h"
#include <util/delay.h>

 u32 c=0,I_RH,D_RH,I_Temp,D_Temp,CheckSum;
void main()
{
	char data[5];
		LCD_VidInit();			/* Initialize LCD */
		LCD_VidClear();			/* Clear LCD */
		LCD_VidSetPosition(0,0);		/* Enter column and row position */
		LCD_VidSendString("Humidity =");
		LCD_VidSetPosition(1,0);
		LCD_VidSendString("Temp = ");


	while(1)
	{
		DHT11_VoidInit(PORTD,PIN6);

		DHT11_VoidResponse(PORTD,PIN6);


		I_RH=DHT11_U8Receive(PORTD,PIN6);	/* store first eight bit in I_RH */
		D_RH=DHT11_U8Receive(PORTD,PIN6);	/* store next eight bit in D_RH */
		I_Temp=DHT11_U8Receive(PORTD,PIN6);	/* store next eight bit in I_Temp */
		D_Temp=DHT11_U8Receive(PORTD,PIN6);	/* store next eight bit in D_Temp */
		CheckSum=DHT11_U8Receive(PORTD,PIN6);/* store next eight bit in CheckSum */
		if ((I_RH + D_RH + I_Temp + D_Temp) != CheckSum)
		{
			LCD_VidSetPosition(0,0);
			LCD_VidSendString("Error");
		}

		else
		{
			itoa(I_RH,data,10);
			LCD_VidSetPosition(0,11);
			LCD_VidSendString(data);
			LCD_VidSendString(".");

			itoa(D_RH,data,10);
			LCD_VidSendString(data);
			LCD_VidSendString("%");


			itoa(I_Temp,data,10);
			LCD_VidSetPosition(1,6);
			LCD_VidSendString(data);
			LCD_VidSendString(".");

			itoa(D_Temp,data,10);
			LCD_VidSendString(data);
			LCD_VidSendData(0xDF);
			LCD_VidSendString("C");

			itoa(CheckSum,data,10);
			LCD_VidSendString(data);
			LCD_VidSendString(" ");
		}

	_delay_ms(10);



	}

}


