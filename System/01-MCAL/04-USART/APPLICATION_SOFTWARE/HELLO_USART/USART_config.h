/*********Author : Khalid Mosaad Zakaria */
/*********Date   :   22/1/2021          */
/*********Version: 1                     */
/****************Desc: *******************/

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

/* MODE OPTIONS
ASYNCHRONOUS_OP
SYNCHRONOUS_OP
*/

#define Mode	ASYNCHRONOUS_OP	

/* Parity Mode Options
DISABLED
ENABLED_EVEN
ENABLED_ODD
*/
#define	Parity_Mode	DISABLED

/*Stop Bit Select Options

ONE_BIT
TWO_BIT

*/
#define	STOP_SELECT	ONE_BIT

/* Character Size Options
FIVE_BITS
SIX_BITS
SEVEN_BITS
EIGHT_BITS
NINE_BITS
*/
#define	Ch_Size	EIGHT_BITS

/*Clock Polarity Options 
TR_RISING
TR_FALING

*/
#define	CL_POL	TR_RISING



#endif 