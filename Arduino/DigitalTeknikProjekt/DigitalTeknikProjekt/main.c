#include <avr/io.h>
#include <stdio.h>
#include "SPILib.h"
#include "UART.h"
#include "packet.h"
#include "ADC.h"
#include "Globals.h"
#include "input.h"
#include <string.h>

#define F_CPU 16000000UL
#include <util/delay.h>

int transmitSPIPacket(SPIPacket* packet){
	//Transmits ADDR
	packet->ACK = SPI_transmit(packet->ADDR, 1);

	//Transmits DATA
	packet->ACK = SPI_transmit(packet->DATA, 1);

	//Transmits CRC
	packet->ACK = SPI_transmit(packet->CRC, 1);

	//Delay
	for(int timer = 0; timer < 20; timer++){}

	//Gets ACK
	packet->ACK = SPI_transmit(0x00, 1);
	if(packet->ACK != 0xFF){
		return -1;
	}
	return 1;
}

int transmitUARTPacket(UARTPacket* packet){
	char recordLengthL = (recordLength+7) & 0x00FF;
	char recordLengthH = (recordLength+7)>>8;
	UART_transChar(0x55);
	UART_transChar(0xAA);
	UART_transChar(recordLengthH);
	UART_transChar(recordLengthL);
	UART_transChar(packet->type);
	for(int i = 0; i < recordLength; i++){
		UART_transChar(packet->data[i]);
	}
	UART_transChar(0x00);
	UART_transChar(0x00);
	//UART_transChar('\n');
	//UART_transChar('\r');
	//for(int timer = 0; timer < 200; timer++){}
	return 1;
}

int main(void){
	UARTPacket OscPacket;
	OscPacket.type = GENERATOR;
	SPIPacket genPacket;
	genPacket.ADDR = 0x00;
	genPacket.DATA = 0x00;
	genPacket.CRC = 0xFF;
	SPI_init(MASTER);
	UART_init();
	ADC_init();
	
//Type 0x01 button 0x00
	buffer[0] = 0x55;
	buffer[1] = 0xAA;
	buffer[2] = 0x00;
	buffer[3] = 0x09;
	buffer[4] = 0x01;
	buffer[5] = 0x00;
	buffer[6] = 0x3F;
	buffer[7] = 0x00;
	buffer[8] = 0x00;
	
//Type 0x01 button 0x01
// 	buffer[0] = 0x55;
// 	buffer[1] = 0xAA;
// 	buffer[2] = 0x00;
// 	buffer[3] = 0x09;
// 	buffer[4] = 0x01;
// 	buffer[5] = 0x01;
// 	buffer[6] = 0x02;
// 	buffer[7] = 0x00;
// 	buffer[8] = 0x00;

//Type 0x01 button 0x02
// 	buffer[0] = 0x55;
// 	buffer[1] = 0xAA;
// 	buffer[2] = 0x00;
// 	buffer[3] = 0x09;
// 	buffer[4] = 0x01;
// 	buffer[5] = 0x02;
// 	buffer[6] = 0x05;
// 	buffer[7] = 0x00;
// 	buffer[8] = 0x00;


//Type 0x01 button 0x03
// 	buffer[0] = 0x55;
// 	buffer[1] = 0xAA;
// 	buffer[2] = 0x00;
// 	buffer[3] = 0x09;
// 	buffer[4] = 0x01;
// 	buffer[5] = 0x03;
// 	buffer[6] = 0x05;
// 	buffer[7] = 0x00;
// 	buffer[8] = 0x00;
	
//Type 0x02 High Sample Rate
// 	buffer[0] = 0x55;
// 	buffer[1] = 0xAA;
// 	buffer[2] = 0x00;
// 	buffer[3] = 0x0B;
// 	buffer[4] = 0x02;
// 	buffer[5] = 0xFF;
// 	buffer[6] = 0xFF;
// 	buffer[7] = 0x00;
// 	buffer[8] = 0x0B;
// 	buffer[9] = 0x00;
// 	buffer[10] = 0x00;
	
//Type 0x02 Low Sample Rate
// 	buffer[0] = 0x55;
// 	buffer[1] = 0xAA;
// 	buffer[2] = 0x00;
// 	buffer[3] = 0x0B;
// 	buffer[4] = 0x02;
// 	buffer[5] = 0x00;
// 	buffer[6] = 0x3F;
// 	buffer[7] = 0x00;
// 	buffer[8] = 0x0B;
// 	buffer[9] = 0x00;
// 	buffer[10] = 0x00;
	
//Type 0x02 Record Length 11
// 	buffer[0] = 0x55;
// 	buffer[1] = 0xAA;
// 	buffer[2] = 0x00;
// 	buffer[3] = 0x0B;
// 	buffer[4] = 0x02;
// 	buffer[5] = 0xFF;
// 	buffer[6] = 0xFF;
// 	buffer[7] = 0x00;
// 	buffer[8] = 0x0B;
// 	buffer[9] = 0x00;
// 	buffer[10] = 0x00;

//Type 0x02 Record Length 12
// 	buffer[0] = 0x55;
// 	buffer[1] = 0xAA;
// 	buffer[2] = 0x00;
// 	buffer[3] = 0x0B;
// 	buffer[4] = 0x02;
// 	buffer[5] = 0xFF;
// 	buffer[6] = 0xFF;
// 	buffer[7] = 0x00;
// 	buffer[8] = 0x0C;
// 	buffer[9] = 0x00;
// 	buffer[10] = 0x00;
	
	
//Type 0x03
// 	buffer[0] = 0x55;
// 	buffer[1] = 0xAA;
// 	buffer[2] = 0x00;
// 	buffer[3] = 0x07;
// 	buffer[4] = 0x03;
// 	buffer[5] = 0x00;
// 	buffer[6] = 0x00;
	
    while(1){
		//Make packet for SPI and transmission of packet
		//Test with ADC connected, remove dims and paste code into RX ISR, remove code in CTC ISR
		if(packetReceiveFlag){
			SPDR = 0x00;
			/*input_makePacket(&OscPacket, buffer);
			packet_makeSPIPacket(&genPacket, &OscPacket);
			
			//Clear buffer or it wont work after time, buffer should only be left uncleared when testing
			//strcpy(buffer, "");
 			if(OscPacket.type == GENERATOR){
 				if(transmitSPIPacket(&genPacket)){}
 			} 
 			else if(OscPacket.type == OSCILLOSCOPE){continue;} 
 			else if(OscPacket.type == BODEPLOT){continue;}*/
			packetReceiveFlag = 0;
		}
		
		//Sending ADC data to LabView    TEST WITH ADC CONNECTED, Expand makeOscPacket based on type
		if(ADCSampleFlag){
			packet_makeOSCPacket(OscPacket.type, ADCReadBuffer, &OscPacket);
			transmitUARTPacket(&OscPacket);
			strcpy(ADCReadBuffer, "");
			ADCSampleFlag = 0;
		}
    }
	free(buffer);
}
