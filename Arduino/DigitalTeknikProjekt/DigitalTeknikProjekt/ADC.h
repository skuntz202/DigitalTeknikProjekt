#ifndef ADC_H_
#define ADC_H_

extern int UARTKernel;
extern int UARTUser;
extern char ADCBuffer[2][1000];
extern unsigned long sampleRate;
extern unsigned int recordLength;
extern float voltage;
extern volatile int ADCSampleFlag;
extern volatile int ADCBufferIndex[2][1];
extern unsigned int adcSample;

extern void ADC_init();
extern void ADC_storeSample();

#endif /*ADC_H_*/