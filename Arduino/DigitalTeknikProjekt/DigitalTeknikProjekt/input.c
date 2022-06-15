#include "input.h"
#include <stdio.h>
#include <stdlib.h>

int input_makePacket(UARTPacket* returnData, char* packet){
	if(packet[0] != 0x55 || packet[1] != 0xAA){
		return -1;
	}
	char* temp = (char*)calloc(2, sizeof(char));
	if(packet[4] == 0x01){
		if(packet[7] != 0x00 || packet[8] != 0x00){
			return -1;
		}
		returnData->type = packet[4];
		returnData->data = (char*)calloc(2, sizeof(char));
		returnData->data[0] = packet[5];
		returnData->data[1] = packet[6];
	}
	else if(packet[4] == 0x02){
		if(packet[9] != 0x00 || packet[10] != 0x00){
			return -1;
		}
		returnData->type = packet[4];
		returnData->data = (char*)calloc(4, sizeof(char));
		temp[0] = packet[5];
		temp[1] = packet[6];
		returnData->sampleRate = atoi(temp);
		temp[0] = packet[7];
		temp[1] = packet[8];
		returnData->recordLength = atoi(temp);
	}
	else if(packet[4] == 0x03){}
	return 1;
}