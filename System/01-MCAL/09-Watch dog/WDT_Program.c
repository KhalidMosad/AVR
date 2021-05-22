/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   20/4/2021          */

/*********Version: 2                     */
/****************Desc: *******************/

#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include "WDT_private.h"
#include "WDT_interface.h"

void WDT_Enable(void)
{

	// enable
	SET_BIT(WDTCR,WDE);
	
	#if   TIME_OUT== TIME_OUT_16_3MS
		CLR_BIT(WDTCR,WDP0);
		CLR_BIT(WDTCR,WDP1);
		CLR_BIT(WDTCR,WDP2);
	#elif TIME_OUT== TIME_OUT_32_5MS
		SET_BIT(WDTCR,WDP0);
		CLR_BIT(WDTCR,WDP1);
		CLR_BIT(WDTCR,WDP2);
	#elif TIME_OUT== TIME_OUT_65MS
		CLR_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		CLR_BIT(WDTCR,WDP2);
	#elif TIME_OUT== TIME_OUT_0_13S
		SET_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		CLR_BIT(WDTCR,WDP2);
	#elif TIME_OUT== TIME_OUT_0_26S
		CLR_BIT(WDTCR,WDP0);
		CLR_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);
	#elif TIME_OUT== TIME_OUT_0_52S
		SET_BIT(WDTCR,WDP0);
		CLR_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);
	#elif TIME_OUT== TIME_OUT_1S
		CLR_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);
	#elif TIME_OUT== TIME_OUT_2_1S
		SET_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);

	#endif

}

void WDT_Disable(void)
{

	WDTCR|=0b00011000;
	WDTCR=0;


}

