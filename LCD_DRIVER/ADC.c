/*
 * ADC.c
 *
 *  Created on: Apr 20, 2018
 *      Author: AbuElkasem
 */

#include<avr/io.h>
 // initialize ADC
    void ADC_init(void) {

	ADMUX=(1<<REFS0);
	ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1);
                          }
// select & read channel
   int ADC_read(unsigned char ch) {
	   /* select channel */
	   ch &= 0x07; // filter input argument
	   ADMUX &=0xE0; // initialize bit0 to bit5 to 0 (MUX0...MUX4
	   ADMUX |=ch;
	   ADCSRA |= (1<<ADSC);
      /* read result */
	   while (ADCSRA & (1<<ADSC));
	   return ADC;


   }

