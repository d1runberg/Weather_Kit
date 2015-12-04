
const byte RAIN = 2;

//Global Variables
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
long lastSecond; //The millis counter to see when a second rolls by
byte seconds; //When it hits 60, increase the current minute
byte seconds_2m; //Keeps track of the "wind speed/dir avg" over last 2 minutes array of data
byte minutes; //Keeps track of where we are in various arrays of data
byte minutes_10m; //Keeps track of where we are in wind gust/dir over last 10 minutes array of data

float rainin = 0; // [rain inches over the past hour)] -- the accumulated rainfall in the past 60 min
volatile float dailyrainin = 0; // [rain inches so far today in local time]
volatile float rainHour[60]; //60 floating numbers to keep track of 60 minutes of rain

// volatiles are subject to modification by IRQs
volatile unsigned long raintime, rainlast, raininterval, rain;

void setup() {
  Serial.begin(9600);
  pinMode(RAIN, INPUT_PULLUP); // input from wind meters rain gauge sensor
    
  // attach external interrupt pins to IRQ functions
  attachInterrupt(0, rainIRQ, FALLING);

  //turn interrupts on
  interrupts();
}

void loop() 
{
 //Total rainfall for the day is calculated within the interrupt
  //Calculate amount of rainfall for the last 60 minutes
  rainin = 0;
  for (int i = 0 ; i < 60 ; i++)
    rainin += rainHour[i];

  if(millis()%5000 == 0)
  {
    Serial.println("-------------Hourly and Daily Rain Ammounts-----------" );
    Serial.print("Hourly Rain Fall(in): ");
    Serial.print(rainin);
    Serial.print(" , ");
    Serial.print("Daily Rain Fall(in): ");
    Serial.println(dailyrainin);
  }

}

void rainIRQ()
// Count rain gauge bucket tips as they occur
// Activated by the magnet and reed switch in the rain gauge, attached to input D2
{
  raintime = millis(); // grab current time
  raininterval = raintime - rainlast; // calculate interval between this and last event

  if (raininterval > 10) // ignore switch-bounce glitches less than 10mS after initial edge
  {
    dailyrainin += 0.011; //Each dump is 0.011" of water
    rainHour[minutes] += 0.011; //Increase this minute's amount of rain

    rainlast = raintime; // set up for next event
  }
}
