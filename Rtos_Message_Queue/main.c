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
void T_send(void *pvData);
void T_Recieve(void *pvData);
void System_Init(void);
// services declare
xQueueHandle MqTerminal;


int main(void){
	OSCCAL=0x93;
	// init system peripheral
	System_Init();
	// os services create

	MqTerminal=xQueueCreate(10,1);

	// create task

	xTaskCreate(T_send,NULL,100,NULL,1,NULL);

	xTaskCreate(T_Recieve,NULL,100,NULL,2,NULL);

	// start scheduler
	vTaskStartScheduler();
	// unrechable code

}

void T_send(void *pvData){
	unsigned char qsend=0;
	while(1){
		qsend=Uart_Recieve_char();

		xQueueSend(MqTerminal,&qsend,1000);



}
}

void T_Recieve(void *pvData){
	unsigned char qRecieve=0;
	while(1){

		if(xQueueReceive(MqTerminal,&qRecieve,1000))
			if(qRecieve=='h')
				Uart_Transmit_char('y');
	/*	if(xQueueReceive(MqTerminal,&qRecieve,1000)){
			vTaskDelay(2000);
		Uart_Transmit_char(qRecieve);

		}
*/

}}

void System_Init(void){

Uart_Init();
//UART_Transmit_STRING("start\r");

}

