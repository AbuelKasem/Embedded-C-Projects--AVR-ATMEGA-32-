
/*
 * main.c
 *
 *  Created on: May 19, 2018
 *      Author: AbuElkasem
 */


#include<avr/io.h>
#include<util/delay.h>
#include"PLATFORM_TYPES.h"
#include"eeprom.h"
#include"KeyPad.h"
#include"LCD_MA.h"



int main(){

	unsigned char x=0,z=0;
	uint8 y;
	//y=&z;

	KEYPAD_init();
	LCD_INIT();
	LCD_SEND_string_4bit("enter number");
	while(1){
		x=KEYPAD_Get_Key();
		LCD_set_cursor_4bit(1,1);
		LCD_SEND_CHAR_4bit(x);
		eeprom_byte_write(0x0f,x);
		LCD_set_cursor_4bit(1,6);
		eeprom_byte_read(0x0f,&y);
		LCD_SEND_CHAR_4bit(y);




	}





}
