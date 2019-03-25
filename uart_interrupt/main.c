/*
 * main.c
 *
 *  Created on: Jun 2, 2018
 *      Author: AbuElkasem
 */


#include<avr/io.h>
#include<avr/interrupt.h>
#include"UART_MA_Interrupt.h"
#include"LCD_MA.h"
#include<util/delay.h>

static unsigned char temp=0;
static unsigned char data=0;
//char arr[10]={0};

ISR(USART_RXC_vect){


	temp=UDR;



}


int main(){
	DDRD&=~(1<<PD2);
	DDRD|=(1<<PD6);
	DDRD|=(1<<PD4);
	DDRD|=(1<<PD5);
	DDRD|=(1<<PD7);
		PORTD&=~(1<<PD6);
	Uart_Init(38400);
    LCD_INIT();
    LCD_send_string_row_column_4bit(0,2,"BLUETOOTH REC");
    char cnt=0;
while(1){


//	LCD_send_string_row_column_4bit(1,1,arr);



	LCD_set_cursor_4bit(1,0);
	LCD_SEND_CHAR_4bit(temp);

	if(temp=='F') {PORTD|=(1<<PD6);
	//_delay_ms(100);

	//data++;

	}

	else if(temp=='B') PORTD&=~(1<<PD6);
	else if(temp=='R') PORTD^=(1<<PD5);
	else if(temp=='L') PORTD^=(1<<PD7);
	else if(temp=='S'){
     data='T';
	UART_Transmit_STRING("HELLO");

	LCD_set_cursor_4bit(1,5);
	LCD_SEND_CHAR_4bit(data);}



	PORTD^=(1<<PD4);
	_delay_ms(100);

}





}
