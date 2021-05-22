#include "LCD.h"
/*DELAY FUNCTION*/
void Delay(u8 m_s, u8 u_s)
{
	u32 cycles;
	u32 i;
	cycles = (F_CPU/MEGA)*((m_s*1000)+u_s);	//CALCULATE NUMBER OF CYCLES ACCORDING TO INPUTS
	for (i=cycles;i>0;--i)					//m_s IS MILLI SECONDS, u_s IS MICRO SECONDS
	{
		asm volatile("nop");	//NO OPERATION INSTRUCTION
	}
}
/*WRITE ONE NIBBLE TO PORT*/
void Write_port(u8 nibble)
{
	if(nibble&N1)
		SET_BIT((LCD_PORT),B0);	//IF 1ST BIT = 1 SET B0
	else
		CLR_BIT(LCD_PORT,B0);	//IF 1ST BIT = 0 CLEAR B0
	
	if(nibble&N2)
		SET_BIT(LCD_PORT,B1);	//IF 2ND BIT = 1 SET B1
	else
		CLR_BIT(LCD_PORT,B1);	//IF 2ND BIT = 0 CLEAR B1
	
	if(nibble&N4)
		SET_BIT(LCD_PORT,B2);	//IF 3RD BIT = 1 SET B2
	else
		CLR_BIT(LCD_PORT,B2);	//IF 3RD BIT = 0 CLEAR B2
	
	if(nibble&N8)
		SET_BIT(LCD_PORT,B3);	//IF 4TH BIT = 1 SET B3
	else
		CLR_BIT(LCD_PORT,B3);	//IF 4TH BIT = 0 CLEAR B3
}
/*MODE SELECT*/
void Mode_select(u8 mode)
{
	switch (mode)
	{
	case MODE_COM:
		CLR_BIT(LCD_PORT,RS);	//CLEAR RS --> SWITCH TO LCD CONTROL REGISTER - COMMAND MODE RS = 0
	break;	
	case MODE_DAT:
		SET_BIT(LCD_PORT,RS);	//SET RS --> SWITCH TO LCD DATA REGISTER - DATA MODE RS = 1 
		CLR_BIT(LCD_PORT,RW);	//CLEAR RW --> ENABLE LCD BACK LIGHT
	break;
	}
}
/*TRIGGER ENABLE BIT*/
void Trigger_enable(void)
{
	SET_BIT(LCD_PORT,EN);	//RAISE ENABLE, EN = 1
	Delay(0,5);
	TOG_BIT(LCD_PORT,EN);	//TOGGLE ENABLE
	Delay(0,5);				//DELAY TO PREVENT DATA OVER FLOW
}
/*SEND COMMAND*/
void Send_command(u8 command)
{
	Mode_select(MODE_COM);		//SELECT COMMAND MODE
	Write_port(command);		//SEND COMAND TO PORT (DATABUS)
	Trigger_enable();			//TRIGGER ENABLE BIT
}
/*INITIALIZE LCD*/
void Initialize_lcd(void)
{
	LCD_IO |= CONNECT;		//ASSIGN DATABUS TO CONNECTION
	Send_command(N0);			//RETURN CURSOR TO HOME POISTION - COMMAND 0X02
	Send_command(N2);	
	Send_command(N2);			//DISPLAY IN 2-LINES AND 4-BIT DATA MODE - COMMAND 0X28
	Send_command(N8);	
	Send_command(N0);			//DISPLAY NO CURSOR AND NO BLINK - COMMAND 0X0C
	Send_command(N8|N4);	
	Send_command(N0);			//DD RAM ADDRESS WITH NO OFFSET - COMMAND 0X06
	Send_command(N4|N2);
}
/*CLEAR LCD*/
void Display_clear(void)
{
	Send_command(N0);		//CLEAR DISPLAY COMMAND 0X01
	Send_command(N1);
	Send_command(N0);		//RETTURN CURSOR HOME COMMAND 0X02
	Send_command(N2);
}
/*DISPLAY ONE ELEMENT*/
void Display_char(s8 c)
{
	u8 msb, lsb;
	msb = c & MSB;			//ASSIGN DATA MOST SIGNIFICANT BITS TO msb
	msb = msb>>4;
	lsb = c & LSB;			//ASSIGN DATA LEAST SIGNIFICANT BITS TO lsb
	Mode_select(MODE_DAT);	//SELECT DATA MODE
	Write_port(msb);		//SEND msb OVER DATABUS
	Trigger_enable();
	Write_port(lsb);		//SEND lsb OVER DATABUS
	Trigger_enable();
}
/*SET CURSOR POSITION*/
void Cursor_pos(u8 vertical, u8 horizontal)
{
	switch (vertical)
	{
	case L1:					//IF VERTICAL IS L1 DISPLAY IN FIRST LINE
		Send_command(N8);		//COMMAND FOR FIRST LINE IS 0X80 | HORIZONTAL
		Send_command(horizontal);	//PASS THE HORIZONTAL POSITION
	break;
	case L2:					//IF VERTICAL IS L2 DISPLAY IN SECOND LINE
		Send_command(N8|N4);	//COMMAND FOR SECOND LINE IS 0XC0
		Send_command(horizontal);
	break;
	}
}
/*DISPLAY STRING*/
void Display_string(s8 *string_0,s8 *string_1)
{
	Display_clear();		//CLEAR DISPLAY BEFORE WRITING NEW STRING
	Delay(0,5);
	Cursor_pos(L1, 0);	//SET STRING OF FIRST LINE
	while (*string_0!='\0')	//WHILE STRING POINTER POINTS TO SOMETHING
	{
		Display_char(*string_0);			//DISPLAY THIS ELEMENT IN THE ARRAY
		++string_0;						//INCREMENT STRING POINTER ADDRESS TO THE NEXT ELEMENT IN THE ARRAY
	}
	Cursor_pos(L2, 0);	//SET STRING SECOND LINE
	while (*string_1!='\0')	//WHILE STRING POINTER POINTS TO SOMETHING
	{
		Display_char(*string_1);			//DISPLAY THIS ELEMENT IN THE ARRAY
		++string_1;						//INCREMENT STRING POINTER ADDRESS TO THE NEXT ELEMENT IN THE ARRAY
	}
}
/*DISPLAY SHIFTTING*/
void Display_shift(u8 direction)
{
	switch (direction)
	{
	case RIGHT:
		Send_command(N1);	//SHIFT RIGHT COMMAND 0X18
		Send_command(N8);
	break;
	case LEFT:
		Send_command(N1);	//SHIFT LEFT COMMAND 0X1C
		Send_command(N8|N4);
	break;	
	}
}