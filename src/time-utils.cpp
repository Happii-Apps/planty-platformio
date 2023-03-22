#include <Arduino.h>
#include <ezTime.h>

void syncTime()
{
    waitForSync(); // Wait for time to be synced
}

String getTime()
{
    String date = UTC.dateTime("Y-m-d");
    String time = UTC.dateTime("H:i:s");
    String dateTime = date + "T" + time + "Z";
    return dateTime;
}