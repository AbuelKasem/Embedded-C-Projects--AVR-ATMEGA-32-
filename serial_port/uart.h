/****************************************************************************
UART INITIALIZATION

This Program enables you to send data from the ATmega32 Serial port to
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
#ifndef UART_H 
#define UART_H 
#include <avr/io.h> 
#include <avr/interrupt.h> 
#include <stdio.h> 

int put_uart_char(char c, FILE *fd); 

//No need to call this function directly, it's just here for printf(). 
//Outputs a single character to the UART when the transmit buffer is empty. 
//This is the function that we bind to printf so it can output the string 
//that printf generates. The FILE parameter is required by printf for behind- 
//the-scenes bookkeeping. *Note that we can write a function that will put a 
//single char anywhere we want -- parallel interface, SPI, I2C, etc.* 

void uart_init(void); 

//Set up the registers that control the UART and bind put_uart_char 
//as our output function. 

#endif