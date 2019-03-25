/*
 * main.c
 *
 *  Created on: May 11, 2018
 *      Author: AbuElkasem
 */



#include<avr/io.h>
#include<util/delay.h>
#include"ADC.h"
#define SS   PB4
#define MOSI PB5
#define MISO PB6
#define SCK  PB7


void SPI_Master_INIT(void){
	// SPI MASTER MODE SS OUT, MOSI OUT , SCK OUT

	   DDRB|=(1<<SS)|(1<<MOSI)|(1<<SCK);

	   // MISO IN

	   DDRB&=~(1<<MISO);

	   // spi enable ,spi master,sck/128

		SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<SPR1);


}

int main(){

	SPI_Master_INIT();

	ADC_init();

	while(1){
		long temp_Sensor;
		temp_Sensor=ADC_read();
		temp_Sensor*=500;
		temp_Sensor/=1023;




		SPDR=(unsigned char )temp_Sensor;
		_delay_ms(100);
	}


}
