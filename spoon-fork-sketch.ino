const int forkClosePin = 2;
const int forkOpenPin = 4;
const int spoonClosePin = 8;
const int spoonOpenPin = 12;

int incoming = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(forkClosePin, OUTPUT);
  pinMode(forkOpenPin, OUTPUT);
  pinMode(spoonOpenPin, OUTPUT);
  pinMode(spoonOpenPin, OUTPUT);
  Serial.begin(2000000);
}

void loop() {

  while (Serial.available() > 0) {
    incoming = Serial.readString().toInt();
    
    if (incoming == 1) {
      digitalWrite(forkOpenPin, HIGH);
      digitalWrite(spoonClosePin, HIGH);
      digitalWrite(forkClosePin, LOW);
      digitalWrite(spoonOpenPin, LOW);
      continue;
    }
    
    if (incoming == 3) {
      digitalWrite(spoonOpenPin, HIGH);
      digitalWrite(forkClosePin, HIGH);
      digitalWrite(forkOpenPin, LOW);
      digitalWrite(spoonClosePin, LOW);
      continue;
    } 

    digitalWrite(spoonOpenPin, LOW);
    digitalWrite(forkClosePin, HIGH);
    digitalWrite(forkOpenPin, LOW);
    digitalWrite(spoonClosePin, HIGH);
    
  }
  
}
