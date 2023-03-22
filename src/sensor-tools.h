#ifndef SENSOR_TOOLS_H
#define SENSOR_TOOLS_H

#include <Arduino.h>

void setupTempSensor();
float readHumidity();
float readCelciusTemperature();
float readFarTemperature();

float takeMoistureReading();

float takeLightReading();

#endif
