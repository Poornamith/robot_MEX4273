#include <Arduino.h>

//== ports =============================================================================

const short swPin = 6;
int swState = 0;

const short ledPin = A2;

const int speakerPin = A1;

const int ssd[7] = { 13, 12, 11, 10, 9, 8, 7 };
int bitVal = 0;

const int sensorPin = A0;
int sensorVal = 0;
//======================================================================================

  
//== function prototypes ===============================================================
  
bool checkSw();
void displaySSD(int getCount);
int readSensors();
void robotFW();
void alarm(int getTone, int getDelay);
//======================================================================================

  
//== functions =========================================================================

bool checkSw() {
  swState = digitalRead(swPin);
  if (swState == HIGH) {
    digitalWrite(swPin, LOW);
    return false;
  }
  else
    return true;
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
/*BCD
void SSD(int getCount) {

  //Operations are done only to the last 4 bits
  //PORTB = PORTB | getCount;   //send value
  PORTB = getCount;
}
*/

int readSensors() {
  sensorVal = analogRead(sensorPin);
  Serial.print(sensorVal);
  return sensorVal;
}

void robotFW() {
  Serial.print("FW");
}

void alarm(int getTone, int getDelay) {
  tone(speakerPin, getTone, getDelay);
}


