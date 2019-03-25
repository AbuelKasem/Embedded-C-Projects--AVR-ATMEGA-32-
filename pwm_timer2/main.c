/*
 * main.c
 *
 *  Created on: Apr 22, 2018
 *      Author: AbuElkasem
 */


#include<avr/io.h>
#include<util/delay.h>
#include"PWM_T2.h"
#include"DIO.h"
#include"ADC.h"
int main(void){
DDRD=0XF0;
PWM_T2_INIT();  // Init pwm on t2
PORTD=0x00; // init portd out to off
DDRD&=~(1<<PD2);
DDRD&=~(1<<PD3);
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
	ADC_init();

int x=0,y=0,z=0;
while(1){
	t_s=ADC_read(1); // 0 TO 1023

			t_s*=5*100;
			t_s/=1023;
			y=t_s;
			if(z>=15){PWM_T2_SET_DUTY_CYCLE(255);}
			else if(z<10) {PWM_T2_SET_DUTY_CYCLE(50);}
			else if(z>=10) {PWM_T2_SET_DUTY_CYCLE(128);}
			else if(z<5) {PWM_T2_SET_DUTY_CYCLE(0);}
			//else if(x<25) {PWM_T2_SET_DUTY_CYCLE(64);}
			//else PWM_T2_SET_DUTY_CYCLE(0);
			PORTB=t_s/10;
			SET_BIT(PORTC,PC5);
			_delay_us(5);
			CLEAR_BIT(PORTC,PC5);
			PORTB=t_s%10;
			SET_BIT(PORTC,PC4);
			_delay_us(5);
			CLEAR_BIT(PORTC,PC4);
			_delay_us(5);


	if((PIND&(1<<PD2))) {z++;
	_delay_ms(250);}

	if((PIND&(1<<PD3))) {z--;
		_delay_ms(250);}

z=(z>20)?20:z;
z=(z<0)?0:z;
			PORTB=z/10;
			SET_BIT(PORTC,PC2);
			_delay_us(5);
			CLEAR_BIT(PORTC,PC2);
			PORTB=z%10;
			SET_BIT(PORTC,PC3);
			_delay_us(5);
			CLEAR_BIT(PORTC,PC3);
			_delay_us(5);
 // if(x) {PWM_T2_SET_DUTY_CYCLE(65);}


 // else if(!x) {PWM_T2_SET_DUTY_CYCLE(255);}*/






}


}
