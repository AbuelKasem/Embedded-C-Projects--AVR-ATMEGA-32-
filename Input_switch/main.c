/*
 * main.c

 *
 *  Created on: Apr 16, 2018
 *      Author: AbuElkasem
 */

#include<avr/io.h>
#include<util/delay.h>
#define GET(PORT, PIN) ((PORT & (1<<PIN)) !=0)
int main (void) {
	int Value =0 ;
	DDRD = 0xC0;
	DDRB = 0xFF;
	DDRC = 0x0F;
	PORTC = 0x0F;

	while(1)
	{
	if(GET( PIND , 2))
	{
	Value++;
	_delay_ms (200);
	}
	if(GET( PIND , 3))
	{
	Value--;
	_delay_ms (200);
	}
	Value = (Value>=9)?(9):(Value);
	Value = (Value<=0)?(0):(Value);
	PORTB = Value;
	}


}
