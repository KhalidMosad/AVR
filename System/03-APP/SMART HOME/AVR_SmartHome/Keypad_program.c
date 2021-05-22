/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   9/4/2021          */
/*********Version: 2                     */
/****************Desc: *******************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"Keypad_interface.h"
#include"Keypad_config.h"
#include"Keypad_private.h"
//#include <avr/io.h>
#include<avr/delay.h>

//#define KEY_PRT 	PORTB
//#define KEY_DDR		DDRB
//#define KEY_PIN		PINB

#define		ROWSHIFT	4

static u8 array_keypad[4][4]={	{'7','8','9','/'},
								{'4','5','6','*'},
								{'1','2','3','-'},
								{'Q','0','=','+'}};

void Keypad_VoidInit(void)
{
	
	DIO_VidSetPinDirection(COLS_ROWSPORT,COLS0,OUTPUT);
	DIO_VidSetPinDirection(COLS_ROWSPORT,COLS1,OUTPUT);
	DIO_VidSetPinDirection(COLS_ROWSPORT,COLS2,OUTPUT);
	DIO_VidSetPinDirection(COLS_ROWSPORT,COLS3,OUTPUT);

	DIO_VidSetPinDirection(COLS_ROWSPORT,ROW0,INPUT);
	DIO_VidSetPinDirection(COLS_ROWSPORT,ROW1,INPUT);
	DIO_VidSetPinDirection(COLS_ROWSPORT,ROW2,INPUT);
	DIO_VidSetPinDirection(COLS_ROWSPORT,ROW3,INPUT);
	DIO_VidSetPinValue(COLS_ROWSPORT,ROW0 ,HIGH);
	DIO_VidSetPinValue(COLS_ROWSPORT,ROW1 ,HIGH);
	DIO_VidSetPinValue(COLS_ROWSPORT,ROW2 ,HIGH);
  	DIO_VidSetPinValue(COLS_ROWSPORT,ROW3 ,HIGH);

	DIO_VidSetPinValue(COLS_ROWSPORT,COLS0,HIGH);
	DIO_VidSetPinValue(COLS_ROWSPORT,COLS1,HIGH);
	DIO_VidSetPinValue(COLS_ROWSPORT,COLS2,HIGH);
  	DIO_VidSetPinValue(COLS_ROWSPORT,COLS3,HIGH);


}

u8 Keypad_U8ReadPin(void)
{

	DIO_VidSetPinValue(COLS_ROWSPORT,ROW0 ,HIGH);
	DIO_VidSetPinValue(COLS_ROWSPORT,ROW1 ,HIGH);
	DIO_VidSetPinValue(COLS_ROWSPORT,ROW2 ,HIGH);
  	DIO_VidSetPinValue(COLS_ROWSPORT,ROW3 ,HIGH);

	u8 pressdkey=DEFAULT_KEY;
	u8 col=0,row=0;

	for(row=0;row<=3;row++)
	{
		DIO_VidSetPinValue(COLS_ROWSPORT,row,LOW);

		for(col=0;col<=3;col++)
		{
			if(DIO_VidGetPinValue(COLS_ROWSPORT,col+ROWSHIFT)==0)
			{
				pressdkey=	array_keypad[row][col];
				while(DIO_VidGetPinValue(COLS_ROWSPORT,col+ROWSHIFT)==0);
				_delay_ms(10);
			}
		}
		DIO_VidSetPinValue(COLS_ROWSPORT,row,HIGH);
	}

return pressdkey;
	
}

u8 Keypad_U8ReadPin1(void)
{
	u8 row, pressdkey=0;
	DIO_VidSetPinValue(COLS_ROWSPORT,COLS0,LOW);
	DIO_VidSetPinValue(COLS_ROWSPORT,COLS1,HIGH);
	DIO_VidSetPinValue(COLS_ROWSPORT,COLS2,HIGH);
  	DIO_VidSetPinValue(COLS_ROWSPORT,COLS3,HIGH);
	for(row=4;row<=7;row++)
	{
		if(DIO_VidGetPinValue(COLS_ROWSPORT,row)==0)
		{
			pressdkey=	array_keypad[row][COLS0];
		}
		while(DIO_VidGetPinValue(COLS_ROWSPORT,row)==0);
		_delay_ms(5);
	}
	DIO_VidSetPinValue(COLS_ROWSPORT,COLS0,HIGH);
	DIO_VidSetPinValue(COLS_ROWSPORT,COLS1,LOW );
	DIO_VidSetPinValue(COLS_ROWSPORT,COLS2,HIGH);
  	DIO_VidSetPinValue(COLS_ROWSPORT,COLS3,HIGH);
	for(row=4;row<=7;row++)
	{
		if(DIO_VidGetPinValue(COLS_ROWSPORT,row)==0)
		{
			pressdkey=	array_keypad[row][COLS1];
		}
		while(DIO_VidGetPinValue(COLS_ROWSPORT,row)==0);
		_delay_ms(5);
	}
	DIO_VidSetPinValue(COLS_ROWSPORT,COLS0,HIGH);
	DIO_VidSetPinValue(COLS_ROWSPORT,COLS1,HIGH);
	DIO_VidSetPinValue(COLS_ROWSPORT,COLS2,LOW );
  	DIO_VidSetPinValue(COLS_ROWSPORT,COLS3,HIGH);
	for(row=4;row<=7;row++)
	{
		if(DIO_VidGetPinValue(COLS_ROWSPORT,row)==0)
		{
			pressdkey=	array_keypad[row][COLS2];
		}
		while(DIO_VidGetPinValue(COLS_ROWSPORT,row)==0);
		_delay_ms(5);
	}
	DIO_VidSetPinValue(COLS_ROWSPORT,COLS0,HIGH);
	DIO_VidSetPinValue(COLS_ROWSPORT,COLS1,HIGH);
	DIO_VidSetPinValue(COLS_ROWSPORT,COLS2,HIGH);
  	DIO_VidSetPinValue(COLS_ROWSPORT,COLS3,LOW );
	for(row=4;row<=7;row++)
	{
		if(DIO_VidGetPinValue(COLS_ROWSPORT,row)==0)
		{
			pressdkey=	array_keypad[row][COLS3];
		}
		while(DIO_VidGetPinValue(COLS_ROWSPORT,row)==0);
		_delay_ms(5);
	}

	return pressdkey;


}




unsigned char keypad[4][4] = {	{'7','8','9','/'},
					{'4','5','6','*'},
					{'1','2','3','-'},
					{' ','0','=','+'}};

unsigned char colloc, rowloc;
/*
char keyfind()
	{
		while(1)
		{
		    KEY_DDR = 0xF0;           //// set port direction as input-output
		    KEY_PRT = 0xFF;

		    do
		    {
			KEY_PRT &= 0x0F;      // mask PORT for column read only
			asm("NOP");
			colloc = (KEY_PIN & 0x0F); /// read status of column //
		    }while(colloc != 0x0F);

		    do
		    {
			do
			{
		            _delay_ms(20);             // 20ms key debounce time //
			    colloc = (KEY_PIN & 0x0F); // read status of column //
			}while(colloc == 0x0F);        // check for any key press //

			_delay_ms (40);	            // 20 ms key debounce time//
			colloc = (KEY_PIN & 0x0F);
		    }while(colloc == 0x0F);

		   /// now check for rows /
		    KEY_PRT = 0xEF;            /// check for pressed key in 1st row /
		    asm("NOP");
		    colloc = (KEY_PIN & 0x0F);
		    if(colloc != 0x0F)
	            {
			rowloc = 0;
			break;
		    }

		    KEY_PRT = 0xDF;		/// check for pressed key in 2nd row /
		    asm("NOP");
		    colloc = (KEY_PIN & 0x0F);
		    if(colloc != 0x0F)
		    {
			rowloc = 1;
			break;
		    }

		    KEY_PRT = 0xBF;		//* check for pressed key in 3rd row /
		    asm("NOP");
	            colloc = (KEY_PIN & 0x0F);
		    if(colloc != 0x0F)
		    {
			rowloc = 2;
			break;
		    }

		    KEY_PRT = 0x7F;		/// check for pressed key in 4th row /
		    asm("NOP");
		    colloc = (KEY_PIN & 0x0F);
		    if(colloc != 0x0F)
		    {
			rowloc = 3;
			break;
		    }
		}

		if(colloc == 0x0E)
		   return(keypad[rowloc][0]);
		else if(colloc == 0x0D)
		   return(keypad[rowloc][1]);
		else if(colloc == 0x0B)
		   return(keypad[rowloc][2]);
		else
		   return(keypad[rowloc][3]);
	}

*/



