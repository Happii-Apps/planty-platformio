#include <Arduino.h>
#include <DHT.h>

// Moisture sensor constants
#define SOIL_MOISTURE_SENSOR_ANALOG_PIN 36
#define SOIL_MOISTURE_SENSOR_DIGITAL_PIN 27

// Temp sensor constants
#define DHT_SENSOR_PIN 4 // ESP32 pin GIOP21 connected to DHT22 sensor
#define DHT_SENSOR_TYPE DHT22

// UV light sensor constants
#define GUVA_SENSOR_PIN 39

DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

float takeMoistureReading()
{
    float moisture = analogRead(SOIL_MOISTURE_SENSOR_ANALOG_PIN);

    float soilSensorValue = 0;

    for (int i = 0; i < 100; i++)
    {
        float newValue = analogRead(SOIL_MOISTURE_SENSOR_ANALOG_PIN);
        soilSensorValue = soilSensorValue + newValue;
        delay(10);
    }

    soilSensorValue = soilSensorValue / 100;

    float convertedMoisture = map(soilSensorValue, 2000, 3370, 0, 100);

    return convertedMoisture;
}

void setupTempSensor()
{
    dht_sensor.begin(); // initialize the DHT sensor
}

float readHumidity()
{
    float humidity = dht_sensor.readHumidity();
    if (isnan(humidity))
    {
        return 0;
    }
    return humidity;
}

float readCelciusTemperature()
{
    float tempC = dht_sensor.readTemperature();
    if (isnan(tempC))
    {
        return 0;
    }
    return tempC;
}

float readFarTemperature()
{
    float tempF = dht_sensor.readTemperature(true);
    if (isnan(tempF))
    {
        return 0;
    }
    return tempF;
}

float takeLightReading()
{
    float sensorValue = analogRead(GUVA_SENSOR_PIN);
    float sensorVoltage = sensorValue / 4095.0 * 3.3;
    return sensorVoltage;
}