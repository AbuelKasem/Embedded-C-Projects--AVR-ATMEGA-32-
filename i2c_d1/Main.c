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
	int i=0;

	TWI_init();

	TWI_address(0x01);

	while(1)
	{

		TWI_start();
		TWI_send_DeviceAddress_Write(0x02);

		for(i=0; i<5 ; i++)
		{
			TWI_send_data('a');
			_delay_ms(500);
			TWI_send_data('b');
			_delay_ms(500);
		}
		TWI_stop();

		TWI_start();
		TWI_send_DeviceAddress_Write(0x03);

		for(i=0; i<5 ; i++)
		{
			TWI_send_data('a');
			_delay_ms(500);
			TWI_send_data('b');
			_delay_ms(500);
		}
		TWI_stop();



	}

	return 0;
}

