/*
 * main.c
 *
 *  Created on: Apr 19, 2018
 *      Author: AbuElkasem
 */


#include<avr/io.h>
#include<util/delay.h>
int main(void){
	int n1=0,n2=0,n3=0,num=0;
	DDRA=0x1E; //PORTA 2,3,4 OUT ,5,6,7 IN
	PORTA=0x00; // porta 2,3,4 low ,5,6,7 in;
	DDRB|=0x0F;  // PORTB OUT
	DDRC|=0x3C;
	PORTB=0x00;
	PORTC|=(1<<2);
	while(1) { //num=0;
		PORTA|=(1<<4);
		//n1=PINA&(1<<7);

		//n2=PINA&(1<<6);

		//n3=PINA&(1<<5);

		if (PINA&(1<<7)) {num=1;
		                  _delay_ms(50);}
		if(PINA&(1<<6)) { num=2;
		                 _delay_ms(50);}
		 if(PINA&(1<<5)) {num=3;
		                 _delay_ms(50);	 }
		//else num=0;

		PORTB=num;



	}



}
