const int switchPin = 2;
const int motorPin = 3;
const int tempPin = A1;

int switchState = 0;
int tempVerdi;

void setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);

}

void loop() {
  unsigned long tid = millis();
  
  switchState = digitalRead(switchPin);
  
  tempVerdi = analogRead(tempPin);
  float volt = (tempVerdi/1024.0) * 5.0;
  float temperatur = (volt - 0.5) * 100;
  Serial.println(temperatur);

  if(switchState == HIGH || temperatur > 26.0){
    digitalWrite(motorPin, HIGH);
    delay(5000);
  }
  else{
    digitalWrite(motorPin, LOW);
  }
  

  

}
