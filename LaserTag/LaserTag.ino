const int buzzerPin = 12;
const int buttonPin = 15;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(buttonPin) == HIGH){
    Serial.write("PRESSED");
    Serial.print('\n');
    buzzer();
  }
}

void buzzer(){
  unsigned long time = millis();
  while(millis() - time <= 100) {
    int freq = random(100, 1000);
    tone(buzzerPin, freq);
  }
  noTone(buzzerPin);
}
