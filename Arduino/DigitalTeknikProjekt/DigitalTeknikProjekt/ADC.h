#ifndef ADC_H_
#define ADC_H_

extern char ADCReadBuffer[1000];
extern char ADCWriteBuffer[1000];
extern float voltage;
extern int ADCSampleFlag;
extern int ADCBufferIndex;
extern unsigned int adcSample;

extern void ADC_init();
extern void ADC_storeSample();


#endif /*ADC_H_*/