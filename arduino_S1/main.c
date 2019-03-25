/*
 * main.c
 *
 *  Created on: May 12, 2018
 *      Author: AbuElkasem
 */


#include<avr/io.h>
#include<util/delay.h>

#define SS1   PB2
#define MOSI PB3
#define MISO PB4
#define SCK  PB5
#define SPI_DIR DDRB
#define SPI_PORT PORTB

void SPI_Slave_INIT(void){

	// SPI slave MODE  MISO OUT

	SPI_DIR|=(1<<MISO);

	// SPI slave MODE SS in  CONNECT TO GND, MOSI in , SCK in

	SPI_DIR &=~((1<<SCK)|(1<<MOSI)|(1<<SS1));

	// spi enable ,spi slave,sck/128

	SPCR=(1<<SPE);


}
char SPI_SlaveReceive(void)
{

	while(!(SPSR & (1<<SPIF)));

	return SPDR;
}


int main(){
	DDRD|=(1<<PD2);
	PORTD&=~(1<<PD2);
	char data=0;
	SPI_Slave_INIT();
	while(1){


		data=SPI_SlaveReceive();
		if (data=='A'){PORTD|=(1<<PD2);}
		else if(data=='B') {PORTD&=~(1<<PD2);}
		else PORTD&=~(1<<PD2);

	}


}
