//Include libraries to use the sensor

#include <Wire.h>

#include <HTU21D.h>

//#include <Math.h>

//create library object
HTU21D Temp_Hum;

//create global variables for temperatures

float humidity;
float tempC;

//intermediate values for calculating dew point
float B;
float L;
float M;
float N;

//variable for final dew point
float DP;

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
  humidity = Temp_Hum.readHumidity();
  //read tempC
  tempC = Temp_Hum.readTemperature();

  //Calculate Intermediate value of L
  L = log(humidity/100);
  M = 17.27 * tempC;
  N = 237.3 + tempC;
  B = (L + (M/N))/17.27;

  //calculate dew point from intermediate values
   
  DP = (237.3 * B)/ (1-B);
  //print out temperatures over the Serial monitor
  Serial.println("-----Dew Point----");
  Serial.print("Dew Point Celcius: ");
  Serial.println(DP);
  

  //wait for 15 seconds before looping
  delay(15*1000);
}
