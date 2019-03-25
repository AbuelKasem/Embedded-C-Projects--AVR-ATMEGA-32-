/*
 * eeprom.c
 *
 *  Created on: May 19, 2018
 *      Author: AbuElkasem
 */


#include"PLATFORM_TYPES.h"
#include"TWI.h"
#include"eeprom.h"
#define Divece_Address 0b01010000


void eeprom_byte_write(uint16 address,uint8 data){



	uint8 H_byte,L_byte;
	TWI_init();

	H_byte=address>>8;
	L_byte=(uint8)address;
	TWI_start();
	TWI_send_DeviceAddress_Write(Divece_Address);
	TWI_send_data(H_byte);
	TWI_send_data(L_byte);
	TWI_send_data(data);
	TWI_stop();

}

void eeprom_byte_read(uint16 address,uint8 *data){


	uint8 H_byte,L_byte;
	TWI_init();

	H_byte=address>>8;
	L_byte=(uint8)address;
	TWI_start();
	TWI_send_DeviceAddress_Write(Divece_Address);
	TWI_send_data(H_byte);
	TWI_send_data(L_byte);


	TWI_start();
	TWI_send_DeviceAddress_Read(Divece_Address);
	*data=TWI_recieve_data_ACK();
	TWI_stop();
}
