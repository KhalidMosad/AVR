#include "I2C.h"

void Initialize_I2C(void)
{
	 //INITIALIZE I2C
	 //SCL FREQ = F_CPU / ( 16 + 2*BIT_RATE * 4^PRE_SCALER)
	 BIT_RATE = 0X02;
	 STATUS_REG = 0X00;	//PRE SCALER
	 CONTROL_REG = ( 1 << I2C_EN);	//ENABLE I2C
}

void Start_I2C(void)
{
	//START CONDITION
	CONTROL_REG = ((1<<I2C_INT_F) | (1<<I2C_START) | (1<<I2C_EN));
	//WAIT FOR INTERRUPT FLAG IN I2C CONTROL REGISTER
	while((CONTROL_REG & ( 1 << I2C_INT_F))==0);
}

void Stop_I2C(void)
{
	//STOP CONDITION
	CONTROL_REG = ((1<<I2C_STOP) | (1<<I2C_INT_F) | (1<<I2C_EN));
}

void Write_I2C(u8 data)
{
	//PUT DATA IN I2C DATA REGISTER
	DATA_REG = data;
	//WRITE CONDITION
	CONTROL_REG = ((1<<I2C_INT_F) | (1<<I2C_EN));
	//WAIT FOR DATA TO BE SENT
	while((CONTROL_REG & ( 1 << I2C_INT_F))==0);
}

u8 ReadACK(void)
{
	//ENABLE ACKNOWLEDGE BIT
	CONTROL_REG = ((1<<I2C_ACK) | (1<<I2C_INT_F) | (1<<I2C_EN));
	//WAIT FOR INTERRUPT FLAG IN I2C CONTROL REGISTER
	while(!(CONTROL_REG & ( 1 << I2C_INT_F)));
	//RETURN ACKNOWLEDGEMENT
	return DATA_REG;
}

u8 ReadNACK(void)
{
	CONTROL_REG = ((1<<I2C_INT_F) | (1<<I2C_EN));
	//WAIT FOR INTERRUPT FLAG IN I2C CONTROL REGISTER
	while((CONTROL_REG & ( 1 << I2C_INT_F)) == 0);
	//RETURN  N ACKNOWLEDGEMENT
	return DATA_REG;
}

u8 Get_Status(void)
{
	return STATUS_REG;	//RETURN STATUS OF I2C
}
