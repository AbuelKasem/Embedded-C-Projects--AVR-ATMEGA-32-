/*
 * main.c
 *
 *  Created on: Apr 19, 2018
 *      Author: AbuElkasem
 */


#include<avr/io.h>
#include<util/delay.h>
#define R0 2
#define R1 3
#define R2 4
#define C0 7
#define C1 6
#define C2 5
#define keypadPORT PORTA
#define keypadPIN PINA
#define keypadDDR DDRA
//Keypad functions and global variables
int getkey();
int keypadRow[] = {R0, R1, R2}; //rows of the keypad
int keypadCol[] = {C0, C1, C2};//columnd

int main(void){
	DDRB|=0x0F;  // PORTB OUT
		DDRC|=0x3C;
		PORTB=0x00;
		PORTC|=(1<<2);
	int key_pressed;

	   keypadDDR |= (1<<R0)|(1<<R1)|(1<<R2);  //set upper part of keypad port as output
	                                                //this will be required for scanning the rows
	   keypadDDR &= ~((1<<C0)|(1<<C1)|(1<<C2));//set lower part of keypad port as input.This is
                                                //the part of the keypad port where the rows are connected.

	   while(1)
	     {
	        key_pressed = getkey();

	        	  PORTB=key_pressed;//send the key pressed to LCD
	        	  _delay_ms(50);
	     }
	     return 0;
	  }

int getkey()
{
   int i, j;
   for(i = 0; i < 3; i++)
   {
    keypadPORT = 0x00;
    keypadPORT |= (1 << keypadRow[i]);//send a high to a particular row of the keypad

    for(j = 0; j < 3; j++)
    {
        if(bit_is_set(keypadPIN,keypadCol[j]))//check if key is pressed
        {
            while(bit_is_set(keypadPIN,keypadCol[j]));  //wait for key to be released
            switch(i)
            {
                case(0):
                {
                    if (j == 0) return 7;
                    else if (j == 1) return 8;
                    else if (j == 2) return 9;

                    break;
                }
                case(1):
                {
                    if (j == 0) return 4;
                    else if (j == 1) return 5;
                    else if (j == 2) return 6;

                       break;
                }
                case(2):
                {
                    if (j == 0) return 1;
                    else if (j == 1) return 2;
                    else if (j == 2) return 3;

                       break;
                }

            }
        }
    }
   }
    return 0;//Return 'A' if no key is pressed.
}
