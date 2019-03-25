/*
 * I2C_MA.c
 *
 *  Created on: May 21, 2018
 *      Author: AbuElkasem
 */


#include<avr/io.h>


void i2c_init(unsigned int bitrate){
 // for 8 Mhz clock
	//TWBR tow wire bit rate regesiter
	switch(bitrate){

	case 100:   TWBR=32;
	break;
	case 400:   TWBR=2;
	break;
	default:    TWBR=32;
	}
	// TWI Control Register  TWCR,TWEA: TWI Enable Acknowledge Bit,TWEN: TWI Enable Bit
	TWCR=(1<<TWEA)|(1<<TWEN);
	//TWI Status Register TWSR
	TWSR=0;

}
	void i2c_address(unsigned char address){
		// TWAR  slave address register
		TWAR= ((address<<1)&(0xFE));


}


	void i2c_start(void){

		// TWI Control Register  TWCR,TWSTA: TWI START Condition Bit,TWINT Flag

			TWCR=(1<<TWSTA)|(1<<TWINT)|(1<<TWEN);

			// check for twint flag & start,repeated START condition success in TWSR

	while(!( TWCR& (1<<TWINT)) && ( ((TWSR & 0xf8)!=0x08)||((TWSR & 0xf8) != 0x10))); //success
	//else return 0; //fail

			// next load SLA+W/R  slave address + r/w in TWDR data buffer

	}


	void i2c_send_DeviceAddress_write(unsigned char address){

		TWDR=(address<<1) & 0xFE;    // address is 7 bit ,lsb =0 to write
		// TWI Control Register  TWCR, clearTWINT Flag by writing 1 to it,enabel twen
		TWCR=(1<<TWINT)|(1<<TWEN);

      while(!(( TWCR& (1<<TWINT)) && ( ((TWSR & 0xf8)!=0x18)||((TWSR & 0xf8) != 0x20)))) ;
      			//else return 0;

	}

	void i2c_send_DeviceAddress_read(unsigned char address){

		TWDR=(address<<1) | (0x01);    // address is 7 bit ,lsb =1 to read

		// TWI Control Register  TWCR, clearTWINT Flag by writing 1 to it,enabel twen
				TWCR=(1<<TWINT)|(1<<TWEN);

		      while(!( TWCR& (1<<TWINT)) && ( ((TWSR & 0xf8)!=0x40)||((TWSR & 0xf8) != 0x48)));
		      		//	else return 0;

			}

	void i2c_send_data(unsigned char data){

		// irte data to be transmitted only if twint is high
		//if( TWCR& (1<<TWINT))
			TWDR=data;
		// TWI Control Register  TWCR, clearTWINT Flag by writing 1 to it,enabel twen
						TWCR=(1<<TWINT)|(1<<TWEN);

	while(!( TWCR& (1<<TWINT)) && ( ((TWSR & 0xf8)!=0x28)||((TWSR & 0xf8) != 0xB8))); //success
			//else return 0; //fail

	}

	unsigned char i2c_Recieve_data_ack(void){

		while(!(((TWCR & (1<<TWINT))))&&((((TWSR&0xf8)!=0x80))||((TWSR&0xf8)!=0x50)));
			TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);
			return TWDR;
	}


	unsigned char i2c_Recieve_data_Nack(void){

			while(!(((TWCR & (1<<TWINT))))&&((((TWSR&0xf8)!=0x88))||((TWSR&0xf8)!=0x58)));
				TWCR=(1<<TWEN)|(1<<TWINT);
				return TWDR;
		}

	void i2c_stop(void){
		TWCR=(1<<TWSTO)|(1<<TWINT)|(1<<TWEN);
	}
