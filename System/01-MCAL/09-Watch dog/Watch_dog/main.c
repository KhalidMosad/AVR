/*

 * main.c
 *
 *  Created on: Dec 21, 2020
 *      Author: Khaled
 */

#include <avr/io.h>
#include <util/delay.h>
#include "WDT_interface.h"

void main()
{
	DDRA|=0b00000001;

	WDT_Enable();
	PORTA|=1;
	_delay_ms(500);
	PORTA&=0;
	//_delay_ms(500);
	//WDT_Disable();
	while(1)
	{



	}
}
