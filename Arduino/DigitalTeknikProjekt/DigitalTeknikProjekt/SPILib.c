#include <avr/io.h>
#include <avr/interrupt.h>
#include "./SPILib.h"

static int SPITransmitFlag = 0;

/* Replace with your library code */
int SPI_init(char role){
	sei();
	if(role == MASTER){
		DDRB = (1<<PB0)|(1<<PB1)|(1<<PB2); //Sets ss-not, MOSI and SCK to be outputs
		PORTB = (1<<PB0);
		SPCR = (1<<SPIE)|(1<<SPE)|(1<<MSTR)|(1<<SPR1); //Initiates control register
		SPSR = (1<<SPI2X);
	}
	else if(role == SLAVE){
		DDRB = (1<<PB3); //Sets MISO as output
		PORTB = (1<<PB0); //Sets clock to pull high
		SPCR = (1<<SPE); //Initiates control register
	}
	else{
		return 0;
	}
	return 1;
}

char SPI_transmit(char transmitionCode, int toggleRecieve){
	PORTB &= 0b11111110;
	SPDR = transmitionCode;
	while(!SPITransmitFlag){} //Waits for transmition to finish
	SPITransmitFlag = 0;
	if(toggleRecieve == 1){
		return SPDR;
	}
	else if(toggleRecieve == 0){
		return 1;
	}
	PORTB |= 0b00000001;
	return 0;
}

ISR(SPI_STC_vect){
	SPITransmitFlag = 1;
}
