#include <Wire.h>

#define SDA_PIN 2
#define SCL_PIN 1
#define MKR_ADDR 0x42  // adresse de la MKR esclave

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);  // init en maître, pins explicites
  Wire.setClock(10000);         // 10 kHz
  delay(1000);
  Serial.println("ESP32-S3 - maître I2C pret");
}

void loop() {
  const char msg[] = "v1tySecure}";
  Serial.print("Message envoyé: ");
  Serial.println(msg);
  Wire.beginTransmission(MKR_ADDR);
  Wire.write((const uint8_t*)msg, sizeof(msg) - 1); // envoie les 5 octets 'H','E','L','L','O'
  uint8_t err = Wire.endTransmission();

  if (err == 0) Serial.println("Message envoye");
  else {
    Serial.print("Erreur I2C: ");
    Serial.println(err);
  }

  delay(3000);
}
