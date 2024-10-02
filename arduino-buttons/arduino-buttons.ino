//variabler for knapper og lys:
const int resetKnapp = 5;
const int led = 13;
const int p1Knapp = 2;
const int p1Led = 7;
const int p2Knapp = 3;
const int p2Led = 8;
const boolean trykket = false;

//variabler for resetknappen:
int resetTilstand = LOW;
int knappNaa;
int knappFor = HIGH;

//variabler for tilfeldighets-implementasjonen:
const unsigned long interval = 400;
unsigned long forrigeTid = 0;
long tilfeldig;

//variabler for spillet:
boolean spill = false;
boolean p1State = digitalRead(p1Knapp);
boolean p2State = digitalRead(p2Knapp);
int p1Poeng = 0;
int p2Poeng = 0;

//funksjon som skriver ut poeng til seriel-terminalen:
void poeng() {
  Serial.print("P1: ");
  Serial.print(p1Poeng);
  Serial.print("     P2: ");
  Serial.print(p2Poeng);
  Serial.println(" ");
}

//funksjon som "rydder" seriel-terminalen:
void rydd() {
  for (int i = 0 ; i < 20 ; i++) {
    Serial.println(" ");
  }
}

void setup() {
  pinMode(resetKnapp, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  
  pinMode(p1Knapp, INPUT_PULLUP);
  pinMode(p1Led, OUTPUT);
  pinMode(p2Knapp, INPUT_PULLUP);
  pinMode(p2Led, OUTPUT);
}

void loop() {
  //resetknapp implementasjon:
  knappNaa = digitalRead(resetKnapp);  
  if (knappNaa && !knappFor) {
    resetTilstand = !resetTilstand;
    
    while (resetKnapp == true) {
      delay(50);
      //gjor ingenting saa lenge knappen er trykket.
    }
    rydd();
    delay(1000);
  }
  
  digitalWrite(led, resetTilstand);
  knappFor = knappNaa;
  
  //starter/stopp med resetkanppen:
  if (resetTilstand) {
    spill = true;
  }
  
  //kjores naar spillet er slutt eller faar "reset":
  else {
    noTone(6);
    spill = false;
    digitalWrite(p1Led, LOW);
    digitalWrite(p2Led, LOW);
    p1Poeng = 0;
    p2Poeng = 0;
  }
  
  //tilfeldighet:
  if (spill == true) {
    //tilfeldighet benytter millis for aa ikke forstyrre resten:
    unsigned long tidNaa = millis();
    if (tidNaa - forrigeTid >= interval) {
      digitalWrite(tilfeldig, LOW);
      //bruker analogRead paa en tom A-pin for tilfeldig verdi:
      randomSeed(analogRead(A0));
      tilfeldig = random(7, 15);
      
      forrigeTid = tidNaa;
      digitalWrite(tilfeldig, HIGH);
      }
      
      //naar spiller 1 trykker:
      if (digitalRead(p1Knapp) == trykket) {
        if (tilfeldig == p1Led) {
          p1Poeng++;
          poeng();
          while (digitalRead(p1Knapp) == trykket) {
          //gjor ingenting for knappen slippes.
          }
          tone(6, 277);
          delay(50);
          noTone(6);
          
        }
        else if (p1Poeng > 0) {
          p1Poeng--;
          poeng();
          while (digitalRead(p1Knapp) == trykket) {
          //gjor ingenting for knappen slippes.
          }
          tone(6, 261);
          delay(50);
          noTone(6);
        }
      }
      
      //naar spiller 2 trykker:
      if (digitalRead(p2Knapp) == trykket) {
        if (tilfeldig == p2Led) {
          p2Poeng++;
          poeng();
          while (digitalRead(p2Knapp) == trykket) {
          //gjor ingenting for knappen slippes.
          }
          tone(6, 349);
          delay(50);
          noTone(6);
        }
        else if (p2Poeng > 0) {
          p2Poeng--;
          poeng();
          while (digitalRead(p2Knapp) == trykket) {
          //gjor ingenting for knappen slippes.
          }
          tone(6, 330);
          delay(50);
          noTone(6);
        }
      }
      
      //ser om spiller 1 har vunnet:
      if (p1Poeng >= 5) {
        Serial.println("PLAYER 1 WON !");
        resetTilstand = !resetTilstand;
        tone(6, 277);
        delay(4000);
        noTone(6);

        
        p1Poeng = 0;
        p2Poeng = 0;
        digitalWrite(p1Led, LOW);
        digitalWrite(p2Led, LOW);
        
        digitalWrite(led, resetTilstand);
        knappFor = knappNaa;
        rydd();
      }
      
      //ser om spiller 2 har vunnet:
      else if (p2Poeng >= 5) {
        Serial.println("PLAYER 2 WON !");
        resetTilstand = !resetTilstand;
        tone(6, 349);
        delay(4000);
        noTone(6);
        
        p1Poeng = 0;
        p2Poeng = 0;
        digitalWrite(p1Led, LOW);
        digitalWrite(p2Led, LOW);
        
        digitalWrite(led, resetTilstand);
        knappFor = knappNaa;
        rydd();
      }
    }
  }
}


