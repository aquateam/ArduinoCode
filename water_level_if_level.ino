/* Arduino Tutorial - Watel Level Sensor 40mm
   More info: */
int motorPin=9;

const int read = A0; //Sensor AO pin to Arduino pin A0
int value;          //Variable to store the incomming data

void setup()
{
  //Begin serial communication
  Serial.begin(9600);
  pinMode(motorPin,OUTPUT);
}

void loop()
{
  value = analogRead(read); //Read data from analog pin and store it to value variable
  Serial.println(value);
  if (value >600){
     analogWrite(motorPin,200);
  delay(10);
  }
  if (value<600){
     analogWrite(motorPin,0);
  delay(10);
  }
  delay(1000);
  
}
