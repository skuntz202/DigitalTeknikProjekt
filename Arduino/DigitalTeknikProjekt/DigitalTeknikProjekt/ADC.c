#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "ADC.h"
#include "UART.h"
#include "GLOBALS.h"

int UARTKernel = 0;
int UARTUser = 1;
unsigned int adcSample = 0;
unsigned long sampleRate = 24;
char ADCBuffer[2][1000];
volatile int ADCBufferIndex[2][1];
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
// 	packetReceiveFlag = 1;
// 	static int timer = 0;
// 	if(timer == 100){
// 		dims();
// 		} else{
// 		timer += 1;
// 	}
}

ISR(ADC_vect){
	adcSample = ADCH;
	ADCBuffer[UARTKernel][ADCBufferIndex[UARTKernel][0]] = adcSample;

	if(ADCBufferIndex[UARTKernel][0] == recordLength){
		ADCSampleFlag = 1;
	} else{
		ADCBufferIndex[UARTKernel][0]++;
 	}
}