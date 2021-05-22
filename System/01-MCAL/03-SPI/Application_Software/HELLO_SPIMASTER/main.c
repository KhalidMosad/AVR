/*

 * main.c
 *
 *  Created on: Jan 21, 2021
 *      Author: Khaled
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "util/delay.h"
void main(void)
{
	SPI_VoidInit();
	_delay_ms(100);
	SPI_u8Send('A');
	_delay_ms(1000);
	SPI_u8Send('B');
	_delay_ms(1000);
	SPI_u8Send('D');
	_delay_ms(1000);
	SPI_u8Send('E');
	_delay_ms(1000);
	SPI_u8Send('5');
	_delay_ms(1000);
	while(1)
	{






	}


}

