/*
 * Main.c
 *
 *  Created on: Apr 27, 2018
 *      Author: ahmed
 */


#include "ULTRASONIC.h"
#include <avr/io.h>
#include <util/delay.h>
#include "PLATFORM_TYPES.h"
#include "LCD.h"

#define BUZZER_ON (PORTD|=(1<<PD5))
#define BUZZER_OFF (PORTD&=~(1<<PD5))


int main(void)
{

	char arr[10]={0};

	uint16 Distance=0;

	LCD_Init();
	LCD_Clear_Display();

	UltraSonic_init();

	DDRD |=(1<<PD5);
	PORTD&=~(1<<PD5);

	while(1)
	{
		Distance = UltraSonic_read();

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

		LCD_Send_String_Row_Column(0,0,"Distance :");
		LCD_Send_String_Row_Column(1,0,arr);
		LCD_Send_String(" cm   ");

	}

}
