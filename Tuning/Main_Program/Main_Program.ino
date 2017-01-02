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
  Serial.println("ROBOT START");
  //================================================================================
  
  //== BEGIN OF PROGRAM ============================================================
  displaySSD(counter);              //display ON
  
  /*while(checkSw());               //Wait for SW press
  robotFW(5000);                    //Move Robot for a small time period
  delay(1000);
  
  while(readSensors() < black) {    //move until first black stripe
    robotFW();
    delay(100);
  }*/

  digitalWrite(ledPin, HIGH);       //activate alarm and Lamps
  alarm(1500, 500);
  state = 1;                        //State set to HIGH
  delay(1000);

  Serial.println(" OK ");
  
  /*while(readSensors() > black) {    //wait until black strip is passed
    robotFW(2000);
    delay(100);
  }

  Serial.println(" ");

  robotFW(1000);
  while(1);*/

  //move robot for a small time period
  robotFW(10000);
}


void loop() {
  
  //Last Black stripe
  if((readSensors() > black) && state) {
    alarm(500, 500);
    delay(100);
    alarm(500, 500);
    robotSTOP(10000);
    
    //go Up
    while(1) {
      Serial.print("END");
      robotFW(1000);
    }
  }

  //White stripe
  if(readSensors() > white) {
    alarm(750, 200);
    counter++;
    Serial.print(counter);
    Serial.print(" ");
    displaySSD(counter);

    Serial.print("WHITE");
    
    while(readSensors() > white) {    //wait until white strip is passed
      robotFW(500);
    }
  }

  //transparent region
  //else {
  Serial.println("TRANSPARENT");
  robotFW(500);
    //delay(100);
  //}
}




