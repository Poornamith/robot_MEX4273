/*
===================================================================================
Program for TUBE CLIMBING ROBOT
===================================================================================

INFO
* Program for the Tube Climbing Robot
* MEX4273 Project Robot
* 

PROBLEMS
* swPin stays HIGH after pressed > Add a 10k MINRES
* change the RobotFW delay to an appropriate value
* write FW() fn

===================================================================================
(copywrite) 
© Poornamith
© Infast

revised: 22-10-2015
Git Repo: https://github.com/Poornamith/robot_MEX4273
===================================================================================
*/

//Port Initialization
#include "portsInit.h"

//Global Variables
int counter = 0;    //SSD counter 
bool state = 0;     //State Variable

const int black = 600, white = 300; 

void setup() {

  //== PIN CONFIG ================================================================
  pinMode(swPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);

  //set 8,9,10,11 as OUTPUT
  //For SSD
  //DDRB = DDRB | B00001111;
  for(int i = 0; i < 7; i++) {
    pinMode(ssd[i], OUTPUT);
  }

  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("START");
  //================================================================================
  
  //== BEGIN OF PROGRAM ============================================================
  displaySSD(counter);              //display ON
  while(checkSw());                 //Wait for SW press

  robotFW();                        //Move Robot for a small time period
  delay(1000);
  
  while(readSensors() < black) {    //move until first black stripe
    robotFW();
    delay(100);
  }

  digitalWrite(ledPin, HIGH);       //activate alarm and Lamps
  alarm(500, 500);
  state = 1;                        //State set to HIGH
  delay(500);

  Serial.println(" ");
  
  while(readSensors() > black) {    //wait until black strip is passed
    robotFW();
    delay(100);
  }

  Serial.println(" ");
}


void loop() {
  
  //Last Black stripe
  if((readSensors() > black) && state) {
    alarm(500, 500);
    delay(10000);

    //go Up
    while(1) {
      Serial.print("END");
      robotFW();
    }
  }

  //White stripe
  else if(readSensors() > white) {
    alarm(750, 200);
    counter++;
    Serial.print(counter);
    Serial.print(" ");
    displaySSD(counter);

    Serial.print("WHITE");
    while(readSensors() > white) {    //wait until white strip is passed
      robotFW();
      delay(100);
    }
  }

  //transparent region
  else {
    Serial.print("TRANSPARENT");
    robotFW();
    delay(100);
  }
}




