#ifndef LCD_H_
#define LCD_H_

#ifndef DATA_TYPES
#define DATA_TYPES
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
#endif

#define ADDRESS_B 0X38		//ADDRESS OF DATA REGISTER B
#define ADDRESS_B_IO 0X37	//ADDRESS OF DATA DIRECTION REGISTER B
#define LCD_PORT *(u8* const)ADDRESS_B		//POINTER TO CHARACTER POINTS TO DATA REGISTER B
#define LCD_IO *(u8* const)ADDRESS_B_IO		//POINTER TO CHARACTER POINTS TO DATA DIRECTION REGISTER B
#define CONNECT 0X7F	//HARDWARE CONNECTION

#define SET_BIT(REG,POS) REG|=(1<<POS)	//SET BIT
#define CLR_BIT(REG,POS) REG&=~(1<<POS)	//CLEAR BIT
#define TOG_BIT(REG,POS) REG^=(1<<POS)	//TOGGLE BIT

#define RW 6	//RW BIT
#define RS 5	//RS BIT
#define EN 4	//ENABLE BIT
#define B3 3	//BIT 3
#define B2 2	//..2
#define B1 1
#define B0 0	
#define L1 0	//FIRST LINE
#define L2 1	//SECOND ..
#define N8 0X08		//NIBBLE 1000
#define N4 0X04		//.. 0100
#define N2 0X02		//.. 0010
#define N1 0X01		//.. 0001
#define N0 0X00		//.. 0000
#define MODE_DAT 1	//DATA MODE
#define MODE_COM 0	//COMMAND MODE
#define MEGA 1000000//MEGA CONVERTION
#define ASCII 48	//ASCI ..
#define LCD_SIZE 16	//LCD SIZE 16*2
#define MSB 0xF0	//CAST BYTE TO MOST SIGNIFICANT BITS NIBBLE
#define LSB 0X0F	//CAST BYTE TO LEAST SIGNIFICANT BITS NIBBLE
#define RIGHT 8		//SHIFTING DIRECTIONS
#define LEFT 9		//..

#ifndef F_CPU
#define F_CPU 16000000UL		//16 MHz CLOCK SPEED IF NOT PREVIOUSLY DEFINED
#endif

void Delay(u8 m_s, u8 u_s);		//DELAY FUNCTION
void Write_port(u8 nibble);		//WRITE NIBBLE ON PORT
void Mode_select(u8 mode);		//SWITCH BETWEEN DATA OR COMMAND MODES
void Trigger_enable(void);		//TRIGGER ENABLE BIT
void Send_command(u8 command);	//SEND COMMAND TO LCD
void Initialize_lcd(void);		//INITIALIZE LCD
void Display_clear(void);		//CLEAR DISPLAY AND RETURN CURSOR TO HOME
void Display_char(s8 character);	//DISPLAY ONE ELEMENT
void Cursor_pos(u8 vertical, u8 horizontal);//SELECT CURSOR POSITION
void Display_string(s8 *string_0,s8 *string_1);	//DISPLAY ARRAY OF ELEMENTS
void Display_shift(u8 direction);	//SHIFT DIPLSYED ELEMENTS

#endif /* LCD_H_ */