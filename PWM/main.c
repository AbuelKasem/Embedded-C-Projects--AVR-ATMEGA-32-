/*
 * main.c
 *
 *  Created on: Apr 21, 2018
 *      Author: AbuElkasem
 */


#include<avr/io.h>
#include<util/delay.h>
#include"PWM.h"
int main(void) {
	PWM_INIT();
	while(1) {
		PWM_SET_DUTY_CYCLE(128);
		_delay_ms(500);
		PWM_SET_DUTY_CYCLE(64);
		_delay_ms(500);

	}
}
