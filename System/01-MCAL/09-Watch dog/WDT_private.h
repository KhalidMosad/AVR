/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   20/4/2021          */

/*********Version: 2                     */
/****************Desc: *******************/
#ifndef WDT_PRIVATE_H_
#define WDT_PRIVATE_H_

#define	R0		7
#define	R1		6
#define	R2		5
#define	WDTOE	4
#define	WDE		3
#define	WDP2	2
#define	WDP1	1
#define	WDP0	0


#define WDTCR *((volatile u8*)0x41)

#endif /* WDT_PRIVATE_H_ */
