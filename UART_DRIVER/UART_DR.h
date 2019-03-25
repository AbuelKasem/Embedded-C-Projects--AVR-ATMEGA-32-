/*
 * UART_DR.h
 *
 *  Created on: May 5, 2018
 *      Author: AbuElkasem
 */

#ifndef UART_DR_H_
#define UART_DR_H_


#define F_OSC (800000)
void UART_INIT(long BaudRate);
void UART_SEND_BYTE(char Byte);
void UART_SEND_STRING(char *String);
char UART_RECIEVE_BYTE(void);
void UART_RECIEVE_STRING(char* string);


#endif /* UART_DR_H_ */
