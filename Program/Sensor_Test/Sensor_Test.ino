const int sensorPin = A0;
int sensorVal = 0;

const int ledPin = A2;
const int speakerPin = A1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
   
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorVal = analogRead(sensorPin);
  Serial.println(sensorVal);

  if(sensorVal < 600) {
    digitalWrite(ledPin, LOW);
  }
  else {
    digitalWrite(ledPin, HIGH);
    alarm(500, 500);
  }
  delay(500);
}

void alarm(int getTone, int getDelay) {
  tone(speakerPin, getTone, getDelay);
}

