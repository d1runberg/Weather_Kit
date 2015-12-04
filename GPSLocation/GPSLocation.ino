#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 4800;

TinyGPSPlus gps;

SoftwareSerial ss(RXPin, TXPin);

void setup() {
 Serial.begin(115200);
  ss.begin(GPSBaud);

}

void loop() {
 if (gps.location.isValid())
  {
    Serial.println("--------Current Location------");
    Serial.print("Lattitude: ");
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print("Longitude: ");
    Serial.print(gps.location.lng(), 6);
  }
  else
  {
    Serial.print(F("Location ERROR!"));
  }
}
