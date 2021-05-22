/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   20/1/2021          */
/*********Version: 2                     */
/****************Desc: *******************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"EXTI_interface.h"
#include"EXTI_config.h"
#include"EXTI_private.h"
#include"util/delay.h"
void EXIT_voidInit(void)
{
	
#if EXTI==INT0
	#if TRIGGER == FALLING
		SET_BIT(MCUCR,ISC01);
		CLR_BIT(MCUCR,ISC00);
	#elif TRIGGER == RISING
		SET_BIT(MCUCR,ISC01);
		SET_BIT(MCUCR,ISC00);
	#elif TRIGGER == ANY_LOGICAL
		SET_BIT(MCUCR,ISC00);
		CLR_BIT(MCUCR,ISC01);
	#elif TRIGGER == LOW_LEVEL
		CLR_BIT(MCUCR,ISC01);
		CLR_BIT(MCUCR,ISC00);
		
	#endif
	
#elif EXTI==INT1
	#if TRIGGER == FALLING
		SET_BIT(MCUCR,ISC11);
		CLR_BIT(MCUCR,ISC10);
	#elif TRIGGER == RISING
		SET_BIT(MCUCR,ISC11);
		SET_BIT(MCUCR,ISC10);
	#elif TRIGGER == ANY_LOGICAL
		SET_BIT(MCUCR,ISC11);
		CLR_BIT(MCUCR,ISC10);
	#elif TRIGGER == LOW_LEVEL
		CLR_BIT(MCUCR,ISC11);
		CLR_BIT(MCUCR,ISC10);
	
	#endif


#elif EXTI==INT2
	#if TRIGGER == FALLING	
		CLR_BIT(MCUCR,ISC2);
	#elif TRIGGER == RISING	
		SET_BIT(MCUCSR,ISC2);
	#endif

	

#endif

}

void EXTI_voidEnable(void)
{	
	//PIE= Enable
	#if EXTI==INT0
		SET_BIT(GICR,INT0E);
	#elif EXTI==INT1
		SET_BIT(GICR,INT1E);
	#elif EXTI==INT2
		SET_BIT(GICR,INT2E);

	#endif


}


void EXTI_voidDisable(void)
{
	#if EXTI==INT0
		CLR_BIT(GICR,INT0E);
	#elif EXTI==INT1
		CLR_BIT(GICR,INT1E);
	#elif EXTI==INT2
		CLR_BIT(GICR,INT2E);

	#endif
}

void GIE_voidEnable(void)
{
	// GIE
	SET_BIT(SREG,GIE);

}

void GIE_voidDisable(void)
{
	// GIE
	CLR_BIT(SREG,GIE);

}


void __vector_1(void)
{

	DIO_VidSetPinValue(PORTA,PIN0,HIGH);
	_delay_ms(5000);
	DIO_VidSetPinValue(PORTA,PIN0,LOW);

}

void __vector_2(void)
{

	DIO_VidSetPinValue(PORTA,PIN0,HIGH);
	_delay_ms(5000);
	DIO_VidSetPinValue(PORTA,PIN0,LOW);

}

void __vector_3(void)
{

	DIO_VidSetPinValue(PORTA,PIN0,HIGH);
	_delay_ms(5000);
	DIO_VidSetPinValue(PORTA,PIN0,LOW);

}





