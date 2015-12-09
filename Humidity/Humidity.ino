/*
 Weather Shield Humidity Sensor (HTU21D) Example Code
 By: Derek Runberg
 SparkFun Electronics
 Date: December 8th, 2015
 License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

 Reads the onboard humidity sensor on the Weather Shield and prints it out over the Serial port
 every 15 seconds.

 Hardware Hookup:
 -Weather Shield -- Make sure all pins are aligned and inserted into the Arduino female headers
 */

//Include libraries to use the sensor

#include <Wire.h>

#include <HTU21D.h>

//create library object
HTU21D Temp_Hum;

//create global variables for temperatures

float humidity;

void setup() 
{
//start up the Humidity/Temp sensor
Temp_Hum.begin();
//start serial monitor at 9600 bps
Serial.begin(9600);
//print message that setup has completed
Serial.println("-----Humidity----");
}

void loop() 
{
  //read temperature from sensor
  humidity = Temp_Hum.readHumidity();

  //print out temperatures over the Serial monitor
  Serial.print("Humidity %: ");
  Serial.println(humidity);
  

  //wait for 15 seconds before looping
  delay(15*1000);
}
