#include "packet.h"
#include "ADC.h"
#include <string.h>	

int packet_makeSPIPacket(SPIPacket* packet, UARTPacket* inputPacket){
	if(inputPacket->type == 0x01){
		//Enter pressed
		if(inputPacket->data[0] == 0x00){
			packet->DATA = inputPacket->data[1];
		}
		//Select pressed
		if(inputPacket->data[0] == 0x01){
			packet->ADDR = inputPacket->data[1];
		}
		//Run/Stop pressed
		else if(inputPacket->data[0] == 0x02){
			packet->ADDR = 0x04;
			packet->DATA = inputPacket->data[1];
		}
		//Reset
		else if(inputPacket->data[0] == 0x03){
			packet->ADDR = 0x00;
			packet->DATA = 0x00;
			strcpy(ADCWriteBuffer, "");
			ADCBufferIndex = 0;
			recordLength = 255;
		}
	}
	packet->CRC = 255 - packet->DATA;
	return 1;
}

void packet_makeOSCPacket(char type, char* DATA, UARTPacket* packet){
	packet->type = type;
	strcpy(packet->data, DATA);
}