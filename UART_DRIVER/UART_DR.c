/*
 * UART_DR.c
 *
 *  Created on: May 5, 2018
 *      Author: AbuElkasem
 */
#include<avr/io.h>

#include"UART_DR.h"



void UART_INIT(long BaudRate){

  // USART Control and Status Register B recv enable and trans enable

	UCSRB=(1<<RXEN)|(1<<TXEN);

	// async mode,disable parity, one stop bit, 8 bit data mode

	UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<< UCSZ0);

	// baudrate setting

	UBRRL=51;
			//(unsigned char) (((F_OSC)/ (16UL*BaudRate))-1); // low baud


	//UBRRH=(((F_CPU)/ (16UL*BaudRate))-1)>>8; // high byte if >255
}


void UART_SEND_BYTE(char Byte){

	  // wait until buffer empty flag become one  to be empty
	while( !( UCSRA&(1<<UDRE)));

	// load byte to be sent in udr uart data register

	UDR=Byte;

}

void UART_SEND_STRING(char *String){

	int i=0;
	while(String[i]!='\0'){
	UART_SEND_BYTE(String[i]);
	i++;
	}

}


char UART_RECIEVE_BYTE(void){

	while( !( UCSRA&(1<<RXC)));
	return UDR;


}


void UART_RECIEVE_STRING(char* string){

	int i=0;

	do{
	string[i]=UART_RECIEVE_BYTE();

}while(string[i++] !='\0');

}
