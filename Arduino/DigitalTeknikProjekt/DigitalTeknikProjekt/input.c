#include "input.h"
#include "ADC.h"
#include "UART.h"
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>

int input_makePacket(UARTPacket* returnData, char* packet){
	if(packet[0] != 0x55 || packet[1] != 0xAA){
		return -1;
	}
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
		int inputSampleRate = ((packet[5]<<8)&0x7F00) + packet[6];
		if(inputSampleRate < 10){
			sampleRate = 24999;
		} else if(inputSampleRate > 10000){
			sampleRate = 0x8F;
		} else{
			sampleRate = (unsigned long)((16000000.f*(1.f/(float)inputSampleRate)-64.f)/64.f);	
		}
		OCR1B = sampleRate;
		OCR1A = sampleRate;
		int inputRecordLength = (packet[7]<<8) + packet[8];
		if(inputRecordLength > 10000){
			recordLength = 10000;
		} else if(inputRecordLength < 10){
			recordLength = 10;
		} else{
			recordLength = inputRecordLength;
		}
	}
	else if(packet[4] == 0x03){}
	return 1;
}