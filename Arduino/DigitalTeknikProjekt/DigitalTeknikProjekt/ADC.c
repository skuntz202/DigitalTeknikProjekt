#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ADC.h"
#include "UART.h"
#include "GLOBALS.h"

unsigned int adcSample = 0;
unsigned long sampleRate = 10;
char ADCReadBuffer[1000];
char ADCWriteBuffer[1000];
volatile int ADCBufferIndex = 0;
float voltage = 0.f;
volatile int ADCSampleFlag = 0;
unsigned int recordLength = 30;

int initTimer1(){
	TCCR1B = (1<<WGM12)|(1<<CS10)|(1<<CS11);	    //Sets mode to CTC, Sets prescaler to 64
	OCR1A =	0x18;				//Sets compare value to 24
	OCR1B =	0x18;				//Sets compare value to 24
	TIMSK1 = (1<<OCIE1B);
	TIFR1 = (1<<OCF1B);
	return 1;
}

void ADC_init(){
	sei();
	initTimer1();
	ADMUX |= (1<<ADLAR);
	ADCSRA |= (1<<ADPS2)|(1<<ADEN)|(1<<ADATE)|(1<<ADIE);
	ADCSRB |= (1<<ADTS2)|(1<<ADTS0);
}

ISR(TIMER1_COMPB_vect){
	packetReceiveFlag = 1;
	static int timer = 0;
	if(timer == 100){
		dims();
	} else{
		timer += 1;
	}
}

ISR(ADC_vect){
	adcSample = ADCH;
	ADCWriteBuffer[ADCBufferIndex] = adcSample;
	if(ADCBufferIndex == recordLength){
		ADCBufferIndex = 0;
		ADCSampleFlag = 1;
	} else{
		ADCBufferIndex += 1;
 	}
}