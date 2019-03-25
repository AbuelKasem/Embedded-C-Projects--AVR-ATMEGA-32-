/*
 * main.c
 *
 *  Created on: Jun 23, 2018
 *      Author: AbuElkasem
 */
//include os header files

#include<FreeRTOS.h>
#include"DIO.h"
#include"UART_MA.h"
#include<FreeRTOSConfig.h>
#include<task.h>
#include<semphr.h>
#include<queue.h>
#include<event_groups.h>
#include<avr/io.h>
// task prototybe
void T_SMS(void *pvData);
void T_Server(void *pvData);
void System_Init(void);
// services declare
xSemaphoreHandle BsResourceUart;


int main(void){
	OSCCAL=0x93;
	// init system peripheral
	System_Init();
	// os services create

	vSemaphoreCreateBinary(BsResourceUart,1);

	// create task

	xTaskCreate(T_SMS,NULL,100,NULL,1,NULL);

	xTaskCreate(T_Server,NULL,100,NULL,2,NULL);

	// start scheduler
	vTaskStartScheduler();
	// unrechable code

}

void T_SMS(void *pvData){
	while(1){

		//taskENTER_CRITICAL();
		if(xSemaphoreTake(BsResourceUart,1000)){
		UART_Transmit_STRING("AT+SMS1\r\n");
		UART_Transmit_STRING("AT+SMS2\r\n");
		xSemaphoreGive(BsResourceUart);}
		//taskEXIT_CRITICAL();



}
}

void T_Server(void *pvData){

	while(1){
		//taskENTER_CRITICAL();
		if(xSemaphoreTake(BsResourceUart,1000))
		{
		UART_Transmit_STRING("AT+SERVER1\r\n");
		UART_Transmit_STRING("AT+SERVER2\r\n");

		xSemaphoreGive(BsResourceUart);

		}vTaskDelay(5);

//	taskEXIT_CRITICAL();

		}


}

void System_Init(void){

Uart_Init();
UART_Transmit_STRING("start\r");

}

