/*
 * main.c
 *
 *  Created on: Apr 21, 2021
 *      Author: Khaled
 */

#include "STD_TYPES.h"
#include  "BIT_MATH.h"
#include "I2C_Interface.h"
#include "DIO_interface.h"

void main(void)
{
	DIO_VidSetPortDirection(PORTB, OUTPUT);
	TWI_VoidSlaveInit(0b11010000);
	TWI_VoidI2cListen();
	u8 i = 0;
	i= TWI_VoidMaster_Reading_Byte_From_Slave(1);
	DIO_VidSetPortValue(PORTB,i);

	while(1);
}
