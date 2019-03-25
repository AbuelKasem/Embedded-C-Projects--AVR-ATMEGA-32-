/*
 * Main.c
 *
 *  Created on: May 12, 2018
 *      Author: ahmed
 */

#include <avr/io.h>
#include "TWI.h"
#include <util/delay.h>

int main(void)
{
	char Data =0;

	TWI_init();

	DDRB |=(1<<PB5);

	TWI_address(0x02);

	while(1)
	{

		Data = TWI_recieve_data_ACK();

		if(Data == 'a')
		{
			PORTB|=(1<<PB5);

		}
		if(Data == 'b')
		{
			PORTB&=~(1<<PB5);

		}

	}

	return 0;
}

