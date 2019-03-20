int motorPin=9;
F2BHFaYD
void setup() {
  // put your setup code here, to run once:
pinMode(motorPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //accelerate from 0 to 255
for (int i=0; i<=255;i++)
{
  analogWrite(motorPin,i);
  delay(10);
}
//hold at top speed 
delay(500); 
//decrease from 255 to 0 
for (int i=255 ; i>=0; i --) 
{
  analogWrite(motorPin,i);
delay(10); 
}

//Hold at zero 
delay(500);
}
