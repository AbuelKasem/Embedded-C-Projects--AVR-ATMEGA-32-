/*
 * PWM.c
 *
 *  Created on: Apr 21, 2018
 *      Author: AbuElkasem
 */

#include<avr/io.h>
void PWM_INIT(void){
	TCCR0 = (1<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<<CS02);    // fast pwm mode,non inverting out mode,256 prescaler
	TCNT0=0;     // INITIALIZE  TIMER0 RESULT TO 0
	OCR0=0;     // INITIALIZE COMPARE REG TO 0
	DDRB|=(1<<PB3); //OC0 SET AS OUTPUT AT PB3
}
void PWM_SET_DUTY_CYCLE(unsigned char DUTY_CYCLE) {

	OCR0=DUTY_CYCLE;
}
