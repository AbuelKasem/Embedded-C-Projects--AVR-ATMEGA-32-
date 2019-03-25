/*
 * ultrasonic_HCSR04.h
 *
 *  Created on: Apr 28, 2018
 *      Author: AbuElkasem
 */
#include "PLATFORM_TYPES.h"
#ifndef ULTRASONIC_HCSR04_H_
#define ULTRASONIC_HCSR04_H_


#define ultrasonic_trig_ddr  DDRD
#define ultrasonic_trig_PORT PORTD
#define ultrasonic_trig_PIN  PD6
#define ultrasonic_ECHO_ddr  DDRD
#define ultrasonic_ECHO_PINX PIND
#define ultrasonic_ECHO_PIN  PD7


void ultrasonic_init(void);
uint16 ultrasonic_read(void);

#endif /* ULTRASONIC_HCSR04_H_ */
