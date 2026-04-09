
#define RXD2 16   // RX2 = connecté au TX de la MKR
#define TXD2 17   // TX2 = connecté au RX de la MKR

bool chall = true;

const String flag = "GH{C0nnect1";

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  delay(1000);
  Serial.println("ESP32-S3 prêt. Attente des HELLO...");
}

void loop() {
  if (chall) {
    func_chall();
  } else {
    func_demo();
  }
}

void func_chall(void) {
  if (Serial2.available()) {
    String msg = Serial2.readStringUntil('\n');
    msg.trim();
    Serial.print("Recu: ");
    Serial.println(msg);
    if (msg.equals(flag)) {
      Serial2.print("Ack");
      Serial.println("Flag reçu -> ACK envoyé");
    }
  }
  delay(10);
}


void func_demo(void) {
    if (Serial2.available()) {
    String msg = Serial2.readStringUntil('\n');
    msg.trim();
    Serial.println("Reçu : " + msg + " → envoi de PONG");
    Serial2.println("PONG");

  }
  delay(10);
}
