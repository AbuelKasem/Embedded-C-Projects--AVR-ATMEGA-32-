/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: Faraday
 */

#include "ServiceLayer/std_types.h"
#include "HAL/EF_Keypad.h"
#include "HAL/EF_LCD.h"


int main ()
{
	U8_t u8KeyPressed;


	EF_void_KeyPad_Init();
	EF_void_LCD_init();
	EF_void_LCD_Clear_Screen();
	EF_void_LCD_goto(1,1);
	while(1)
	{
		u8KeyPressed = EF_u8_KeyPad_Scan();
		if(u8KeyPressed != 0)
		{
			EF_void_LCD_print_NUM(u8KeyPressed,1);
		}
	}
	return 0;
}
