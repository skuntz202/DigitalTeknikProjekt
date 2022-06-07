#include <avr/io.h>
#include <avr/interrupt.h>
#include "./SPILib.h"

/* Replace with your library code */
int SPI_init(char role){
	sei();
	if(role == MASTER){
		DDRB = (1<<PB0)|(1<<PB1)|(1<<PB2); //Sets ss-not, MOSI and SCK to be outputs
		PORTB = 0x00;
		SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0); //Initiates control register
	}
	else if(role == SLAVE){
		DDRB = (1<<PB3); //Sets MISO as output
		PORTB = (1<<PB0); //Sets clock to pull high
		SPCR = 0b01001000; //Initiates control register
	}
	else{
		return 0;
	}
	return 1;
}

char SPI_transmit(char transmitionCode, int toggleRecieve){
	if((DDRB & 0b00000111) == 0b00000111){
		PORTB &= 0b11111110;
		SPDR = transmitionCode;
		while((SPSR & 0b10000000) != 0b10000000){} //Waits for transmition to finish
		PORTB |= 0b00000001;
		if(toggleRecieve == 1){
			return SPDR;
		}
		else if(toggleRecieve == 0){
			return 1;
		}
	}
	return 0;
}

ISR(SPI_STC_vect){
	
}
