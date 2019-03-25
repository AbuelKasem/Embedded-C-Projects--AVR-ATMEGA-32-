/*
 * main.c
 *
 *  Created on: May 11, 2018
 *      Author: AbuElkasem
 */



#include<avr/io.h>
#include<util/delay.h>
#include"LCD_MA.h"

#define SS   PB4
#define MOSI PB5
#define MISO PB6
#define SCK  PB7
void SPI_Slave_INIT(void){

	// SPI slave MODE  MISO OUT

	   DDRB|=(1<<PB6);

	   // SPI slave MODE SS in  CONNECT TO GND, MOSI in , SCK in

	   DDRB &=~((1<<SCK)|(1<<MOSI)|(1<<SS));

	   // spi enable ,spi slave,sck/128

		SPCR=(1<<SPE);


}

int main(){



	SPI_Slave_INIT();
	char DATA=0;
	char arr[10];
	LCD_INIT();
	LCD_CLEAR();

	while(1){


	while(!(SPSR &(1<<SPIF)));
	DATA=SPDR;


	}


}
