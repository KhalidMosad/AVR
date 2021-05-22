/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   21/1/2021          */
/*********Version: 2                     */
/****************Desc: *******************/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#define	F_4				0
#define	F_16			1
#define	F_64			2
#define	F_128			3
#define	F_2				4
#define	F_8				5
#define	F_32			6
#define	F_64D  			8

#define	LEADING_RISING	0
#define	LEADING_FALLING	1

#define	LEADING_SAMPLE	0
#define	LEADING_SETUP	1

#define	MASTER			0
#define	SLAVE			1

#define	LSB_FIRST		0
#define	MSB_FIRST		1

#define	INT_ENABLE		0
#define	INT_DISABLE		1

void SPI_VoidInit(void);
u8 SPI_u8Send(u8 data);
u8 SPI_u8Receive(void);
void GIE_voidEnable(void);
void GIE_voidDisable(void);

#endif 
