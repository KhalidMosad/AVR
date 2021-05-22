/*

 * main.c
 *
 *  Created on: Apr 20, 2021
 *      Author: Khaled
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_interface.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "Keypad_interface.h"
#include "LCD_private.h"
#include<util/delay.h>
#include <stdio.h>
u16 password=0 ;
u16 Get_Password(u8 Key);

#define DEFAULT_PASS		1234
void main()
{
	u8 buffer[50];
	u8 trials = 3;
	u16 pressed;
	u16 Password_Input;
	DIO_VidSetPinDirection(PORTA,PIN0,INPUT);
	Keypad_VoidInit();
	LCD_VidInit();
	ADC_VoidInit();
	ADC_VoidADCEnable();
	_delay_ms(100);

	u32 Digital_value=0;
	_delay_ms(1000);
	LCD_VidClear();

	while(1)
	{
		LCD_VidSetPosition(0,0);
		LCD_VidSendString("Welcome to our SmartHome ");
		LCD_VidSetPosition(1,5);
		LCD_VidSendString("SmartHome ");
		_delay_ms(1000);
		LCD_VidClear();
		LCD_VidSetPosition(0,0);
		LCD_VidSendString("Enter Password: ");
		LCD_VidSetPosition(1,0);
		while(trials >0)
		{
			u8 i =4;
			while(1)
			{
				while(i>0)
				{
					pressed= Keypad_U8ReadPin();
					if(pressed != DEFAULT_KEY)
					{
						Password_Input=	Get_Password(pressed);
						--i ;
					}
				}
				break;

			}

			trials -- ;
			if(Password_Input == DEFAULT_PASS)
			{
				break;
			}
			else
			{
				sprintf(buffer,"You have %d Trials", trials);
				LCD_VidClear();
				LCD_VidSetPosition(0,0);
				LCD_VidSendString(buffer);
				_delay_ms(500);
				LCD_VidClear();
				LCD_VidSetPosition(0,0);
				LCD_VidSendString("Enter Password: ");
				LCD_VidSetPosition(1,0);
				password=0;
			}


		}
		if(trials==0)
		{
			LCD_VidClear();
			LCD_VidSetPosition(0,5);
			LCD_VidSendString("SYSTEM");
			LCD_VidSetPosition(1,2);
			LCD_VidSendString("WILL CLOSE");
			_delay_ms(1000);
			break;
		}

		LCD_VidSetPosition(1,0);
		LCD_VidSendNumber(Password_Input);
		LCD_VidSendNumber(1000);
		if(Password_Input == DEFAULT_PASS)
		{
			LCD_VidClear();
			LCD_VidSetPosition(1,0);
			LCD_VidSendString("PASSWORD SUCCESSFUL !");
			while(1);
		}



//		Digital_value= ADC_U16ReadDigitalValue();
//		LCD_VidSendString("TEMP:");
//		LCD_VidSetPosition(1,9);
//		LCD_VidSendNumber(Digital_value>>2);
//		_delay_ms(1000);
//		LCD_VidClear();

	}

}

u16 Get_Password(u8 key)
{

	if(key>='0' && key <='9')
	{
		key = key -'0';
		LCD_VidSendNumber(key);
		password = password*10 +key;
	}
	return password;
}
