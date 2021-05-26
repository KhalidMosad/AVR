/*

 * App.c
 *
 *  Created on: May 25, 2021
 *      Author: Khaled
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Keypad_interface.h"
#include "LCD_Interface.h"
#include "App.h"
#include <avr/delay.h>
void calculate(void)
{
	int i=0;
	int j = 0;
	static Sum = 0;
	u8 Buffer[50];
	while(1)
	{
		if(InputBuffer[i]>=0 && InputBuffer[i]<=9)
		{
			Sum = InputBuffer[i]+Sum*10;
			InputBuffer[i] = 0;
			i++;
		}
		else if(InputBuffer[i] == '+')
		{
			break;
		}
		else
		{
			Organized[j] = Sum;
			Organized[j]=InputBuffer[i];
			Sum = 0;
			j++;
		}

	}

	//sprintf(Buffer,"%s", Organized);
	LCD_VidSendNumber(Organized[0]);



}
int PasswordTrials(void)
{
	u8 Trials = 3;
	u8 buffer[50];
	while (Trials > 0)
	{
		u32 getPassword = Password_Func();
		if(getPassword == DefaultPassword)
		{
			LCD_VidClear();
			LCD_VidSetPosition(0,3);
			LCD_VidSendString("WELCOME TO ");
			LCD_VidSetPosition(1,3);
			LCD_VidSendString("YOUR  HOME");
			return 1;
		}
		else
		{
			Trials--;
			_delay_ms(200);
			sprintf(buffer,"You have %d Trials", Trials);
			LCD_VidClear();
			LCD_VidSetPosition(0,0);
			LCD_VidSendString(buffer);
			_delay_ms(500);
			LCD_VidClear();
		}
	}
	return 0;
}


int Password_Func(void)
{
	int Pass =0;
	int i = 4;
	static int x=0;
	u8 Pressed =0;
	u8 starts;
	LCD_VidSendString("Enter Password");
	while(i>0)
	{

		Pressed = Keypad_U8ReadPin();
		if(Pressed>='0' && Pressed <='9')
		{
			LCD_VidSetPosition(1,0);
			Pressed = Pressed -'0';

			x= Pressed + x*10 ;
			LCD_VidSendNumber(x);
			i--;
			for(starts=0; starts<=3-i;starts++)
			{
				LCD_VidSetPosition(1,starts);
				LCD_VidSendData('*');
			}

		}
		else
		{
			_delay_ms(200);
			LCD_VidClear();
			LCD_VidSendString("Wrong Password");
			break;
		}
	}

	Pass = x;
	x = 0;

	return Pass;
}


