#include <SoftwareSerial.h>

#define ena   9
#define enb   10
#define dira  8
#define rema  7
#define dirb  11
#define remb  13
int INA = 5; 
int INB = 6;
char data;
int api;

SoftwareSerial Bluetooth(2,3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(2400);
  Bluetooth.begin(9600);
  pinMode (A0, INPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);
  pinMode(dira,OUTPUT);
  pinMode(dirb,OUTPUT);
  pinMode(rema,OUTPUT);
  pinMode(remb,OUTPUT);
  pinMode(INA,OUTPUT); 
  pinMode(INB,OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Bluetooth.available() > 0)
  {
    data=Bluetooth.read();
    Serial.println(data);

    if(data=='S')      
    {
      maju();
    }
    else if(data=='W')  
    {
      mundur();
    }
    else if(data=='D')  
    {
      kiri();
    }
    else if(data=='A')  
    {
      kanan();
    }
    else                
    {
      berhenti();
    }
  }
  api = analogRead(A0);
  Serial.print("Data analog sensor : ");Serial.println(api);
  float voltage = (api/1024.0)*5.0;
  float temperature = api/2.0491;
  Serial.print("Suhu : ");Serial.println(temperature);
  
  delay(100);
 if ( api<=45 ) {
    berhenti();
    digitalWrite(INA,LOW);
    digitalWrite(INB, HIGH); 
    delay(8000); 
  } else {
    digitalWrite(INA,LOW);
    digitalWrite(INB,LOW); 
    delay(500); 
  }
  
}

void maju()
{
  digitalWrite(dira,HIGH);
  digitalWrite(dirb,HIGH);
  digitalWrite(rema,LOW);
  digitalWrite(remb,LOW);
  analogWrite(ena,75);
  analogWrite(enb,76);
}

void mundur()
{
  digitalWrite(dira,LOW);
  digitalWrite(dirb,LOW);
  digitalWrite(rema,HIGH);
  digitalWrite(remb,HIGH); 
  analogWrite(ena,75);
  analogWrite(enb,76); 
}

void kiri()
{
  digitalWrite(dira,HIGH);
  digitalWrite(dirb,LOW);
  digitalWrite(rema,LOW);
  digitalWrite(remb,HIGH);
  analogWrite(ena,60);
  analogWrite(enb,0);
}

void kanan()
{
  digitalWrite(dira,LOW);
  digitalWrite(dirb,HIGH);
  digitalWrite(rema,HIGH);
  digitalWrite(remb,LOW);
  analogWrite(ena,0);
  analogWrite(enb,60);
}

void berhenti()
{
  analogWrite(ena,0);
  analogWrite(enb,0);
}

