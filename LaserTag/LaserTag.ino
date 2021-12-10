const int buzzerPin = 2;
const int buttonPin = 4;
const int Sensor = 15;
const int Led1 = 5;
const int Led2 = 14;
const int Led3 = 12;
int HealthPoint = 3;

void setup() {
  // put your setup code here, to run once: 
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(Sensor, INPUT);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, HIGH);
  digitalWrite(Led3, HIGH);
  
  Serial.begin(9600);
}

void Fire(){
    Serial.write("Fire");
    Serial.print('\n');
    buzzer();
    delay(50);
}

void Reset(){
    if(digitalRead(Led1) == LOW){ 
      HealthPoint = 3;
      digitalWrite(Led1, HIGH);
      digitalWrite(Led2, HIGH);
      digitalWrite(Led3, HIGH);
      Serial.println(HealthPoint);
    }
}

void Hit(){
  Serial.print("Hit!");
  tone(buzzerPin, 2093);
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
  delay(500);
  noTone(buzzerPin);
}

void buzzer(){
    tone(buzzerPin,2200); // then buzz by going high
    tone(buzzerPin,1000);
    tone(buzzerPin,500);
    tone(buzzerPin,200);
    tone(buzzerPin,500);
    delayMicroseconds(10000);    // waiting
    noTone(buzzerPin);  // going low
    delayMicroseconds(10000);    // and waiting more
    tone(buzzerPin,2200); 
    tone(buzzerPin,1000);
    delayMicroseconds(10000);    // waiting
    noTone(buzzerPin);  // going low
    delayMicroseconds(10000);    // and waiting more
    tone(buzzerPin,100); 
    delayMicroseconds(10000);    // waiting
    noTone(buzzerPin);  // going low
    delayMicroseconds(10000);    // and waiting more
    tone(buzzerPin,100); 
    delayMicroseconds(10000);    // waiting
    noTone(buzzerPin);  // going low
    delayMicroseconds(10000);    // and waiting more
}

void loop() {
  // put your main code here, to run repeatedly:
  bool value = digitalRead(Sensor);
  if(value == 0){
    Hit();
  }
  if(digitalRead(buttonPin) == HIGH){
    Fire();
  }
  Reset();
}
