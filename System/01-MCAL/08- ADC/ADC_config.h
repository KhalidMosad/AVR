/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   20/4/2021          */
/*********Version: 2                     */
/****************Desc: *******************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/* CLOCK RATE SELECT OPTIONS
F_2	
F_4	
F_8	
F_16
F_32
F_64
F_128

*/
#define CLOCK_RATE	F_64

/* Vref Source
1- AREF_PIN_SETEXTERNALLY
2- ACCC_PIN_SAMEVCC
3- RESERVED
4- INTERNAL_2_56   
*/

#define VREF_S ACCC_PIN_SAMEVCC

/* Single Ended Channel */
/* ADC CHANNEL 
1- ADC_C0
2- ADC_C1
3- ADC_C2
4- ADC_C3 
5- ADC_C4
6- ADC_C5
7- ADC_C6
8- ADC_C7 

*/

/*Differential  Channel 
Naming Rule will be accordoing to Positive Differential
Input first Then Negative Differential
Input Then The gain*/
/* ADC CHANNEL 

1- ADC0_ADC0_10X
2- ADC1_ADC0_10X
3- ADC0_ADC0_200X
4- ADC1_ADC0_200X
5- ADC2_ADC2_10X
6- ADC3_ADC2_10X
7- ADC2_ADC2_200X
8- ADC3_ADC2_200X
9- ADC0_ADC1_1x
10-ADC1_ADC1_1x
11-ADC2_ADC1_1x
12-ADC3_ADC1_1x
13-ADC4_ADC1_1x
14-ADC5_ADC1_1x
15-ADC6_ADC1_1x
16-ADC7_ADC1_1x
17-ADC0_ADC2_1x
18-ADC1_ADC2_1x
19-ADC2_ADC2_1x
20-ADC3_ADC2_1x
21-ADC4_ADC2_1x
19-ADC5_ADC2_1x
20-
*/



#define ADC_CHANNEL ADC_C0

/* ADC DATA REGISTER ADJUSTANCE 
1- ADJUST_LEFT
2- ADJUST_RIGHT                     // The High 6 Bits in ADC_DATA Register are not used. 
*/
#define ADC_DATA_ADJUST ADJUST_RIGHT 


/* INTERRUPT OPTIONS: 
1- ENABLE
2- DISABLE
*/

#define INT_OP  DISABLE



#endif
