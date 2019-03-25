/*
 * main.c
 *
 *  Created on: May 1, 2018
 *      Author: AbuElkasem
 */


#include<avr/io.h>
#include"DIO.h"
#include"LCD_MA.h"
#include"KeyPad.h"
#include<util/delay.h>
#include<stdlib.h>
int main(void){
	SET_BIT(DDRD,PD7);
	SET_BIT(PORTD,PD7);
	char i=0;
	int x=0,j=0,cnt=0;
	char password[]="1234";
	char inpass[2],arr[2]={0,0};
	LCD_INIT();
	LCD_SEND_string_4bit( "  ");
	KEYPAD_init();
	while(1){
		LCD_send_string_row_column_4bit(0,0,"Enter pin");
		do{
			i=KEYPAD_Get_Key();
			_delay_ms(200);
		}while(i==0);
		inpass[x]=i;
		LCD_set_cursor_4bit(1,x);
		LCD_SEND_CHAR_4bit(i);
		_delay_ms(300);
		LCD_set_cursor_4bit(1,x);
		LCD_SEND_CHAR_4bit('*');
		x++;

	if(x>1) {j=atoi(inpass);
		itoa(j,arr,10);
	LCD_send_string_row_column_4bit(1,7,arr);}
if(j==25) TOGGLE_BIT(PORTD,PD7);
	/*	if(x>3)
		{

			for(j=0;j<4;j++)
			{
				if(inpass[j]  == password[j])
				{
					cnt++;
				}

			}

			if(cnt==4)
			{
				LCD_CLEAR();
				LCD_send_string_row_column_4bit(0,0,"Access Granted");
				_delay_ms(3000);
				LCD_CLEAR();
			}
			else
			{
				LCD_CLEAR();
				LCD_send_string_row_column_4bit(0,0,"Access Denied");
				_delay_ms(3000);
				LCD_CLEAR();
			}

			i=0; j=0;cnt=0;
		}*/

	}
	return 0;
}
