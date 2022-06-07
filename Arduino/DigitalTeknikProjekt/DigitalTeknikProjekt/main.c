#include <avr/io.h>
#include <stdio.h>
#include "SPILib.h"
#include "UART.h"
#include "packet.h"
#include "ADC.h"

#define F_CPU 16000000UL
#include <util/delay.h>

int transmitPacket(char* packet){
	char response;
	for(int i = 0; i < 3; i++){
		response = SPI_transmit(packet[i], 1);
		if(response == 0x03){
			UART_transStr("ERR: 101", 1);
			return -1;
		}
		else if(response == 0x02){
			UART_transStr("ERR: 102", 1);
			return -1;
		}
		else if(response == 0x01){
			UART_transStr("ERR: 103", 1);
			return -1;
		}
		else if(response == 0x00){}else{
			UART_transStr("ERR: 104", 1);
			return -1;
		}
	}
	for(int timer = 0; timer < 200; timer++){}
	//_delay_ms(1);
	response = SPI_transmit(0x00, 1);
	if(response == 0x03){
		UART_transStr("ERR: 101", 1);
		return -1;
	}
	else if(response == 0x02){
		UART_transStr("ERR: 102", 1);
		return -1;
	}
	else if(response == 0x01){return 1;}
	else if(response == 0x00){
		UART_transStr("ERR: 105", 1);
		return -1;
	} else{
		UART_transStr("ERR: 104", 1);
		return -1;
	}
	return 0;
}

int main(void){
	SPI_init(MASTER);
	UART_init();
	ADC_init();
	char* packet = (char*)calloc(3, sizeof(char));
    while(1){
		if(receiveCompleteFlag){
			UART_receiveChar();
			receiveCompleteFlag = 0;
		}
		packet_makePacket(AMPLITUDE, 0x3F, packet);
		transmitPacket(packet);
		UART_transChar(adcSample);
		if(ADCSampleFlag){
			//Send contents of ADCReadBuffer to computer.
		}
    }
}
