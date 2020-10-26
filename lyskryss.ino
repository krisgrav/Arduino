const int gronnBil = 12; //LED for grlnt lys til biler
const int gulBil = 11; //LED for gult lys til biler
const int rodBil = 10; //LEd for rødt lys til biler
const int gronnFot = 9;  //LED for grønt lys til fotgjenger
const int rodFot = 8;  //LED for rødt lys til fotgjenger
const int blaaFot = 7;  //LED som aktiveres når fotgjenger trykker inn knappen
const int knapp = 2;  //Knapp for fotgjenger
const unsigned long tidForBil = 10000;  //Tid som skal gå før det er mulig for fotgjenger å få grønt igjen (10sek)
unsigned long bleGront = 0; //Variabel for tiden lyset blir rødt for fotgjengere og grønt for biler (millis())
unsigned long knappeTrykk = 0; //Variabel for tidspunktet fotgjenger trykker på knappen for å få grønt lys
int statusKnapp = 0; //Knapp for fotgjenger. Status på knapp LOW/HIGH.


void setup() { //Setter opp alle OUTPUT/INPUT
  pinMode(gronnBil, OUTPUT);
  pinMode(gulBil, OUTPUT);
  pinMode(rodBil, OUTPUT);
  pinMode(gronnFot, OUTPUT);
  pinMode(rodFot, OUTPUT);
  pinMode(blaaFot, OUTPUT);
  pinMode(knapp, INPUT);
  grontForBil(); //Setter lyset til grønt for biler/rødt for fotgjenger som utgangspunkt.

}

void loop(){
  unsigned long tidGatt = millis(); //Teller for tiden som ar gått 
  statusKnapp = digitalRead(knapp);  //Leser input fra fotgjengerknapp
  if(tidGatt >= tidForBil + bleGront){  //Hvis tiden nå er = eller mer enn tiden for da lyset sist ble grønt + 10 sekunder som skal være prioritert for bilene, 
    lysKryss(); //kalles lysKryss();
  }
  else{ //Hvis bilene ikke har het grønt lys i 10 sekunder kalles lysKryss2().
    lysKryss2(); 
  }  
}



void lysKryss(){
  if(statusKnapp == HIGH){ //Om fotgjenger trykker på knapp etter 10 sek med grønt lys for bilene kalles disse metodene.
    tilGrontForFot();
    grontForFot();
    tilGrontForBil();
  }
}

void lysKryss2(){ 
  if(statusKnapp == HIGH){ //Om fotgjenger trykker på knapp før 10 sek med grønt lys for bilene har gått kalles disse metodene.
    digitalWrite(blaaFot, HIGH); //Setter på blått lys som indikerer at fotgjengern har trykket men må vente på grønt lys.
    unsigned long naa = millis(); //VAriabel som brukes i løkke nedenfor.
    while(bleGront + tidForBil > naa){ //Denne løkken brukes som en timer der naa oppdateres kontinuerlig helt til den er høyere enn sist bilene fikk grønt lys + 10sek prioritert for bilene
      naa = millis(); //Oppdatere2 naa
    }
    tilGrontForFot(); //Når 10sek prioritert tid har gått kalles disse metodene.
    grontForFot();
    tilGrontForBil();
  } 
}

void grontForBil(){ //Ferdig grønt lys for biler/rødt for fotgjenger
  digitalWrite(gronnBil, HIGH);
  digitalWrite(gulBil, LOW);
  digitalWrite(rodBil, LOW);
  digitalWrite(gronnFot, LOW);
  digitalWrite(rodFot, HIGH);
  digitalWrite(blaaFot, LOW);
}

void grontForFot(){ //Ferdig grønt lys for fotgjenger/rødt for biler
  digitalWrite(gronnBil, LOW);
  digitalWrite(gulBil, LOW);
  digitalWrite(rodBil, HIGH);
  digitalWrite(gronnFot, HIGH);
  digitalWrite(rodFot, LOW); 
  delay(5000); //Fotgjengere har grønt lys i 5sek
}

void tilGrontForFot(){ //Overgang fra rødt for fotgjengere til grønt for fotgjengere
  digitalWrite(blaaFot, LOW); //Skrur av ventelyset for fotgjengere
  digitalWrite(gronnBil, HIGH);
  digitalWrite(gronnBil, HIGH);
  digitalWrite(gulBil, HIGH);
  digitalWrite(rodBil, LOW);
  pinMode(knapp, OUTPUT); //Bytter pinmode på fotgjengerknapp, slik at ingen kan aktivere den mens fotgjengerene har grønt lys.
  blinkRodFot(); //Kaller metoden blinkRodFot();

}

void tilGrontForBil(){ //Overgang fra rødt lys for bilene til grønt lys for bilene
  digitalWrite(blaaFot, LOW);
  digitalWrite(gronnBil, LOW);
  digitalWrite(gulBil, HIGH);
  digitalWrite(rodBil, LOW);
  blinkGronnFot(); //Kaller metoden blinkGronnFot()
  grontForBil(); //Kaller metoden grontForBil()
  bleGront = millis(); //Tiden det ble grønt for bilene igjen
  pinMode(knapp, INPUT); //Setter pinmode for knap tilbake til input, slik at den tillater å bli trykket på igjen.
}

void blinkGronnFot(){ //Denne metoden blinker det grønne fotgjengerlyet for å indikere at det snart skifter
  digitalWrite(gronnFot, HIGH);
  delay(250);
  digitalWrite(gronnFot, LOW);
  delay(250);
  digitalWrite(gronnFot, HIGH);
  delay(250);
  digitalWrite(gronnFot, LOW);
  delay(250);
  digitalWrite(gronnFot, HIGH);
  delay(250);
  digitalWrite(gronnFot, LOW);
  delay(250);
  digitalWrite(gronnFot, HIGH);
  delay(250);
  digitalWrite(gronnFot, LOW);
  delay(250);
  digitalWrite(gronnFot, HIGH);
  delay(250);
  digitalWrite(gronnFot, LOW);
  delay(250);
  digitalWrite(gronnFot, HIGH);
  delay(250);
  digitalWrite(gronnFot, LOW);
  delay(250);
}

void blinkRodFot(){ //Denne metoden blinker det røde fotgjengerlyset for å indikere at det snart skifter.
  digitalWrite(rodFot, HIGH);
  delay(250);
  digitalWrite(rodFot, LOW);
  delay(250);
  digitalWrite(rodFot, HIGH);
  delay(250);
  digitalWrite(rodFot, LOW);
  delay(250);
  digitalWrite(rodFot, HIGH);
  delay(250);
  digitalWrite(rodFot, LOW);
  delay(250);
  digitalWrite(rodFot, HIGH);
  delay(250);
  digitalWrite(rodFot, LOW);
  delay(250);
  digitalWrite(rodFot, HIGH);
  delay(250);
  digitalWrite(rodFot, LOW);
  delay(250);
  digitalWrite(rodFot, HIGH);
  delay(250);
  digitalWrite(rodFot, LOW);
  delay(250);
  digitalWrite(blaaFot, LOW);
}
