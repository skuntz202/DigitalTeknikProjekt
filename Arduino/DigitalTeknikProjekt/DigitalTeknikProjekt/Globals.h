#ifndef GLOBALS_H
#define GLOBALS_H

extern int packetLength;
extern int compareValue;

typedef struct{
	char type;
	char* data;
} UARTPacket;

typedef struct{
	char ADDR;
	char DATA;
	char CRC;
	char ACK;
} SPIPacket;

#endif //GLOBALS_H