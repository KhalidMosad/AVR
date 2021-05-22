#include "I2C.h"
#include "EEPROM.h"

/*Initialize EEPROM*/
void Initialize_EEPROM(void)
{
	Initialize_I2C();
}

/*The Slave Address of Chip is 0b1010(0xA), so have Three bits free
 We can take a part from 11 bit address and send it with Device Add
 Send 3 MSBs From Address "As Device Address"*/
u8 SendAddress_EEPROM(u32 address, u8 state)
{
	u8 msb_add = 0;
	
	switch (state)	// Send Slave Address -> For EEPROM 24cXX
	{
	case I2C_FIRST_START:	// Set Action To Write -> 0
		
		msb_add = (u8) ((address&ADD_CAST)>>7);	// Cast Address
		Write_I2C(CHIP_ADDRESS|msb_add);// Write the MSB of Location Address & Chip address
		
		state = Get_Status();	// Get Status
		
		if(state != I2C_MT_SLA_ACK)	// Check if it is I2C_MT_SLA_ACK
			return 0;
		
		Write_I2C((u8) address);	// Write the Rest of Location Address(8 Bits)
		
		state = Get_Status();		// Get State
		
		if(state != I2C_MT_DATA_ACK)// check if it is I2C_MT_DATA_ACK
			return 0;
		else
			return 1;
			
		break;
		
	case I2C_SECOND_START:	// Set Action to Read -> 1
	
		msb_add = (u8) ((address&ADD_CAST)>>7);	// Cast Address
		Write_I2C(CHIP_ADDRESS|msb_add|1);// Write the MSB of Location Address & Chip address with Action to Read -> 1
		
		state = Get_Status();	// Get Status
		
		if(state != I2C_MR_SLA_ACK)	// Check if it is I2C_MR_SLA_ACK
			return 0;
		else
			return 1;
			
		break;
	}
	return 0;
}

/*Write Byte to EEPROM*/
u8 WriteByte_EEPROM(u32 address, s8 data)
{
	u8 state = 0;
	u8 address_ack = 0;
	
	Start_I2C();	// Start I2C
	
	state = Get_Status();	// Get State
	
	if(state != I2C_FIRST_START)	// Check if I2C Start is ok
		return 0;
		
	address_ack = SendAddress_EEPROM(address,state);
	
	if(address_ack != 1)	//Send Address then check ack
		return 0;
	
	Write_I2C(data);	// Send Data
	
	state = Get_Status();	// Get Status
	
	if(state != I2C_MT_DATA_ACK)	// Check if it is I2C_MT_DATA_ACK
		return 0;
		
	Stop_I2C();	// I2C Stop
	
	return 1;	// Return Done
}

/*Read Byte from EEPROM*/
u8 ReadByte_EEPROM(u32 address, s8 *data)
{
	u8 state = 0;
	u8 address_ack = 0;
	
	Start_I2C();	// Start I2C
	
	state = Get_Status();	// Get State
	
	if(state != I2C_FIRST_START)	// Check if I2C Start is ok
		return 0;

	address_ack = SendAddress_EEPROM(address,state);
	
	if(address_ack != 1)	//Send Address then check ack
		return 0;
	
	Start_I2C();// Start I2C again, Now The Master Will Be Master Receiver
	
	state = Get_Status();	// Get State
	
	if(state != I2C_SECOND_START)	// Check if I2C_SECOND_START is ok
		return 0;

	address_ack = SendAddress_EEPROM(address,state);
	
	if(address_ack != 1)	//Send Address then check ack
		return 0;
	
	*data =  ReadNACK();	// Read Data
	
	state = Get_Status();	// Get Status
	
	if(state != I2C_MR_DATA_NACK)	// Check if it is I2C_MR_DATA_NACK
		return 0;
	
	Stop_I2C();	// I2C Stop
	
	return 1;	// Return Done
}
