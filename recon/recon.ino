#include <Servo.h>
int q=0;
const int throttlepin = 7; //input
const int HexMotors = 8;
const int OctMotors = 9;
const int HexaPin = 2;  //input
const int OctaPin = 3;  //input
const int HexServo =4;
const int OctServo =5;

unsigned long ThrottleSig=1000;
unsigned long HexaSignal=1900;
unsigned long OctaSignal=1900;
unsigned long ModeSampleTime;

Servo HexM;
Servo OctM;
Servo HexS;
Servo OctS;

char Mode = 'q';

void setup()
{
  Serial.begin(9600);
  pinMode(throttlepin, INPUT);
  pinMode(HexaPin, INPUT);
  pinMode(OctaPin, INPUT);
  HexM.attach(HexMotors);
  OctM.attach(OctMotors);
  HexS.attach(HexServo);
  OctS.attach(OctServo);
}

void loop()
{
  //if(micros()-ModeSampleTime>1000000)
  //{ModeSampleTime=micros();
HexaSignal = pulseIn(HexaPin, HIGH);
if(HexaSignal<1200){Mode = 'h';OctS.writeMicroseconds(1000);OctM.writeMicroseconds(1000);Serial.println("HexOn");q=1;}
if(HexaSignal>1400 && HexaSignal<1600){Mode = 'a';HexS.writeMicroseconds(2000);HexM.writeMicroseconds(1000);OctS.writeMicroseconds(1000);OctM.writeMicroseconds(1000);Serial.println("HexOff");}
if(HexaSignal>1800){HexM.writeMicroseconds(1000);OctM.writeMicroseconds(1000);HexS.writeMicroseconds(1000);OctS.writeMicroseconds(1000);Serial.println("quad");}

if(q=1)
{
OctaSignal = pulseIn(OctaPin, HIGH);
if(OctaSignal<1200){Mode = 'o';Serial.println("OctaOn");}
if(OctaSignal>1400 && OctaSignal<1600){Mode = 'h';OctM.writeMicroseconds(1000);OctS.writeMicroseconds(2000);Serial.println("OctaOff");}
if(OctaSignal>1800){Mode = 'h';OctM.writeMicroseconds(1000);OctS.writeMicroseconds(1000);Serial.println("quad");}
}


if(Mode=='h')
{
  HexS.writeMicroseconds(2000);
  ThrottleSig = pulseIn(throttlepin,HIGH);
  HexM.writeMicroseconds(ThrottleSig);
  Serial.println(ThrottleSig);
}
if(Mode=='o')
{
  HexS.writeMicroseconds(2000);
  OctS.writeMicroseconds(2000);
  ThrottleSig = pulseIn(throttlepin,HIGH);
  HexM.writeMicroseconds(ThrottleSig);
  OctM.writeMicroseconds(ThrottleSig);
  Serial.println(ThrottleSig);
}
  
  
}

