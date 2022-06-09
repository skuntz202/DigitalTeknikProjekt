#ifndef GLOBALS_H
#define GLOBALS_H

extern int packetLength;
extern int compareValue;

typedef struct packetStruct{
	char type;
	char* data;
} Packet;

#endif //GLOBALS_H