/*
 * UART_MA.c
 *
 *  Created on: May 16, 2018
 *      Author: AbuElkasem
 */

#include<avr/io.h>
#include"UART_MA_Interrupt.h"
#include<avr/interrupt.h>
#define F_OSC 8000000UL


void Uart_Init(long BaudRate){

	// init uart registers

	//USART Control and Status Register B,enabel RX,TX,enable recieve interrupt

	//UCSRB=(1<<RXEN)|(1<<TXEN)|(1<<RXCIE);
	UCSRB=(1<<RXEN)|(1<<TXEN)|(1<<UDRIE);

	// async mode,disable parity, one stop bit, 8 bit data mode

		UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<< UCSZ0);

		// baudrate setting

		//UBRRL=51;
		UBRRL=	(unsigned char) (((F_OSC)/ (16UL*BaudRate))-1); // low baud


		UBRRH=(((F_OSC)/ (16UL*BaudRate))-1)>>8; // high byte if >255


		sei(); // enable global interrupt

}
/*
void UART_Config(unsigned long int baud,unsigned int data_bits,char parity,unsigned int stop_bits){

	//USART Control and Status Register C,URSEL: Register Select

	UCSRC=(1<<URSEL);

	//UPM1:0: Parity Mode

	switch(parity){
	case 'N':   UCSRC=(UCSRC&(~(1<<UPM0)&~(1<<UPM1)))|(1<<URSEL);
	break;
	case 'E':   UCSRC=(UCSRC&(~(1<<UPM0)))|(1<<UPM1)|(1<<URSEL);
				//UCSRC=(1<<UPM1);
	break;
	case 'O':   UCSRC=UCSRC|(1<<UPM0)|(1<<UPM1)|(1<<URSEL);
	break;
	default: UCSRC=(UCSRC&(~(1<<UPM0)&~(1<<UPM1)))|(1<<URSEL);
	}

	//USBS: Stop Bit Select
	switch(stop_bits){
	case 1:   UCSRC=UCSRC&(~(1<<USBS));
	break;
	case 2:   UCSRC=UCSRC|(1<<USBS);
	break;
	default:UCSRC=UCSRC&(~(1<<USBS));
	}

	//Bit 2:1 – UCSZ1:0: Character Size
	switch(data_bits){
	case 5:  	 UCSRC=UCSRC&(~(1<<UCSZ0)&~(1<<UCSZ1));
	break;
	case 6:  	 UCSRC&=(UCSRC|(1<<UCSZ0))&(~(1<<UCSZ1));
				// UCSRC|=(1<<UCSZ0);
	break;
	case 7:   	 UCSRC&=(UCSRC|(1<<UCSZ1))&(~(1<<UCSZ0));

	break;
	case 8:   	 UCSRC=UCSRC|(1<<UCSZ0)|(1<<UCSZ1);
	break;
	default: UCSRC=UCSRC|(1<<UCSZ0)|(1<<UCSZ1);
	}


	//USART Baud Rate	Registers – UBRRL and UBRRH
	//Bit 15 – URSEL: Register Select UBRRH
	UBRRH&=~(1<<UBRRH);

	switch(baud){
		case 9600:  	 UBRRL=51;
		break;
		case 19200:  	 UBRRL=25;
		break;
		case 38400:  	 UBRRL=12;
		break;
		case 57600:  	 UBRRL=8;
		break;
		case 115200:  	 UBRRL=3;
		break;
		default: UBRRL=51;


		}

}

*/
void Uart_Transmit_char(unsigned char data){
	while(! ( UCSRA & (1<<UDRE) ) );
	UDR=data;
}

void UART_Transmit_STRING(char *String){

	int i;
	for(i=0;String[i]!='\0';i++)
		Uart_Transmit_char(String[i]);

}


unsigned char  Uart_Recieve_char(void){

	while(! ( UCSRA & (1<<RXC) ) );
	return UDR;

}


void  Uart_Recieve_String(char *String){

	int i=0;
	do{
		String[i]=Uart_Recieve_char();

	}
	while(String[i++]!='\0');





}
