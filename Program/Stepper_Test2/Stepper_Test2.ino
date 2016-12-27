#include <Stepper.h>

int in1Pin = 5;
int in2Pin = 4;
int in3Pin = 3;
int in4Pin = 2;

Stepper motor(768, in1Pin, in2Pin, in3Pin, in4Pin);  //Step angle: 5.625, Reduction ratio: 1 / 64
                                                     // 5.625 x 64 = 360

void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);

  Serial.begin(9600);
  motor.setSpeed(20);  //max is 50 (can't handle the speed. It skids)

  //int steps = Serial.parseInt();
  motor.step(500);
}

void loop()
{
  
}
