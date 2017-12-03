#include<Servo.h>
const int Hexapin=5;
const int Octapin=8;
const int throttlepin=7;
const int Hexa=6;
const int Octa=9;
const int HexaInterruptpin=2;
const int OctaInterruptpin=3;
//const int Check=10;

unsigned long ThrottleSig;
unsigned long HexaSignal=1900;
unsigned long OctaSignal=1900;
unsigned long a=0;

int t=0;
int r=0;
int p=0;
int HexTrans=0;
float q=0;

int s=0;
int w=0;
int u=0;
int OctTrans=0;
float v=0;

Servo Hex;
Servo Oct;

void hexInterrupt()
{
  r=1;
  }

void octInterrupt()
{
  w=1;
  }


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
  attachInterrupt(digitalPinToInterrupt(HexaInterruptpin), hexInterrupt,RISING);
  attachInterrupt(digitalPinToInterrupt(OctaInterruptpin), octInterrupt,RISING);
  pinMode(HexaInterruptpin,INPUT);
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
  Serial.println(q);
  Serial.println("-q"); 
if(HexaSignal<1600){Hex.writeMicroseconds(ThrottleSig);Serial.println(ThrottleSig);Serial.println("-Hex");digitalWrite(HexaInterruptpin,LOW);p=(ThrottleSig+990)/2;}
if(HexaSignal>1800)
{
  if(r==0){Hex.writeMicroseconds(990);Serial.println(a);Serial.println("-Hex");digitalWrite(HexaInterruptpin,HIGH);}
  if(r==1)
  {
    Hex.writeMicroseconds(p);
    delay(500);
    p=(p+990)/2;
    Hex.writeMicroseconds(p);
    delay(500);
    p=(p+990)/2;
    Hex.writeMicroseconds(p);
    delay(500);
    p=(p+990)/2;
    Hex.writeMicroseconds(p);
    delay(500);
    Hex.writeMicroseconds(990);
    r=0;}
 }
if(OctaSignal<1600){Oct.writeMicroseconds(ThrottleSig);Serial.println(ThrottleSig);Serial.println("-Oct");digitalWrite(OctaInterruptpin,LOW);u=(ThrottleSig+990)/2;}
if(OctaSignal>1800)
{
  if(w==0){Oct.writeMicroseconds(990);Serial.println(a);Serial.println("-Oct");digitalWrite(OctaInterruptpin,HIGH);}
  if(w==1)
  {
     Oct.writeMicroseconds(u);
    delay(500);
    u=(u+990)/2;
    Oct.writeMicroseconds(u);
    delay(500);
    u=(u+990)/2;
    Oct.writeMicroseconds(u);
    delay(500);
    u=(u+990)/2;
    Oct.writeMicroseconds(u);
    delay(500);
    Oct.writeMicroseconds(990);
    w=0;}
  }
}



