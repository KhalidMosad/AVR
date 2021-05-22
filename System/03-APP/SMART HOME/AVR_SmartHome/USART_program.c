/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   22/1/2021          */
/*********Version: 1                     */
/****************Desc: *******************/

#include "STD_Types.h"
#include "BIT_Math.h"
#include "USART_private.h"
#include "USART_interface.h"
#include "USART_config.h"


void USART_voidINIT(void)
{
	u8 static UCSRC_HELP=0;

	//Select Normal Mode
	CLR_BIT(UCSRA,U2X);
	CLR_BIT(UCSRA,MPCM);

	//Baud rate
	UBRRH=0;
	UBRRL=51;

	#if Ch_Size==EIGHT_BITS
	//frame size   // 8bit
	CLR_BIT(UCSRB,UCSZ2);
	SET_BIT(UCSRC_HELP,UCSZ1);
	SET_BIT(UCSRC_HELP,UCSZ0);
	#elif Ch_Size==FIVE_BITS
	CLR_BIT(UCSRB,UCSZ2);
	CLR_BIT(UCSRC_HELP,UCSZ1);
	CLR_BIT(UCSRC_HELP,UCSZ0);
	#elif Ch_Size==SIX_BITS
	CLR_BIT(UCSRB,UCSZ2);
	CLR_BIT(UCSRC_HELP,UCSZ1);
	SET_BIT(UCSRC_HELP,UCSZ0);
	#elif Ch_Size==SEVEN_BITS
	CLR_BIT(UCSRB,UCSZ2);
	SET_BIT(UCSRC_HELP,UCSZ1);
	CLR_BIT(UCSRC_HELP,UCSZ0);
	#elif Ch_Size==NINE_BITS
	SET_BIT(UCSRB,UCSZ2);
	SET_BIT(UCSRC_HELP,UCSZ1);
	SET_BIT(UCSRC_HELP,UCSZ0);
	#else 
		#error("Wrong choice")
		
	#endif

	// Select UCSRC
	SET_BIT(UCSRC_HELP,URSEL);
	//Asynchronous Operation
	#if Mode==ASYNCHRONOUS_OP
	CLR_BIT(UCSRC_HELP,UMSEL);
	#elif Mode==SYNCHRONOUS_OP
	SET_BIT(UCSRC_HELP,UMSEL);
	#else 
		#error("Wrong choice")
	#endif
	// Disabled Parity Mode
	#if Parity_Mode==DISABLED
	CLR_BIT(UCSRC_HELP,UPM1);
	CLR_BIT(UCSRC_HELP,UPM0);
	#elif Parity_Mode==ENABLED_EVEN
	SET_BIT(UCSRC_HELP,UPM1);
	CLR_BIT(UCSRC_HELP,UPM0);
	#elif Parity_Mode==ENABLED_ODD
	SET_BIT(UCSRC_HELP,UPM1);
	SET_BIT(UCSRC_HELP,UPM0);
	
	#else
		#error("Wrong choice")
	#endif
	
	#if STOP_SELECT==ONE_BIT
	CLR_BIT(UCSRC_HELP,USBS);
	#elif STOP_SELECT==TWO_BIT
	SET_BIT(UCSRC_HELP,USBS);
	#endif
	//Clock Polarity
	#if CL_POL==TR_RISING
	CLR_BIT(UCSRC_HELP,UCPOL);
	#elif CL_POL==TR_FALING
	SET_BIT(UCSRC_HELP,UCPOL);
	#endif
	


	//UCSRC Accessing

	UCSRC=UCSRC_HELP;

	//Transmitter Enable
	SET_BIT(UCSRB,TXEN);

	//Receiver Enable
	SET_BIT(UCSRB,RXEN);

}

u8 USART_u8Receive(void)
{
	u8 x;
	// USART Receive Complete
	while(0==GET_BIT(UCSRA,RXC));
	x=UDR;
	return x;
}

void USART_voidtransmit(u8 data_transmitted)
{

	UDR=data_transmitted;
	// Data register empty
	//while UDR is not empty wait until it finishes
	while(0==GET_BIT(UCSRA,UDRE));

}

void USART_voidSendString(char *str)
{
	u8 j=0;

	while (str[j]!=0)		/* Send string till null*/
	{
		USART_voidtransmit(str[j]);
		j++;
	}
}


u8 *USART_u8ReceiveString(u8 *receive_string,u8 terminating_character)
{
	int i,temp=0;
	for(i=0;;i++)
	{
		*(receive_string+i)=USART_u8Receive();
		if(*(receive_string+i)==terminating_character)
			break;
		else
			temp++;
	}
	*(receive_string+temp)='\0';
	return receive_string;
}





