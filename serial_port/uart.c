/****************************************************************************
UART INITIALIZATION

This Program enables you to send data from the ATmega32 serial port to
the PC so that the data can be read on hyperterminal. This is very
useful for debugging purposes when the development system has no
display of its own.

To send data through the UART printf() is used.

uart.c and uart.h must be included in the main project, and the function
uart_init() called to enable serial port output.

In order to print floating point values, you will need to add the line 
"-Wl,-u,vfprintf -lprintf_flt -lm" to AVR Studio4 linker options by going to 
Project->Configuration Options->Custom Options 

Read the "Detailed Description" section of 
http://www.nongnu.org/avr-libc/user-manual/group__avr__stdio.html for 
more detail. 

*******************************************************************************/
#include <avr/io.h> 
#include <avr/interrupt.h> 
#include <stdio.h> 
#include "uart.h" 

int put_uart_char(char c, FILE *fd) 
{
  while (!(UCSRA & _BV(UDRE)));  //Wait for transmit buffer to become empty. 
  UDR = c; //Write the character to the UART. 
  return 0; 
}

void uart_init(void) 
{
  //UART Init 
  UCSRB  |=  _BV(TXEN)  |  _BV(RXEN)  |  _BV(RXCIE);  //Enable  Transmit,  Receive, Receive Interrupt 
  UCSRC |= _BV(UCSZ1) | _BV(UCSZ0); //8 bit character size. 
  UBRRH = 0; 
  UBRRL = 51; //9600 baud for a 16MHz Clock.


  
  //Call fdevopen. This is what binds printf to put_uart_char. The first 
  //parameter is the address of our function that will output a single 
  //character, the second parameter is an optional parameter that is 
  //used for get functions, ie. receiving a character from the UART. 
  //This is the function that uses malloc. 
  
  fdevopen(&put_uart_char, NULL); 
  
  //Enable the interrupts globally. 
  
  SREG |= _BV(SREG_I); 
}
  
  
  
  
  
