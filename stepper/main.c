/*
 * main.c
 *
 *  Created on: 28 Jul 2018
 *      Author: dell
 */


#include <avr/io.h>
#include "util/delay.h"


#define	stepPin PD7            //Define Step pin
#define dirPin PD6             //Define Direction pin
#define Enable PD5              //Define Enable pin


int main(void)
{
    int x,y;
    DDRD |= (1<<5)|(1<<6)|(1<<7);     // Configure PORTD5, PORTD6, PORTD7 as output
    PORTD &= ~(1<<5);                 // Enable driver

    while (1)
    {
	  	PORTD |= (1<<6);                //Make PORTD6 high to rotate motor in clockwise direction

	  	for(x=0; x<4; x++)              //Give 50 pulses to rotate stepper motor by 90 degree's in full step mode
	  	{
		    for(y=0; y<7; y++)
		    {
		      PORTD |=(1<<7);
		      _delay_us(700);
		      PORTD &=~(1<<7);
		      _delay_us(700);
		    }
		      _delay_ms(2000);
		  }

		  PORTD &= ~(1<<6);              //Make PORTD6 high to rotate motor in anti-clockwise direction

		  for(x=0; x<4; x++)             //Give 50 pulses to rotate stepper motor by 90 degree's in full step mode
		 {
		      for(y=0; y<7; y++)
		      {
	              PORTD |=(1<<7);
	              _delay_us(700);
		      PORTD &=~(1<<7);
		      _delay_us(700);
		      }
		      _delay_ms(2000);
	          }
    }
}
