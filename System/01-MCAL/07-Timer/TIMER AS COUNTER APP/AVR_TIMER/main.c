/*

 * main.c
 *
 *  Created on: Apr 16, 2021
 *      Author: Khaled
 */
#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"DIO_interface.h"
#include"TIMER_interface.h"
#include<avr/delay.h>

void main(void)
{
	DIO_VidSetPinDirection(PORTA,PIN0,OUTPUT);
	DIO_VidSetPinDirection(PORTA,PIN5,OUTPUT);
	DIO_VidSetPinDirection(PORTB,PIN0,INPUT);
	DIO_VidSetPinDirection(PORTC,PIN3,OUTPUT);


	TM_voidTimerInit();
	TM_VoidPrealoadOverFlow();


	while(1)
	{
		DIO_VidSetPinValue(PORTC,PIN3,HIGH);
		_delay_ms(100);
		DIO_VidSetPinValue(PORTC,PIN3,LOW);
		_delay_ms(100);

	}


}


