/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   22/1/2021          */
/*********Version: 1                     */
/****************Desc: *******************/

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#define	ASYNCHRONOUS_OP	0
#define	SYNCHRONOUS_OP	1

#define	DISABLED		0
#define	ENABLED_EVEN	1
#define	ENABLED_ODD		2

#define	ONE_BIT			0
#define	TWO_BIT			1

#define FIVE_BITS		0
#define SIX_BITS		1
#define SEVEN_BITS		2
#define EIGHT_BITS		3
#define NINE_BITS		4

#define TR_RISING		0
#define TR_FALING		1

void USART_voidINIT(void);
u8 USART_u8Receive(void);
void USART_voidtransmit(u8 data_transmitted);
void USART_voidSendString(char *str);
u8 *USART_u8ReceiveString(u8 *receive_string,u8 terminating_character);






#endif 
