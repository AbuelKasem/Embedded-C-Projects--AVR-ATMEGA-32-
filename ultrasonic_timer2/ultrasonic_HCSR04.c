/*
 * ultrasonic_HCSR04.c
 *
 *  Created on: Apr 28, 2018
 *      Author: AbuElkasem
 */

#include<avr/io.h>
#include"ultrasonic_HCSR04.h"
#include"timer2_normal.h"
#include<util/delay.h>
#include"DIO.h"
#include "PLATFORM_TYPES.h"
void ultrasonic_init(void){
	SET_BIT(ultrasonic_trig_ddr,ultrasonic_trig_PIN);
	//ultrasonic_trig_ddr|=(1<<ultrasonic_trig_PIN); // SET TRIG PIN OUTPUT
	CLEAR_BIT(ultrasonic_ECHO_ddr,ultrasonic_ECHO_PIN);
	//ultrasonic_ECHO_ddr&=~(1<<ultrasonic_ECHO_PIN);  // SET ECHO PIN INPUT
	timer2_normal_init();                             // init timer


}

uint16 ultrasonic_read(void){
	double time=0;
	uint16 distance=0;
	// SENDING TRIG FOR 10us
	CLEAR_BIT(ultrasonic_trig_PORT,ultrasonic_trig_PIN);
	//ultrasonic_trig_PORT&=~(1<<ultrasonic_trig_PIN); // SET TRIG PIN TO OFF
	_delay_ms(5);
	SET_BIT(ultrasonic_trig_PORT,ultrasonic_trig_PIN);
		//ultrasonic_trig_PORT|=(1<<ultrasonic_trig_PIN); // high
		_delay_us(10);                                   // wait 10us
		CLEAR_BIT(ultrasonic_trig_PORT,ultrasonic_trig_PIN); // low

	// start timing

		while(BIT_CLEARED(ultrasonic_ECHO_PINX,ultrasonic_ECHO_PIN));
		timer2_normal_start(); // start timer when echo go high

		 while((BIT_SET(ultrasonic_ECHO_PINX,ultrasonic_ECHO_PIN))&& ((timer2_read())<250));      //loop as long as echo pin high
		 timer2_normal_stop(); // stop timer when echo pin go low

		time=timer2_read();   // time in us
		time=time*(0.017)*128;    //0.017=0.034 cm/us/2  sound speed one tick is 128 us ,prescaler 1024
		distance=(uint16)time;
		Timer2_clear();
		return distance;

}
