/*
 * main.c
 *
 *  Created on: May 12, 2018
 *      Author: AbuElkasem
 */


#include<avr/io.h>
#include<util/delay.h>

#define SS2   PB2
#define MOSI PB3
#define MISO PB4
#define SCK  PB5
#define SPI_DIR DDRB
#define SPI_PORT PORTB


unsigned char spi_tranceiver (unsigned char data);
void SPI_Slave_INIT(void);

char SPI_SlaveReceive(void)
{

	while(!(SPSR & (1<<SPIF)));

	return SPDR;
}


int main(){
	DDRD|=(1<<PD2);
	PORTD&=~(1<<PD2);
	char dat=0;
	SPI_Slave_INIT();
	while(1){


		dat=spi_tranceiver(8);

		if (dat=='A'){PORTD|=(1<<PD2);}
		else if(dat=='B') {PORTD&=~(1<<PD2);}
		else PORTD&=~(1<<PD2);

	}
	//spi_tranceiver(6);

}
//Function to send and receive data for both master and slave

unsigned char spi_tranceiver (unsigned char data)
{
    // Load data into the buffer
    SPDR = data;

    //Wait until transmission complete
    while(!(SPSR & (1<<SPIF)));   // Return received data

  return(SPDR);
}
void SPI_Slave_INIT(void){

	// SPI slave MODE  MISO OUT

	SPI_DIR|=(1<<MISO);

	// SPI slave MODE SS in  CONNECT TO GND, MOSI in , SCK in

	SPI_DIR &=~((1<<SCK)|(1<<MOSI)|(1<<SS2));

	// spi enable ,spi slave,sck/128

	SPCR=(1<<SPE);


}
