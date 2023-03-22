#include <Arduino.h>
#include <WiFi.h>

// Wifi credentials
#define WIFI_SSID "MyAltice e3219d"
#define WIFI_PASSWORD "24-chestnut-8872"

void connectWifi()
{
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(300);
    }
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();
}

void disconnectWifi()
{
    WiFi.disconnect();
    Serial.println("Disconnected from Wi-Fi");
}