#include <avr/io.h>
#include <stdio.h>
#include "SPILib.h"
#include "UART.h"
#include "packet.h"

#define F_CPU 16000000UL
#include <util/delay.h>

int transmitPacket(char* packet){
	char response;
	for(int z = 0; z < 3; z++){
		for(int i = 0; i < 3; i++){
			response = SPI_transmit(packet[i], 1);
			if(response == 0x03){
				UART_transStr("Unkown error", 1);
				i = 0;
			}
			else if(response == 0x02){
				UART_transStr("CRC error", 1);
				i = 0;
			}
			else if(response == 0x01){
				UART_transStr("ACK error", 1);
				i = 0;
			}
			else if(response == 0x00){}else{
				UART_transStr("Response error, package terminated", 1);
				return 1;
			}
		}
		_delay_ms(1);
		response = SPI_transmit(0x00, 1);
		if(response == 0x03){
			UART_transStr("Unknown error", 1);
		}
		else if(response == 0x02){
			UART_transStr("CRC error", 1);
		}
		else if(response == 0x01){
			return 1;
		}
		else if(response == 0x00){}else{
			UART_transStr("Response error, package terminated", 1);
		}
	}
	UART_transStr("Transmission error, package terminated", 1);
	return 1;
}

int main(void){
	SPI_init(MASTER);
	UART_init();
	char* packet = (char*)calloc(3, sizeof(char));
    while(1){
		packet_makePacket(AMPLITUDE, 0x3F, packet);
		transmitPacket(packet);
    }
}

