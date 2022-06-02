#ifndef UART_H_
#define UART_H_
#include <stdio.h>
#include <stdlib.h>

extern char buffer[100];
extern int receiveComplete;

extern void UART_init();
extern void UART_transChar(char transData);
extern void UART_transStr(char* transDataStr, int endLine);
extern void UART_receiveChar();

#endif /*UART_H_*/
