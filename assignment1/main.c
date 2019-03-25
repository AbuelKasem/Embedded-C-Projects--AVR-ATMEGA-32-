/*
 * main.c
 *
 *  Created on: Apr 20, 2018
 *      Author: AbuElkasem
 */

#include<avr/io.h>
#include<util/delay.h>
#include"DIO.h"

int main(){
int CNT=0;
	//SET_BIT(DDRD , PD5);
	//CLEAR_BIT(DDRD,PD2);  //PD 2 INPUT
	//CLEAR_BIT(DDRD,PD3);  //PD 3 INPUT
	DDRB=0x00;
	PORTD=0xF0;// PORTB 0,1,2,3 OUT
	//SET_BIT(DDRC,PC5);  // PORTC ,5 OUT
	DDRC=0x03F;
	//SET_BIT(PORTC,PC5); // ENABLE PC5 7SEG
	//SET_BIT(PORTC,PC4);
	//SET_BIT(PORTC,PC2);
	//SET_BIT(PORTC,PC3);
	//SET_BIT(DDRD,PD6);

	DDRD=0XF0;
	CNT=0;
	while(1)
	{
		if(READ_BIT_TRUE(PINB,PB0))
	{
		CNT++;
		if(CNT>=10) CLEAR_BIT(PORTD,PD6);
		_delay_ms(250);
	}
	 if(READ_BIT_TRUE(PIND,PD3)) {
			CNT--;
			if(CNT<=0) CNT=0;
			_delay_ms(250);
		}


		//PORTB=CNT;

	}


}
