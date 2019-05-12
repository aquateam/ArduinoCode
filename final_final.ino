
#include <OneWire.h>
#include <DallasTemperature.h>
int motorPin=9;
int motorPin2=10; 
#define ONE_WIRE_BUS 2

const int read = A0; //Sensor AO pin to Arduino pin A0
const int temp1 =0 ;
const int temp2=27 ;
int value;          //Variable to store the incomming data
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup()
{
  //Begin serial communication
  Serial.begin(9600);
  pinMode(motorPin,OUTPUT);
  pinMode(motorPin2,OUTPUT);
    Serial.println("Dallas Temperature IC Control Library Demo");

    sensors.begin();

}

void loop()
{
  value = analogRead(read); //Read data from analog pin and store it to value variable
  Serial.println(value);
  if (value >600){
     analogWrite(motorPin,250);
     analogWrite(motorPin2,0);
  delay(10);
  }
  if (value<500){
     analogWrite(motorPin,0);
     analogWrite(motorPin2,250);
  delay(10);
  }
  if (value<600 && value>500){
    analogWrite(motorPin,0);
    analogWrite(motorPin2,0);
    delay(10);
  }

   Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");
  // We use the function ByIndex, and as an example get the temperature from the first sensor only.
  float tempC = sensors.getTempCByIndex(0);

  // Check if reading was successful
  
    Serial.print("Temperature for the device 1 (index 0) is: ");
    Serial.println(tempC);
    delay(10);
        if (tempC >=temp2)
    {
  analogWrite(motorPin,200);
  analogWrite(motorPin2,200);
  delay(10);

      }
   
  else if (tempC<temp1) 
  { analogWrite(motorPin,200);
  analogWrite(motorPin2,200);
  delay(10);
  }
 else 
  {
    Serial.println("Error: Could not read temperature data");
  }
  delay(1000);
  
}
