#include "SPI.h"

char str[] = "v1tySecure}";

void setup() {
  Serial.begin(115200);  // set baud rate to 115200 for usart
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);  //divide the clock by 8
  Serial.println("Hello I'm SPI Master");
}

void loop(void) {
  digitalWrite(SS, LOW);  // enable Slave Select
  // send test string
  for (int i = 0; i < sizeof(str); i++)
    SPI.transfer(str[i]);
  digitalWrite(SS, HIGH);  // disable Slave Select
  delay(20);
}
