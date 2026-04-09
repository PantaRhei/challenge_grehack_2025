#include <Wire.h>

#define MKR_ADDR 0x42  // adresse de l'esclave

int c = 0;

void receiveEvent(int howMany) {
  Serial.print("Recu: ");
  while (Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
  Serial.print(" ");
  Serial.println(c);
  c = c + 1;
  if (c > 100) {
    c = 0;
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Wire.begin(MKR_ADDR);     // mode esclave (SDA=11, SCL=12)
  Wire.onReceive(receiveEvent);
  Serial.println("MKR WiFi 1010 - esclave I2C prêt (adresse 0x42)");
}

void loop() {
  delay(100);
}
