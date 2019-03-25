/*
 * main.c
 *
 *  Created on: Apr 2, 2018
 *      Author: AbuElkasem
 */


#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRD = 0xF0;
   for(;;) {
    	PORTD=0x00;
    	_delay_ms(20);
    	PORTD=0x30;
    	_delay_ms(20);
    	PORTD=0x70;
    	_delay_ms(20);
    	  PORTD=0xF0;
    	  _delay_ms(20);
    	    PORTD=0x70;
    	    _delay_ms(20);
    	       PORTD=0x30;
    	       _delay_ms(20);
    	           PORTD=0x10;
    	           _delay_ms(20);
   }





    return 0;
}
