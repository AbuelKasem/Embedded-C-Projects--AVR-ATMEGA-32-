/*
 * main.c
 *
 *  Created on: May 17, 2018
 *      Author: AbuElkasem
 */


#include<avr/io.h>
#include<util/delay.h>
#include"DIO.h"
#include"UART_MA.h"
#include"LCD_MA.h"

int main(){
	char Data=0;

	SET_BIT(DDRD,PD5);
	//SET_BIT(DDRD,PD7);
LCD_INIT();
LCD_CLEAR();
LCD_send_string_row_column_4bit(0,1,"ENTER");
	Uart_Init();
	//UART_Config(57600,8,'E',1);

	Uart_Transmit_char('W');
    while(1){

    	Data=Uart_Recieve_char();
    	LCD_set_cursor_4bit(1,3);
    	LCD_SEND_CHAR_4bit(Data );
    	LCD_SEND_CHAR_4bit(' ');
    	if(Data=='A') {SET_BIT(PORTD,PD5);
    	//Uart_Transmit_char('X');

    	}
    	else if(Data=='B') {CLEAR_BIT(PORTD,PD5);
    	//Uart_Transmit_char('Z');
    	LCD_SEND_CHAR_4bit(Data);
    	LCD_SEND_CHAR_4bit(' ' );
    	}
    }
	return 0;
}
