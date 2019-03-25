/*
 * main.c
 *
 *  Created on: Apr 21, 2018
 *      Author: AbuElkasem
 */


#include<avr/io.h>
#include<util/delay.h>
#include"Timer0.h"
#include<avr/interrupt.h>
ISR(TIMER0_OVF_vect) {
	static int cnt=0;

	cnt++;
	if(cnt>3921) {
		PORTD^=(1<<PD7);
		cnt=0;
	}
}



int main(void) {

	DDRD |=(1<<PD7)|(1<<PD6);
	DDRD &=~(1<<PD2);
	timer0_init();
	timer0_start();
while(1){
	if(PIND&(1<<PD2))
		PORTD&=(0<<PD6);
	else PORTD|=(1<<PD6);

}


}
