
const byte LIGHT = A1;
const byte REFERENCE_3V3 = A3;

float light_lvl = 455; //[analog value from 0 to 1023]
float operatingVoltage;
float lightSensor;
void setup()
{
  pinMode(REFERENCE_3V3, INPUT);
  pinMode(LIGHT, INPUT);

  Serial.begin(9600);
}

void loop()
{
  operatingVoltage = analogRead(REFERENCE_3V3);

  lightSensor = analogRead(LIGHT);

  operatingVoltage = 3.3 / operatingVoltage; //The reference voltage is 3.3V

  lightSensor = operatingVoltage * lightSensor;

  if (millis() % 1000 == 0)
  {
    Serial.println("---------Light Level------------");
    Serial.print("Light Level: ");
    Serial.println(lightSensor);
  }
}
