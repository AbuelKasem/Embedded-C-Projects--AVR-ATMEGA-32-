/*
 * LCD_MA.c
 *
 *  Created on: Apr 29, 2018
 *      Author: AbuElkasem
 */

#include<avr/io.h>
#include"LCD_MA.h"
#include<util/delay.h>


void LCD_INIT(void){
	LCD_DATA_DDR|=0xF0;   //set data pins as output ,4 bit mode
	LCD_Control_DDR|=(1<<E)|(1<<RS); // set control pins out
	LCD_SEND_COMMAND_4bit(B4_init);
	LCD_SEND_COMMAND_4bit(RT_HOME);
	LCD_SEND_COMMAND_4bit(DISP_init);
	LCD_CLEAR();
}

void LCD_SEND_COMMAND_4bit(unsigned char command){
	LCD_Control_PORT&=~(1<<RS);    //RS LOW
	LCD_Control_PORT|=(1<<E); //SET E
	_delay_ms(5);
	LCD_DATA_PORT=command &0xF0;   //send high byte first
	_delay_ms(5);
	LCD_Control_PORT&=~(1<<E);  // reset E
	_delay_ms(5);
	LCD_Control_PORT|=(1<<E); //SET E
	_delay_ms(5);
	LCD_DATA_PORT=(command<<4) & 0xF0; // send low byte
	LCD_Control_PORT&=~(1<<E);  // reset E



}
void LCD_CLEAR(void){
	LCD_SEND_COMMAND_4bit(Clear);
}

void LCD_SEND_CHAR_4bit(unsigned char character){
	LCD_Control_PORT|=(1<<RS);    //RS HIGH
		LCD_Control_PORT|=(1<<E); //SET E
		_delay_ms(5);
		LCD_DATA_PORT=character &0xF0;   //send high byte first
		_delay_ms(5);
		LCD_Control_PORT&=~(1<<E);  // reset E
		_delay_ms(5);
		LCD_Control_PORT|=(1<<E); //SET E
		_delay_ms(5);
		LCD_DATA_PORT=(character<<4) & 0xF0; // send low byte
		LCD_Control_PORT&=~(1<<E);  // reset E
}

void LCD_SEND_string_4bit( char *string){



int i=0;
	while(string[i]!='\0'){
		LCD_SEND_CHAR_4bit(string[i]);
		i++;
	}
}
void LCD_set_cursor_4bit( char row,char column){
	char r=0,c=0,pos=0.;
	if(row==0) r=0x80;
	else if(row==1) r=0xC0;
	c=column>15?15:column;
	c=column<0?0:column;
	pos=r|c;
	LCD_SEND_COMMAND_4bit(pos);


}

void LCD_send_string_row_column_4bit( char row,char column,char *string){
	int i=0;
	LCD_set_cursor_4bit(  row, column);
		while(string[i]!='\0'){
			LCD_SEND_CHAR_4bit(string[i]);
			i++;
		}
}
