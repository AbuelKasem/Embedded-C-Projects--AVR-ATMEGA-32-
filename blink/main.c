/*
 * vvvv.c
 *
 *  Created on: Apr 2, 2018
 *      Author: AbuElkasem
 */


#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRD = 0xF0;


    while(1) {




    	PORTD=0xF0;


_delay_ms(1000);


PORTD=0x00;


_delay_ms(1000);

    }
    return 0;
}
