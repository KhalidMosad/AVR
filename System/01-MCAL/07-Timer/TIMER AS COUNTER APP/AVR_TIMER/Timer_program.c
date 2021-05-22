/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   16/4/2021          */
/*********Version: 1                     */
/****************Desc: *******************/


#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"Timer_interface.h"
#include"Timer_private.h"
#include"Timer_config.h"
#include"DIO_interface.h"


void TM_voidTimerInit(void)
{
    #if TIMER_S== TIMER0

        #if TIMER0_M==NORMAL
            CLR_BIT(TCCR0,WGM00);
            CLR_BIT(TCCR0,WGM01);
            SET_BIT(TIMSK, TOIE0);

        #elif TIMER0_M==CTC
            CLR_BIT(TCCR0,WGM00);
            SET_BIT(TCCR0,WGM01);
            OCR0= OCR_VALUE_CTCMode;
            SET_BIT(TIMSK, OCIE0);

        // WAVE GENERATOR ON PINB.3
            CLR_BIT(TCCR0,COM01);
            SET_BIT(TCCR0,COM00);



        #elif TIMER0_M==PWM
            SET_BIT(TCCR0,WGM00);
            CLR_BIT(TCCR0,WGM01);

        #elif TIMER0_M==FAST_PWM
            SET_BIT(TCCR0,WGM00);
            SET_BIT(TCCR0,WGM01);

        #endif

        #if TIMER0_CLK == NO_CLOCK
            CLR_BIT(TCCR0,CS00);
            CLR_BIT(TCCR0,CS01);
            CLR_BIT(TCCR0,CS02);
        #elif TIMER0_CLK == CLK
            SET_BIT(TCCR0,CS00);
            CLR_BIT(TCCR0,CS01);
            CLR_BIT(TCCR0,CS02);
        #elif TIMER0_CLK == CLK_8
            CLR_BIT(TCCR0,CS00);
            SET_BIT(TCCR0,CS01);
            CLR_BIT(TCCR0,CS02);
        #elif TIMER0_CLK == CLK_64
            SET_BIT(TCCR0,CS00);
            SET_BIT(TCCR0,CS01);
            CLR_BIT(TCCR0,CS02);
        #elif TIMER0_CLK == CLK_256
            CLR_BIT(TCCR0,CS00);
            CLR_BIT(TCCR0,CS01);
            SET_BIT(TCCR0,CS02);
        #elif TIMER0_CLK == CLK_1024
            SET_BIT(TCCR0,CS00);
            CLR_BIT(TCCR0,CS01);
            SET_BIT(TCCR0,CS02);
        #elif TIMER0_CLK == EXTERNAL_CLK_FALLING
            CLR_BIT(TCCR0,CS00);
            SET_BIT(TCCR0,CS01);
            SET_BIT(TCCR0,CS02);
        #elif TIMER0_CLK == EXTERNAL_CLK_RISING
            SET_BIT(TCCR0,CS00);
            SET_BIT(TCCR0,CS01);
            SET_BIT(TCCR0,CS02);
        
        #endif


    #elif TIMER_S== TIMER1
        

    #elif TIMER_S== TIMER2
        #if TIMER2_M==NORMAL
            CLR_BIT(TCCR2,WGM20);
            CLR_BIT(TCCR2,WGM21);
            SET_BIT(TIMSK, TOIE2);

        #elif TIMER2_M==CTC
            CLR_BIT(TCCR2,WGM20);
            SET_BIT(TCCR2,WGM21);
            OCR0= OCR_VALUE_CTCMode;
            SET_BIT(TIMSK, OCIE2);

        // WAVE GENERATOR ON PINB.3
            CLR_BIT(TCCR2,COM21);
            SET_BIT(TCCR2,COM20);



        #elif TIMER2_M==PWM
            SET_BIT(TCCR2,WGM20);
            CLR_BIT(TCCR2,WGM21);

        #elif TIMER2_M==FAST_PWM
            SET_BIT(TCCR2,WGM20);
            SET_BIT(TCCR2,WGM21);

        #endif

        #if TIMER2_CLK == NO_CLOCK
            CLR_BIT(TCCR2,CS20);
            CLR_BIT(TCCR2,CS21);
            CLR_BIT(TCCR2,CS22);
        #elif TIMER2_CLK == CLK
            SET_BIT(TCCR2,CS20);
            CLR_BIT(TCCR2,CS21);
            CLR_BIT(TCCR2,CS22);
        #elif TIMER2_CLK == CLK_8
            CLR_BIT(TCCR2,CS20);
            SET_BIT(TCCR2,CS21);
            CLR_BIT(TCCR2,CS22);
        #elif TIMER2_CLK == CLK_32
            SET_BIT(TCCR2,CS20);
            SET_BIT(TCCR2,CS21);
            CLR_BIT(TCCR2,CS22);
        #elif TIMER2_CLK == CLK_64
            CLR_BIT(TCCR2,CS20);
            CLR_BIT(TCCR2,CS21);
            SET_BIT(TCCR2,CS22);
        #elif TIMER2_CLK == CLK_128
            SET_BIT(TCCR2,CS20);
            CLR_BIT(TCCR2,CS21);
            SET_BIT(TCCR2,CS22);
        #elif TIMER2_CLK == CLK_256
            CLR_BIT(TCCR2,CS20);
            SET_BIT(TCCR2,CS21);
            SET_BIT(TCCR2,CS22);
        #elif TIMER2_CLK == CLK_1024
            SET_BIT(TCCR2,CS20);
            SET_BIT(TCCR2,CS21);
            SET_BIT(TCCR2,CS22);    

        #endif

    #else
    #endif
   
    SET_BIT(SREG, BIT7);
    
}


void TM_VoidPrealoadOverFlow(void)
{ 
    TCNT0= PRELOAD_VALUE;
    TCNT2= PRELOAD_VALUE;
}


void __vector_11(void)
{
//    static u16 counter=0;
//	counter++;
//	if(counter==245)
//	{
//		TCNT0=PRELOAD_VALUE;
//		DIO_VidTogglePin(PORTA,PIN0);
//		counter=0;
//}

	DIO_VidTogglePin(PORTA,PIN0);
}

void __vector_10(void)
{
    static u16 Counter=0;
	Counter++;
	if(Counter==5000)
	{

        DIO_VidTogglePin(PORTA,PIN0);
		Counter=0;

	}

}

void __vector_5(void)
{
    static u16 counter=0;
	counter++;
	if(counter==245)
	{
		TCNT2=PRELOAD_VALUE;
		DIO_VidTogglePin(PORTA,PIN5);
		counter=0;
	}


}
