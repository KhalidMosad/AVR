/*
 * LCD_Programe.c
 *
 *  Created on: Nov 30, 2020
 *      Author: neutr
 */
#include "STD_Types.h"
#include "DIO_interface.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include <util/delay.h>

void LCD_VidSendCommand(u8 Copy_U8Command)
{
	DIO_VidSetPinValue(CONTROL_PORT,RS,DIO_LOW);	//RS = 0	D0
	DIO_VidSetPinValue(CONTROL_PORT,RW,DIO_LOW);	//RW = 0	D1
	//	PORTA		Data PORT
	DIO_VidSetPortValue(LCD_PORT,Copy_U8Command);
	// Enable Sequence
	DIO_VidSetPinValue(CONTROL_PORT,E,DIO_HIGH);
	_delay_ms(1);
	DIO_VidSetPinValue(CONTROL_PORT,E,DIO_LOW);
}

void LCD_VidInit(void)
{
#ifdef _8_bit
	DIO_VidSetPortDirection(LCD_DDR,0xff);

	DIO_VidSetPinDirection(CONTROL_PORT,RS,DIO_HIGH);
	DIO_VidSetPinDirection(CONTROL_PORT,RW,DIO_HIGH);
	DIO_VidSetPinDirection(CONTROL_PORT,E,DIO_HIGH);

	_delay_ms(40);
	LCD_VidSendCommand(0b00111000);
	_delay_ms(1);
	//	Display ON, Cursor ON, Cursor Blink ON
	LCD_VidSendCommand(0b00001100);
	_delay_ms(1);
	//	Clear Display
	LCD_VidSendCommand(0b00000001);
	_delay_ms(2);
#endif

#ifdef _4_bit
	// TO DO
	DIO_VidSetPortDirection(LCD_DDR,0xff);
	DIO_VidSetPinDirection(CONTROL_PORT,RS,DIO_HIGH);
	DIO_VidSetPinDirection(CONTROL_PORT,RW,DIO_HIGH);
	DIO_VidSetPinDirection(CONTROL_PORT,E,DIO_HIGH);

	_delay_ms(40);
	LCD_VidSendCommand(0b00111000);
	_delay_ms(1);
	//	Display ON, Cursor ON, Cursor Blink ON
	LCD_VidSendCommand(0b00001100);
	_delay_ms(1);
	//	Clear Display
	LCD_VidSendCommand(0b00000001);
	_delay_ms(2);
#endif
}

void LCD_VidSendData(u8 Copy_U8Data)
{
	DIO_VidSetPinValue(CONTROL_PORT,RS,DIO_HIGH);	//RS = 1	D0
	DIO_VidSetPinValue(CONTROL_PORT,RW,DIO_LOW);	//RW = 0	D1
	//	PORTA		Data PORT
	DIO_VidSetPortValue(LCD_PORT,Copy_U8Data);
	// Enable Sequence
	DIO_VidSetPinValue(CONTROL_PORT,E,DIO_HIGH);
	_delay_ms(1);
	DIO_VidSetPinValue(CONTROL_PORT,E,DIO_LOW);
	_delay_ms(1);
}



void LCD_VidSendString(u8 *Copy_U8String)
{	u8 i = 0;
//	u8 String[100] ={0};

while (Copy_U8String[i]!='\0')
{
	LCD_VidSendData(Copy_U8String[i]);
	_delay_ms(1);
	i++;
}
}

void LCD_VidSendNumber(u16 Copy_U8Number)

{

	//	u16 reverse = 0, number = Copy_U8Number;
	//
	//	while(number > 0)
	//	{
	//		reverse = (reverse * 10) + (number % 10);
	//		number = number / 10;
	//	}
	//
	//	while (reverse > 0)
	//	{
	//		LCD_VidSendData(48 + (reverse % 10));
	//		reverse = reverse / 10;
	//	}

	if(Copy_U8Number <=9 &&Copy_U8Number >=0)
	{
		LCD_VidSendData(Copy_U8Number + 48);
	}

	else
	{ u16 i=0;

	while(Copy_U8Number%10==0)
	{
		i++;
		Copy_U8Number=Copy_U8Number/10;
	}

	u32 Local_u16rev=0;
	while(Copy_U8Number>0)
	{
		Local_u16rev=Local_u16rev*10+Copy_U8Number %10;
		Copy_U8Number=Copy_U8Number/10;

	}
	while(Local_u16rev>0)
	{
		LCD_VidSendData(48+(Local_u16rev % 10));
		Local_u16rev=Local_u16rev/10;
	}
	while(i>0)
	{
		LCD_VidSendData('0');
		i--;
	}
	}
}
void LCD_VidClearDisplay()
{
	LCD_VidSendCommand(0b00000001);
	_delay_ms(1);
}

void LCD_VidSetPosition(u8 Copy_U8Row, u8 Copy_U8Col)
{
	if (0 == Copy_U8Row)
	{
		LCD_VidSendCommand(0x80 + Copy_U8Col);
	}

	else if (1 ==Copy_U8Row)
	{
		LCD_VidSendCommand(0xc0 + Copy_U8Col);
	}
}

void LCD_VidWriteCGRAM(u8 Copy_U8Location, u8 *Copy_U8Char)
{

	if ( Copy_U8Location < 8)
	{
		LCD_VidSendCommand(0x40 + (Copy_U8Location * 8));
		for (u8 i = 0; i < 8; i++)
		{
			LCD_VidSendData(Copy_U8Char[i]);
			_delay_ms(5);
		}
	}
}
/*
void LCD_VidSendCustomChar(u8 Copy_U8Row, u8 Copy_U8Col,u8 Copy_U8Location, u8 *Copy_U8Char)
{
	LCD_VidWriteCGRAM(Copy_U8Location,Copy_U8Char);
	LCD_VidSetPosition(Copy_U8Row,Copy_U8Col);
	LCD_VidSendData(Copy_U8Location);
}*/
