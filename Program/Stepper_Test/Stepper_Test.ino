int in1Pin = 5;
int in2Pin = 4;
int in3Pin = 3;
int in4Pin = 2;

int delayVal = 0;;

void setup() {
  
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);

  Serial.begin(9600);
  Serial.print("OK");

  delayVal = 20;
}

void loop() {
  
  /*PORTD = B11000000;
  delay(20);
  PORTD = B01100000;
  delay(20);
  PORTD = B00110000;
  delay(20);
  PORTD = B10010000;
  delay(20);*/

  digitalWrite(in1Pin, LOW); 
  digitalWrite(in1Pin, LOW);
  digitalWrite(in1Pin, LOW);
  digitalWrite(in1Pin, HIGH);

  delay(delayVal);

  digitalWrite(in1Pin, LOW); 
  digitalWrite(in1Pin, LOW);
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in1Pin, HIGH);

  delay(delayVal);

  digitalWrite(in1Pin, LOW); 
  digitalWrite(in2Pin, LOW);
  digitalWrite(in3Pin, HIGH);
  digitalWrite(in4Pin, LOW);

  delay(delayVal);

  digitalWrite(in1Pin, LOW); 
  digitalWrite(in2Pin, HIGH);
  digitalWrite(in3Pin, HIGH);
  digitalWrite(in4Pin, LOW);

  delay(delayVal);
  
  digitalWrite(in1Pin, LOW); 
  digitalWrite(in2Pin, HIGH);
  digitalWrite(in3Pin, LOW);
  digitalWrite(in4Pin, LOW);

  delay(delayVal);
  
  digitalWrite(in1Pin, HIGH); 
  digitalWrite(in2Pin, HIGH);
  digitalWrite(in3Pin, LOW);
  digitalWrite(in4Pin, LOW);

  delay(delayVal);
  
  digitalWrite(in1Pin, HIGH); 
  digitalWrite(in2Pin, LOW);
  digitalWrite(in3Pin, LOW);
  digitalWrite(in4Pin, LOW);

  delay(delayVal);
  
  digitalWrite(in1Pin, HIGH); 
  digitalWrite(in2Pin, LOW);
  digitalWrite(in3Pin, LOW);
  digitalWrite(in4Pin, HIGH);

  delay(delayVal);

}
