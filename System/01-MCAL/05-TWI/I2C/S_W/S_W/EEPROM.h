#ifndef DATA_TYPES_H_
#define DATA_TYPES_H_

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

#endif /* DATA_TYPES_H_ */

#ifndef EEPROM_H_
#define EEPROM_H_

#define DATA_SIZE			16		//EEPROM SIZE
#define I2C_FIRST_START		0x08	//ACK OF FIRST START
#define I2C_SECOND_START	0x10	//.. 	SECOND START
#define I2C_MT_SLA_ACK		0x18	//.. 	MT SLA
#define I2C_MT_DATA_ACK		0x28	//.. 	MT DATA
#define I2C_MR_SLA_ACK		0x40	//.. 	MR SLA
#define I2C_MR_DATA_ACK		0x50	//.. 	MR DATA
#define I2C_MR_SLA_NACK		0x48	//NO ACK OF MR SLA
#define I2C_MR_DATA_NACK	0x58	//.. 		MR DATA
#define I2C_MT_SLA_NACK		0x20	//.. 		MT SLA
#define I2C_MT_DATA_NACK	0x30	//.. 		MT DATA
#define CHIP_ADDRESS		0XA0	//CHIP ADDRESS
#define ADD_CAST			0X0700	//MEMORY ADDRESSES CAST FACTOR

void Initialize_EEPROM(void);	//INIT EEPROM
u8 WriteByte_EEPROM(u32 address, s8 data);	//WRITE ONE BYTE @ ADDRESS
u8 ReadByte_EEPROM(u32 address, s8 *data);	//READ ONE BYTE FROM ADRESS
u8 SendAddress_EEPROM(u32 address, u8 state);	//SEND ADDRESS TO CHIP 24AAxx

#endif /* EEPROM_H_ */