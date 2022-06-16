#ifndef ADC_H_
#define ADC_H_

extern char ADCReadBuffer[1000];
extern char ADCWriteBuffer[1000];
extern unsigned long sampleRate;
extern unsigned int recordLength;
extern unsigned int tempRecordLength;
extern float voltage;
extern volatile int ADCSampleFlag;
extern volatile int ADCBufferIndex;
extern unsigned int adcSample;

extern void ADC_init();
extern void ADC_storeSample();


#endif /*ADC_H_*/