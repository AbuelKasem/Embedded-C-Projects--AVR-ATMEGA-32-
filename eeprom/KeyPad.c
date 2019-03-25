/*
 * KeyPad.c
 *
 *  Created on: May 1, 2018
 *      Author: AbuElkasem
 */


#include<avr/io.h>
#include<util/delay.h>
#include"KeyPad.h"
#include"DIO.h"

void KEYPAD_init(void){

	//config  row pins as input

	KEYPAD_DDR &= ~(1<<KEYPAD_R0);
	KEYPAD_DDR &= ~(1<<KEYPAD_R1);
	KEYPAD_DDR &= ~(1<<KEYPAD_R2);

	//config  columns pins as output

	KEYPAD_DDR |= (1<<KEYPAD_C0);
	KEYPAD_DDR |= (1<<KEYPAD_C1);
	KEYPAD_DDR |= (1<<KEYPAD_C2);

	// pull up the input row pins high

	KEYPAD_PORT|=(1<<KEYPAD_R0);
	KEYPAD_PORT|=(1<<KEYPAD_R1);
	KEYPAD_PORT|=(1<<KEYPAD_R2);

	// set output columns pins high

	KEYPAD_PORT|=(1<<KEYPAD_C0);
	KEYPAD_PORT|=(1<<KEYPAD_C1);
	KEYPAD_PORT|=(1<<KEYPAD_C2);

}

unsigned char KEYPAD_Get_Key(void){
	unsigned char Key=0;
	// c0
	KEYPAD_PORT&=~(1<<KEYPAD_C0);
	KEYPAD_PORT|=(1<<KEYPAD_C1);
	KEYPAD_PORT|=(1<<KEYPAD_C2);
	if(READ_BIT_FALSE(KEYPAD_PIN,KEYPAD_R0)) {Key ='1';
	}
	else if(READ_BIT_FALSE(KEYPAD_PIN,KEYPAD_R1)) {Key ='4';

	}
	else if(READ_BIT_FALSE(KEYPAD_PIN,KEYPAD_R2)) Key ='7';


	_delay_ms(5);

	//c1
	KEYPAD_PORT&=~(1<<KEYPAD_C1);
	KEYPAD_PORT|=(1<<KEYPAD_C0);
	KEYPAD_PORT|=(1<<KEYPAD_C2);
	if(READ_BIT_FALSE(KEYPAD_PIN,KEYPAD_R0)) {Key ='2';
	}
	else if(READ_BIT_FALSE(KEYPAD_PIN,KEYPAD_R1)) {Key ='5';
	}
	else if(READ_BIT_FALSE(KEYPAD_PIN,KEYPAD_R2)) Key ='8';
	_delay_ms(5);



	//c2
	KEYPAD_PORT&=~(1<<KEYPAD_C2);
	KEYPAD_PORT|=(1<<KEYPAD_C1);
	KEYPAD_PORT|=(1<<KEYPAD_C0);
	if(READ_BIT_FALSE(KEYPAD_PIN,KEYPAD_R0)) {Key ='3';

	}

	else if(READ_BIT_FALSE(KEYPAD_PIN,KEYPAD_R1)) {Key ='6';

	}

	else if(READ_BIT_FALSE(KEYPAD_PIN,KEYPAD_R2)) {Key ='9';

	}



	return Key;
}













