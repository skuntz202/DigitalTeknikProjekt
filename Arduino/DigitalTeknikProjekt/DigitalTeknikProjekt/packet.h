#ifndef PACKET_H
#define PACKET_H

#include "Globals.h"

#define SHAPE 0x01
#define AMPLITUDE 0x02
#define FREQUENCY 0x03

#define SINE 0x01
#define TRIANGLE 0x02
#define SQUARE 0x03

extern int packet_makeSPIPacket(SPIPacket* packet, UARTPacket* inputPacket);
extern void packet_makeOSCPacket(char type, char* DATA, UARTPacket* packet);
extern void packet_makeOSCResponse(SPIPacket* inputPacket, UARTPacket* returnPacket);

#endif /*PACKET_H*/
