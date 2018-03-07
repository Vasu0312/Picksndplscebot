
int potp1=A4;
int val=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(potp1,INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(potp1);
  Serial.println(val);
  delay(100);

}
