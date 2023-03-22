#include <Arduino.h>
#include <Firebase_ESP_Client.h>

#include "wifi-tools.h"
#include "time-utils.h"
#include "sensor-tools.h"
#include "firebase.h"

#include "sensor-tools.h"

unsigned long dataMillis = 0;

void setup()
{
    Serial.begin(115200);

    connectWifi();
    syncTime();
    setupTempSensor();
    setupFirebase();
}

void loop()
{
    long interval = 600000; // Every hour

    if (Firebase.ready() && (millis() - dataMillis > interval || dataMillis == 0))
    {
        dataMillis = millis();
        createDataPoint();
    }

    delay(2000);
}