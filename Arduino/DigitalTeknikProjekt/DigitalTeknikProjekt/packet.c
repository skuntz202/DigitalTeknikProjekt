#include "packet.h"

void packet_makePacket(char ADDR, char DATA, char* packet){
	char CRC;
	if(DATA >= 255){
		CRC = 255 - ((int)DATA % 255);
	} else{
		CRC = 255 - DATA;
	}
	packet[0] = ADDR;
	packet[1] = DATA;
	packet[2] = CRC;
}