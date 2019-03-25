/*
 * main.c
 *
 *  Created on: Apr 28, 2018
 *      Author: AbuElkasem
 */

#include <avr/io.h>
#include <util/delay.h>
#include "PLATFORM_TYPES.h"
#include"ultrasonic_HCSR04.h"
#include"LCD_MA.h"
#include"DIO.h"
#include"timer2_normal.h"
#include<stdlib.h>
#define BUZZER_ON (PORTD|=(1<<PD5))
#define BUZZER_OFF (PORTD&=~(1<<PD5))


int main(void)
{

	char arr[10]={0};

	uint16 Distance=0;

	ultrasonic_init();
		LCD_INIT();
		LCD_send_string_row_column_4bit(0,0,"Distance is ");



	DDRD |=(1<<PD5);
	PORTD&=~(1<<PD5);

	while(1)
	{
		Distance = ultrasonic_read();

		if((Distance <30)&&(Distance >20))
		{
			BUZZER_ON;
			_delay_ms(300);
			BUZZER_OFF;
			_delay_ms(300);
		}
		if((Distance <20)&&(Distance >10))
		{
			BUZZER_ON;
			_delay_ms(100);
			BUZZER_OFF;
			_delay_ms(100);
		}
		if((Distance <10))
		{
			BUZZER_ON;

		}

		itoa(Distance,arr,10);

		LCD_send_string_row_column_4bit(0,0,"Distance :");
		LCD_send_string_row_column_4bit(1,0,arr);
	//	LCD_Send_String(" cm   ");

	}

}






/*


#include<avr/io.h>
//#include"ultrasonic_HCSR04.h"
//#include"LCD_MA.h"
//#include"KeyPad.h"
#include"DIO.h"
#include"timer2_normal.h"
#include<util/delay.h>
#include<stdlib.h>
#include "PLATFORM_TYPES.h"
#include "LCD.h"
#include "ULTRASONIC.h"
int main(void){
	SET_BIT(DDRD,PD5);
	SET_BIT(PORTD,PD5);
	uint16 dis=0;
	char arr[10]={0};
	UltraSonic_init();
	LCD_Init();
		LCD_Clear_Display();

		LCD_Send_String_Row_Column(0,0,"distance");
	while(1){
		dis=UltraSonic_read();
		if(dis<=10) CLEAR_BIT(PORTD,PD5);
		itoa(dis,arr,10);
		LCD_Send_String_Row_Column(1,0,arr);
	}




}
*/
