int Buzzer = 16;
int Sensor = 13;
int ButtonReset = 2;
int ButtonShoot = 10;
int Led1 = 5;
int Led2 = 4;
int Led3 = 0;
int HealthPoint = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Sensor, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, HIGH);
  digitalWrite(Led3, HIGH);
  pinMode(ButtonReset, INPUT_PULLUP);
  pinMode(ButtonShoot, INPUT_PULLUP);

}

void loop() {
  bool value = digitalRead(Sensor);
  bool currentResetButtonState = digitalRead(ButtonReset);
  bool currentShootButtonState = digitalRead(ButtonShoot);

  if(currentResetButtonState == 0){
    Serial.println("La partie a reset");
    if(digitalRead(Led1) == LOW){ HealthPoint = 3;
      digitalWrite(Led1, HIGH);
      digitalWrite(Led2, HIGH);
      digitalWrite(Led3, HIGH);
    Serial.println(HealthPoint);
    }
  }

  if(currentShootButtonState == 0){
    Serial.println("Pew Pew");
    digitalWrite(Buzzer, HIGH);
  }
  
  if (value == 1) {
    Serial.write("Aucune lumiere");

  } else {
    Serial.write("Que la lumiere soit!");
    tone(Buzzer, 2093,150);
    HealthPoint = HealthPoint - 1;
    switch(HealthPoint){
      case 0:
        digitalWrite(Led1, LOW);
        digitalWrite(Led2, LOW);
        digitalWrite(Led3, LOW);
        delay(500);
        digitalWrite(Led1, HIGH);
        digitalWrite(Led2, HIGH);
        digitalWrite(Led3, HIGH);
        delay(500);
        digitalWrite(Led1, LOW);
        digitalWrite(Led2, LOW);
        digitalWrite(Led3, LOW);
        delay(500);
        digitalWrite(Led1, HIGH);
        digitalWrite(Led2, HIGH);
        digitalWrite(Led3, HIGH);
        delay(500);
        digitalWrite(Led1, LOW);
        digitalWrite(Led2, LOW);
        digitalWrite(Led3, LOW);
      case 1:
        digitalWrite(Led3, LOW);
        digitalWrite(Led2, LOW);
      case 2:
        digitalWrite(Led3, LOW);
      }

  }
  delay(500);

}
