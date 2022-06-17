#ifndef GLOBALS_H
#define GLOBALS_H

extern unsigned long packetLength;
extern int compareValue;

#define GENERATOR 0x01
#define OSCILLOSCOPE 0x02
#define BODEPLOT 0x03

typedef struct{
	char type;
	char* data;
} UARTPacket;

typedef struct{
	char curr;
	char shape;
	char amplitude;
	char frequency;
	char ADDR;
	char DATA;
	char CRC;
	char ACK;
} SPIPacket;

#endif //GLOBALS_H