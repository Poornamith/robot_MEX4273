#include <Arduino.h>
//#include <Stepper.h>

//== ports =============================================================================

const short swPin = 6;
int swState = 0;

const short ledPin = A2;

const int speakerPin = A1;

const int ssd[7] = { 13, 12, 11, 10, 9, 8, 7 };
int bitVal = 0;

const int sensorPin = A0;
int sensorVal = 0;

const int in1Pin = 5;
const int in2Pin = 4;
const int in3Pin = 3;
const int in4Pin = 2;

//Stepper motor(512, in1Pin, in2Pin, in3Pin, in4Pin);
//======================================================================================

  
//== function prototypes ===============================================================
  
bool checkSw();
void displaySSD(int getCount);
int readSensors();
void robotFW(int getTime);
void robotSTOP(int getTime);
void alarm(int getTone, int getDelay);
//======================================================================================

  
//== functions =========================================================================

bool checkSw() {
  swState = digitalRead(swPin);         //get the SW state
  if (swState == HIGH) {
    digitalWrite(swPin, LOW);           //pull-down mode
    return false;
  }
  else
    return true;
}

void displaySSD(int getCount) {

  switch(getCount) {
    case 0: bitVal = B00111111; break;    // 7 seg val for digit 0
    case 1: bitVal = B00000110; break;    // 7 seg val for digit 1
    case 2: bitVal = B01011011; break;    // 7 seg val for digit 2
    case 3: bitVal = B01001111; break;    // 7 seg val for digit 3
    case 4: bitVal = B01100110; break;    // 7 seg val for digit 4
    case 5: bitVal = B01101101; break;    // 7 seg val for digit 5
    case 6: bitVal = B01111101; break;    // 7 seg val for digit 6
    case 7: bitVal = B00000111; break;    // 7 seg val for digit 7
    case 8: bitVal = B01111111; break;    // 7 seg val for digit 8
    case 9: bitVal = B01101111; break;    // 7 seg val for digit 9

    default: bitVal = B00111111; break;   //default val as digit 0
  }
  
  for(int i = 0; i < 7; i++) {
    digitalWrite(ssd[i], bitRead(bitVal, i));   //pass counter val bitwise
    Serial.print(bitRead(bitVal, i));
  }
  Serial.println(" ");
}
/*BCD
void SSD(int getCount) {

  //Operations are done only to the last 4 bits
  //PORTB = PORTB | getCount;   //send value
  PORTB = getCount;
}
*/

int readSensors() {
  sensorVal = analogRead(sensorPin);      //get the sensor val
  Serial.print(sensorVal);
  return sensorVal;
}

void robotFW(int getTime) {
  Serial.print("FW");
  //motor.setSpeed(20);
  //motor.step(getSpeed);                   //rotate motor for number of steps
  
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, HIGH);
  digitalWrite(in3Pin, HIGH);
  digitalWrite(in4Pin, LOW);

  delay(getTime);
}

void robotSTOP(int getTime) {
  Serial.print("STOP");

  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, LOW);
  digitalWrite(in3Pin, LOW);
  digitalWrite(in4Pin, LOW);

  delay(getTime);
}

void alarm(int getTone, int getDelay) {
  tone(speakerPin, getTone, getDelay);    //alarm tone generator
}


