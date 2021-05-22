/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   20/1/2021          */

/*********Version: 2                     */
/****************Desc: *******************/
#include"BIT_Math.h"
#include"STD_Types.h"
#include"SPI_interface.h"
#include"SPI_private.h"
#include"SPI_config.h"
#include"DIO_interface.h"

u8 SPCR_Help;

void SPI_VoidInit(void)
{
	
	
	
	#if MODE==MASTER
		SET_BIT(SPCR_Help,MSTR);
		// MISO PB6 INPUT
		//DIO_VidSetPinDirection(1,6,0);
		// SCK PB7 OUT
		DIO_VidSetPinDirection(1,7,1);
		// MOSI PB5 OUT
		DIO_VidSetPinDirection(1,5,1);
		// SS PB4 OUT
		DIO_VidSetPinDirection(1,4,1);
		DIO_VidSetPinValue(1,4,0);
	#elif MODE==SLAVE
		CLR_BIT(SPCR_Help,MSTR);
		// PIN CONFIG
		// MISO PB6 out
		DIO_VidSetPinDirection(1,6,1);
		// SCK PB7 IN
		DIO_VidSetPinDirection(1,7,0);
		// MOSI PB5 IN
		DIO_VidSetPinDirection(1,5,0);
		// SS PB4 IN
		DIO_VidSetPinDirection(1,4,0);
		DIO_VidSetPinValue(1,4,1);
	#endif
	
	
	#if	CLOCK_RATE == F_16
		CLR_BIT(SPSR,SPI2X);
		SET_BIT(SPCR_Help,SPR0);
		CLR_BIT(SPCR_Help,SPR1);
		
	#elif CLOCK_RATE== F_4
		CLR_BIT(SPSR,SPI2X);
		CLR_BIT(SPCR_Help,SPR0);
		CLR_BIT(SPCR_Help,SPR1);
	#elif CLOCK_RATE== F_64
		CLR_BIT(SPSR,SPI2X);
		SET_BIT(SPCR_Help,SPR1);
		CLR_BIT(SPCR_Help,SPR0);
	#elif CLOCK_RATE== F_128
		CLR_BIT(SPSR,SPI2X);
		SET_BIT(SPCR_Help,SPR0);
		SET_BIT(SPCR_Help,SPR1);
	#elif	CLOCK_RATE == F_8
		SET_BIT(SPSR,SPI2X);
		SET_BIT(SPCR_Help,SPR0);
		CLR_BIT(SPCR_Help,SPR1);
		
	#elif CLOCK_RATE== F_2
		SET_BIT(SPSR,SPI2X);
		CLR_BIT(SPCR_Help,SPR0);
		CLR_BIT(SPCR_Help,SPR1);
	#elif CLOCK_RATE== F_32
		SET_BIT(SPSR,SPI2X);
		SET_BIT(SPCR_Help,SPR1);
		CLR_BIT(SPCR_Help,SPR0);
	#elif CLOCK_RATE== F_64D
		SET_BIT(SPSR,SPI2X);
		SET_BIT(SPCR_Help,SPR0);
		SET_BIT(SPCR_Help,SPR1);
	#endif
	//SPI operations enable
	SET_BIT(SPCR_Help,SPE);
	
	#if CLOCK_POLARITY==LEADING_RISING
		CLR_BIT(SPCR_Help,CPOL); 
	#elif CLOCK_POLARITY==LEADING_FALLING
		SET_BIT(SPCR_Help,CPOL);
	#endif

	#if CLOCK_PHASE==LEADING_SAMPLE
		CLR_BIT(SPCR_Help,CPHA);
	#elif CLOCK_PHASE==LEADING_SETUP
		SET_BIT(SPCR_Help,CPHA); 
	#endif
	
	#if DATA== LSB_FIRST
		SET_BIT(SPCR_Help,DORD);
	#elif DATA==MSB_FIRST
		CLR_BIT(SPCR_Help,DORD);
	#endif
	
	SPCR=SPCR_Help;

}

u8 SPI_u8Send(u8 data)
{
	DIO_VidSetPinDirection(PORTA,PIN4,OUTPUT);
	SPDR=data;
	while(0==GET_BIT(SPSR,SPIF));
	DIO_VidSetPinValue(PORTA,PIN4,HIGH);
return SPDR;

}
u8 SPI_u8Receive(void)
{
	while(0==GET_BIT(SPSR,SPIF));
	u8 x;
	x= SPDR;

return x;
}

