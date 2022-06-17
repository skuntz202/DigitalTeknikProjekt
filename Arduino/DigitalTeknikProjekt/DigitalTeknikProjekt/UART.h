#ifndef UART_H_
#define UART_H_
#include <stdio.h>
#include <stdlib.h>

extern char* buffer;
extern int receiveComplete;
extern int packetReceiveFlag;
extern volatile unsigned long bufferIndex;

extern void UART_init();
extern void UART_transChar(char transData);
extern void UART_transStr(char* transDataStr, int endLine);
extern int UART_receiveChar();
extern void dims();

#endif /*UART_H_*/
