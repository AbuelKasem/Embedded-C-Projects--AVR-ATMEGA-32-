/*
 * m.c
 *
 *  Created on: Apr 17, 2018
 *      Author: AbuElkasem
 */


#include<avr/io.h>
#include<util/delay.h>
int fun(int C) {
	int n=0;
	switch(C) {

	 	case 0: n=0;  break;
	 	case 1: n=1;  break;
	 	case 2: n=3;  break;
	 	case 3: n=7;  break;
	 	case 4: n=15;}
	return n;

}
int main(void){
	DDRD=0xF0;
	PORTD=0xF0;
 int x=0,y=0,C=0,n=0;

	while(1) {
		x=PIND&(1<<2);
		y=PIND&(1<<3);
if(x) {
		C++;
	_delay_ms(200);
}

 if(y){
	 	 C--;
	 	_delay_ms(200);
 }

    C=(C>=4)?4:C;
 	C=(C<=0)?0:C;


    // PORTD=(C<<4);
 	int m=fun(C);
 	 PORTD=~(m<<4);

	}
	}
