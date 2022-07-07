/*


        _          _ ______ _____ _____
       (_)        | |  ____|  __ \_   _|
  _ __  ___  _____| | |__  | |  | || |
 | '_ \| \ \/ / _ \ |  __| | |  | || |
 | |_) | |>  <  __/ | |____| |__| || |_
 | .__/|_/_/\_\___|_|______|_____/_____|
 | |
 |_|

www.pixeledi.eu | twitter.com/pixeledi
ATtiny Moisture Sensore | V1.0 | 06/2022

Calibrate Moisture Sensor

1 Step: print Value from sensor and set dry variable
2 Step. print value from sensor in water and set wet
2 Step: map Sensor values for percentage value

*/

#include <Arduino.h>

int dry = 457;
int wet = 186;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  int sensorVal = analogRead(0);

  int percentHum = map(sensorVal, wet, dry, 100, 0);

  Serial.println(percentHum);
  delay(500);
}