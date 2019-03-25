/*
 * timer2_normal.c
 *
 *  Created on: Apr 28, 2018
 *      Author: AbuElkasem
 */
#include<avr/io.h>
#include "timer2_normal.h"

void timer2_normal_init(void){

    // normal mode FOC2=1,WGM21,WGM20 =0,COM21,COM20=0,CS22:0: Clock Select;
	TCCR2=(1<<FOC2);
	TCNT2=0; // set timer counter2 reg to 0
	//OCR2=0;  // set timer counter2 compare reg to 0


}
void timer2_normal_start(void){
	TCCR2=(1<<FOC2)|(1<<CS22)|(1<<CS21)|(1<<CS20); // 1024 prescaler 8000000/1024=7812.5 hz, t= 0.000128 s=128us

}

void timer2_normal_stop(void){
	TCCR2=(1<<FOC2);   // TCCR2=TCCR2& 0b1111 1000;
}

unsigned char timer2_read(void)
{
	return TCNT2;

}


void  Timer2_clear(void)
 	 {
	 TCNT2=0;
 	 }
