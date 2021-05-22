#ifndef DATA_TYPES_H_
#define DATA_TYPES_H_

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

#endif /* DATA_TYPES_H_ */

#ifndef I2C_H_
#define I2C_H_

#define ADD_CONTROL_REG 0X56//ADDRESS OF I2C CONTROL REGISTER
#define ADD_DATA_REG 0X23	//..			 DATA REGISTER
#define ADD_ADD_REG 0X22	//..			 ADDRESSES REGISTER
#define ADD_STATUS_REG 0X21	//..			 STATUS REGISTER
#define ADD_BIT_RATE 0X20	//..			 BIT RATE REGISTER

#define CONTROL_REG *(volatile u8*)ADD_CONTROL_REG
#define DATA_REG *(u8*)ADD_DATA_REG
#define ADD_REG *(u8*)ADD_ADD_REG
#define STATUS_REG *(volatile u8*)ADD_STATUS_REG
#define BIT_RATE *(u8*)ADD_BIT_RATE

/*CONTROL REGISTER*/
#define I2C_INT_F 7
#define I2C_ACK 6
#define I2C_START 5
#define I2C_STOP 4
#define I2C_EN 2

void Initialize_I2C(void);
void Start_I2C(void);
void Stop_I2C(void);
void Write_I2C(unsigned char data);
u8 ReadACK(void);
u8 ReadNACK(void);
u8 Get_Status(void);

#endif /* I2C_H_ */