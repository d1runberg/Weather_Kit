
//digital input pin variables
const byte WSPEED = 3;

//global variables
long lastSecond; //The millis counter to see when a second rolls by
byte seconds; //When it hits 60, increase the current minute

long lastWindCheck = 0;
volatile long lastWindIRQ = 0;
volatile byte windClicks = 0;

float windspeedmph = 0; // [mph instantaneous wind speed]

void setup()
{
  //start serial port at 9600bps
  Serial.begin(9600);
  //set WSPEED pin as an input_pullup
  pinMode(WSPEED, INPUT_PULLUP); // input from wind meters windspeed sensor

  //setup timing variables for tracking seconds
  seconds = 0;
  lastSecond = millis();

  //setup interupts for watching the wind speed, for every falling edge of a click of the annenometer the wsepedIRQ function will be triggered.
  attachInterrupt(1, wspeedIRQ, FALLING);

  //turn on interupts and watch for them.
  interrupts();
}

void loop()
{
  float deltaTime = millis() - lastWindCheck; //750ms

  deltaTime /= 1000.0; //Covert to seconds

  float windSpeed = (float)windClicks / deltaTime; //3 / 0.750s = 4

  windClicks = 0; //Reset and start watching for new wind
  lastWindCheck = millis();

  windSpeed *= 1.492; //4 * 1.492 = 5.968MPH

  //print out the wind speed once a second
  if(millis()%1000==0)
  {
  Serial.println("-------Wind Speed---------");
  Serial.print("Windspeed (mph):");
  Serial.println(windSpeed);
  }
}

// Activated by the magnet in the anemometer (2 ticks per rotation), attached to input D3 triggered by the interrupt
void wspeedIRQ()
{
  if (millis() - lastWindIRQ > 10) // Ignore switch-bounce glitches less than 10ms (142MPH max reading) after the reed switch closes
  {
    lastWindIRQ = millis(); //Grab the current time
    windClicks++; //There is 1.492MPH for each click per second.
  }
}
