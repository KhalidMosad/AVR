#include <stdio.h>
#include "EEPROM.h"
#include "LCD.h"

int main(void)
{
	u8 i;
	u8 value = 0;
	u8 data_array[DATA_SIZE];
	u8 lcd_l1[LCD_SIZE];
	u8 lcd_l2[LCD_SIZE];
	Initialize_lcd();
	Initialize_EEPROM();
	
	while(1)
	{
		for (i = 0; i < DATA_SIZE; i++)
		{
			data_array[i] = (i*2)+(i*3);
		}
		for (i = 0; i < DATA_SIZE; i++)
		{
			WriteByte_EEPROM(i, data_array[i]);
			sprintf(lcd_l1,"Address 0x%02X", i);
			sprintf(lcd_l2,"Stored");
			Display_string(lcd_l1,lcd_l2);
		}
		for (i = 0; i < DATA_SIZE; i++)
		{
			value = 0;
			ReadByte_EEPROM(i,&value);
			sprintf(lcd_l1,"Address 0x%02X", i);
			sprintf(lcd_l2,"Value 0x%02X", value);
			Display_string(lcd_l1,lcd_l2);
			Delay(15,0);		
		}
	}
	return 0;
}