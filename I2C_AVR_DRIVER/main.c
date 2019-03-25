/*
 * MAIN.C
 *
 *  Created on: May 21, 2018
 *      Author: AbuElkasem
 */


#include<avr/io.h>
#include"I2C_MA.h"
#include"LCD_MA.h"
#include<util/delay.h>
/*
int main(){

 // int x=0,y=0,z=0;
   int i;
   DDRB=0x0f;
   PORTB=0X00;
   DDRC=0X08;
   PORTC=0X08;
   char Data =0;
	i2c_init(100);
	i2c_address(10);
	LCD_INIT();
	LCD_CLEAR();

	while(1){
		for (i=0;i<5;i++){
		i2c_start();
		 i2c_send_DeviceAddress_write(2);
		  i2c_send_data('A');
		//LCD_send_string_row_column_4bit(0,1,"SUCCESS!");
	//LCD_send_string_row_column_4bit(0,1,"Fail!")

		 i2c_stop();

		_delay_ms(250);
		i2c_start();
				i2c_send_DeviceAddress_write(2);
				i2c_send_data('B');

				i2c_stop();
				_delay_ms(250);
		}



		/*
		i2c_start();
		i2c_send_DeviceAddress_read(2);
		Data = i2c_Recieve_data_Nack();
		PORTB=Data;
		LCD_set_cursor_4bit(0,2);
		LCD_SEND_CHAR_4bit(Data);
		i2c_stop();




}
	return 0;
	}

*/


#define F_CPU 8000000U

void I2C_Init(unsigned long Clock){
  TWSR = Clock >>8; // No prescaler
  TWBR = Clock; // SCL frequency is 50K for XTAL = 8M
}
void I2C_Start(void){
  TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
  while ((TWCR & 0x80) == 0); // wait to finish
}
void I2C_Write(unsigned char cByte){
  TWDR = cByte;
  TWCR = (1<<TWINT)|(1<<TWEN);
  while ((TWCR & 0x80) == 0);
}
unsigned char I2C_Read(unsigned char ack){
  TWCR = (1<<TWINT)|(1<<TWEN)|(ack<<TWEA);
  while ((TWCR & 0x80) == 0); return TWDR;
}
void I2C_Stop(){ TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO); }
int main (void){
	LCD_INIT();
		LCD_CLEAR();
  unsigned char ch;
  DDRB = 0xFF;
  DDRC = 0xFF;
  PORTC=0X08;// PortA is output
  I2C_Init(0x48) ; // initialize TWI for master mode
  while(1){
  _delay_ms(1000);  I2C_Start(); // transmit START condition
  I2C_Write(0b11010000+1); // transmit SLA + R(1)
  ch = I2C_Read(0); // read last byte send NACK
  I2C_Stop(); // transmit STOP condition
  PORTB = ch;
  //LCD_set_cursor_4bit(0,2);
  		//LCD_SEND_CHAR_4bit(ch);
  }
  return 0 ;
}



