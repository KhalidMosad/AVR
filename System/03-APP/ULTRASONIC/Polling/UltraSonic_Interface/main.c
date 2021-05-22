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

extern u8 ov;

void main(void)
{
	long count;
	double distance;
	char string[10];
	DIO_VidSetPinDirection(PORTA,PIN0,OUTPUT);
	DIO_VidSetPinDirection(PORTA,PIN1,OUTPUT);
	TM_voidTimerInit();
	//TM1_VoidInputCapture();
	LCD_VidInit();
	while(1)
	{
//		DIO_VidSetPinValue(0,5,1);
//		if(3==flag)
//		{

			// Trigger Signal
			DIO_VidSetPinValue(PORTA,PIN0,LOW);
			_delay_us(5);
			DIO_VidSetPinValue(PORTA,PIN0,HIGH);
			_delay_us(10);
			DIO_VidSetPinValue(PORTA,PIN0,LOW);


			TCNT1 = 0;	/* Clear Timer counter */
			TCCR1 = 0x41;	/* Capture on rising edge, No prescaler*/
			TIFR = 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */
			TIFR = 1<<TOV1;	/* Clear Timer Overflow flag */

			/*Calculate width of Echo by Input Capture (ICP) */

			while ((TIFR & (1 << ICF1)) == 0);/* Wait for rising edge */
			TCNT1 = 0;	/* Clear Timer counter */
			TCCR1 = 0x01;	/* Capture on falling edge, No prescaler */
			TIFR = 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */
			TIFR = 1<<TOV1;	/* Clear Timer Overflow flag */
			ov = 0;/* Clear Timer overflow count */

			while ((TIFR & (1 << ICF1)) == 0);/* Wait for falling edge */
			count = ICR1 + (65535 * ov);	/* Take count */
			/* 8MHz Timer freq, sound speed =343 m/s */
			distance = (double)count / 466.47;
			LCD_VidClear();
			LCD_VidSetPosition(0,0);
			LCD_VidSendString("Ultrasonic");
			LCD_VidSetPosition(1,0);
			LCD_VidSendString("Distance= ");
			LCD_VidSendNumber(distance);

			_delay_ms(200);


		}

	}






