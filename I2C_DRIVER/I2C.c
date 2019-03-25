/*
 * I2C.c
 *
 *  Created on: May 12, 2018
 *      Author: AbuElkasem
 */

#include<avr/io.h>
#include"I2C.h"


void TWI_INIT(unsigned char BitRate){
//TWBR bit rate register

	if(BitRate==100) { TWBR=32;}
	else if(BitRate==400) {TWBR=2;}

// twcr control reg   TWEA=enable ack,TWEN enable TW

	TWCR=(1<<TWEA)|(1<< TWEN);

	// TWSR  status reg , prescaler =0; TWPS: TWI Prescaler Bits

	TWSR=0;
}


void TWI_address(unsigned char address){

	//TWAR TWI (Slave) Address Register 7 bits of address,
//	Bit 0 – TWGCE: TWI General Call Recognition Enable Bit=0,DISABLE BROADCAST;

	TWAR=((address<<1)&(0xFE));


}

void TWI_START(void){
   // enable twsta  start bit,CLEAR INTERUPT FLAG
	TWCR=(1<<TWSTA)|(1<<TWINT)|(1<< TWEN);
	while(!(TWCR&(1<<TWINT))&&( (((TWSR&0xf8)!=0x08))||(((TWSR&0xf8)!=0x10))));



}


void TWI_Send_DeviceAdrress_Read(unsigned char address){
	TWDR=((address<<1)|(0x01));
	TWCR=(1<<TWEA)|(1<<TWINT)|(1<< TWEN);
	while(!((TWCR & (1<<TWINT)))&& ((((TWSR&0xf8)!=0x40))));



}


void TWI_Send_DeviceAdrress_Write(unsigned char address){
	TWDR=((address<<1)|(0xfe));
	TWCR=(1<<TWINT)|(1<< TWEN);
	while((!(TWCR & (1<<TWINT)))&&((TWSR&0xf8)!=0x18));



}
void TWI_Send_Data(unsigned char DATA){
	TWDR=DATA;
	TWCR=(1<<TWINT)|(1<< TWEN);
	while(!((TWCR & (1<<TWINT)))&&( (((TWSR&0xf8)!=0x28))||(((TWSR&0xf8)!=0xB8))));


}
unsigned char TWI_Data_Recieve_ACK(void){

	while(!(((TWCR & (1<<TWINT))))&&((((TWSR&0xf8)!=0x80))||((TWSR&0xf8)!=0x50)));
		TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);
		return TWDR;
}


unsigned char  TWI_recieve_data_NACK(void)
{
	while(!(((TWCR & (1<<TWINT))))&&((((TWSR&0xf8)!=0x88))||((TWSR&0xf8)!=0x58)));
	TWCR=(1<<TWEN)|(1<<TWINT);
	return TWDR;
}


void TWI_stop(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);


}
