/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   16/4/2021          */
/*********Version: 1                     */
/****************Desc: *******************/

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_



#define     TCNT0       *((volatile u8*)0x52)
#define     OCR0        *((volatile u8*)0x5C)

/* TCCR0 REGISTER*/ 
#define 	CS00			0
#define 	CS01	    	1
#define 	CS02	    	2
#define 	WGM01			3
#define 	COM00	    	4
#define 	COM01			5
#define 	WGM00			6
#define 	FOC0			7



#define     TCCR0       *((volatile u8*)0x53)

#define     BIT7            7

#define     SREG        *((volatile u8*)0x5F)



#define     TCNT1       *((volatile u16*)0x4C)
#define     OCR1A       *((volatile u16*)0x4A)
#define     OCR1B       *((volatile u16*)0x48)



/* TCCR1 REGISTER*/ 
#define 	COM1A1  	15
#define 	COM1A0   	14
#define 	COM1B1  	13
#define 	COM1B0  	12
#define 	FOC1A    	11
#define 	FOC1B   	10
#define 	WGM11   	9
#define 	WGM10   	8
#define 	ICNC1		7
#define 	ICES1    	6
#define 	R       	5
#define 	WGM13		4
#define 	WGM12    	3
#define 	CS12		2
#define 	CS11		1
#define 	CS10		0

#define     TCCR1       *((volatile u16*)0x4E)



/* TCCR2 REGISTER*/ 

#define 	FOC2    	7
#define 	WGM20    	6
#define 	COM21   	5
#define 	COM20   	4
#define 	WGM21    	3
#define 	CS22    	2
#define 	CS21    	1
#define 	CS20    	0


#define     TCCR2      *((volatile u8*)0x45) 
#define     TCNT2      *((volatile u8*)0x44)        
#define     OCR2       *((volatile u8*)0x43)




/* TIMSK REGISTER*/ 
#define 	TOIE0		0
#define 	OCIE0     	1
#define 	TOIE1     	2
#define 	OCIE1B 		3
#define 	OCIE1A     	4
#define 	TICIE1 		5
#define 	TOIE2 		6
#define 	OCIE2 		7

#define     TIMSK       *((volatile u8*)0x59)

void __vector_5(void) __attribute__((signal));
void __vector_11(void) __attribute__((signal));
void __vector_10(void) __attribute__((signal));


#endif