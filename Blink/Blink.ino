/* 
 Weather Shield Status LED Example Code
 By: Derek Runberg
 SparkFun Electronics
 Date: December 8th, 2015
 License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).
 
 Uses the onboard status LEDs on pins 7 and 8 to blink a "railroad crossing" style blink
 
 Hardware Hookup:
 -Weather Shield -- Make sure all pins are aligned and inserted into the Arduino female headers
 */



//create global variables for status LEDs
const byte STAT1 = 7;
const byte STAT2 = 8;

void setup()
{
 //set up the status pins as outputs 
  pinMode(STAT1, OUTPUT);
  pinMode(STAT2, OUTPUT);
}

void loop()
{
  //turn STAT1 on and STAT2 off
  digitalWrite(STAT1,HIGH);
  digitalWrite(STAT2,LOW);
  //wait for 500ms
  delay(500);
  //Turn STAT1 off and STAT2 on
  digitalWrite(STAT1,LOW);
  digitalWrite(STAT2,HIGH);
  //wait for 500ms
  delay(500);
}

