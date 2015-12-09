/*
 Weather Shield Altitude Example using the MPL3115A2 Barometric Pressure Sensor Example Code
 By: Derek Runberg
 SparkFun Electronics
 Date: December 8th, 2015
 License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

 Reads the onboard Barometric Pressure sensor on the Weather Shield and prints it out over 
 the Serial port every 15 seconds

 Hardware Hookup:
 -Weather Shield -- Make sure all pins are aligned and inserted into the Arduino female headers
 */

//include required libraries
#include <Wire.h>

#include <SparkFunMPL3115A2.h>


//create sensor object
MPL3115A2 myPressure;

//create pressure variable
float altitude;
float altitudeFt;

void setup()
{
  // Start serial for output
  Serial.begin(9600);

  // Get sensor online
  myPressure.begin();

  // Configure the sensor
  myPressure.setModeAltimeter(); // Measure altitude above sea level in meters
  myPressure.setOversampleRate(7); // Set Oversample to the recommended 128
  myPressure.enableEventFlags(); // Enable all three pressure and temp event flags

  Serial.println("------Altitude------");
}

void loop()
{
  //read the altitude in meters and store it in the altitude variable
  altitude =  myPressure.readAltitude();

  //read the altitude in feet and store it in the altitudeFt variable
  altitudeFt = myPressure.readAltitudeFt();
  

  //print out the pressure over the serial port
  Serial.print("Altitude(m): ");
  Serial.print(altitude, 2);
  Serial.print(" , ");
  Serial.print("Altitude(ft): ");
  Serial.println(altitudeFt,2);

  //wait 15 seconds
  delay(15 * 1000);
}

