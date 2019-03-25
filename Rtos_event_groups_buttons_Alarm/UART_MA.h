/*
 * UART_MA.h
 *
 *  Created on: May 16, 2018
 *      Author: AbuElkasem
 */

#ifndef UART_MA_H_
#define UART_MA_H_

void Uart_Init(void);
void UART_Config(unsigned long int baud,unsigned int data_bits,char parity,unsigned int stop_bits);
void Uart_Transmit_char(char data);
char  Uart_Recieve_char(void);
void UART_Transmit_STRING(char *String);
void  Uart_Recieve_String(char *String);
#endif /* UART_MA_H_ */
