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
	DIO_VidSetPinDirection(PORTB,PIN3,OUTPUT);
	TM_voidTimerInit();


	while(1)
	{
		TM_VoidSetDuty(30);
		_delay_ms(1000);
		TM_VoidSetDuty(60);
		_delay_ms(1000);
		TM_VoidSetDuty(90);
		_delay_ms(1000);
		TM_VoidSetDuty(120);
		_delay_ms(1000);
		TM_VoidSetDuty(160);
		_delay_ms(1000);
		TM_VoidSetDuty(200);
		_delay_ms(1000);
		TM_VoidSetDuty(220);
		_delay_ms(1000);
		TM_VoidSetDuty(255);
		_delay_ms(1000);

	}


}


