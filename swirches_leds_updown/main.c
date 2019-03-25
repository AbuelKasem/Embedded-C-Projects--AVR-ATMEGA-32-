
#include<avr/io.h>
#include<util/delay.h>
#define GET(PORT, PIN) ((PORT & (1<<PIN)) !=0)
#define OUT(DDR, PIN) {DDR |= (1<<PIN);}
#define IN(DDR, PIN) {DDR &= ~(1<<PIN);}
#define SET(PORT, PIN) {PORT |= (1<<PIN);}
#define RESET(PORT, PIN) {PORT &= ~(1<<PIN);}
int main (void) {
	PORTD=0x00;
	int Value =0 ;
	int  x=0;
	OUT( DDRD , 4);
	OUT( DDRD , 5);
	OUT( DDRD , 6);
	OUT( DDRD , 7);
	DDRD &= ~(1<<2);
	DDRD &= ~(1<<3);
	while(1)
	{
		if(GET( PIND , 2))
		{
		Value++;
		_delay_ms (200);
		PORTD|=(Value<<4);
		}
		if(GET( PIND , 3))
		{
		Value--;
		_delay_ms (200);
		}

	switch(Value) {
	case 1: x=1;
	break;
	case 2: x=3;
	break;
	case 3: x=7;
	break;
	case 4: x=15;
	 }
	//PORTD|=(x<<4);
	}

return 0;
}



