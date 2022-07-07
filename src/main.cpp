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
Moisture Sensor with Buzzer | V1.0 | 06/2022

*/

#include <Arduino.h>

#include <tinysnore.h>
#include "TimerFreeTone.h"

const byte buzzer = 1;
const byte powerBrightnessMoisture = 0;
const byte brightnessSensor = A3;
const byte moistureSensor = A2;
const byte led = 2;

int dry = 457;
int wet = 186;

bool dark = true;
bool moistureThreshold = false;
int sensorVal = 0;
int percentageHumidity = 0;

void readMoistureSensor()
{
  int moistureValue = analogRead(moistureSensor);

  percentageHumidity = map(moistureValue, wet, dry, 100, 0);

  if (percentageHumidity <= 0)
    percentageHumidity = 0;
  else if (percentageHumidity >= 99)
    percentageHumidity = 99;

  if (percentageHumidity < 10)
    moistureThreshold = true;
  else
    moistureThreshold = false;
}

void flashLED(bool withSound)
{

  for (byte i = 0; i < 3; i++)
  {

    if (withSound)
      TimerFreeTone(buzzer, 1000, 500, 8);

    digitalWrite(led, HIGH);
    delay(1000);

    if (withSound)
      TimerFreeTone(buzzer, 50, 500, 8);

    digitalWrite(led, LOW);
    delay(1000);
  }
}

void readPhotoresistor()
{
  sensorVal = 1023;

  for (byte i = 0; i < 50; i++)
  {
    int tmpVal = analogRead(brightnessSensor);
    if (tmpVal < sensorVal)
      sensorVal = tmpVal;
    delay(20);
  }

  if (sensorVal < 400)
    dark = true;
  else
    dark = false;
}

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(powerBrightnessMoisture, OUTPUT);

  flashLED(true);
  delay(1000);
}

void loop()
{
  digitalWrite(powerBrightnessMoisture, HIGH);
  delay(100);

  readPhotoresistor();
  readMoistureSensor();

  if (!dark && moistureThreshold)
  {
    flashLED(true); // with buzzer
  }
  else if (dark && moistureThreshold)
  {
    flashLED(false); // with no buzzer
  }

  digitalWrite(powerBrightnessMoisture, LOW);
  //delay(10000);
  snore(10000);
}