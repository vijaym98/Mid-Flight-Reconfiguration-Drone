#include <Servo.h> 

Servo myservo;

void setup() 
{ 
  myservo.attach(10);
  myservo.writeMicroseconds(2000);  // set servo to mid-point
} 

void loop() {} 
