#include "packet.h"

void packet_makePacket(char ADDR, char DATA, char* packet){
	char CRC;
	int temp = (int)DATA % 255;
	CRC = 255 - temp;
	packet[0] = ADDR;
	packet[1] = DATA;
	packet[2] = CRC;
}