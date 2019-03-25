/*
 * main.c
 *
 *  Created on: Apr 18, 2018
 *      Author: AbuElkasem
 */


#include<avr/io.h>
#include<util/delay.h>
int main(void){
	int x=0,y=0;
	DDRD|=(1<<6);
	PORTD=0x00;
	while(1) {
		x=PIND &(1<<2);
		y=PIND &(1<<3);
		if(x) PORTD|=(0<<6);

		if(y) PORTD|=(1<<6);

	}

}
