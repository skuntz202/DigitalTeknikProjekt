# DigitalTeknikProjekt

Data packet:

ADDR;DATA;CRC;ACK

| ADDR |           |      |
| ---- | --------- | ---- |
| 0x01 | Shape     |      |
| 0x02 | Amplitude |      |
| 0x03 | Frequency |      |

| DATA      |               |      |
| --------- | ------------- | ---- |
| 0x01      | Sine wave     |      |
| 0x02      | Triangle wave |      |
| 0x03      | Square wave   |      |
| 0x00-0xFF | Amplitude     |      |
| 0x00-0xFF | Frequency     |      |

| ACK  |                                |      |
| ---- | ------------------------------ | ---- |
| 0x00 | Placeholder during transmition |      |
| 0x01 | Transmition acknowledged.      |      |
| 0x02 | CRC error                      |      |
| 0x03 | Unknown error                  |      |

CRC is any type of parity check, legit CRC might be implemented but time is the limiting factor.



Frequency maxes out at 115.2kHz

