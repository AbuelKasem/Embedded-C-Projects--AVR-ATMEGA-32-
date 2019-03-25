/*
 * main.c
 *
 *  Created on: Apr 19, 2018
 *      Author: AbuElkasem
 */





#define D4 eS_PORTB4
#define D5 eS_PORTB5
#define D6 eS_PORTB6
#define D7 eS_PORTB7
#define RS eS_PORTC6
#define EN eS_PORTC7

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"


#include <avr/io.h>

int main(void)
{
  DDRB = 0xFF;
  DDRC = 0xFF;
  int i;
  Lcd4_Init();
  while(1)
  {
    Lcd4_Set_Cursor(1,1);
    Lcd4_Write_String("Abuelkasem");
    for(i=0;i<15;i++)
    {
      _delay_ms(200);
      Lcd4_Shift_Left();
    }
    for(i=0;i<15;i++)
    {
      _delay_ms(500);
      Lcd4_Shift_Right();
    }
    Lcd4_Clear();
    Lcd4_Set_Cursor(2,1);

    _delay_ms(200);
  }
}
