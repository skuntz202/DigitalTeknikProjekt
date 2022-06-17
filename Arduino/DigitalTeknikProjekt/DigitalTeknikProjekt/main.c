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
	if(packet->ADDR == 0x01){
		packet->curr = 0x00;
		packet->shape = packet->DATA;
	} else if(packet->ADDR == 0x02){
		packet->curr = 0x01;
		packet->amplitude = packet->DATA;
	} else if(packet->ADDR == 0x03){
		packet->curr = 0x02;
		packet->frequency = packet->DATA;
	} else

	//Transmits DATA
	packet->ACK = SPI_transmit(packet->DATA, 1);

	//Transmits CRC
	packet->ACK = SPI_transmit(packet->CRC, 1);

	//Delay
	//for(int timer = 0; timer < 20; timer++){}

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
	//Transmits sync byte
	UART_transChar(0x55);
	UART_transChar(0xAA);
	
	//Transmits total packet length
	UART_transChar(recordLengthH);
	UART_transChar(recordLengthL);
	
	//Transmits packet type
	UART_transChar(packet->type);
	
	//Transmits packet data
	for(int i = 0; i < ADCBufferIndex[UARTUser][0]; i++){
		UART_transChar(packet->data[i]);
	}
	
	//Transmits CRC(ZERO16)
	UART_transChar(0x00);
	UART_transChar(0x00);
	return 1;
}

int main(void){
	UARTPacket OscPacket;
	OscPacket.type = GENERATOR;
	SPIPacket genPacket;
	
	//Initializes SPI packet
	genPacket.ADDR = 0x00;
	genPacket.DATA = 0x00;
	genPacket.CRC = 0xFF;
	SPI_init(MASTER);
	UART_init();
	ADC_init();
	
	
	
/////////  TEST PACKETS, ONLY WORK IF CTC ISR AND DIMS() IS IMPLEMENTED/////////
//Type 0x01 button 0x00
// 	buffer[0] = 0x55;
// 	buffer[1] = 0xAA;
// 	buffer[2] = 0x00;
// 	buffer[3] = 0x09;
// 	buffer[4] = 0x01;
// 	buffer[5] = 0x00;
// 	buffer[6] = 0x3F;
// 	buffer[7] = 0x00;
// 	buffer[8] = 0x00;
	
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
		if(packetReceiveFlag){
			//Handles input packet
			input_makePacket(&OscPacket, buffer);
			
			//Makes SPI compatible packet
			packet_makeSPIPacket(&genPacket, &OscPacket);
			
			if(OscPacket.type == GENERATOR){
				//Transmits packet via SPI
 				if(transmitSPIPacket(&genPacket)){}
				packet_makeOSCResponse(&genPacket, &OscPacket);
				transmitUARTPacket(&OscPacket);
				OscPacket.type = 0x00;
			 }
			packetReceiveFlag = 0;
		}
		
		//Sending ADC data to LabView
		if(ADCSampleFlag){
			//Swaps buffers
			UARTUser = (!UARTUser) & 0x01;
			UARTKernel = (!UARTKernel) & 0x01;
			ADCBufferIndex[UARTKernel][0] = 0;
			
			//Makes packet labview accepts
			packet_makeOSCPacket(OSCILLOSCOPE, ADCBuffer[UARTUser], &OscPacket);
			
			//Sends Labview packet via UART
			transmitUARTPacket(&OscPacket);
	
			ADCSampleFlag = 0;
		}
    }
	free(buffer);
}
