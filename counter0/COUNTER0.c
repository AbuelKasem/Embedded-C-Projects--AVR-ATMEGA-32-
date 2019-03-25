/*
 * COUNTER0.c
 *
 *  Created on: Apr 25, 2018
 *      Author: AbuElkasem
 */

#include<avr/io.h>

	void counter_init(void){
	  // timer counter 0 control reg setting
	 //non-pwm mode(foc0=1) / ctc mode clear timer on compare (wgm01=1)
	 //source of clock when cs00 to sc02 all ones the clock source is pin t0 rising edge
	 TCCR0 = (1<<FOC0)|(1<<WGM01)|(1<<CS01)|(1<<CS02);//|(1<<CS00);

	 TCNT0 = 0;  // init timer counter0 register to 0 (Present value of counter)
	 OCR0 = 0;   // init output comare register to z (set value of counter)
	 TIMSK = (1<<OCIE0);    //Timer/Counter Interrupt Mask Reg ,enable counter compare match interrupt OCIE0


 }
	void counter_SV_set(unsigned char set_value) {
	 OCR0 = set_value; // output comare reg 0 set to set_value
 }

	unsigned char counter_PV_read(void){
		return TCNT0;
	}
