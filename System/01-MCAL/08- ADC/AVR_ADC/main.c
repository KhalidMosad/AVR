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
#include<util/delay.h>

void main()
{
	DIO_VidSetPinDirection(PORTA,PIN0,INPUT);
	LCD_VidInit();
	ADC_VoidInit();
	ADC_VoidADCEnable();
	_delay_ms(100);

	u32 Digital_value=0;
	u32 Analog_Value=0;
	_delay_ms(1000);
	LCD_VidClear();

	while(1)
	{

		Digital_value= ADC_U16ReadDigitalValue();
		Analog_Value= ((5*1000*Digital_value)/1023);
		LCD_VidSetPosition(0,0);
		LCD_VidSendString("ANALOG:");
		LCD_VidSetPosition(0,9);
		LCD_VidSendNumber(Analog_Value);
		LCD_VidSetPosition(1,0);
		LCD_VidSendString("DIGITAL:");
		LCD_VidSetPosition(1,9);
		LCD_VidSendNumber(Digital_value);
		_delay_ms(1000);
		LCD_VidClear();

	}

}


