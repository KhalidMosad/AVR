/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   22/1/2021          */
/*********Version: 1                     */
/****************Desc: *******************/

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

#define UDR   		 *( (volatile u8*) 0x2C)

//----------------------------------------------------------------
/* UCSRA REGISTER*/
#define	RXC			7		//USART Receive Complete
#define	TXC			6		//USART Transmit Complete
#define	UDRE		5		//USART Data Register Empty
#define	FE			4		//Frame Error
#define	DOR			3		//Data OverRun
#define	PE			2		//Parity Error
#define	U2X			1		// Double the USART Transmission Speed
/*
This bit only has effect for the asynchronous operation. 
Write this bit to zero when using synchronous operation
Writing this bit to one will reduce 
the divisor of the baud rate divider 
from 16 to 8 effectively doubling the transfer rate for asynchronous communication
*/
#define	MPCM		0		// Multi-processor Communication Mode

#define UCSRA   	 *( (volatile u8*) 0x2B)
//-------------------------------------------------------------------
/* UCSRB REGISTER*/
#define	RXCIE			7			//RX Complete Interrupt Enable
#define	TXCIE			6			//TX Complete Interrupt Enable
#define	UDRIE			5			// Data Register Empty Interrupt Enable
#define	RXEN			4			// Receiver Enable
#define	TXEN			3			// Transmitter Enable
#define	UCSZ2			2			// Character Size
#define	RXB8			1			// Receive Data Bit 8
#define	TXB8			0			//  Transmit Data Bit 8

#define UCSRB   	 *( (volatile u8*) 0x2A)
//--------------------------------------------------------------


#define UBRRL   	 *( (volatile u8*) 0x29)
#define UBRRH   	 *( (volatile u8*) 0x40)
#define UBRR   	     *( (volatile u16*) 0x29|0x40)


//--------------------------------------------------------------

/* UCSRC REGISTER*/
#define	URSEL			7			//Register Select
/*
This bit selects between accessing the UCSRC or the UBRRH Register.
 It is read as one when reading UCSRC.
 The URSEL must be one when writing the UCSRC


*/
#define	UMSEL			6			//USART Mode Select

//  Parity Mode Select
#define	UPM1			5			
#define	UPM0			4	
		
#define	USBS			3			// Stop Bit Select
#define	UCSZ1			2			// Character Size
#define	UCSZ0			1			
#define	UCPOL			0			//  Clock Polarity

#define UCSRC  		 *((volatile  u8*)  0X40  )

//----------------------------------------------------------------




#endif 