/*

 * WDT_Program.c
 *
 *  Created on: Dec 21, 2020
 *      Author: Khaled
 */

#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include "WDT_private.h"
#include "WDT_interface.h"

void WDT_Enable(void)
{


	// enable
	SET_BIT(WDTCR,3);

	// pre_scaler=1s
	SET_BIT(WDTCR,2);
	SET_BIT(WDTCR,1);
	CLR_BIT(WDTCR,0);

}

void WDT_Disable(void)
{

	WDTCR|=0b00011000;
	WDTCR=0;


}

