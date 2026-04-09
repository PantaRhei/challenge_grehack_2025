# SPI
https://www.makerguides.com/master-slave-spi-communication-arduino/

two arduino

# Connection 

MASTER     SLAVE
SCK    <->  SLK    (CH1)
MISO   <->  MISO   (CH2)
MOSI   <->  MOSI   (CH3)
SS     <->  SS     (CH4)


# Parametter

Dans PulseView :
- Decoder : SPI
- CLK : SCK
- MOSI : MOSI
- MISO : optionnel
- CS : SS
- Mode : 0
- Clock polarity : Idle low
- Clock phase : sample on rising edge
- Word size : 8 bits
- Bit order : MSB First


# Flag
```
v1tySecure}
```