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
xSemaphoreHandle CsButtonPressedEvent;


int main(void){

	// init system peripheral
	System_Init();
	// os services create

	CsButtonPressedEvent=xSemaphoreCreateCounting(3,0);

	// create task

	xTaskCreate(T_Button,NULL,100,NULL,1,NULL);

	xTaskCreate(T_Led,NULL,100,NULL,2,NULL);

	// start scheduler
	vTaskStartScheduler();
	// unrechable code

}

void T_Button(void *pvData){
	while(1){
		if(READ_BIT_TRUE(PIND,PD2)){
		xSemaphoreGive(CsButtonPressedEvent);

		while(READ_BIT_TRUE(PIND,PD2)){vTaskDelay(50);
	}}
		vTaskDelay(50);
}
}

void T_Led(void *pvData){

	while(1){

		if(xSemaphoreTake(CsButtonPressedEvent,1000))
			//TOGGLE_BIT(PORTD,PD5);

			 SET_BIT(PORTD,PD5);
		vTaskDelay(1000);
		CLEAR_BIT(PORTD,PD5);
		vTaskDelay(1000);

		}


}

void System_Init(void){

 SET_BIT(DDRD,PD5);
 CLEAR_BIT(DDRD,PD2);
 SET_BIT(PORTD,PD5);
}

