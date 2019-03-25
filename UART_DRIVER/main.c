/*
 * main.c
 *
 *  Created on: May 5, 2018
 *      Author: AbuElkasem
 */


#include<avr/io.h>
#include<util/delay.h>
#include"UART_DR.h"



int main(void){
	char data=0;

	DDRD|=(1<<PD5);
	PORTD&=~(1<<PD5);
	UART_INIT(9600);
	_delay_ms(100);
	//UART_SEND_BYTE('X');
	//UART_SEND_STRING("ENTER F OR B");


	while(1){
		//UART_SEND_STRING("ENTER F OR B");
		data=UART_RECIEVE_BYTE();
		if(data=='F')
		{
			PORTD|=(1<<PD5);
		//	UART_SEND_STRING("LED on");
		}
		else if(data=='B')
				{
					PORTD&=~(1<<PD5);
				//	UART_SEND_STRING("LED off");

				}
		else PORTD|=(1<<PD5);
	}

}
