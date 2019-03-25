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

	DDRD |=(1<<PD5);

	TWI_address(0x03);

	while(1)
	{

		Data = TWI_recieve_data_ACK();

		if(Data == 'a')
		{
			PORTD|=(1<<PD5);

		}
		if(Data == 'b')
		{
			PORTD&=~(1<<PD5);

		}

	}

	return 0;
}

