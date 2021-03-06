#include "input.h"
#include "ADC.h"
#include "UART.h"
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input_makePacket(UARTPacket* returnData, char* packet){
	if(packet[0] != 0x55 || packet[1] != 0xAA){
		return -1;
	}
	if(packet[4] == GENERATOR){
		if(packet[7] != 0x00 || packet[8] != 0x00){
			return -1;
		}
		returnData->type = packet[4];
		returnData->data = (char*)calloc(2, sizeof(char));
		returnData->data[0] = packet[5];
		returnData->data[1] = packet[6];
	}
	else if(packet[4] == OSCILLOSCOPE){
		if(packet[9] != 0x00 || packet[10] != 0x00){
			return -1;
		}
		returnData->type = packet[4];
		returnData->data = (char*)calloc(4, sizeof(char));
		int inputSampleRate = ((packet[5]<<8)&0x7F00) + packet[6];
		if(inputSampleRate < 10){
			sampleRate = 24999;
		} else if(inputSampleRate > 10000){
			sampleRate = 24;
		} else{
			sampleRate = (unsigned long)((16000000.f*(1.f/(float)inputSampleRate)-64.f)/64.f);	
		}
		OCR1B = sampleRate;
		OCR1A = sampleRate;
		ADCBufferIndex[UARTKernel][0] = 0;
		ADCBufferIndex[UARTUser][0] = 0;
		int inputRecordLength = ((packet[7]<<8)&0x7F00) + packet[8];
		if(inputRecordLength > 10000){
			recordLength = 10000;
		} else if(inputRecordLength < 10){
			recordLength = 10;
		} else{
			recordLength = inputRecordLength;
		}
	}
	else if(packet[4] == BODEPLOT){}
	return 1;
}