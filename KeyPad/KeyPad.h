/*
 * KeyPad.h
 *
 *  Created on: May 1, 2018
 *      Author: AbuElkasem
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#define KEYPAD_DDR  DDRA
#define KEYPAD_PORT PORTA
#define KEYPAD_PIN  PINA

#define KEYPAD_C0  PA7
#define KEYPAD_C1  PA6
#define KEYPAD_C2  PA5
#define KEYPAD_R0  PA4
#define KEYPAD_R1  PA3
#define KEYPAD_R2  PA2

void KEYPAD_init(void);
unsigned char KEYPAD_Get_Key(void);

#endif /* KEYPAD_H_ */
