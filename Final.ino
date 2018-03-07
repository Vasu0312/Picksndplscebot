#include<Servo.h>

int svp1 = 5;
int svp2 = 6;
int svp0 = 10;
int potp1=A4;
int potp2=A5;
int potp3=A0;
int val_1;
int val_2;
int val_0;
int a[100],b[100],c[100];
int i=1,k;
boolean startaction=LOW;
Servo sv1;
Servo sv2;
Servo sv0;

 
 void setup() {
  pinMode (svp1,OUTPUT);
  pinMode(svp2,OUTPUT);
  pinMode(svp0,OUTPUT);
  sv1.attach(svp1);
  sv2.attach(svp2);
  sv0.attach(svp0);
  pinMode(potp1,INPUT);
  pinMode(potp2,INPUT);
  pinMode(potp3,INPUT);
  attachInterrupt(0,toggle,RISING);
  attachInterrupt(1,start,RISING);
  
}



void loop() {
  a[0]=0;
    b[0]=0;
    c[0]=0;
val_1=analogRead(potp1);
val_2=analogRead(potp2);
val_0=analogRead(potp3);

val_1=map(val_1,0,1023,0,180);
sv1.write(val_1);
val_2=map(val_2,0,1023,0,180);
sv2.write(val_2);
val_0=map(val_0,0,1023,0,180);
sv0.write(val_0);
if(startaction==HIGH){
  for(int j=1;j<=i;j++){
    if(a[j-1]<a[j]){
      for(k=a[j-1];k<=a[j];k++){
        sv1.write(k);
        delay(10);
      }
    }
    else if(a[j-1]>a[j]){
      for(k=a[j-1];k>=a[j];k--){
        sv1.write(k);
        delay(10);
      }
    }
    if(b[j-1]<b[j]){
      for(k=b[j-1];k<=b[j];k++){
        sv2.write(k);
        delay(10);
      }
    }
    else if(b[j-1]>b[j]){
      for(k=b[j-1];k>=b[j];k--){
        sv2.write(k);
        delay(10);
      }
    }
    if(c[j-1]<c[j]){
      for(k=c[j-1];k<=c[j];k++){
        sv0.write(k);
        delay(10);
      }
    }
    else if(c[j-1]>c[j]){
      for(k=c[j-1];k>=c[j];k--){
        sv0.write(k);
        delay(10);
      }
    }
  }
} 
}
 
   void toggle(){
    delay(500);
    
    a[i]= val_1;
    b[i]= val_2;
    c[i]= val_0;
    i=i+1;
    }
   
   void start(){
    delay(500);
    startaction=!startaction;
    
   }

