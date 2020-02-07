int s1,s2,s3,s4;
boolean k1,k2,k3,k4;

void setup() {
  pinMode(5,OUTPUT);// put your setup code here, to run once:
  pinMode(6,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
delay(500);
s1=analogRead(A0);
s2=analogRead(A1);
s3=analogRead(A2);
s4=analogRead(A3);
if(s1<100)
k1=1;
else
k1=0;
if(s2<100)
k2=1;
else
k2=0;
if(s3<100)
k3=1;
else
k3=0;
if(s4<100)
k4=1;
else
k4=0;
Serial.print(s1);
Serial.print(',');
Serial.print(s2);
Serial.print(',');
Serial.print(s3);
Serial.print(',');
Serial.print(s4);
Serial.println("-");
Serial.print(k1);
Serial.print(',');
Serial.print(k2);
Serial.print(',');
Serial.print(k3);
Serial.print(',');
Serial.print(k4);
Serial.println("-");


}
