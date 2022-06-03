#include <avr/io.h>
#include <avr/interrupt.h>

volatile int transmitComplete = 1;
volatile int bufferIndex = 0;
char buffer[100];
char RX = ' ';
int carriageReturn = 0;
int receiveComplete = 0;
int receiveCompleteFlag = 0;


void UART_init(){
	sei();
	int ubrr = 51;
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	UCSR0B |= (1<<RXCIE0)|(1<<TXCIE0)|(1<<RXEN0)|(1<<TXEN0);
	UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);
}


void UART_transChar(char transData){
	while(!transmitComplete){}
	transmitComplete = 0;
	UDR0 = transData;
}

void UART_transStr(char* transDataStr, int endLine){
	for(int i = 0; transDataStr[i] != '\0'; i++){
		UART_transChar(transDataStr[i]);
	}
	if(endLine){
		UART_transChar('\r');
		UART_transChar('\n');
	}
}

void checkCarriageReturn(){
	if(RX == '\r'){
		carriageReturn = 1;
	}
	else if(carriageReturn && RX == '\n'){
		receiveComplete = 1;
		bufferIndex = 0;
	}
}

void UART_receiveChar(){
	RX = UDR0;
	buffer[bufferIndex] = RX;
	bufferIndex += 1;
	//checkCarriageReturn();
}


ISR(USART0_RX_vect){
	receiveCompleteFlag = 1;
};

ISR(USART0_TX_vect){
	transmitComplete = 1;
}