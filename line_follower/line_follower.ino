int s1,s2,s3,s4;
boolean k1,k2,k3,k4;
void setup() {
  // put your setup code here, to run once:
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
Serial.begin(9600);
}

void forward()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);  
}
void right()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
   digitalWrite(8,LOW);
    digitalWrite(9,LOW);  
}
void left()
{
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
   digitalWrite(8,HIGH);
    digitalWrite(9,LOW);  
}



void loop() {
  // put your main code here, to run repeatedly:
s1=analogRead(A0);
s2=analogRead(A1);
s3=analogRead(A2);
s4=analogRead(A3);
if(s1<400)
k1=1;
else
k1=0;
if(s2<300)
k2=1;
else
k2=0;
if(s3<400)
k3=1;
else
k3=0;
if(s4<290)
k4=1;
else
k4=0;
if(k1==0 && k2==1 && k3==1 && k4==0)
forward();
else if(k1==1 && k2==0 && k3==0 && k4==0)
left();
else if(k1==1 && k2==1 && k3==0 && k4==0)
left();
else if(k1==1 && k2==1 && k3==1 && k4==0)
left();
//else if(k1==0 && k2==1 && k3==0 && k4==0)
//left();
else if(k1==0 && k2==1 && k3==1 && k4==1)
right();
else if(k1==0 && k2==0 && k3==1 && k4==1)
right();
else if(k1==0 && k2==0 && k3==0 && k4==1)
right();
//else if(k1==0 && k2==0 && k3==1 && k4==0)
//right()
;

Serial.print(s1);
Serial.print(" ");
Serial.print(s2);
Serial.print(" ");
Serial.print(s3);
Serial.print(" ");
Serial.print(s4);
Serial.println();
delay(100);
Serial.print(k1);
Serial.print(" ");
Serial.print(k2);
Serial.print(" ");
Serial.print(k3);
Serial.print(" ");
Serial.print(k4);
Serial.println();
delay(100);
}
