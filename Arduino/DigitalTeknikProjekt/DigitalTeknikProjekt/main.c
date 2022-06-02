/*
 * DigitalTeknikProjekt.c
 *
 * Created: 6/2/2022 11:30:50 AM
 * Author : marcu
 */ 

#include <avr/io.h>
#include "SPILib.h"
#include "UART.h"

int main(void)
{
	SPI_init(MASTER);
	UART_init();
	char response;
    while(1){
		response = SPI_transmit('t', 1);
		UART_transChar(response);
    }
}

