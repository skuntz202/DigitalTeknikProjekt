# DigitalTeknikProjekt

Data packet:

ADDR;DATA;CRC;ACK

| ADDR |               |      |
| ---- | ------------- | ---- |
| 0x01 | Shape         |      |
| 0x02 | Amplitude     |      |
| 0x03 | Frequency     |      |
| 0x04 | Signal Enable |      |
| 0x05 | Reset         |      |

| DATA      |                      |      |
| --------- | -------------------- | ---- |
| 0x01      | Shape(Sine wave)     |      |
| 0x02      | Shape(Triangle wave) |      |
| 0x03      | Shape(Square wave)   |      |
| 0x00-0xFF | Amplitude            |      |
| 0x00-0xFF | Frequency            |      |
| 0x00      | Signal(Disable)      |      |
| 0x01      | Signal(Enable)       |      |

| ACK  |                            |      |
| ---- | -------------------------- | ---- |
| 0x00 | Transmission Error         |      |
| 0xFF | Transmission acknowledged. |      |

| ERR  | Description        | Type               |
| ---- | ------------------ | ------------------ |
| 101  | Transmission Error | SPI Response Error |
| 102  | Unknown Response   | SPI Response Error |





For følgende pakke.

ADDR: 0x02(00000010)

DATA: 0xF2(11110010)

CRC: 0xCD(10101011)

Pakke:

00000010 11110010 10101011 00000000

00000010 sendes først og fortæller slaven at vi sender amplituden.
11110010 sendes derefter og fortæller slaven hvilken værdi amplituden skal have.
10101011 sendes derefter og er CRC-8 værdien for data-pakken.
00000000 bruges til at clocke et acknowledgement tilbage, notér at et delay mellem CRC og ACK er nødvendigt for at slaven har tid til at processere pakken, eftersom ACK ikke som sådan er en del af pakken, men godkendelse på at pakken er modtaget.

CRC er en relativ simpel redundancy check, det er ikke nøvendigt at bruge specifikt CRC-8.

Frequency maxes out at 115.2kHz
 
 
 I am Gay
 
