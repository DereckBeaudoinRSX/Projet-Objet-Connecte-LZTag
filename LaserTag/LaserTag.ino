const int buzzerPin = 12;
const int buttonPin = 15;
const int laserPin = 5;
const int dataPin = 4;
const int latchPin = 0;
const int clockPin = 2;

void setup() {
  // put your setup code here, to run once: 
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(laserPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  
  Serial.begin(9600);
}

void Fire(){
    digitalWrite(laserPin, HIGH);
    buzzer();
    digitalWrite(laserPin, LOW);
    delay(50);
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
  if(digitalRead(buttonPin) == HIGH){
    Serial.write("PRESSED");
    Serial.print('\n');
    Fire();
  }
}
