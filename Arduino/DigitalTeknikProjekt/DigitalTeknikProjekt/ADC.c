#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ADC.h"
#include "GLOBALS.h"

unsigned int adcSample = 0;
char ADCReadBuffer[1000];
char ADCWriteBuffer[1000];
int ADCBufferIndex = 0;
float voltage = 0.f;
int ADCSampleFlag = 0;

int initTimer0(){
	TCCR0A = (1<<WGM01);	    //Sets mode to CTC
	TCCR0B = (1<<CS02);			//Sets prescaler to 512
	OCR0A =	0x7C;				//Sets compare value to 124
	OCR0B =	0x7C;
	TIMSK0 = (1<<OCIE0A);
	TIFR0 = (1<<OCF0A);
	return 1;
}

void ADC_init(){
	initTimer0();
	ADMUX = (1<<REFS0)|(1<<ADLAR);
	ADCSRA = (1<<ADEN)|(1<<ADATE)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS0);
	ADCSRB = (1<<ADTS1)|(1<<ADTS0);
}

void ADC_storeSample(){
	adcSample = ADCH;
	/*voltage = (float)adcSample*0.013;
	ADCWriteBuffer[ADCBufferIndex] = adcSample;
	if(ADCBufferIndex == 999){
		ADCBufferIndex = 0;
		ADCSampleFlag = 1;
		
		//VERY EXPERIMENTAL
		char* temp = ADCWriteBuffer;
		*ADCWriteBuffer = *ADCReadBuffer;
		*ADCReadBuffer = *temp;
	} else{
		ADCBufferIndex += 1;
	}*/
}

ISR(TIMER0_COMPA_vect){
	
}

ISR(ADC_vect){
	ADC_storeSample();
}