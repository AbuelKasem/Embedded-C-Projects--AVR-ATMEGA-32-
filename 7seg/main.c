/*
 * main.c
 *
 *  Created on: Apr 19, 2018
 *      Author: AbuElkasem
 */

#include<avr/io.h>
#include<util/delay.h>
int main(void){

	DDRC|=0x3C; //portc pins 2,3,4,5 out
	DDRB|=0x0F; //portb 0,1,2,3 out
	PORTB|=0x00; // init portb
	DDRD|=0xEC;   //portd 2,3 inputs,5,6,7 out
	PORTC|=0x3C;  // portc 2,3,4,5 out high ,enable 4 segments
	PORTD|=0x00; // INIT PORTD

	 int x=0,y=0,C=0;

		while(1) {
			x=PIND&(1<<2);
			y=PIND&(1<<3);
	if(x) {
			PORTD|=(1<<5); // SET BUZZER
			PORTD|=(1<<6); // relay
			C++;
		_delay_ms(200);
	}

	 if(y){
		 	 PORTD &=(0<<5); // RESET BUZZER
		 	PORTD &=(0<<6);
		 	 C--;
		 	_delay_ms(200);
	 }

	    C=(C>=9)?9:C;
	 	C=(C<=0)?0:C;
PORTB=C;

}}

