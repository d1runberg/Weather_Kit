//include required libraries
#include <Wire.h>

#include <SparkFunMPL3115A2.h>


//create sensor object
MPL3115A2 myPressure;

//create pressure variable
float pressure;

void setup()
{
  // Start serial for output
  Serial.begin(9600);

  // Get sensor online
  myPressure.begin();

  // Configure the sensor
  myPressure.setModeBarometer(); // Measure pressure in Pascals from 20 to 110 kPa
  myPressure.setOversampleRate(7); // Set Oversample to the recommended 128
  myPressure.enableEventFlags(); // Enable all three pressure and temp event flags
}

void loop()
{
  //read the pressure and store it in the pressure variable
  pressure = myPressue.readPressure();

  //print out the pressure over the serial port
  Serial.println("------Pressure Reading------");
  Serial.print("Pressure(pa): ");
  Serial.println(pressure, 2);

  //wait 15 seconds
  delay(15 * 1000);
}

