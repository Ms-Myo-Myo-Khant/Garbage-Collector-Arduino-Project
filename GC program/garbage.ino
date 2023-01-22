  #define in1 7
#define in2 6
#define in3 4
#define in4 5
#define enA 11
#define enB 3
int const sp=9;
char t;
#include<Servo.h>
Servo sc;

 void setup()
 {
   sc.attach(sp);
   pinMode(enA,OUTPUT);
   pinMode(enB,OUTPUT);
   pinMode(in1,OUTPUT);
   pinMode(in2,OUTPUT);
   pinMode(in3,OUTPUT);
   pinMode(in4,OUTPUT);
   pinMode(sp,OUTPUT);
   Serial.begin(9600);
   
  stopc();
  sc.write(90);
  
 }
void loop()
{
  if(Serial.available())
  {
    t=Serial.read();
    if(t=='f')
    {
      forward();
    }
    else if(t=='b')
    {
      reverse();
    }
    else if(t=='l')
    {
      left();
    }
    else if(t=='r')
    {
      right();
    }
    else if(t=='s')
    {
      stopc();
    }
    else if(t=='c')
    {
      collect();
      sc.write(90);
    }
    else if(t='e')
    {
      sc.write(0);
    }
    else if(t='d')
    {
      sc.write(90);
    }
  }
}
void forward()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(enA,HIGH);
  digitalWrite(enB,HIGH);
}
void reverse()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(enA,HIGH);
  digitalWrite(enB,HIGH);
}
void left()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(enA,HIGH);
  digitalWrite(enB,HIGH);
}
void right()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(enA,HIGH);
  digitalWrite(enB,HIGH);
}
void stopc()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(enA,LOW);
  digitalWrite(enB,LOW);
}
void collect()
{
for(int i=100;i<=0;i--)
{
  sc.write(i);
  delay(1000);
  
}
 

}

