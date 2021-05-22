/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   16/4/2021          */
/*********Version: 1                     */
/****************Desc: *******************/

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_


/* Timer Options:

1- TIMER0
2- TIMER1
3- TIMER2

*/

#define  TIMER_S    TIMER0

/* Timer0 Mode Options:

1- NORMAL
2- CTC
3- PWM
4- FAST_PWM
*/
#define TIMER0_M    NORMAL

/* Timer0 Clock Options:

1- NO_CLOCK
2- CLK
3- CLK_8
4- CLK_64
5- CLK_256
6- CLK_1024
7- EXTERNAL_CLK_FALLING
8- EXTERNAL_CLK_RISING
*/
#define TIMER0_CLK    EXTERNAL_CLK_FALLING


/* TIMER0 PreLoad Value*/

#define PRELOAD_VALUE         220
#define OCR_VALUE_CTCMode     220

/* Timer1 Mode Options:

1- NORMAL
2- CTC
3- PWM
4- FAST_PWM
*/
#define TIMER2_M    NORMAL

/* Timer0 Clock Options:


1- NO_CLOCK
2- CLK
3- CLK_8
4- CLK_32
5- CLK_64
6- CLK_128
7- CLK_256
8- CLK_1024

*/
#define TIMER2_CLK    CLK_256






#endif
