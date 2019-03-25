/*
 * I2C_MA.h
 *
 *  Created on: May 21, 2018
 *      Author: AbuElkasem
 */

#ifndef I2C_MA_H_
#define I2C_MA_H_

void i2c_init(unsigned int bitrate);

void i2c_address(unsigned char address);

void i2c_start(void);

void i2c_send_DeviceAddress_write(unsigned char address);

void i2c_send_DeviceAddress_read(unsigned char address);

void i2c_send_data(unsigned char data);

unsigned char i2c_Recieve_data_ack(void);

unsigned char i2c_Recieve_data_Nack(void);

void i2c_stop(void);

#endif /* I2C_MA_H_ */
