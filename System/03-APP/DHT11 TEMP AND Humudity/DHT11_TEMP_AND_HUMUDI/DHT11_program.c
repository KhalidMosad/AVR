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
#include "DHT11_config.h"
#include <avr/delay.h>

void DHT11_VoidInit(void )
{
	DIO_VidSetPinDirection(SENSOR_PORT,SENSOR_PIN, OUTPUT);
	DIO_VidSetPinValue(SENSOR_PORT,SENSOR_PIN, LOW);
	_delay_ms(20);
	DIO_VidSetPinValue(SENSOR_PORT,SENSOR_PIN, HIGH);
}

void DHT11_VoidResponse()
{
	DIO_VidSetPinDirection(SENSOR_PORT,SENSOR_PIN, INPUT);
	while(DIO_VidGetPinValue(SENSOR_PORT,SENSOR_PIN)==1);
	while(DIO_VidGetPinValue(SENSOR_PORT,SENSOR_PIN)==0);
	while(DIO_VidGetPinValue(SENSOR_PORT,SENSOR_PIN)==1);

}
u8 DHT11_U8Receive()
{

	u8 Received;
	for(u8 q=0; q<8; q++)
	{
		while(DIO_VidGetPinValue(SENSOR_PORT,SENSOR_PIN)==0);
		_delay_us(30);
		if(DIO_VidGetPinValue(SENSOR_PORT,SENSOR_PIN)==1)
			Received = Received<<1 |0x01;
		else
			Received = Received<<1;
		while(DIO_VidGetPinValue(SENSOR_PORT,SENSOR_PIN)==1);
	}
	return Received;
}


