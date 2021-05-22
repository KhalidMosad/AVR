/*

 * main.c
 *
 *  Created on: Apr 16, 2021
 *      Author: Khaled
 */
#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"LCD_interface.h"
#include"DIO_interface.h"
#include"TIMER_interface.h"
#include <avr/delay.h>


extern  u8 flag;
extern u16 snap1;
extern u32 snap2;
extern u32 snap3;

u16 duty;
u16 freq;

void main(void)
{
	TM_voidTimerInit();
	TM1_VoidInputCapture();
	LCD_VidInit();
	while(1)
	{
	if(3==flag)
	{

	 	LCD_VidClear();
		duty=(100*(snap2-snap1)/(snap3-snap1));
		freq=(1000000)/(snap3-snap1);
		LCD_VidSetPosition(0,0);
		LCD_VidSendString("Duty = ");
		LCD_VidSendNumber(duty);
		LCD_VidSetPosition(1,0);
		LCD_VidSendString("Freq = ");
		LCD_VidSendNumber(freq);

		_delay_ms(1000);
		 flag=0;

	}
	}


}


