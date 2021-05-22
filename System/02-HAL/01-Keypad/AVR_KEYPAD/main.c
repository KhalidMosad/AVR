#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_Interface.h"
#include "Keypad_interface.h"
#include "avr/delay.h"

void main()
{
	LCD_VidInit();

	Keypad_VoidInit();

	LCD_VidSendString("Simple Calculator");
	LCD_VidSetPosition(1,1);
	LCD_VidSendString("OP1");
	LCD_VidSetPosition(1,4);
	u8 x;
	while(1)
	{
		x= Keypad_U8ReadPin();

		if(x != DEFAULT_KEY)
		{
			x=x-'0';
			LCD_VidSendNumber(x);
			break;
		}

	}
	_delay_ms(500);
	LCD_VidClear();
	LCD_VidSendString("OP2");
	LCD_VidSetPosition(0,4);
	u8 Y;
	while(1)
	{
		Y= Keypad_U8ReadPin();

		if(Y != DEFAULT_KEY)
		{
			Y= Y-'0';
			LCD_VidSendNumber(Y);
			break;
		}

	}
	_delay_ms(500);
	LCD_VidClear();

	LCD_VidSendString("OPERATION");
	u8 Op;
	while(1)
	{
		Op= Keypad_U8ReadPin();

		if(Op != DEFAULT_KEY)
		{
			LCD_VidSendData(Op);
			break;
		}

	}
	_delay_ms(500);
	LCD_VidClear();

	u8 Sum;
	float sum;
	switch (Op)
	{
	case '+':
		Sum= x+Y;
		LCD_VidSendNumber(Sum);
		break;
	case '-':
		Sum= x-Y;

		LCD_VidSendNumber(Sum);
		break;
	case '*':
		Sum= x*Y;
		LCD_VidSendNumber(Sum);
		break;
	case '/':

		sum = (float)x/Y;
		LCD_VidSendNumber(sum);
	break;

	}


	while(1)
	{

//		u8 x= Keypad_U8ReadPin();
//		if(x != DEFAULT_KEY )
//		{
//			LCD_VidSendData(x);
//		}


	}


}


