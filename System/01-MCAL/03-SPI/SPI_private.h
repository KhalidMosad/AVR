/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   21/1/2021          */
/*********Version: 2                     */
/****************Desc: *******************/

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

/* SPCR REGISTER */


#define 	SPIE	7			//SPI Interrupt Enable
#define 	SPE		6			//SPI Enable
#define 	DORD	5			//Data Order
/*
When the DORD bit is written to one,
		the LSB of the data word is transmitted first.
When the DORD bit is written to zero, 
		the MSB of the data word is transmitted first.
*/
#define 	MSTR	4			//Master/Slave Select
/*
 Slave SPI mode when written logic zero  
 Master SPI mode when written to one
*/
#define 	CPOL	3			// Clock Polarity
#define 	CPHA	2			//CPHA Functionality

//Clock Rate Select
#define 	SPR1	1
#define 	SPR0	0

#define SPCR   		 *((volatile u8*)0x2D)

/* SPSR REGISTER */
#define 	SPIF	7			//SPI Interrupt  Flag
#define 	WCOL	6			//Write COLlision Flag
#define 	SPI2X	0			//Double SPI Speed Bit

#define SPSR    	 *((volatile u8*)0x2E)

/* SPDR REGISTER */

#define 	MSB		7			//SPI Interrupt  Flag
#define 	LSB		0

#define SPDR	     *((volatile u8*)0x2F)


/* SREG REGISTER*/ 
#define	GIE				7
#define SREG  *((volatile u8*)0x5f)

void __vector_12(void) __attribute__((signal));

#endif 
