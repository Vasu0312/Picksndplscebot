#include<Servo.h>
int svp1=3;
int potp1=A4;
int val=0;
Servo sv1;
void setup() {
  // put your setup code here, to run once:
  sv1.attach(svp1);
   pinMode(potp1,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val=analogRead(potp1);
  val=map(val, 0, 1023, 0, 180);
  sv1.write(val);

}
