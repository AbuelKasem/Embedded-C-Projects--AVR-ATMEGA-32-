/*
 * COUNTER0.h
 *
 *  Created on: Apr 25, 2018
 *      Author: AbuElkasem
 */

#ifndef COUNTER0_H_
#define COUNTER0_H_
void counter_init(void);
void counter_SV_set(unsigned char set_value);
unsigned char counter_PV_read(void);


#endif /* COUNTER0_H_ */
