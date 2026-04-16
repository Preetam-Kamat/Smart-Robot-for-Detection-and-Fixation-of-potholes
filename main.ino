#include <SoftwareSerial.h>
#include "NewPing.h" 
#define TRIGGER_PIN1 11
#define ECHO_PIN1 12
NewPing sonar(TRIGGER_PIN1, ECHO_PIN1);

int LmotorA=4;
int LmotorB=5;
int RmotorA=6;
int RmotorB=7;
int M3=8;
int M4=9;
SoftwareSerial Ser(2,3);              
void setup() 
{
  pinMode(LmotorA,OUTPUT);
  pinMode(LmotorB,OUTPUT);
  pinMode(RmotorA,OUTPUT);
  pinMode(RmotorB,OUTPUT);
  pinMode(M3,OUTPUT);
  pinMode(M4,OUTPUT);

  Ser.begin(9600);
  Serial.begin(9600);
}


void loop() 
{
  unsigned int distance = sonar.ping_cm();
   Serial.println(distance);
     if (distance>=6 && distance<7) 
      {
         fixing(); 
      }
     else if (distance>=7 && distance<9) 
      {
         fixing1(); 
      }
 
  if(Ser.available())
  {
    char data=Ser.read();
    Serial.print(data);
    if(data=='F')
    {
      Forward();
    }
    else if(data=='B')
    {
      Backward();
    }
    else if(data=='L')
    {
      Left();
    }
    else if(data=='R')
    {
      Right();
    }
    else if(data=='W')
    {
      Clockwise(); 
    }
    else if(data=='U')
    {
      CounterClockwise();
    }
    else if((data=='w')||(data=='u'))
    {
      MotorStop();
    }
   
    else
    {
      Stop();
    }
  }
}

void Forward()
{
  digitalWrite(LmotorA,HIGH);
  digitalWrite(LmotorB,LOW);
  digitalWrite(RmotorA,HIGH);
  digitalWrite(RmotorB,LOW);
  Serial.println("F");
}
void Backward()
{
  digitalWrite(LmotorA,LOW);
  digitalWrite(LmotorB,HIGH);
  digitalWrite(RmotorA,LOW);
  digitalWrite(RmotorB,HIGH);
  Serial.println("B");
}
void Right()
{
  digitalWrite(LmotorA,HIGH);
  digitalWrite(LmotorB,LOW);
  digitalWrite(RmotorA,LOW);
  digitalWrite(RmotorB,HIGH);
  Serial.println("R");
}
void Left()
{
  digitalWrite(LmotorA,LOW);
  digitalWrite(LmotorB,HIGH);
  digitalWrite(RmotorA,HIGH);
  digitalWrite(RmotorB,LOW);
  Serial.println("L");
}
void Clockwise()
{
  digitalWrite(M3,LOW);
  digitalWrite(M4,HIGH);
  Serial.println("CW");
}
void CounterClockwise()
{
  digitalWrite(M3,HIGH);
  digitalWrite(M4,LOW);
  Serial.println("CCW");
}
void MotorStop()
{
  digitalWrite(M3,LOW);
  digitalWrite(M4,LOW);
  Serial.println("Mstop");
}

void Stop()
{
  digitalWrite(LmotorA,LOW);
  digitalWrite(LmotorB,LOW);
  digitalWrite(RmotorA,LOW);
  digitalWrite(RmotorB,LOW);
  Serial.println("S");
}
void fixing() 
  {
    Serial.print("1");
    digitalWrite(LmotorA,LOW);
    digitalWrite(LmotorB,LOW);
    digitalWrite(RmotorA,LOW);
    digitalWrite(RmotorB,LOW);
    delay(200);
      digitalWrite(LmotorA,HIGH);
      digitalWrite(LmotorB,LOW);
      digitalWrite(RmotorA,HIGH);
      digitalWrite(RmotorB,LOW);
      delay(2000);
    digitalWrite(LmotorA,LOW);
    digitalWrite(LmotorB,LOW);
    digitalWrite(RmotorA,LOW);
    digitalWrite(RmotorB,LOW); 
    
      digitalWrite(M3,HIGH);
      delay(2000);
      digitalWrite(M3,LOW);
  }
void fixing1() 
  {
    Serial.print("2");
    digitalWrite(LmotorA,LOW);
    digitalWrite(LmotorB,LOW);
    digitalWrite(RmotorA,LOW);
    digitalWrite(RmotorB,LOW);
    delay(200);
      digitalWrite(LmotorA,HIGH);
      digitalWrite(LmotorB,LOW);
      digitalWrite(RmotorA,HIGH);
      digitalWrite(RmotorB,LOW);
      delay(2000);
    digitalWrite(LmotorA,LOW);
    digitalWrite(LmotorB,LOW);
    digitalWrite(RmotorA,LOW);
    digitalWrite(RmotorB,LOW); 
    
      digitalWrite(M3,HIGH);
      delay(4000);
      digitalWrite(M3,LOW);
  }    
