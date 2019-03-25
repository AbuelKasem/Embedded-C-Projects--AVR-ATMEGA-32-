/*
 * main.c
 *
 *  Created on: Apr 17, 2018
 *      Author: AbuElkasem
 */
#include<avr/io.h>
#include<util/delay.h>
#define GET(PORT, PIN) ((PORT & (1<<PIN)) !=0)
int main (void) {
	PORTD=0xF0;
	int Value =0 ;
	int  x=0;
	DDRD |= (1<<4);
	DDRD |= (1<<5);
	DDRD |= (1<<6);
	DDRD |= (1<<7);
	DDRD &= ~(1<<2);
	DDRD &= ~(1<<3);
while(1)
	{
		if(GET( PIND , 2))
		{
		//Value++;
			PORTD=PORTD | 0x10;
		_delay_ms (200);

		}
		if(GET( PIND , 3))
		{
		//Value--;
			PORTD=PORTD & 0x0F;
		_delay_ms (200);

		}
		//Value = (Value>=15)?(15):(Value);
		//Value = (Value<=0)?(0):(Value);
		//PORTD|=(Value<<4);
	}
}
