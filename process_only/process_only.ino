int s1,s2,s3,s4,i,j,t,n,y;
boolean k1,k2,k3,k4,testNo,marker;
 char arr[50];

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
n=8;
arr[0]='S';
arr[1]='L';
arr[2]='L';
arr[3]='R';
arr[4]='B';
arr[5]='L';
arr[6]='S';
arr[7]='J';
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
}

void exitcond(){
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  Serial.println("exit");
}

int processdata(){
    for(i=0;arr[i]!='J';i++){
            if(arr[i-1]=='L' && arr[i]=='B' && arr[i+1]=='S'){
                arr[i-1]='R';
                for(int k=i;k<=n-3;k++){
                    arr[k]=arr[k+2];
                }
                n=n-2;
            }
            if(arr[i-1]=='L' &&  arr[i]=='B' && arr[i+1]=='R'){
                arr[i-1]='B';
                for(int k=i;k<=n-3;k++){
                    arr[k]=arr[k+2];
                }
                n=n-2;
            }
            if(arr[i-1]=='L' &&  arr[i]=='B' && arr[i+1]=='L'){
                arr[i-1]='S';
                for(int k=i;k<=n-3;k++){
                    arr[k]=arr[k+2];
                }
                n=n-2;
            }
            if(arr[i-1]=='S' &&  arr[i]=='B' && arr[i+1]=='S'){
                arr[i-1]='B';
                for(int k=i;k<=n-3;k++){
                    arr[k]=arr[k+2];
                }
                n=n-2;
            }
            if(arr[i-1]=='S' &&  arr[i]=='B' && arr[i+1]=='L'){
                arr[i-1]='R';
                for(int k=i;k<=n-3;k++){
                    arr[k]=arr[k+2];
                }
                n=n-2;
            }
            if(arr[i-1]=='R' &&  arr[i]=='B' && arr[i+1]=='L'){
                arr[i-1]='B';
                for(int k=i;k<=n-3;k++){
                    arr[k]=arr[k+2];
                }
                n=n-2;
                /*for(int m=0;m<n;m++)
                    cout<<arr[m];
                cout<<endl;*/
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
  y=counter();

  Serial.println(y);
  
  while(y>0){
    processdata();
    y=counter();
    Serial.println(y);
  }
  
  for(j=0;arr[j]!='J';j++)
  Serial.println(arr[j]);

  delay(5000);

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
      if(k1==1 && k2==0 && k3==0 && k4==0)
      exitcond();
    }
    
    while(arr[j]=='L'){
      //node();
      marker=0;
      nudge();
      delay(2000);
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
      if(k1==1 && k2==0 && k3==0 && k4==0)
      exitcond();
    }
    
    while(arr[j]=='R'){
      //node();
      marker=0;
      nudge();
      delay(2000);
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
      if(k1==1 && k2==0 && k3==0 && k4==1)
      exitcond();
    }

    while(arr[j]=='J'){
      node();
      if(k1==1 && k2==0 && k3==0 && k4==1)
      exitcond();
      Serial.println("exit");
      delay(10000);
    }
}
}




