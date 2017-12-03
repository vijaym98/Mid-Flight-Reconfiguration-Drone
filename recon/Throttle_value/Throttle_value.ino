#include<Servo.h>
const int throttlepin=7;
unsigned long ThrottleSig=975;

void setup()
{
  Serial.begin(9600);
  pinMode(throttlepin,INPUT);
}

void loop()
{
  ThrottleSig = pulseIn(throttlepin,HIGH);
  Serial.println(ThrottleSig);
}

