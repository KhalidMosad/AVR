#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_Interface.h"
#include "Keypad_interface.h"
#include "App.h"
#include "avr/delay.h"


void main()
{
	u8 State;
	LCD_VidInit();

	Keypad_VoidInit();


	State = PasswordTrials();
	if(State== 0)
	{
		LCD_VidSendString("System Will Restart..");
		_delay_ms(500);
		main();
	}
	else
	{
		LCD_VidClear();
	}
	while(1)
	{




	}

}


