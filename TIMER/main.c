/*
 * main.c
 *
 *  Created on: Apr 20, 2018
 *      Author: AbuElkasem
 */

#include<avr/io.h>
#include<util/delay.h>
#include"DIO.h"
#define LED PD4
#define LED2 PD5
int main(void)
{   int sec=0;
	uint8_t timerOverflowCount=0;
	DDRB=0x0F;
	SET_BIT(DDRC,PC4);
	SET_BIT(DDRC,PC5);
	CLEAR_BIT(PORTC,PC4);
	CLEAR_BIT(PORTC,PC5);

	DDRD=0xff;         //configure PORTD as output
	TCNT0=0x00;
	TCCR0 = (1<<CS00) | (1<<CS02);

		while(1)
		{
			 while ((TIFR & 0x01) == 0);
			  TCNT0 = 0x00;
			  TIFR=0x01; //clear timer1 overflow flag
			 timerOverflowCount++;

			 if (timerOverflowCount>=62)
			 {   sec++;
			 sec=(sec>99)?99:sec;


				 PORTD ^= (0x01 << LED);
				 timerOverflowCount=0;
			 }
			 PORTB=sec/10;
						 			 		 SET_BIT(PORTC,PC5);
						 			 		 _delay_us(5);
						 			 		 CLEAR_BIT(PORTC,PC5);
						 			 		PORTB=sec%10;
						 			 		 SET_BIT(PORTC,PC4);
						 			 		 _delay_us(5);
						 			 		 CLEAR_BIT(PORTC,PC4);


		}

	}






