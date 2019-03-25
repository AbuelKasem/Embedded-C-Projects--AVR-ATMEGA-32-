/*
 * main.c
 *
 *  Created on: Apr 20, 2018
 *      Author: AbuElkasem
 */

#include<avr/io.h>
#include<util/delay.h>
#include"ADC.h"
#include"DIO.h"
int main(void)
{
	DDRB=0x0F;
	SET_BIT(DDRC,PC4);
	SET_BIT(DDRC,PC5);
	CLEAR_BIT(PORTC,PC4);
	CLEAR_BIT(PORTC,PC5);
	SET_BIT(DDRC,PC3);
	SET_BIT(DDRC,PC2);
	CLEAR_BIT(PORTC,PC3);
	CLEAR_BIT(PORTC,PC2);
	long t_s=0;
	int var_ldr=0;
	int var_res=0;


	DDRD=0xF0;
	PORTD=0xf0;
	ADC_init();
	while(1) {

		t_s=ADC_read(1); // 0 TO 1023

		t_s*=5*100;
		t_s/=1023;
		PORTB=t_s/10;
		SET_BIT(PORTC,PC5);
		_delay_us(5);
		CLEAR_BIT(PORTC,PC5);
		PORTB=t_s%10;
		SET_BIT(PORTC,PC4);
		_delay_us(5);
		CLEAR_BIT(PORTC,PC4);
		//if(t_s>30) PORTD|=(1<<PD5);
		//else {PORTD&=~(1<<PD5); }
		_delay_us(5);
		var_ldr=ADC_read(5);
		if(var_ldr > 200)
					{
			PORTD=0xF0;    //If ADC value is above 200 turn led OFF
					}
					else {
						PORTD=0x00;   //Else turn led oN
						}
		/*_delay_us(5);
		var_res=ADC_read(2);
		var_res/=10;
		PORTB=var_res/10;
				SET_BIT(PORTC,PC2);
				_delay_us(5);
				CLEAR_BIT(PORTC,PC2);
				PORTB=var_res%10;
				SET_BIT(PORTC,PC3);
				_delay_us(5);
				CLEAR_BIT(PORTC,PC3);
				_delay_us(5);*/

	}
}





