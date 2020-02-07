int s1,s2,s3,s4,i,j,t,n,y;
boolean k1,k2,k3,k4,testNo,marker;
char arr[25];

void setup() {
  // put your setup code here, to run once:
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
i=0;
j=0;
marker=0;
testNo=0;
Serial.begin(9600);
}

void forward()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  delay(100);
}

void Rturn()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  delay(100);  
}

void Lturn()
{
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW); 
  delay(100);
}

void node()
{
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  Serial.println("Node");
  delay(500);  
}

void reader(){
s1=analogRead(A0);
s2=analogRead(A1);
s3=analogRead(A2);
s4=analogRead(A3);
if(s1<350)
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
if(s4<250)
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

void nudge()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  Serial.println("Nudge");
  delay(2000);  
}

int processdata(){
    for(int i=0;arr[i]!='J';i++){
        if(arr[i]=='B'){
            if(arr[i-1]=='L' && arr[i+1]=='S'){
                arr[i-1]='R';
                for(int k=i;k<=n-2;k++){
                    arr[k]=arr[k+2];
                }
                n=n-2;
            }
            if(arr[i-1]=='L' && arr[i+1]=='R'){
                arr[i-1]='B';
                for(int k=i;k<=n-2;k++){
                    arr[k]=arr[k+2];
                }
                n=n-2;
            }
            if(arr[i-1]=='L' && arr[i+1]=='L'){
                arr[i-1]='S';
                for(int k=i;k<=n-2;k++){
                    arr[k]=arr[k+2];
                }
                n=n-2;
            }
            if(arr[i-1]=='S' && arr[i+1]=='S'){
                arr[i-1]='B';
                for(int k=i;k<=n-2;k++){
                    arr[k]=arr[k+2];
                }
                n=n-2;
            }
            if(arr[i-1]=='S' && arr[i+1]=='L'){
                arr[i-1]='R';
                for(int k=i;k<=n-2;k++){
                    arr[k]=arr[k+2];
                }
                n=n-2;
            }
            if(arr[i-1]=='R' && arr[i+1]=='L'){
                arr[i-1]='B';
                for(int k=i;k<=n-2;k++){
                    arr[k]=arr[k+2];
                }
                n=n-2;
            }
        }
    }
    return 0;
}

int counter(){
    int x=0;
    for(int i=0;arr[i]!='J';i++){
        if(arr[i]=='B')
            x++;
    }
    return x;
}

void loop(){
  while(testNo==0){
   reader();

if((k1==0 && k2==1 && k3==1 && k4==0) || (k1==0 && k2==1 && k3==0 && k4==0) || (k1==0 && k2==0 && k3==1 && k4==0)){
  while(k1!=1 && k4!=1){ 
  forward();
  Serial.println("Forwardf");
  reader();
  }
  Serial.println("Coming out");
  arr[i]='S';
  i=i+1;
}

else if((k1==1 && k2==1 && k3==1 && k4==0) || (k1==1 && k2==1 && k3==0 && k4==0)){
  node();
  nudge();
  marker=0;
  Lturn();
  delay(500);
  while(marker==0){
  Lturn();
  Serial.println("Lturn");
  reader();
  if(k2==1 && k3==1)
  marker=1;
  }
  while(marker==1){ 
  forward();
  Serial.println("Forwardl");
  reader();
  if(k1==1 || k4==1)
  marker=0; 
  }
  Serial.println("Coming out");
  arr[i]='L';
  i=i+1;
}

else if ((k1==0 && k2==1 && k3==1 && k4==1) || (k1==0 && k2==0 && k3==1 && k4==1)){
  node();
  nudge();
  reader();
  marker=0;
  if(k1==0 && k2==1 && k3==1 && k4==0){
  while(k1!=1 || k4!=1){ 
  forward();
  Serial.println("Forwardr");
  reader();
  }
  arr[i]='F';
  i=i+1;
  }
  else{
    Rturn();
    delay(500);
  while(marker==0){
  Rturn();
  Serial.println("Rturn");
  reader();
  if(k2==1 && k3==1)
  marker=1;
  }
  while(marker==1){ 
  forward();
  Serial.println("Forwardr");
  reader();
  if(k1==1 || k4==1)
  marker=0;
  }
  arr[i]='R';
  i=i+1;
  }
}

else if(k1==1 && k2==1 && k3==1 && k4==1){
  node();
  nudge();
  reader();
  while(marker==0){
  Lturn();
  Serial.println("lturn");
  reader();
  if(k2==1 && k3==1)
  marker=1;
  }
  while(marker==1){ 
  forward();
  Serial.println("Forwardl2");
  reader();
  if(k1==0 && k4==0)
  marker=0;
  }
  arr[i]='L';
  Serial.println("coming out");
  i=i+1;
}

else if(k1==0 && k2==0 && k3==0 && k4==0){
  node();
  marker=0;
  while(marker==0){
  Lturn();
  Serial.println("lturnb");
 // node();
  reader();
  if(k2==1 && k3==1)
  marker=1;
  }
  while(marker==1){ 
  forward();
  Serial.println("Forwardl3");
  reader();
  if(k1==1 || k4==1)
  marker=0;
  }
  Serial.println("coming out");
  arr[i]='B';
  i=i+1;
}

else if(k1==1 && k2==0 && k3==0 && k4==1){
  testNo=1;
  arr[i]='J';
  i=i+1;
  n=i;
    delay(10000);
    for(j=0;j<n;j++)
        Serial.println(arr[j]);
}

else{
  reader();
} 
}

while(testNo==1){
  node();
  y=counter();
  while(y>0){
    processdata();
    y=counter();
  }
  
  for(j=0;arr[j]!='J';j++)
  Serial.println(arr[j]);
  
  Serial.println("loop enters");
  
  for(j=0;arr[j]!='J';j++){
    Serial.println(j);
    
    while(arr[j]=='S'){
      forward();
      Serial.println("forward");
      reader();
      t=k1+k2+k3+k4;
      if(t>=3){
      node();  
      break;
      }
    }
    
    while(arr[j]=='L'){
      //node();
      marker=0;
      nudge();
      //delay(2000);
      while(marker==0){
      Lturn();
      if(k1==0 && k2==1 && k3==1 && k4==0)
      marker=1;
      Serial.println("Lturn");
      reader();
      }
      if(marker==1){
      //node();
      t=0;
      while(t<=3){
      forward();
      Serial.println("Forwardl");
      reader();
      t=k1+k2+k3+k4;
      }
      break;
      }
    }
    
    while(arr[j]=='R'){
      //node();
      marker=0;
      nudge();
      //delay(2000);
      while(marker==0){
      Rturn();
      if(k1==0 && k2==1 && k3==1 && k4==0)
      marker=1;
      Serial.println("Rturn");
      reader();
      }
      if(marker==1){
      //node();
      t=0;
      while(t<=3){
      forward();
      Serial.println("Forwardr");
      reader();
      t=k1+k2+k3+k4;
      }
      break;
      }
    }

    while(arr[j]=='J'){
      node();
      Serial.println("exit");
      delay(10000);
    }
}
}
}

