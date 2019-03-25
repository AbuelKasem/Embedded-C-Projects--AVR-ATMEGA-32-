/*****************************************************************************
Author: Peter J. Vis
Title: Testing UART Interface

Microcontroller: ATmega32
Crystal: 		 16Mhz
Platform:        Development System

LIMITATIONS:
No part of this work may be used in commercial
applications without prior written permission. This work cannot be
used by Bloggers, or any kind of on-line publishing.

COPYRIGHT:	
All the materials including function names are copyright protected.

Documentation:
Further information regarding this code is available on my site:
http://petervis.com

PURPOSE:
To test the UART Interface communication to a PC by sending characters to the 
Windows HyperTerminal.

CIRCUIT:
UART PC Communication Interface with a MAX232 chip.
*******************************************************************************/


#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "uart.c"

int main()
{
  // Initialise UART. This function is in an external file uart.c
  // and is needed to make printf work. It sends characters to HyperTerminal.
  uart_init();

 
  // Initialise HyperTerminal by sending VT100 Escape Sequences.
  printf("\x1B[2J\x1B\x63");
 
  // Print a welcome message.
  printf("Hello...would you like to play a game? \r\n");
}
