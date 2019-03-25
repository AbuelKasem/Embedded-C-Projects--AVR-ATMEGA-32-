/*
 * timer.c
 *
 *  Created on: Apr 21, 2018
 *      Author: AbuElkasem
 */


#include<avr/io.h>

void timer0_init(void){

	TCCR0 = (1<<FOC0); //  Force Output Compare set to 1 to enable non pwm mode
	TCNT0 = 0x00;  // timer 0 result reset
	TIMSK = (1<<TOIE0);  //  Timer/Counter0 Overflow Interrupt Enable set to 1
	SREG |=(1<<7);      // status register bit 7 global interrupt enable
}
    void timer0_start(void) {

    	TCCR0 |=(1<<CS01);  //Clock Select bits to enable prescaler & start timing/counting

    }
    void timer0_stop(void){
    	TCCR0 &=0xF8;
    }

    unsigned char timer0_read(void)
    {
    	return (TCNT0*1);
    }
    void timer0_reset(void){
    	TCNT0 = 0x00;  // timer 0 result reset
    }
