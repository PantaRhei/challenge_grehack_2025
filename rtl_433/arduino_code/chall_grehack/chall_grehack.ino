// Nécessite la librairie RadioHead (RH_ASK)
// Installer via Library Manager : "RadioHead" par Mike McCauley
#include <RH_ASK.h>
#include <SPI.h>   // requis par RadioHead, même si on n'utilise pas SPI explicitement

// Choix des broches (adaptables si besoin)
// Ici : TX -> D2, RX -> D3 (on n'utilise pas le RX dans ce sketch mais RH_ASK demande un paramètre)
const uint8_t PIN_RX = 3;   // broche du récepteur (non utilisée ici, mais demandée par le constructeur)
/*
pin TX <-> 14
gnd <-> gnd
vcc <-> +
*/
const uint8_t PIN_TX = 14;   // broche de transmission (connecter le "DATA" de l'émetteur ici)

// Vitesse (bits/s) ASK — valeur classique 2000 (2 kbps)
RH_ASK rf_driver(2000, PIN_RX, PIN_TX);

// Messages encodes/decodes avec le chiffre de Vigenere
// Cle utilisee : RADIOWAVEAUTHMHZ

const char* messages_cipher[] = {"R: XRHG VCKW, RRH POX FN KHLA WRHYIANXC?", "R: KHLVUO AUVB VSFIZWTZH.", "R: KHH LNLKCNN GOQQSO YAYM", "R: UEFTONEY FPHV NAU FN KHH XOYMFJMZRT.", "S: TOSG, SLXM CAQBSNN.", "S: Z ME JEHV KHH SRRIRYANX—JPDZYHEN", "S: RNG LLWQAWTPQS.", "S: KHH FTWMFO RRH DOEQZEZDRG LNGMF KHHQF SAQVSN.", "R: PEDP, RNG EOZ KHH NOODSO XOW ZNYWZREY.", "R: GUQS RNDZQDINXS, CEDBVAR AAFSSPS,", "R: JPUIM-GALVHAD WLDOG, KHH NHRTS KHLVU.", "R: KHHG ME YIMIQGEY KHH VAVBSNN IESMOPEM.", "S: Z ZNWMFYEKXEX KHHQF THDVH FN", "S: JHRZHSAQI—GUUM THDWG.", "S: JOPMHDIIK RBRCH “WRHMRKM, WUU, RNG WEHLPWCF.”", "R: KHH GOQQSO RRH KRBQBC KO AAP", "R: KHHU NIWP XLLBHAR SUUAHO.", "R: ZT J RFIMQPIIK VVHZM", "R: WRHYIANXC WRRU 7 DHC KO TOPXZATZ EOQASJSZ.", "S: Z ME COVB YAON DY JEQACNS KO JPDZYHE", "S: TOQBOIIIETCHU. KHH FTWMFO JWLBQDEY KO", "S: RMSPWXIJYS XUHZFELGE KAFBWYS—KHHG IE", "S: WLRWRENB KHH GOZMF GLDVH.", "R: XOYMFJMZRT J GAQQQGIIK.", "R: KHHG RSNMR LS KO EEJWHEAOI.", "R: Z KOOL KHHU POX UOQ K", "R: EEJWHEAOI NIWP DAJQQWL DAPUOHS.", "S: NIVM. KHH NOODSO SRRIRYANXEX R", "S: DAQQTASOS TLDQAENB KHH IIYMFO", "S: RNG JKLMG SEOWBC KO VVHZMKNZ", "S: NIWP RN RTWQHQDZ GRRJZAM.", "R: DEDVKDIGI, KHH GOQQSO RRH WOUUWJG", "R: JOPMHDIIK TAOTSZ KHH 'IAGQOJT TOPUOJD.'", "R: KHHG IE KRDQBENB GIJMCJS RS ZNWMFYEKXOLL.", "S: GIJMCJS NOQ K JTDVR R THDVQA.", "S: NOODSO YAFSSZ R URRVS WLHMH RNG", "S: IESTOYEY KHH JIUMBO NIWP XULBON JOOWG.", "R: KHH NOUTR J TOOTOLSDRG ZNWW RN 80J RLECA TOYMF.", "S: GRHBHU DUFP. BEHX POXZ YEDL UOZV RNG", "S: POXZ KRDVGIIOXEL TLHIB.", "S: THRWGA R JIGM FNOG ZF ZT JTLTZ", "S: SEOQSREN ZN VNFZMLTDSN.", "R: TOSG KHDB.", "R: EEXBFWL LNWQZ KHH XLLBHAR JTRXG WAOTWJG."};
const char* messages_clear[]  = {"A: GREY ECHO, ARE YOU ON THIS FREQUENCY?", "A: THINGS JUST ESCALATED.", "A: THE UNICORN PONIES HAVE", "A: DECLARED OPEN WAR ON THE GOVERNMENT.", "B: COPY, BLUE LANTERN.", "B: I VE SEEN THE BROADCAST—SPARKLES", "B: AND ULTIMATUMS.", "B: THE OTTERS ARE MOBILIZING UNDER THEIR BANNER.", "A: YEAH, AND NOW THE WOLVES GOT INVOLVED.", "A: PUNK ANARCHISTS, LEATHER JACKETS,", "A: SPRAY-PAINTED FLAGS, THE WHOLE THING.", "A: THEY VE HIJACKED THE EASTERN REPEATER.", "B: I INTERCEPTED THEIR CHANT ON", "B: SHORTWAVE—PURE CHAOS.", "B: SOMETHING ABOUT “FREEDOM, FUR, AND FEEDBACK.”", "A: THE PONIES ARE TRYING TO JAM", "A: THEM WITH GLITTER BURSTS.", "A: IT S AFFECTING EVERY", "A: FREQUENCY FROM 7 MHZ TO COMPLETE NONSENSE.", "B: I VE LOST HALF MY SENSORS TO SPARKLE", "B: CONTAMINATION. THE OTTERS SWITCHED TO", "B: AMPHIBIOUS GUERRILLA TACTICS—THEY RE", "B: FLOODING THE POWER PLANT.", "A: GOVERNMENT S PANICKING.", "A: THEY ASKED US TO NEGOTIATE.", "A: I TOLD THEM YOU DON T", "A: NEGOTIATE WITH MAGICAL MAMMALS.", "B: WISE. THE WOLVES BROADCASTED A", "B: MANIFESTO CLAIMING THE RIVERS", "B: AND SKIES BELONG TO EVERYONE", "B: WITH AN ATTITUDE PROBLEM.", "A: MEANWHILE, THE PONIES ARE FORMING", "A: SOMETHING CALLED THE 'RADIANT COMMAND.'", "A: THEY RE TRAINING PIGEONS AS INTERCEPTORS.", "B: PIGEONS WON T STAND A CHANCE.", "B: WOLVES HACKED A DRONE FLEET AND", "B: REPLACED THE SIRENS WITH GUITAR SOLOS.", "A: THE WORLD S COLLAPSING INTO AN 80S ALBUM COVER.", "B: PRETTY MUCH. KEEP YOUR HEAD DOWN AND", "B: YOUR TRANSMITTER CLEAN.", "B: CHOOSE A SIDE ONLY IF IT STILL", "B: BELIEVES IN ENCRYPTION.", "A: COPY THAT.", "A: NEUTRAL UNTIL THE GLITTER STOPS FALLING."};

const int messageCount = 44;


int i = 0;
int r = 1;
int s = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(1); } // attendre le port série (utile pour MKR)
  Serial.println("Initialisation RH_ASK...");

  if (!rf_driver.init()) {
    Serial.println("ERREUR: impossible d initialiser RH_ASK.");
    Serial.println("Verifier les connexions et la librairie RadioHead.");
    // On reste bloqué pour signaler l'erreur
    while (1) {
      delay(500);
    }
  }
  // initialisation du générateur avec du "bruit"
  randomSeed(analogRead(A0));
  Serial.println("RH_ASK initialise. Envoi de 'hello word' toutes les 2s.");
}

void loop() {
  long n = random(0,60000) + 5000;
  // long n = 3000;
  if ((i!= 0) && (messages_cipher[i-1][0] == messages_cipher[i][0]) ) {
  Serial.print("====> ");
  Serial.print(messages_cipher[i-1][0]);
  Serial.print(" ");
  Serial.println(messages_cipher[i][0]);
    n = 500;
  } 



  //float time = (n * 0.10) + ;
  
  send_msg();
  
  Serial.print("Time: ");
  Serial.println(n);
  delay(n); // envoyer toutes les 2 secondes
}

void send_msg() {
    if (i < messageCount) {
    // envoyer le message
    const char *msg = messages_cipher[i];
    const char *msg_cipher = messages_clear[i];
    const uint8_t len = strlen(msg);
    bool ok = rf_driver.send((uint8_t*)msg, len);
    if (!ok) {
      Serial.println("-----------------------------------Erreur lors de l'appel à send()");
    } else {
      rf_driver.waitPacketSent(); // attendre la fin de l'emission
      Serial.print("Message envoye: ");
      Serial.println(msg);
      Serial.print("Message envoye dechiffrer: ");
      Serial.println(msg_cipher);
      i++;
    }
  }
}

