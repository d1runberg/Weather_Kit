
//create variables for status LEDs
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

