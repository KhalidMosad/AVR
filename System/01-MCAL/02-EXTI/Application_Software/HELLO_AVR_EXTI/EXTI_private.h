/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   20/1/2021          */
/*********Version: 2                     */
/****************Desc: *******************/

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define		FALLING		0
#define		RISING		1
#define		LOW_LEVEL	2
#define		ANY_LOGICAL	2

#define		INT0		0
#define		INT1		1
#define		INT2		2




/* MCUCR REGISTER*/ 
#define	ISC00			0
#define	ISC01			1
#define	ISC10			2
#define	ISC11			3
#define	SM0				4
#define	SM1				5
#define	SM2				6
#define	SE				7
#define MCUCR *((volatile u8*)0x55)


/* GICR REGISTER*/ 
#define	IVCE			0
#define	IVSEL			1
#define	RESERVED		2
#define	RESERVED1		3
#define	RESERVED2		4
#define	INT2E			5
#define	INT0E			6
#define	INT1E			7

#define GICR  *((volatile u8*)0x5b)


#define		ISC2		6	
#define MCUCSR  *((volatile u8*)0x54)
/* SREG REGISTER*/ 
#define	GIE				7

#define SREG  *((volatile u8*)0x5f)


void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));


#endif 
