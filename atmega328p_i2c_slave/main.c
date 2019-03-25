/*
 * main.c
 *
 *  Created on: May 21, 2018
 *      Author: AbuElkasem
 */


#include <avr/io.h>
#include"I2C_MA.h"
#include <util/delay.h>
/*
int main(void)
{
	char Data =0,Dat=0;

	i2c_init(100);
	i2c_address(2);

	DDRB |=(1<<PB5);



	while(1)
	{


		Data = i2c_Recieve_data_ack();

		if(Data == 'A')
		{
			PORTB|=(1<<PB5);

		}
		if(Data == 'B')
		{
			PORTB&=~(1<<PB5);

		}

		//i2c_Recieve_data_ack();
		//i2c_send_data(Dat++);

	}

	return 0;
}
*/
void I2C_Set_Address(unsigned char address){
  TWAR = address;
}
unsigned char I2C_Read(unsigned char ack){
  TWCR = (1<<TWINT)|(1<<TWEN)|(ack<<TWEA);
  while ((TWCR & 0x80) == 0); return TWDR;
}

void I2C_Write(unsigned char cByte){
  TWDR = cByte;
  TWCR = (1<<TWINT)|(1<<TWEN);
  while ((TWCR & 0x80) == 0);
}
int main (void)
{
  unsigned char ch=0;
  I2C_Set_Address(0b11010000);  // Set Slave Address
  while(1){
    I2C_Read(1);      // read byte send ACK
    I2C_Write(ch++);  // SLA(1001100)+R(1)
  }
  return 0 ;
}

