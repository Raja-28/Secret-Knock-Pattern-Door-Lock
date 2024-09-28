
const int relayPin = 7; 
const int ledPin = 13;      
const int speakerPin = 8;   
const int buttonPin = 2;    

const int knockReadings = 10;
int secretKnock[knockReadings] = {100, 200, 150};
int knockValues[knockReadings];

int currentKnockIndex = 0;
bool listening = false;
long lastKnockTime = 0;

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(speakerPin, OUTPUT);

  
  digitalWrite(relayPin, LOW);
  digitalWrite(ledPin, LOW);
  
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(buttonPin) == LOW && !listening) {
    listening = true;
    currentKnockIndex = 0;
    lastKnockTime = millis();
    Serial.println("Listening for knocks...");
  }

  if (listening) {
    int knockSensorValue = analogRead(A0); 
    if (knockSensorValue > 500) {
      long knockTime = millis() - lastKnockTime;
      lastKnockTime = millis();
      Serial.print("Knock detected: ");
      Serial.println(knockTime);
      
      if (currentKnockIndex < knockReadings) {
        knockValues[currentKnockIndex] = knockTime;
        currentKnockIndex++;
      }
      
      if (currentKnockIndex == knockReadings) {
        listening = false;
        checkKnockPattern();
      }
    }

  
    if (millis() - lastKnockTime > 5000) {
      listening = false;
      Serial.println("Stopped listening, timeout.");
    }
  }
}

void checkKnockPattern() {
  int tolerance = 50; 
  bool match = true;
  
  for (int i = 0; i < knockReadings; i++) {
    if (abs(knockValues[i] - secretKnock[i]) > tolerance) {
      match = false;
      break;
    }
  }

  if (match) {
    Serial.println("Correct knock pattern! Unlocking...");
    digitalWrite(ledPin, HIGH);
    tone(speakerPin, 1000, 500); 
    digitalWrite(relayPin, HIGH); 
    delay(5000);  
    digitalWrite(relayPin, LOW);  
    digitalWrite(ledPin, LOW);
  } else {
    Serial.println("Wrong pattern, try again.");
    tone(speakerPin, 500, 500);
  }
}
