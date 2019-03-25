/*
 * PWM_T2.c
 *
 *  Created on: Apr 22, 2018
 *      Author: AbuElkasem
 */


#include<avr/io.h>
void PWM_T2_INIT(void) {
	/* TCCR2  timer counter 2 control register / 1<<WGM20)|(1<<WGM21) (wave generator)
	 * set fast pwm mode / (1<<COM21) Compare Match Output Mode set non-inverting mode on pin OC2
	 * (1<<CS20)|(1<<CS21) (clk/32) clock & pre-scaler select
	 */
	TCCR2=(1<<WGM20)|(1<<WGM21)|(1<<COM21)|(1<<CS21);
	TCNT2=0;                      // timer counter 2 current value reg  set to 0 to initilize
	DDRD|=(1<<PD7);               // SET PD7 AS output  OC2 pin


}
void PWM_T2_SET_DUTY_CYCLE(unsigned char Duty_cylce2){

	OCR2=Duty_cylce2;

}
