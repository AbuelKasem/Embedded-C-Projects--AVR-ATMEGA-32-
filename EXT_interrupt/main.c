/*
 * main.c
 *
 *  Created on: Apr 23, 2018
 *      Author: AbuElkasem
 */

#include<avr/io.h>
#include<stdlib.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include"LCD_MA.h"

 int cnt=0;
ISR(INT0_vect){
	_delay_ms(200);
	PORTD&=~(1<<PD7);
	_delay_ms(200);
	cnt=cnt+1;
}
int main(void){
	DDRD=0XF0;
	PORTD=0XF0;
	char arr[10];
	LCD_INIT();
	GICR=1<<INT0;
	MCUCR=1<<ISC00;
	sei();





	while(1) {
		PORTD^=(1<<PD6);
		_delay_ms(500);
		itoa(cnt,arr,10);
		LCD_send_string_row_column_4bit(0,2,arr);
		if(cnt>=8) PORTD&=~(1<<PD4);
		PORTD|=(1<<PD7);
	}

}


