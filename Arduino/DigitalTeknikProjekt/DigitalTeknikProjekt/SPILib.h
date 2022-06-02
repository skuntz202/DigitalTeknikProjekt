#ifndef SPILib_H
#define SPILib_H

#define MASTER 0x00
#define SLAVE 0xff

int SPI_init(char role);
char SPI_transmit(char transmitionCode, int toggleRecieve);

#endif // SPILib_H