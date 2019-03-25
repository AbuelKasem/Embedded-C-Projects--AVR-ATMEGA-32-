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
unsigned short CNT=0,n=0;
		unsigned short	m=0;
		int x=0,y=0;

	DDRB=0x0F;          // PORTB 0,1,2,3 OUT
	//SET_BIT(DDRC,PC5);  // PORTC ,5 OUT
	CLEAR_BIT(DDRD,PD2);  //PD 2 INPUT
	CLEAR_BIT(DDRD,PD3);  //PD 3 INPUT
	SET_BIT(DDRC,PC4);
	SET_BIT(DDRC,PC5);
	SET_BIT(DDRC,PC2);
	SET_BIT(DDRC,PC3);
	CLEAR_BIT(PORTC,PC4);
	CLEAR_BIT(PORTC,PC5);
	CLEAR_BIT(PORTC,PC2);
	CLEAR_BIT(PORTC,PC3);


	while(1)
	{
		if(READ_BIT_TRUE(PIND,PD2))
			{
				CNT++;
				if(CNT>99) CNT=99;
				_delay_ms(100);
			}
		if(READ_BIT_TRUE(PIND,PD3)) {
					CNT--;
					if(CNT<=0) CNT=0;
					_delay_ms(100);
				}
		n=CNT%10;
		m=CNT/10;
		x=CNT/100;
		PORTB=m;
		SET_BIT(PORTC,PC5);
		_delay_us(5);
		CLEAR_BIT(PORTC,PC5);
		PORTB=n;
		SET_BIT(PORTC,PC4);
		_delay_us(5);
		CLEAR_BIT(PORTC,PC4);
		//PORTB=x;
		//SET_BIT(PORTC,PC3);
		//_delay_us(5);
		//CLEAR_BIT(PORTC,PC3);
		//if(CNT>99) y=CNT%100;
		//PORTB=y;
		//SET_BIT(PORTC,PC3);
		//_delay_us(5);
		//CLEAR_BIT(PORTC,PC3);



	}


}
