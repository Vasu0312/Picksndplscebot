#include <Servo.h>
int svp1=3;
int svp2=5;
Servo sv1;
Servo sv2;
void setup() {
  // put your setup code here, to run once:
  
sv1.attach(svp1);
sv2.attach(svp2);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<181;i++)
  {sv1.write(i);
   sv2.write(i);
  delay(10);}
  for(int i=180;i>0;i--)
  {sv1.write(i);
  sv2.write(i);
  delay(10);}


}
