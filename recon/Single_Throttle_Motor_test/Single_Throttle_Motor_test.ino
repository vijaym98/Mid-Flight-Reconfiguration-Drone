#include<Servo.h>
const int throttlepin=7;
const int MotorPin=8;
const int Motors=9;
const int Check=10;

unsigned long ThrottleSig;
unsigned long MotorSignal;
unsigned long a=0;

Servo Motor;

void setup()
{
  Serial.begin(9600);
  pinMode(throttlepin,INPUT);
  pinMode(MotorPin,INPUT);
  pinMode(Motors,OUTPUT);
  pinMode(Check,INPUT);
  Motor.attach(Motors);
 
}

void loop()
{
  ThrottleSig = pulseIn(throttlepin,HIGH);
  a = pulseIn(Check,HIGH);
  Serial.println(ThrottleSig);
  Serial.println("-throttle");
  MotorSignal = pulseIn(MotorPin, HIGH);
  Serial.println(MotorSignal);
  Serial.println("MotorSignal");  
if(MotorSignal<1600){Motor.writeMicroseconds(ThrottleSig);Serial.println(ThrottleSig);Serial.println("value");}
if(MotorSignal>1800){Motor.writeMicroseconds(990);Serial.println(a);Serial.println("value");}
 Serial.println(a);
 Serial.println("check");
}

