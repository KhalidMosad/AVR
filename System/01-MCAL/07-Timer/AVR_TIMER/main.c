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

void main(void)
{
	DIO_VidSetPinDirection(PORTA,PIN0,OUTPUT);
	DIO_VidSetPinDirection(PORTA,PIN5,OUTPUT);
	//DIO_VidSetPinDirection(PORTB,PIN3,OUTPUT);
	TM_voidTimerInit();
	TM_VoidPrealoadOverFlow();


	while(1)
	{

	}


}


