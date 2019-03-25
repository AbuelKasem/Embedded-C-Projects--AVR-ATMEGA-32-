/*

 * I2C.h
 *
 *  Created on: May 12, 2018
 *      Author: AbuElkasem
 */


void TWI_INIT(unsigned char BitRate);
void TWI_address(unsigned char address);
void TWI_START(void);
void TWI_Send_DeviceAdrress_Read(unsigned char address);
void TWI_Send_DeviceAdrress_Write(unsigned char address);
void TWI_Send_Data(unsigned char DATA);
unsigned char TWI_Data_Recieve_ACK(void);
unsigned char  TWI_recieve_data_NACK(void);
void TWI_stop(void);
