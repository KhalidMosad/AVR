/*

 * main.c
 *
 *  Created on: Apr 20, 2021
 *      Author: Khaled
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include <stdio.h>
#include <util/delay.h>

void main()
{
	/*Pyroelectricity can be described as
	 * the ability of certain materials to
	 * generate a temporary voltage
	 * when they are heated or cooled.
	 * */
	DIO_VidSetPinDirection(PORTA,PIN0,INPUT);
	DIO_VidSetPinDirection(PORTC,PIN0,OUTPUT);

	while(1)
	{
			DIO_VidSetPinValue(PORTC,PIN0,DIO_VidGetPinValue(PORTA,PIN0));
	}

}


