#include<Servo.h>
const int Hexapin=5;                  //input
const int Octapin=8;                  //input
const int throttlepin=7;              //input
const int Hexa=6;                     //output
const int Octa=9;                     //output
const int HexaInterruptpin=2;         //no connection
const int OctaInterruptpin=3;         //no connection
const int HexaServoInterruptpin=20;   //no connection
const int OctaServoInterruptpin=21;   //no connection

const int Hexaservo=10;               //output
const int Octaservo=11;               //output
const int Hexaservocheck=12;               //output
const int Octaservocheck=13;               //output
//const int Check=10;

unsigned long ThrottleSig;
unsigned long HexaSignal=1900;
unsigned long OctaSignal=1900;
unsigned long Hexaservovalue=1900;
unsigned long Octaservovalue=1900;
unsigned long a=0;

int t=0;
int r=0;
int p=0;
int HexTrans=0;
int q=0;

int s=0;
int w=0;
int u=0;
int OctTrans=0;
int v=0;

Servo Hex;
Servo Oct;
Servo HexS;
Servo OctS;

void hexInterrupt()
{
  r=1;
  }

void octInterrupt()
{
  w=1;
  }

void hexservoInterrupt()
{
  q=1;
  }
void octservoInterrupt()
{
  v=1;
  }

void setup()
{
  Serial.begin(9600);
  pinMode(Hexapin,INPUT);
  pinMode(Octapin,INPUT);
  pinMode(throttlepin,INPUT);
  pinMode(Hexa,OUTPUT);
  pinMode(Octa,OUTPUT);

  pinMode(Hexaservo,OUTPUT);
  pinMode(Octaservo,OUTPUT);

  pinMode(Hexaservocheck,INPUT);
  pinMode(Octaservocheck,INPUT);
  
  //pinMode(Check,INPUT);
  Hex.attach(Hexa);
  Oct.attach(Octa);
  HexS.attach(Hexaservo);
  OctS.attach(Octaservo);
  attachInterrupt(digitalPinToInterrupt(HexaInterruptpin), hexInterrupt,RISING);
  attachInterrupt(digitalPinToInterrupt(OctaInterruptpin), octInterrupt,RISING);
  attachInterrupt(digitalPinToInterrupt(HexaServoInterruptpin), hexservoInterrupt,RISING);
  attachInterrupt(digitalPinToInterrupt(OctaServoInterruptpin), octservoInterrupt,RISING);
  pinMode(HexaInterruptpin,INPUT);
  pinMode(OctaInterruptpin,INPUT);
  pinMode(HexaServoInterruptpin,INPUT);
  pinMode(OctaServoInterruptpin,INPUT);
}

void loop()
{
  ThrottleSig = pulseIn(throttlepin,HIGH);
  //a = pulseIn(Check,HIGH);
  Serial.println(ThrottleSig);
  Serial.println("-throttle");
  HexaSignal = pulseIn(Hexapin, HIGH);
  OctaSignal = pulseIn(Octapin, HIGH);
  Hexaservovalue = pulseIn(Hexaservocheck, HIGH);
  Octaservovalue = pulseIn(Octaservocheck, HIGH);
  Serial.println(HexaSignal);
  Serial.println("HexaSignal");
  Serial.println(OctaSignal);
  Serial.println("OctaSignal");
  
  Serial.println(Hexaservovalue);
  Serial.println("Hexaservovalue");
  Serial.println(Octaservovalue);
  Serial.println("Octaservovalue");
  
if(HexaSignal<1200){Hex.writeMicroseconds(ThrottleSig);digitalWrite(HexaInterruptpin,LOW);p=(ThrottleSig+990)/2;}
if(HexaSignal>1400 && HexaSignal<1600)
{
  if(r==0){Hex.writeMicroseconds(990);digitalWrite(HexaInterruptpin,HIGH);}
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
    HexS.writeMicroseconds(2000);
   }
if(HexaSignal>1800){
  Hex.writeMicroseconds(990);
  digitalWrite(HexaInterruptpin,HIGH);
  HexS.writeMicroseconds(1000);
 
   }
if(OctaSignal<1200){Oct.writeMicroseconds(ThrottleSig);digitalWrite(OctaInterruptpin,LOW);u=(ThrottleSig+990)/2;}
if(OctaSignal>1400 && OctaSignal<1600)
{
  if(w==0){Oct.writeMicroseconds(990);digitalWrite(OctaInterruptpin,HIGH);}
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
   OctS.writeMicroseconds(2000);
   
}
if(OctaSignal>1800){
  Oct.writeMicroseconds(990);
  digitalWrite(OctaInterruptpin,HIGH);
  OctS.writeMicroseconds(1000);
  
   }
}
