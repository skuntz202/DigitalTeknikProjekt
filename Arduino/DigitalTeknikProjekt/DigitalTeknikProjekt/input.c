#include "input.h"
#include <stdio.h>
#include <stdlib.h>

UARTPacket input_checkPacket(char* packet){
	UARTPacket returnData;
	returnData.type = packet[4];
	if(returnData.type == 0x01){
		returnData.data = (char*)calloc(2, sizeof(char));
		returnData.data[0] = packet[5];
		returnData.data[1] = packet[6];
	}
	else if(returnData.type == 0x02){
		returnData.data = (char*)calloc(4, sizeof(char));
		returnData.data[0] = packet[5];
		returnData.data[1] = packet[6];
		returnData.data[2] = packet[7];
		returnData.data[3] = packet[8];
	}
	else if(returnData.type == 0x03){}
	return returnData;
}