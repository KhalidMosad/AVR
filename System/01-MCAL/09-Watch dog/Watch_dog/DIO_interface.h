/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   29/11/2020          */
/*********Version: 1                     */
/****************Desc: *******************/

#ifndef  DIO_interface_h_
#define  DIO_interface_h_

void DIO_VidSetPinDirection		(u8 copy_u8port, u8 copy_U8pin, u8 copy_U8state);
void DIO_VidSetPinValue			(u8 copy_u8port, u8 copy_U8pin, u8 copy_U8value);
u8 DIO_VidGetPinValue			(u8 copy_u8port, u8 Copy_U8Pin);
void DIO_VidSetPortDirection	(u8 copy_u8port, u8 copy_U8state);
void DIO_VidSetPortValue		(u8 copy_u8port, u8 copy_U8value);
void DIO_VidTogglePin			(u8 copy_u8port, u8 copy_U8pin);

#endif
