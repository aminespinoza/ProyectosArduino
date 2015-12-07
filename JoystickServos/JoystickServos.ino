#include <Servo.h>

const int selectedButton = 6;
const int xAxis = 1; 
const int yAxis = 0; 

Servo horizontalEngine;
Servo verticalEngine;

void setup()
{
  horizontalEngine.attach(9);
  verticalEngine.attach(8);
  Serial.begin(9600);
}

void loop()
{
  int horizontalPosition = (analogRead(xAxis) / 5.7);
  horizontalEngine.write(horizontalPosition);
  
  int verticalPosition = (analogRead(yAxis) / 5.7);
  verticalEngine.write(verticalPosition);
  
  delay(10);
}
