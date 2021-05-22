/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   16/4/2021          */
/*********Version: 1                     */
/****************Desc: *******************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_




#define NORMAL      0
#define CTC         1
#define PWM         2
#define FAST_PWM    3

#define TIMER0  0
#define TIMER1  1
#define TIMER2  2

#define NO_CLOCK                0
#define CLK                     1
#define CLK_8                   2
#define CLK_64                  3
#define CLK_256                 4
#define CLK_1024                5
#define EXTERNAL_CLK_FALLING    6
#define EXTERNAL_CLK_RISING     7
#define CLK_128                 8
#define CLK_32                  9


void TM_voidTimerInit(void);
void TM_VoidPrealoadOverFlow(void);





#endif