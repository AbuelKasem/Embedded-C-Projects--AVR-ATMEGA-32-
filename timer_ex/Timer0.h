/*
 * timer.h
 *
 *  Created on: Apr 21, 2018
 *      Author: AbuElkasem
 */

#ifndef TIMER0_H_
#define TIMER0_H_

void timer0_init(void);
void timer0_start(void);
void timer0_stop(void);
unsigned char timer0_read(void);
void timer0_reset(void);

#endif /* TIMER0_H_ */
