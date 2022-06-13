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
		UART_transStr("ERR: 103", 1);
		return -1;
	}
	else if(packet->ACK == 0x00){}else{
		UART_transStr("ERR: 104", 1);
		return -1;
	}*/

	//Transmits data
	packet->ACK = SPI_transmit(packet->DATA, 1);
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
		UART_transStr("ERR: 103", 1);
		return -1;
	}
	else if(packet->ACK == 0x00){}else{
		UART_transStr("ERR: 104", 1);
		return -1;
	}*/

	//Transmits CRC
	packet->ACK = SPI_transmit(packet->CRC, 1);
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
		UART_transStr("ERR: 103", 1);
		return -1;
	}
	else if(packet->ACK == 0x00){}else{
		UART_transStr("ERR: 104", 1);
		return -1;
	}*/

	//Delay
	for(int timer = 0; timer < 200; timer++){}

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
	SPI_transmit(0x55, 0);
	SPI_transmit(0xAA, 0);
	SPI_transmit(recordLengthH, 0);
	SPI_transmit(recordLengthL, 0);
	SPI_transmit(packet->type, 0);
	for(int i = 0; i < packet->recordLength; i++){
		SPI_transmit(packet->data[i], 0);
	}
	SPI_transmit(0x00, 0);
	SPI_transmit(0x00, 0);
	for(int timer = 0; timer < 200; timer++){}
	return 1;
}

int main(void){
	UARTPacket OscPacket;
	SPIPacket genPacket;
	SPI_init(MASTER);
	UART_init();
	ADC_init();
	char* data = "SS";
	OscPacket.recordLength = 2;
    while(1){
		if(receiveCompleteFlag){
			UART_receiveChar();
			receiveCompleteFlag = 0;
		}
		if(packetReceiveFlag){
			OscPacket = input_makePacket(buffer);
			char* temp = buffer;
			buffer = (char*)calloc(100, sizeof(char));
			free(temp);
			packetReceiveFlag = 0;
		}
		//packet_makeSPIPacket(AMPLITUDE, 0x3F, &genPacket);
		//transmitSPIPacket(&genPacket);
		packet_makeOSCPacket(OSCILLOSCOPE, data, &OscPacket);
		transmitUARTPacket(&OscPacket);
		//UART_transChar(adcSample);
		if(ADCSampleFlag){
			//Send contents of ADCReadBuffer to computer.
		}
    }
}
