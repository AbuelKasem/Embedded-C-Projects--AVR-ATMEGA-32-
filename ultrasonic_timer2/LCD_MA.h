/*
 * LCD_MA.h
 *
 *  Created on: Apr 28, 2018
 *      Author: AbuElkasem
 */

#ifndef LCD_MA_H_
#define LCD_MA_H_

#define LCD_DATA_DDR DDRB
#define LCD_DATA_PORT PORTB
#define LCD_Control_PORT PORTC
#define LCD_Control_DDR DDRC
#define E PC7
#define RS PC6
#define Clear (0x01)
#define RT_HOME (0x02)
#define B4_init (0x28)
#define DISP_init (0x0C)
void LCD_INIT(void);
void LCD_CLEAR(void);

void LCD_SEND_COMMAND_4bit(unsigned char command);
void LCD_SEND_CHAR_4bit(unsigned char character);
void LCD_SEND_string_4bit( char *string);
void LCD_set_cursor_4bit( char row,char column);
void LCD_send_string_row_column_4bit( char row,char column,char *string);

#endif /* LCD_MA_H_ */
