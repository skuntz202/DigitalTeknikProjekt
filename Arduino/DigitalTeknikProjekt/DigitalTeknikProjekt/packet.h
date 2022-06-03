#ifndef PACKET_H
#define PACKET_H

#define SHAPE 0x01
#define AMPLITUDE 0x02
#define FREQUENCY 0x03

#define SINE 0x01
#define TRIANGLE 0x02
#define SQUARE 0x03

void packet_makePacket(char ADDR, char DATA, char* packet);


#endif /*PACKET_H*/