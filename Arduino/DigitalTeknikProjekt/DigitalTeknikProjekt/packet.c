#include "packet.h"
#include <string.h>	

void packet_makeSPIPacket(char ADDR, char DATA, SPIPacket* packet){
	char CRC = 255 - DATA;
	packet->ADDR = ADDR;
	packet->DATA = DATA;
	packet->CRC = CRC;
}

void packet_makeOSCPacket(char type, char* DATA, UARTPacket* packet){
	packet->type = type;
	strcpy(packet->data, DATA);
}