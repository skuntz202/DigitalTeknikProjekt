#ifndef GLOBALS_H
#define GLOBALS_H

extern int packetLength;
extern int compareValue;

#define GENERATOR 0x01
#define OSCILLOSCOPE 0x02
#define BODEPLOT 0x03

typedef struct{
	int sampleRate : 2;
	int recordLength : 2;
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