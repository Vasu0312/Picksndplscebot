#include<Servo.h>
int svp1 = 5;  // the number of the pushbutton pin
int buttonPin = 2;  // the number of the LED pin
int potp1=A4;
int val=0;
int x;
int a[100],b[100];
int i=0;
boolean buttonState; 
boolean lastState = LOW;
boolean startaction=LOW;
boolean state ;// variable for first status
Servo sv1;
 
 void setup() {
  pinMode (svp1,OUTPUT);  // initialize the LED pin as an output:
  sv1.attach(svp1);
  pinMode(potp1,INPUT);
  attachInterrupt(0,toggle,RISING);
  attachInterrupt(1,start,RISING);
}


void loop() {
val=analogRead(potp1);
val=map(val,0,1023,0,180);
sv1.write(val);
if(startaction==HIGH){
  for(int j=0;j<i;j++){
    sv1.write(a[j]);
    delay(500);
  }
}
}
 
   void toggle(){
    delay(10);
    a[i]= val;
    i=i+1;
   }
   void start(){
    startaction=!startaction;
   }

