/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   29/11/2020          */
/*********Version: 1                     */
/****************Desc: *******************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_Register.h"
#include"DIO_interface.h"
void DIO_VidSetPinDirection		(u8 copy_u8port, u8 copy_U8pin, u8 copy_U8state)
{
	if(1==copy_U8state)
	{
		switch (copy_u8port)
		{
			case 0:SET_BIT(DDRA, copy_U8pin); break;
			case 1:SET_BIT(DDRB, copy_U8pin); break;
			case 2:SET_BIT(DDRC, copy_U8pin); break;
			case 3:SET_BIT(DDRD, copy_U8pin); break;
	
		}	
	}
	else if(0==copy_U8state)
	{
		switch(copy_u8port)
		{
			case 0:CLR_BIT(DDRA, copy_U8pin); break;
			case 1:CLR_BIT(DDRB, copy_U8pin); break;
		    case 2:CLR_BIT(DDRC, copy_U8pin); break;
		    case 3:CLR_BIT(DDRD, copy_U8pin); break;
		}	
	}
	else
	{
		
	}
	
}
void DIO_VidSetPinValue			(u8 copy_u8port, u8 copy_U8pin, u8 copy_U8value)
{
	if(1==copy_U8value)
	{
		switch (copy_u8port)
		{
			case 0:SET_BIT(PORTA, copy_U8pin); break;
			case 1:SET_BIT(PORTB, copy_U8pin); break;
			case 2:SET_BIT(PORTC, copy_U8pin); break;
			case 3:SET_BIT(PORTD, copy_U8pin); break;
	
		}	
	}
	else if(0==copy_U8value)
	{
		switch(copy_u8port)
		{
			case 0:CLR_BIT(PORTA, copy_U8pin); break;
			case 1:CLR_BIT(PORTB, copy_U8pin); break;
		    case 2:CLR_BIT(PORTC, copy_U8pin); break;
		    case 3:CLR_BIT(PORTD, copy_U8pin); break;
		}	
	}
	else
	{
		
	}	
	
	
	
}


u8 DIO_VidGetPinValue			(u8 copy_u8port, u8 Copy_U8Pin)
{
	u8 Lcal_U8PinResult=0;
	switch(copy_u8port){

			case 0 :		Lcal_U8PinResult=GET_BIT(PINA,Copy_U8Pin);	        break;
			case 1 :		Lcal_U8PinResult=GET_BIT(PINB,Copy_U8Pin); 		    break;
			case 2 :		Lcal_U8PinResult=GET_BIT(PINC,Copy_U8Pin);			break;
			case 3 :		Lcal_U8PinResult=GET_BIT(PIND,Copy_U8Pin);			break;

			}


return(Lcal_U8PinResult);
	
	
}

void DIO_VidSetPortDirection	(u8 copy_u8port, u8 copy_U8state)
{
	
	if(1==copy_U8state)
	{
		switch (copy_u8port)
		{
			case 0:DDRA= 0xff		; break;
			case 1:DDRB= 0xff		; break;
			case 2:DDRC= 0xff		; break;
			case 3:DDRD= 0xff		; break;
	
		}	
	}
	else if(0==copy_U8state)
	{
		switch(copy_u8port)
		{
			case 0:DDRA= 0x00		; break;
			case 1:DDRB= 0x00		; break;
			case 2:DDRC= 0x00		; break;
			case 3:DDRD= 0x00		; break;
		}	
	}
	else
	{
		
	}
	
	
}
void DIO_VidSetPortValue		(u8 copy_u8port, u8 copy_U8value)
{
		
		switch (copy_u8port)
		{
			case 0:PORTA=copy_U8value		; break;
			case 1:PORTB=copy_U8value		; break;
			case 2:PORTC=copy_U8value		; break;
			case 3:PORTD=copy_U8value		; break;
	
		}	
	
	
	
	
}

void DIO_VidTogglePin			(u8 copy_u8port, u8 copy_U8pin)
{

		switch (copy_u8port)
		{
					case 0:TOG_BIT(PORTA, copy_U8pin); break;
					case 1:TOG_BIT(PORTB, copy_U8pin); break;
					case 2:TOG_BIT(PORTC, copy_U8pin); break;
					case 3:TOG_BIT(PORTD, copy_U8pin); break;
		}

}

