/*
 * main.c
 *
 *  Created on: Jun 6, 2018
 *      Author: AbuElkasem
 */



#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include"UART_MA_Interrupt.h"
#include"LCD_MA.h"

//--------------------------------

#define BAUD 9600UL
#define MYUBRR  ((F_CPU/(16*BAUD))-1)

char* volatile txStr;
volatile unsigned char temp=0;
//(variable used both in ISR and main() or another ISR must be volatile)

//--------------------------------
ISR(USART_RXC_vect){


	temp=UDR;



}
void USART_init(void)
{
	// Definir Baud Rate
	UBRRH = (unsigned char) (MYUBRR >> 8);
	UBRRL = (unsigned char) MYUBRR;

	// Habilitar Receptor e Transmissor 8,0,1
	UCSRB = (1 << RXEN) | (1 << TXEN)|(1<<RXCIE);
}
//--------------------------------

void USART_transmit(char* str)
{
	txStr = str;
	UCSRB |= (1<<UDRIE); // enable UDRE interrupt
}

//--------------------------------

ISR(USART_UDRE_vect)
{
static uint8_t txIndex=0;

   UDR = txStr[txIndex];
	   txIndex += 1;

   if(txStr[txIndex] == 0) // end of string
   {
      txIndex = 0;
      UCSRB &= ~(1<<UDRIE); // disable UDRE interrupt
   }
}

//================================

int main(void)
{ DDRD|=(1<<PD4);
DDRD|=(1<<PD6);
LCD_INIT();
	OSCCAL=0x93;
   USART_init();
   sei();

   while(1)
   {


      _delay_ms(200);
      USART_transmit(" ");
      PORTD^=(1<<PD4);
      _delay_ms(100);

      LCD_set_cursor_4bit(1,0);
      	LCD_SEND_CHAR_4bit(temp);

      	if(temp=='F') {PORTD^=(1<<PD6);
      	USART_transmit("HELLO");

      	}
      	else  USART_transmit("no");
   }
}

