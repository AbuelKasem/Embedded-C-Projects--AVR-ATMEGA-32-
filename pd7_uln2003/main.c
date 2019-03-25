#include<avr/io.h>
#include<util/delay.h>

int main(void){
	DDRD=0xF0;
	PORTD=0X00;
    while(1){
    	PORTD|=(1<<PD7);
    	_delay_ms(5000);
    	PORTD&=~(1<<PD7);
    	_delay_ms(5000);
    }
}
