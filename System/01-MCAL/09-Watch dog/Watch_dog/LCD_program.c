/*
 * LCD_program.c

 *
 *  Created on: Nov 30, 2020
 *      Author: Khaled
 */
#include "STD_TYPES.h"
#include"DIO_Register.h"
#include"DIO_interface.h"
#include"LCD_Interface.h"
#include<util/delay.h>
void LCD_VidInit(void)
{
	//_delay_ms(40);
	DIO_VidSetPortDirection(2,1);
	DIO_VidSetPinDirection(3,0,1);
	DIO_VidSetPinDirection(3,1,1);
	DIO_VidSetPinDirection(3,2,1);
	_delay_ms(40);
	LCD_VidSendCommand(0b00111000);
	_delay_ms(1);
	LCD_VidSendCommand(0b00001111);
	_delay_ms(1);
	LCD_VidSendCommand(0b00000001);
	_delay_ms(2);
	LCD_VidSendCommand(0b00000110);


}

void LCD_VidSendData(u32 copy_u8data)
{
		DIO_VidSetPinValue(3,0,1);   // portD Pin0, Rs=1 // data
		DIO_VidSetPinValue(3,1,0);    // portD Pin1, R/w=0 // r/w=0.... write
		_delay_ms(2);
		DIO_VidSetPortValue(2,copy_u8data);    // port C
		_delay_ms(2);
		DIO_VidSetPinValue(3,2,1);  // E=1; Upload Command
		_delay_ms(2);
		DIO_VidSetPinValue(3,2,0);   // E=0 Display Command
		_delay_ms(2);
}
void LCD_VidSendCommand(u8 copy_u8command)
{
	DIO_VidSetPinValue(3,0,0);   // portD Pin0, Rs=0 // command
	DIO_VidSetPinValue(3,1,0);    // portD Pin1, R/w=0 // r/w=0.... write
	DIO_VidSetPortValue(2,copy_u8command);    // port C
	DIO_VidSetPinValue(3,2,1);  // E=1; Upload Command
	_delay_ms(1);
	DIO_VidSetPinValue(3,2,0);   // E=0 Display Command
	if (copy_u8command==1)
	_delay_ms(2);
}

void LCD_VidSendString( u8 *copy_u8string)
{
	u8 i=0;

	while(copy_u8string[i] != '\0')
	{

		LCD_VidSendData(copy_u8string[i]);
		_delay_ms(1);
		i++;
	}

}

void LCD_VidSendNum(u32 Copy_u16Num)
{	u32 rev=0;
	u8 zeros=0;
	u8 flag=0;
	if(Copy_u16Num<0)
	{
		Copy_u16Num*=-1;
		flag=1;
	}
	if (Copy_u16Num!=0)
	{
	while(Copy_u16Num>0)
		{
		 rev=(rev*10)+(Copy_u16Num % 10);
		Copy_u16Num/=10;
		zeros++;
		};
	while(rev!=0)
	{
	u32 rem=rev%10;
	rev/=10;
	if(flag==1)
	{
		LCD_VidSendData('-');
		flag=0;
	}
		LCD_VidSendData((48+rem));//+48 to have aski code
	zeros--;
	}
	while(zeros>0)
	{
		LCD_VidSendData((48+0));
	zeros--;
	}
	}
	else
	{

		LCD_VidSendData((48+0));
	}
}

void LCD_VidSetPosition(u8 raw, u8 column)
{
	if(0==raw)       // raw= 0
	{
	LCD_VidSendCommand(128+column);    // 0b10000000=128 +column
	}
	if(1==raw)
	{
	LCD_VidSendCommand(128+64+column);  //  // 0b10000000=128 +column+64
	                                    // 64 is the start address of row 2
	}

}

void LCD_VidClear(void)
{
	LCD_VidSendCommand(1);
	_delay_ms(3);
}

void LCD_integer_string(u32 copy_u8num)
{
	if (0== copy_u8num)
	{
		LCD_VidSendData('0');
	}

	u32 i, rem, len = 0, n;
	    u8 str[20]={0};

	    n = copy_u8num;
	    while (n != 0)
	    {
	        len++;
	        n /= 10;
	    }
	    for (i = 0; i < len; i++)
	    {
	        rem = copy_u8num % 10;
	        copy_u8num = copy_u8num / 10;
	        str[len - (i + 1)] = rem + '0';
	    }
	    str[len] = '\0';
	    LCD_VidSendString(str);

}

void LCD_displayStringRowColum(u8 copy_u8row, u8 copy_u8colum, u32 *string)
{

		LCD_VidSetPosition(copy_u8row, copy_u8colum);
		LCD_VidSendString(string);

}







