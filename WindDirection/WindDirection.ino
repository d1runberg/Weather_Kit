//create variable for analog input pin
const byte WDIR = A0;

//create variable for storing wind direction
// [0-360 instantaneous wind direction]
int winddir = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  //create a local variable to store the raw analog input
  unsigned int adc = analogRead(WDIR); // get the current reading from the sensor

  // The following table is ADC readings for the wind direction sensor output, sorted from low to high.
  // Each threshold is the midpoint between adjacent headings. The output is degrees for that ADC reading.
  // Note that these are not in compass degree order! See Weather Meters datasheet for more information.

  if (adc < 380) winddir = 113;
  if (adc < 393) winddir = 68;
  if (adc < 414) winddir = 90;
  if (adc < 456) winddir = 158;
  if (adc < 508)winddir = 135;
  if (adc < 551) winddir = 203;
  if (adc < 615) winddir = 180;
  if (adc < 680) winddir = 23;
  if (adc < 746) winddir = 45;
  if (adc < 801) winddir = 248;
  if (adc < 833) winddir = 225;
  if (adc < 878) winddir = 338;
  if (adc < 913) winddir = 0;
  if (adc < 940) winddir = 293;
  if (adc < 967) winddir = 315;
  if (adc < 990) winddir = 270;
  // error, disconnected?
  else winddir = -1; 

  Serial.println("------Wind Direction---------");
  Serial.print("Direction(Degrees): ");
  Serial.println(winddir);
}

