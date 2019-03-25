/*
 * main.c
 *
 *  Created on: Apr 19, 2018
 *      Author: AbuElkasem
 */


#include<avr/io.h>
#include<util/delay.h>
int main(void){

	DDRD|=0xF0;
	PORTD|=0xF0;

	while(1){
		PORTD=PORTD^0xF0;
		_delay_ms(250);
	}


}
