/*
 * LCD_Interface.h
 *
 *  Created on: Nov 30, 2020
 *      Author: neutr
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "STD_Types.h"
#include "LCD_Private.h"

void LCD_VidInit(void);

void LCD_VidSendData(u8 Copy_U8Data);

void LCD_VidSendCommand(u8 Copy_U8Command);

void LCD_VidSendString(u8 *Copy_U8String);

void LCD_VidSendNumber(u16 Copy_U8Number);

void LCD_VidClearDisplay();

void LCD_VidSetPosition(u8 Copy_U8Row, u8 Copy_U8Col);

void LCD_VidWriteCGRAM(u8 Copy_U8Location, u8 *Copy_U8Char);

void LCD_VidSendCustomChar(u8 Copy_U8Row, u8 Copy_U8Col,u8 Copy_U8Location, u8 *Copy_U8Char);

#endif /* LCD_INTERFACE_H_ */
