int ssd[7] = { 13, 12, 11, 10, 9, 8, 7 };
int counter = 0;
int bitVal = 0;

const short swPin = 6;
const short ledPin = 3;
int swState = 0;

void setup() {
  
  // put your setup code here, to run once:
  for(int i = 0; i < 7; i++) {
    pinMode(ssd[i], OUTPUT);
  }

  pinMode(swPin, INPUT);
  pinMode(ledPin, OUTPUT);
   
  Serial.begin(9600);
  Serial.print("OK");
}

void loop() {

  Serial.print(counter);
  Serial.print(" ");
  /*displaySSD(counter);
  delay(250);*/
  displaySSD(counter);
  while(checkSw());
  counter++;
  delay(1000);
}

void displaySSD(int getCount) {

  switch(getCount) {
    case 0: bitVal = B00111111; break;
    case 1: bitVal = B00000110; break;
    case 2: bitVal = B01011011; break;
    case 3: bitVal = B01001111; break;
    case 4: bitVal = B01100110; break;
    case 5: bitVal = B01101101; break;
    case 6: bitVal = B01111101; break;
    case 7: bitVal = B00000111; break;
    case 8: bitVal = B01111111; break;
    case 9: bitVal = B01101111; break;

    default: bitVal = B00111111; break;
  }
  
  for(int i = 0; i < 7; i++) {
    digitalWrite(ssd[i], bitRead(bitVal, i));
    Serial.print(bitRead(bitVal, i));
  }
  Serial.println(" ");
}

bool checkSw() {
  swState = digitalRead(swPin);
  if (swState == HIGH) {
    digitalWrite(swPin, HIGH);
    return true;
  }
  else
    return false;
}

