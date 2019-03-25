/*
 * main.c
 *
 *  Created on: Apr 25, 2018
 *      Author: AbuElkasem
 */

#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#include"COUNTER0.h"
#include"DIO.h"
ISR(TIMER0_COMP_vect){
	PORTD&=~(1<<PD5);
	_delay_ms(250);
	PORTD|=(1<<PD5);


}

int main(void){
	DDRD=0xF0;
	PORTD=0XF0;
	CLEAR_BIT(DDRB,PB0);
	counter_init();
	counter_SV_set(20);
	sei();
	//int cnt=0;

	//cnt=counter_PV_read();
	while(1){

		PORTD^=(1<<PD7);
		_delay_ms(100);

}
}
