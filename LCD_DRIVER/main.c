/*
 * main.c
 *
 *  Created on: Apr 30, 2018
 *      Author: AbuElkasem
 */

#include<avr/io.h>

#include"LCD_MA.h"
#include"KeyPad.h"
#include"ADC.h"
#include<util/delay.h>
#include<stdlib.h>
int main(void){
// unsigned char x=65;
	unsigned int i=0;

 ADC_init();

unsigned int t_s=0;
 char arr[10];
	LCD_INIT();
	LCD_SEND_COMMAND_4bit(B4_init);
		LCD_SEND_COMMAND_4bit(RT_HOME);
		LCD_SEND_COMMAND_4bit(DISP_init);
		LCD_CLEAR();
		LCD_SEND_CHAR_4bit(0xDF);
		//for(i=65;i<70;i++){
					//	LCD_SEND_CHAR_4bit(i);	}
		LCD_SEND_string_4bit( "TEMP IS ");
		LCD_SEND_string_4bit( " ");
		while(1){
			t_s=ADC_read(1); // 0 TO 1023

					t_s*=5*100;
					t_s/=1023;
					i=t_s;
					itoa(i,arr,10);
					//LCD_set_cursor_4bit(1,5);
					//LCD_SEND_COMMAND_4bit(0xC5);
					LCD_send_string_row_column_4bit( 0,9,arr);
					//LCD_SEND_string_4bit(arr);
					LCD_send_string_row_column_4bit( 1,0,"I love Embedded");
		}
		return 0;
}
