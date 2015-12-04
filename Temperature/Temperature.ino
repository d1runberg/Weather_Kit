//Include libraries to use the sensor

#include <Wire.h>

#include <HTU21D.h>

//create library object
HTU21D Temp_Hum;

//create global variables for temperatures

float tempC;
float tempF;

void setup() 
{
//start up the Humidity/Temp sensor
Temp_Hum.begin();
//start serial monitor at 9600 bps
Serial.begin(9600);
//print message that setup has completed
Serial.println("HTU21D Started");
}

void loop() 
{
  //read temperature from sensor
  tempC = Temp_Hum.readTemperature();

  //calculate tempF from tempC
  tempF = (tempC*2)+30;

  //print out temperatures over the Serial monitor
  Serial.println("-----Temperature----");
  Serial.print("Celcius: ");
  Serial.print(tempC);
  Serial.print(" , ");
  Serial.print("Fahrenheit: ");
  Serial.println(tempF);

  //wait for 15 seconds before looping
  delay(15*1000);
}
