/*
 * DHT11_program.c

 *
 *  Created on: May 2, 2021
 *      Author: Khaled
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_Interface.h"
#include "DHT11_interface.h"
#include <avr/delay.h>

void DHT11_VoidInit(u8 Cope_u8Port,u8 Cope_u8Pin )
{
	DIO_VidSetPinDirection(Cope_u8Port,Cope_u8Pin, OUTPUT);
	DIO_VidSetPinValue(Cope_u8Port,Cope_u8Pin, LOW);
	_delay_ms(20);
	DIO_VidSetPinValue(Cope_u8Port,Cope_u8Pin, HIGH);
}

void DHT11_VoidResponse(u8 Cope_u8Port,u8 Cope_u8Pin )
{
	DIO_VidSetPinDirection(Cope_u8Port,Cope_u8Pin, INPUT);
	while(DIO_VidGetPinValue(Cope_u8Port,Cope_u8Pin)==1);
	while(DIO_VidGetPinValue(Cope_u8Port,Cope_u8Pin)==0);
	while(DIO_VidGetPinValue(Cope_u8Port,Cope_u8Pin)==1);


}
u8 DHT11_U8Receive(u8 Cope_u8Port,u8 Cope_u8Pin)
{

	u8 Received;
	for(u8 q=0; q<=7; q++)
	{
		while(DIO_VidGetPinValue(Cope_u8Port,Cope_u8Pin)==0);
		_delay_us(30);
		if(DIO_VidGetPinValue(Cope_u8Port,Cope_u8Pin)==1)
			Received = Received<<1 |0x01;
		else
			Received = Received<<1;
		while(DIO_VidGetPinValue(Cope_u8Port,Cope_u8Pin)==1);
	}
	return Received;
}


