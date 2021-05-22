/*********Author : Khalid Mosaad Zakaria */
/*********Date   :   22/4/2021           */
/*********Version: 1                     */
/****************Desc: *******************/
#include"STD_Types.h"
#include"BIT_Math.h"
#include "I2C_interface.h"
#include "I2C_Config.h"
#include "I2C_private.h"

void TWI_VoidMasterInit(void)
{

	//Set Prescalar Value 0
	#if PRESCALER == ONE 
		CLR_BIT(TWSR,TWPS0);
		CLR_BIT(TWSR,TWPS1);
	#elif PRESCALER == FOUR
		SET_BIT(TWSR,TWPS0);
		CLR_BIT(TWSR,TWPS1);	
	#elif PRESCALER == SIXTEEN
		CLR_BIT(TWSR,TWPS0);
		SET_BIT(TWSR,TWPS1);
	#elif PRESCALER == FOURTY_SIX
		SET_BIT(TWSR,TWPS0);
		SET_BIT(TWSR,TWPS1);	
	#endif	

	#if INTERRUPT_O== ENABLE
		SET_BIT(TWCR, TWIE);
	#elif INTERRUPT_O== DISABLE
		CLR_BIT(TWCR, TWIE);
	#endif

	#if ACK_OP== ENABLE
		SET_BIT(TWCR, TWEA);
	#elif ACK_OP== DISABLE
		CLR_BIT(TWCR, TWEA);
	#endif

	//CLK 400kHZ
	TWBR = Division_Factor;

	//Enable I2C Peripheral
	SET_BIT(TWCR,TWEN);

}

void TWI_VoidSlaveInit(u8 Copy_u8Address)
{
	TWAR = Copy_u8Address<<1;

	//Enable Ack
	SET_BIT(TWCR,TWEA);
	//Enable I2C Peripheral
	SET_BIT(TWCR,TWEN);

}



void  TWI_VoidStartCondition()
{


	//start condition
	//TWCR = (1<<TWINT)|(1<<TWSTA)| (1<<TWEN)
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);   // Clearing TWINT flag by logic one

	// Wait for TWINT Flag set
	while (!(TWCR & (1<<TWINT)));
}

void TWI_VoidRepeatedStartCondition(void)
{
	// Send Repeated Start Condition
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);

	// Wait for TWINT Flag set
	while (!(TWCR & (1<<TWINT)));

}

void TWI_VoidMaster_Send_Slave_Address_With_Write(u8 Address, u8 Copy_Rw)
{

	//Load SLA_W into TWDR Register

	TWDR = (Address<<1);
	if(Copy_Rw == 1)
	{
		SET_BIT(TWDR,R_W);		//Set R\W Bit To Read From Slave
		// Clear TWINT bit in TWCR to start transmission of address
		TWCR=(1<<TWEN)|(1<<TWINT);

		//Wait for TWINT Flag set
		while(!(TWCR&(1<<TWINT)));

	}
	else
	{
		CLR_BIT(TWDR,R_W);
		// Clear TWINT bit in TWCR to start transmission of address
		TWCR=(1<<TWEN)|(1<<TWINT);

		//Wait for TWINT Flag set
		while(!(TWCR&(1<<TWINT)));		
	}
}

u8  TWI_VoidMaster_Reading_Byte_From_Slave(u8 No_ofBytes)
{
	if(No_ofBytes>1)
	{
			TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA); 
	}
	else
	{
			TWCR=(1<<TWEN)|(1<<TWINT); 
	}

	while((TWCR & (1<<TWINT))==0);

	return TWDR;


}

u8 TWI_U8ReadACK(void)
{
	TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);   //enable Ack
	//Wait for TWINT flag to be set
	while (!(TWCR & (1<<TWINT)));
	// Read Data
	return TWDR;
							
		
}

u8 TWI_U8ReadNACK(void)
{
	TWCR=(1<<TWEN)|(1<<TWINT);

	//Wait for TWINT flag to be set
	 while(!(TWCR&(1<<TWINT)));
	// Read Data
	return TWDR;

}

void TWI_VoidMaster_Write_Byte_To_Slave(u8 data)
{
	// Load SLA_W into TWDR Register
	TWDR = data;
	// Clear TWINT bit in TWCR to start transmission of address
	TWCR=(1<<TWEN)|(1<<TWINT);
	//Wait for TWINT flag to be set
	while(!(TWCR&(1<<TWINT)));;

}




u8 TWI_U8GetStatus(void)
{
	u8 status;
	status = (TWSR & I2C_STATUS_CODE_MASK);
	if (status != 0x08)
	{
		return 0;
	}
	return status;
}


void  TWI_VoidStopCondition()
{
	//TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	TWCR=(1<<TWSTO)|(1<<TWINT)|(1<<TWEN);  /* Enable TWI, generate stop */
    while(TWCR&(1<<TWSTO));	               /* Wait until stop condition execution */

}

