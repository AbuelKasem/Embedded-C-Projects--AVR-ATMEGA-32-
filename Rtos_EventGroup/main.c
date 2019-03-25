/*
 * main.c
 *
 *  Created on: Jun 23, 2018
 *      Author: AbuElkasem
 */
//include os header files

#include<FreeRTOS.h>
#include"DIO.h"
#include<FreeRTOSConfig.h>
#include<task.h>
#include<semphr.h>
#include<queue.h>
#include<event_groups.h>
#include<avr/io.h>
// task prototybe
void T_Button(void *pvData);
void T_Led(void *pvData);
void System_Init(void);

// services declare

#define BTN2 (1<<2)
#define BTN3 (1<<3)

EventGroupHandle_t EgBTNS;

EventBits_t EventsBitsValues;




int main(void){

	// init system peripheral
	System_Init();
	// os services create

	EgBTNS = xEventGroupCreate();

	// create task

	xTaskCreate(T_Button,NULL,100,NULL,1,NULL);

	xTaskCreate(T_Led,NULL,100,NULL,2,NULL);

	// start scheduler
	vTaskStartScheduler();
	// unrechable code

}

void T_Button(void *pvData){
	while(1){
		if(READ_BIT_TRUE(PIND,PD3)){
			xEventGroupSetBits(EgBTNS, BTN3 );

		while(READ_BIT_TRUE(PIND,PD3));
	}
		if(READ_BIT_TRUE(PIND,PD2)){
					xEventGroupSetBits(EgBTNS, BTN2 );

				while(READ_BIT_TRUE(PIND,PD2));
			}
		vTaskDelay(50);
}
}

void T_Led(void *pvData){

	while(1){
// (reg&mask) == mask
		EventsBitsValues = xEventGroupWaitBits(EgBTNS,(BTN3|BTN2),1,1,0xFFFF);

			 if (((EventsBitsValues &(BTN2|BTN3)))== (BTN3|BTN2) ){
					 TOGGLE_BIT(PORTD,PD6);}
		vTaskDelay(1000);


		}


}

void System_Init(void){

 SET_BIT(DDRD,PD6);
 CLEAR_BIT(DDRD,PD2);
 CLEAR_BIT(DDRD,PD3);
 SET_BIT(PORTD,PD6);
}

