/*
 * ULTRASONIC.h
 *
 *  Created on: Jan 31, 2017
 *      Author: ahmed
 */

#ifndef HAL_ULTRASONIC_H_
#define HAL_ULTRASONIC_H_

#include "PLATFORM_TYPES.h"

#define DISTANCE (CM)


#define ULTRASONIC_TRIG_DDR  (DDRD)
#define ULTRASONIC_TRIG_PIN	 (PD6)
#define ULTRASONIC_TRIG_PORT  (PORTD)

#define ULTRASONIC_ECHO_DDR  (DDRD)
#define ULTRASONIC_ECHO_PIN	 (PD7)
#define ULTRASONIC_ECHO_PORT  (PIND)

extern void UltraSonic_init(void);
extern uint16 UltraSonic_read(void);


#endif /* HAL_ULTRASONIC_H_ */
