#include<Servo.h>
const int Hexapin=5;
const int Octapin=8;
const int throttlepin=7;
const int Hexa=6;
const int Octa=9;
//const int Check=10;

unsigned long ThrottleSig;
unsigned long HexaSignal;
unsigned long OctaSignal;
unsigned long a=0;

Servo Hex;
Servo Oct;

void setup()
{
  Serial.begin(9600);
  pinMode(Hexapin,INPUT);
  pinMode(Octapin,INPUT);
  pinMode(throttlepin,INPUT);
  pinMode(Hexa,OUTPUT);
  pinMode(Octa,OUTPUT);
  //pinMode(Check,INPUT);
  Hex.attach(Hexa);
  Oct.attach(Octa);
}

void loop()
{
  ThrottleSig = pulseIn(throttlepin,HIGH);
  //a = pulseIn(Check,HIGH);
  Serial.println(ThrottleSig);
  Serial.println("-throttle");
  HexaSignal = pulseIn(Hexapin, HIGH);
  OctaSignal = pulseIn(Octapin, HIGH);
  Serial.println(HexaSignal);
  Serial.println("HexaSignal");
  Serial.println(OctaSignal);
  Serial.println("OctaSignal");  
if(HexaSignal<1600){Hex.writeMicroseconds(ThrottleSig);Serial.println(ThrottleSig);Serial.println("-Hex");}
if(HexaSignal>1800){Hex.writeMicroseconds(990);Serial.println(a);Serial.println("-Hex");}
if(OctaSignal<1600){Oct.writeMicroseconds(ThrottleSig);Serial.println(ThrottleSig);Serial.println("-Oct");}
if(OctaSignal>1800){Oct.writeMicroseconds(990);Serial.println(a);Serial.println("-Oct");}
}

