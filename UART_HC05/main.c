/*
 * main.c
 *
 *  Created on: May 5, 2018
 *      Author: AbuElkasem
 */


#include<avr/io.h>
#include<util/delay.h>
#include "UART.h"
#include"LCD_MA.h"


int main(void){
	char data=0;
char y[10]={'h','e'};
	DDRD|=(1<<PD6);
	PORTD&=~(1<<PD6);
	Uart_init(38400);
	_delay_ms(100);
	//UART_send_byte('7');
	LCD_INIT();
	LCD_send_string_row_column_4bit(0,2,"UART RECIEVED");
	UART_send_string(y);
 char arr[15];
 //LCD_send_string_row_column_4bit(1,1,arr);

	while(1){

		UART_recieve_string(arr);
	//	Uart_Recieve_String(arr);
		//_delay_ms(50);
			LCD_send_string_row_column_4bit(1,1,arr);
			//_delay_ms(100);
		//	UART_send_string("ENTER F OR B");
				//LCD_set_cursor_4bit(1,3);
					//	LCD_SEND_CHAR_4bit(ar);

		//UART_send_string("ENTER F OR B");
			_delay_ms(100);
	data= UART_recieve_byte();
			_delay_ms(100);

		if(data=='F')
		{LCD_set_cursor_4bit(1,1);
		LCD_SEND_CHAR_4bit(data);
			PORTD|=(1<<PD6);
			LCD_set_cursor_4bit(1,3);
					LCD_SEND_CHAR_4bit(data);
			//UART_send_byte('N');
			//UART_send_string("LED on");
		}
		else if(data=='B')
				{   LCD_set_cursor_4bit(1,2);
				LCD_SEND_CHAR_4bit(data);
					PORTD&=~(1<<PD6);
					LCD_set_cursor_4bit(1,3);
										LCD_SEND_CHAR_4bit(data);
					//UART_send_byte('F');
				//	UART_send_string("LED off");

				}

		//else PORTD|=(1<<PD6);
		//LCD_CLEAR();
	}

}
