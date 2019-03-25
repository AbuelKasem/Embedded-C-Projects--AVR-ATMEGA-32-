/*
 * main.c
 *
 *  Created on: May 2, 2018
 *      Author: AbuElkasem
 */


#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
DDRD|=(1<<PD5);
    // Insert code

    while(1){
        PORTD^=(1<<PD5);
        _delay_ms(200);
    }


    return 0;
}
