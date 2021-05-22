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
	TWI_VoidMasterInit();
	TWI_VoidStartCondition();
	TWI_VoidMaster_Send_Slave_Address_With_Write(0b1101000,0);
	TWI_VoidMaster_Write_Byte_To_Slave(0b11111100);
	TWI_VoidStopCondition();
	while(1);
}
