

#define RX_PIN 0   // RX = connecté au TX de l’ESP32-S3
#define TX_PIN 1   // TX = connecté au RX de l’ESP32-S3

#define MAX_COMPTEUR 10

bool chall = true;

const String flag = "GH{C0nnect1";

int compteur = 0;

void setup() {
  Serial.begin(115200);
  Serial1.begin(9600);
  delay(5000);
  Serial.println("MKR WiFi 1010 pret.");
}

void loop() {
  if (chall) {
    func_chall();
  } else {
    func_demo();
  }
  //delay(1000);
}

void func_chall(void) {
  String msg = flag;
  Serial.print("Send payload: ");
  Serial.println(msg);
  Serial1.print(msg);
  delay(10);
  if (Serial1.available()) {
    String reponse = Serial1.readStringUntil('\n');
    reponse.trim();
    Serial.println("Recu : " + reponse);
  }
  delay(2000);
}

void func_demo() {
  Serial1.println("PING");
  Serial.print("Envoy : PING ");
  Serial.println(compteur);

  // Lecture éventuelle de la réponse
  if (Serial1.available()) {
    String reponse = Serial1.readStringUntil('\n');
    reponse.trim();
    Serial.println("Recu : " + reponse + " " + compteur);
    compteur = compteur + 1;
    if (compteur > MAX_COMPTEUR) {
      Serial.println("Reset compteur");
      compteur = 0;
    }
  }
}
