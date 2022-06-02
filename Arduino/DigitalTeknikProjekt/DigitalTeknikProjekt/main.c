#include <avr/io.h>
#include <stdio.h>
#include "SPILib.h"
#include "UART.h"

#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	SPI_init(MASTER);
	UART_init();
	char response;
    while(1){
		//_delay_ms(100);
		response = SPI_transmit(0xF2, 1);
		UART_transChar(response);
    }
}

