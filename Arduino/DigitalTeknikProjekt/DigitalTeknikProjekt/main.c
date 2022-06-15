#include <avr/io.h>
#include <stdio.h>
#include "SPILib.h"
#include "UART.h"
#include "packet.h"
#include "ADC.h"
#include "Globals.h"
#include "input.h"

#define F_CPU 16000000UL
#include <util/delay.h>

int transmitSPIPacket(SPIPacket* packet){
	//Transmits address
	packet->ACK = SPI_transmit(packet->ADDR, 1);
	//UART_transChar(packet->ACK);
	/*if(packet->ACK == 0x03){
		UART_transStr("ERR: 101", 1);
		return -1;
	}
	else if(packet->ACK == 0x02){
		UART_transStr("ERR: 102", 1);
		return -1;
	}
	else if(packet->ACK == 0x01){
		UART_transStr("ERR: 103", 1);
		return -1;
	}
	else if(packet->ACK == 0x00){}else{
		UART_transStr("ERR: 104", 1);
		return -1;
	}*/

	//Transmits data
	packet->ACK = SPI_transmit(packet->DATA, 1);
	//UART_transChar(packet->ACK);
	/*if(packet->ACK == 0x03){
		UART_transStr("ERR: 101", 1);
		return -1;
	}
	else if(packet->ACK == 0x02){
		UART_transStr("ERR: 102", 1);
		return -1;
	}
	else if(packet->ACK == 0x01){
		UART_transStr("ERR: 103", 1);
		return -1;
	}
	else if(packet->ACK == 0x00){}else{
		UART_transStr("ERR: 104", 1);
		return -1;
	}*/

	//Transmits CRC
	packet->ACK = SPI_transmit(packet->CRC, 1);
	//UART_transChar(packet->ACK);
	/*if(packet->ACK == 0x03){
		UART_transStr("ERR: 101", 1);
		return -1;
	}
	else if(packet->ACK == 0x02){
		UART_transStr("ERR: 102", 1);
		return -1;
	}
	else if(packet->ACK == 0x01){
		UART_transStr("ERR: 103", 1);
		return -1;
	}
	else if(packet->ACK == 0x00){}else{
		UART_transStr("ERR: 104", 1);
		return -1;
	}*/

	//Delay
	for(int timer = 0; timer < 20; timer++){}

	//Gets ack
	packet->ACK = SPI_transmit(0x00, 1);
	UART_transChar(packet->ACK);
	/*if(packet->ACK == 0x03){
		UART_transStr("ERR: 101", 1);
		return -1;
	}
	else if(packet->ACK == 0x02){
		UART_transStr("ERR: 102", 1);
		return -1;
	}
	else if(packet->ACK == 0x01){
		return 1;
	}
	else if(packet->ACK == 0x00){
		UART_transStr("ERR: 105", 1);
		return -1;
	} else{
		UART_transStr("ERR: 104", 1);
		return -1;
	}*/
	return 0;
}

int transmitUARTPacket(UARTPacket* packet){
	char recordLengthL = (packet->recordLength+7) & 0x00FF;
	char recordLengthH = (packet->recordLength+7)>>8;
	UART_transChar(0x55);
	UART_transChar(0xAA);
	UART_transChar(recordLengthH);
	UART_transChar(recordLengthL);
	UART_transChar(packet->type);
	for(int i = 0; i < packet->recordLength; i++){
		UART_transChar(packet->data[i]);
	}
	UART_transChar(0x00);
	UART_transChar(0x00);
	UART_transChar('\n');
	UART_transChar('\r');
	for(int timer = 0; timer < 20; timer++){}
	return 1;
}

int main(void){
	UARTPacket OscPacket;
	SPIPacket genPacket;
	genPacket.ADDR = 0x02;
	genPacket.DATA = 0x02;
	genPacket.CRC = 0x00;
	SPI_init(MASTER);
	UART_init();
	ADC_init();
	char* data = "SS";
	OscPacket.recordLength = 2;
	char* temptemp = (char*)calloc(100, sizeof(char));
	temptemp[0] = 0x55;
	temptemp[1] = 0xAA;
	temptemp[2] = 0x00;
	temptemp[3] = 0x09;
	temptemp[4] = 0x01;
	temptemp[5] = 0x00;
	temptemp[6] = 0x3F;
	temptemp[7] = 0x00;
	temptemp[8] = 0x00;
    while(1){
		if(receiveCompleteFlag){
			UART_receiveChar();
			receiveCompleteFlag = 0;
		}
		if(packetReceiveFlag){
			input_makePacket(&OscPacket, temptemp);
			/*char* temp = buffer;
			buffer = (char*)calloc(100, sizeof(char));
			free(temp);*/
			packet_makeSPIPacket(&genPacket, &OscPacket);
			transmitSPIPacket(&genPacket);
			packetReceiveFlag = 0;
		}
		//packet_makeOSCPacket(OSCILLOSCOPE, data, &OscPacket);
		// transmitUARTPacket(&OscPacket);
		//UART_transChar(adcSample);
		if(ADCSampleFlag){
			//Send contents of ADCReadBuffer to computer.
		}
    }
}
