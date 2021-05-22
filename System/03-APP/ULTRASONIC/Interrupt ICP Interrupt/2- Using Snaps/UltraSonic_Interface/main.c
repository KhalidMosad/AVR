/*

 * main.c
 *
 *  Created on: Apr 16, 2021
 *      Author: Khaled
 */
#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"LCD_interface.h"
#include"DIO_interface.h"
#include"TIMER_interface.h"
#include <avr/delay.h>
#include "Timer_private.h"

extern u16 ov;
extern u8 flag;
extern 	double distance;
void main(void)
{
	long count;

	char string[10];
	DIO_VidSetPinDirection(PORTA,PIN0,OUTPUT);
	DIO_VidSetPinDirection(PORTA,PIN1,OUTPUT);
	TM_voidTimerInit();
	TM1_VoidInputCapture();
	LCD_VidInit();
	while(1)
	{
		DIO_VidSetPinValue(0,5,1);
		// Trigger Signal
		DIO_VidSetPinValue(PORTA,PIN0,LOW);
		_delay_us(5);
		DIO_VidSetPinValue(PORTA,PIN0,HIGH);
		_delay_us(10);
		DIO_VidSetPinValue(PORTA,PIN0,LOW);

		if(3==flag)
		{
			LCD_VidClear();
			LCD_VidSetPosition(0,0);
			LCD_VidSendString("Ultrasonic");
			LCD_VidSetPosition(1,0);
			LCD_VidSendString("Distance= ");
			LCD_VidSendNumber(distance);

			_delay_ms(200);
			flag = 0;


		}
	}

	}






