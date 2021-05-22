/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   21/4/2021          */
/*********Version: 2                     */
/****************Desc: *******************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
#define	F_2				0
#define	F_4				1
#define	F_8				3
#define	F_16			4
#define	F_32			5
#define	F_64			6
#define	F_128			7

#define AREF_PIN_SETEXTERNALLY  0
#define ACCC_PIN_SAMEVCC        1
#define RESERVED                2
#define INTERNAL_2_56           3


#define ADC_C0         0
#define ADC_C1         1
#define ADC_C2         2
#define ADC_C3         3 
#define ADC_C4         4
#define ADC_C5         5
#define ADC_C6         6
#define ADC_C7         7 


#define	ADJUST_LEFT 	0
#define	ADJUST_RIGHT  	1


void ADC_VoidInit(void);
void ADC_VoidADCEnable(void);
void ADC_VoidSelect_channel(u8 Copy_Channel);
void ADC_VoidStartConversion(void);
u16 ADC_U16ReadDigitalValue(void);
void GIE_voidEnable(void);
void GIE_voidDisable(void);

#endif 
