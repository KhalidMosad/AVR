/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   20/4/2021          */

/*********Version: 2                     */
/****************Desc: *******************/

#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_


#define	TIME_OUT_16_3MS		0
#define	TIME_OUT_32_5MS		1
#define	TIME_OUT_65MS		2
#define	TIME_OUT_0_13S		3
#define	TIME_OUT_0_26S		4
#define	TIME_OUT_0_52S		5
#define	TIME_OUT_1S			6
#define	TIME_OUT_2_1S		7

void WDT_Enable(void);
void WDT_Disable(void);

#endif /* WDT_INTERFACE_H_ */
