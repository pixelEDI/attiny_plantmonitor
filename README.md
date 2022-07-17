<img src="https://img.shields.io/badge/-ATtiny%20Project-blue.svg?&amp;style=flat-square&amp" style="max-width: 100%;"> <img src="https://img.shields.io/badge/-PlattformIO-orange.svg?&amp;style=flat-square&amp" style="max-width: 100%;">


# General info
[![](https://yt-embed.live/embed?v=3gcNlHXEj_g)](http://www.youtube.com/watch?v=3gcNlHXEj_g "DIY Moisture Control for Plants")

## Code
- First we have to calibrate the moisture sensor with the arduino UNO and the file CalibrateMoistureSensor/src/main.cpp. To do this, we connect the sensor as shown below: 

![Verdrahtung](https://github.com/pixelEDI/attiny_plantmonitor/blob/main/CalibrateMoistureSensor_ArduinoUno_wiring.jpg)

- After the sensor is calibrated, we can program the ATtiny with the attiny_plantmonitor/src/main.cpp file.
- In this project we work with the tinysnore library to put the ATtiny into deep sleep, which increases the life of the button cell battery.
- We also use the TimerFreeTone library for the buzzing sound. 
- In the readMoistureSensor() function, we get the moisture value from the sensor and map it into percentage values according to the values we got from calibrating the sensor.
- If the percentage is less than 10, the moisture value is set to true for the alarm.
- In the function flashLED(bool withSound) we turn the LED on and off, and if the bool "withSound" is true, we also turn the buzzer on and off.
- The function readPhotoresistor() evaluates the brightness. If the brightness becomes less than 400, the bool "dark" becomes true.
- In the loop we read the photoresistor and the moisture sensor.
- We check if the bool "dark" is true and the "moistureThreshold" is true, then the alarm is without buzzer.
- If "dark" bool is false and "moistureThreshold" is true, the alarm is with buzzer.
- At the end we send the ATtiny into deep sleep (for test purposes only for 10 seconds at first, if it works properly you can increase the ms here).

## Hardware
- This DIY moisture controller for plants runs on an ATtiny 25. 
- We have built in a capacitive soil moisture sensor to measure the moisture of the plant.
- For the alarm sound we have built in a piezo buzzer and a 100 Ω resistor to soften the sound.
- We also built in a 3mm LED connected to a 100 Ω resistor.
- To switch between the alarm with the sound or the LED, we have built in a photoresistor connected to a 10k Ω resistor.
- The moisture control is powered by a CR2032 3V button cell battery.

![Verdrahtung](https://github.com/pixelEDI/attiny_plantmonitor/blob/main/MoistureSensorWithBuzzer_wiring.jpg)


## 3D Case
Get the Case:   [Thingiverse](https://www.thingiverse.com/thing:5434778)

You like it? Then I would be very happy if you treat me to a coffee on [ko-fi.com/pixeledi](https://www.ko-fi.com/pixeledi)
