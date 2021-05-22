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
#include <stdio.h>
#include <util/delay.h>

void main()
{
	DIO_VidSetPortDirection(PORTA,INPUT);
	LCD_VidInit();
	ADC_VoidInit();
	ADC_VoidADCEnable();

	u8 buffer[20];
	u32 ADC_Value=0;

	_delay_ms(100);
	LCD_VidClear();

	while(1)
	{

		LCD_VidSetPosition(0,0);
		ADC_VoidSelect_channel(ADC_C0);
		ADC_Value= ADC_U16ReadDigitalValue();
		sprintf(buffer,"X= %d ", ADC_Value);
		LCD_VidSendString(buffer);
		_delay_ms(10);

		LCD_VidSetPosition(1,0);
		ADC_VoidSelect_channel(1);
		ADC_Value= ADC_U16ReadDigitalValue();
		sprintf(buffer,"Y= %d ", ADC_Value);
		LCD_VidSendString(buffer);
		_delay_ms(10);

		ADC_VoidSelect_channel(2);
		ADC_Value= ADC_U16ReadDigitalValue();

		if(ADC_Value<600)
		{
			LCD_VidSetPosition(0,8);
			LCD_VidSendString("ON");
		}
		else
		{
			LCD_VidSetPosition(0,8);
			LCD_VidSendString("OFF");
		}

		_delay_ms(1000);
		LCD_VidClear();

	}

}


