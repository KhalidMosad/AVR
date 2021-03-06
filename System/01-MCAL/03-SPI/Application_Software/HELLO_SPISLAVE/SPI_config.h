/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   20/1/2021          */
/*********Version: 2                     */
/****************Desc: *******************/

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/* CLOCK RATE SELECT OPTIONS
F_4
F_16
F_64
F_128
F_2
F_8
F_32
F_64D

*/
#define CLOCK_RATE	F_16

/* CLOCK POLARITY OPTIONS

LEADING_RISING
LEADING_FALLING

*/

#define CLOCK_POLARITY	LEADING_RISING
 
 
/* CLOCK PHASE OPTIONS

LEADING_SAMPLE
LEADING_SETUP

*/ 
#define CLOCK_PHASE	LEADING_SETUP

/* Mode Options 
MASTER
SLAVE
*/
#define MODE	SLAVE

/* DATA TRANSFER OPTIONS:

LSB_FIRST
MSB_FIRST
*/
#define	DATA	LSB_FIRST

#endif
