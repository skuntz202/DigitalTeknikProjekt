#include "packet.h"

void packet_makePacket(char ADDR, char DATA, SPIPacket* packet){
	char CRC = 255 - DATA;
	packet->ADDR = ADDR;
	packet->DATA = DATA;
	packet->CRC = CRC;
}