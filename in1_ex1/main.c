/*
 * main.c
 *
 *  Created on: Apr 16, 2018
 *      Author: AbuElkasem
 */


#include <avr/io.h>
#include <util/delay.h>
#define SET(PORT, PIN) {PORT |= (1<<PIN);}
#define RESET(PORT, PIN) {PORT &= ~(1<<PIN);}
int main(void) {
    int x=0,y=0;

	DDRD=(1<<DDD4)|(1<<DDD5)|(1<<DDD6)|(1<<DDD7);
	//DDRD=(0<<DDD2)|(0<<DDD3);
	//PORTD=(1<<DDD2)|(1<<DDD3);


	while(1) {
		//x=PIND2;
			//y=PIND3;
      //  if(x)
        //	PORTD=(1<<DDD7);
       // else if (y)
        //PORTD=(0<<DDD7);

		PORTD=(1<<DDD4)|(1<<DDD5)|(1<<DDD6);
		//PORTD|=(1<<7);
		SET(PORTD,7);
		_delay_ms(500);
		PORTD=(0<<DDD4)|(0<<DDD5)|(0<<DDD6);
		//PORTD|=(0<<7);
		RESET(PORTD,7);
		_delay_ms(500);
	}


	return 0;
}
