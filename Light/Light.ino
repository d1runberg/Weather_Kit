/*
 Weather Shield Status Light Sensor Example Code
 By: Derek Runberg
 SparkFun Electronics
 Date: December 8th, 2015
 License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

 Reads the onboard light sensor on pin A1 of the Weather Shield and prints it out over the Serial port

 Hardware Hookup:
 -Weather Shield -- Make sure all pins are aligned and inserted into the Arduino female headers
 */


//constant variables for light sensor and reference voltage
const byte LIGHT = A1;
const byte REFERENCE_3V3 = A3;

//create global variables
float light_lvl = 0; //[analog value from 0 to 1023]
float operatingVoltage;
float lightSensor;

void setup()
{
  //pinMode(REFERENCE_3V3, INPUT);
  //pinMode(LIGHT, INPUT);

  Serial.begin(9600);
  Serial.println("---------Light Level------------");
}

void loop()
{
  //store the referece voltage of 3.3 volts
  operatingVoltage = analogRead(REFERENCE_3V3);
  //read the light sensor and store it in the lightSensor variable
  lightSensor = analogRead(LIGHT);
  //calculate operating voltage
  operatingVoltage = 3.3 / operatingVoltage; //The reference voltage is 3.3V
  //scale light sensor value
  lightSensor = operatingVoltage * lightSensor;

  //print out lightSensor values every 1 second (millis() % 1000)

    Serial.print("Light Level: ");
    Serial.println(lightSensor);
    delay(1000);
}
