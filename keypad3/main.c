/*
 * main.c
 *
 *  Created on: Apr 19, 2018
 *      Author: AbuElkasem
 */



#include<avr/io.h>
#include<util/delay.h>
int main(void){
	int spw[3]={0,0,0};
	int KeyPressed = 0;
	/*Initialization for 7th segment*/
	DDRD = 0xF0;
	PORTD = 0xF0;
	DDRB = 0x0F;
	DDRC = 0x0C;
	PORTC = 0x0C;
	DDRA = 0xE0; /* Init Port A "Keypad"*/
	PORTA = 0x1C;
	while(1)
	{ int i;
	int pw[3]={1,2,3};
	//  while(i<3)
	for(i=0;i<3;i++){
		if(i==0) { PORTA &= ~(1 << 5); //reset first column from the right
		PORTA |= (1 << 6); //set other column
		PORTA |= (1 << 7);
	/* Scan First Column */
		if(! (PINA & (1 << 2))){
		KeyPressed = 9;
		}else if(!(PINA & (1 << 3))){
		KeyPressed = 6;
		}else if(!(PINA & (1 << 4))){
		KeyPressed = 3;
		}}
		if(i==1) { PORTA &= ~(1 << 6); //reset 2nd column from the right
		PORTA |= (1 << 5); //set other column
		PORTA |= (1 << 7);
			/* Scan 2nd Column */
			if(!(PINA & (1 << 2))){
			KeyPressed = 8;
			}else if(! (PINA & (1 << 3))){
			KeyPressed = 5;
			}else if(!(PINA & (1 << 4))){
			KeyPressed = 2;
			}}
		if(i==2) { PORTA &= ~(1 << 7); //reset 3rd column
		PORTA |= (1 << 6); //set other column
		PORTA |= (1 << 5);
			/* Scan 3rd Column */
			if(0 == (PINA & (1 << 2))){
			KeyPressed = 7;
			}else if(!(PINA & (1 << 3))){
			KeyPressed = 4;
			}else if(!(PINA & (1 << 4))){
			KeyPressed = 1;
			}}

		PORTB = KeyPressed;
			_delay_ms(50);
		spw[i]=	KeyPressed;
		if ((pw[0]==spw[0])&&(pw[1]==spw[1])) PORTD = 0x00;
		//&&(pw[1]==spw[1])&&(pw[2]==spw[2]))

			//i++;
	  }
    // if( pw[0]==spw[0]&&pw[1]==spw[1]&&pw[2]==spw[2])  PORTD = 0x00;

}
}
