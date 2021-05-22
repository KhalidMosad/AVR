/*

 * main.c
 *
 *  Created on: Jan 21, 2021
 *      Author: Khaled
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"

void main(void)
{
	DIO_VidSetPinDirection(PORTA,PIN0,OUTPUT);
	DIO_VidSetPinDirection(PORTB,PIN2,INPUT);
	DIO_VidSetPinValue(PORTB,PIN2,HIGH);  // active high 1
	EXIT_voidInit();
	EXTI_voidEnable();
	GIE_voidEnable();

	while(1)
	{


	}



}

