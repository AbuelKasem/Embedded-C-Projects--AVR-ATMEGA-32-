/*
 * main.c
 *
 *  Created on: May 19, 2018
 *      Author: AbuElkasem
 */


#include"timer2_normal.h"
#include <avr/io.h>
#include <util/delay.h>
#include<stdlib.h>
#include"LCD_MA.h"
#include"DIO.h"


int main(){
	unsigned char x=0;

char arr[5] = {'a', 'b', 'c','d','f'};
char arr1[5]={0};
    int i=0,j=0;
	unsigned long int z=0;
	SET_BIT(DDRD,PD7);
	SET_BIT(DDRD,PD5);
   unsigned long int level=0;
	SET_BIT(PORTD,PD7);
	timer2_normal_init();
	LCD_INIT();
	//LCD_SEND_string_4bit("TIMER 2 PWM");
	LCD_send_string_row_column_4bit(0,3,arr);
	for(i=0;i<=4;i++)
	    arr1[i]=arr[4-i];
	LCD_send_string_row_column_4bit(1,3,arr1);
	timer2_normal_start();

	while(1){
		  x=timer2_read();
		z=x*64;
		//level=(256*30)/2;
		if(z>16000) {CLEAR_BIT(PORTD,PD7);}
		else if(z<16000 ){SET_BIT(PORTD,PD7);}
		else SET_BIT(PORTD,PD7);

		if(z>4096) {CLEAR_BIT(PORTD,PD5);}
		else if(z<4096 ){SET_BIT(PORTD,PD5);}
		else SET_BIT(PORTD,PD5);
/*
		SET_BIT(PORTD,PD5);
		_delay_ms(500);
		CLEAR_BIT(PORTD,PD5);
		_delay_ms(500);



		itoa(z,arr,10);
		LCD_send_string_row_column_4bit(1,3,arr);
		LCD_SEND_CHAR_4bit(' ');


*/

	}


}
