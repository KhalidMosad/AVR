/*
 * LCD_Interface.h

 *
 *  Created on: Nov 30, 2020
 *      Author: Khaled
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


void LCD_VidInit(void);
void LCD_VidSendData(u32 copy_u8data);
void LCD_VidSendCommand(u8 copy_u8command);
void LCD_VidSendString(u8 *copy_u8string);
void LCD_VidSendNum(u32 Copy_u16Num);
void  LCD_VidSetPosition(u8 raw, u8 column);
void LCD_VidClear(void);
void LCD_integer_string(u32 copy_u8num);
void LCD_displayStringRowColum(u8 copy_u8row, u8 copy_u8colum, u32 *string);
#endif /* LCD_INTERFACE_H_ */
