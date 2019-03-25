/*
 * main.c
 *
 *  Created on: May 11, 2018
 *      Author: AbuElkasem
 */

#include<avr/io.h>
#include<util/delay.h>
#include"DIO.h"


#define SS1   PB4
#define SS2   PB3
#define MOSI PB5
#define MISO PB6
#define SCK  PB7
#define SPI_DIR DDRB
#define SPI_PORT PORTB

unsigned char spi_tranceiver (unsigned char data);




void SPI_Master_INIT(void);

int main(void){

// SLAVE 1 ATMEG328P
	//SS OUT 0 TO ENABLE 1ST SLAVE
	int i=0;
	unsigned char redata=0;
	SET_BIT(DDRC,PC4);
	SET_BIT(DDRB,PB3);
	SET_BIT(DDRB,PB2);
	SET_BIT(DDRB,PB1);
	SET_BIT(DDRB,PB0);

	CLEAR_BIT(PORTC,PC4);
	SPI_Master_INIT();
	SET_BIT(PORTC,PC4);
	//PORTB=5;

	while(1){
		SPI_PORT&=~(1<<SS1); // ENABLE 1ST SLAVE
		SPI_PORT|=(1<<SS2);  // DISABLE 2ND SLAVE


		redata=spi_tranceiver(0) ;
		PORTB=redata;

		for(i=0;i<6;i++){
			spi_tranceiver('A');
			_delay_ms(100);
			spi_tranceiver('B');
			_delay_ms(100);
		}
		i=0;
_delay_ms(500);

/*SPI_PORT&=~(1<<SS2); // ENABLE 2ND SLAVE
		SPI_PORT|=(1<<SS1);  // DISABLE 1st SLAVE
		for(i=0;i<6;i++){
			spi_tranceiver('A');
			_delay_ms(100);
			SPDR='B';
			_delay_ms(100);
	}
		i=0;
		_delay_ms(500);

*/
}
	return 0;}
unsigned char spi_tranceiver (unsigned char data)
{
    // Load data into the buffer
    SPDR = data;

    //Wait until transmission complete
    while(!(SPSR & (1<<SPIF)));   // Return received data

  return(SPDR);
}
void SPI_Master_INIT(void){
	// SPI MASTER MODE SS OUT, MOSI OUT , SCK OUT

	SPI_DIR|=(1<<SS1)|(1<<SS2)|(1<<MOSI)|(1<<SCK);

	   // MISO IN

	SPI_DIR&=~(1<<MISO);

	   // spi enable ,spi master,sck/128

		SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<SPR1);


}
