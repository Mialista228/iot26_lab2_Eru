

#include "Arduino.h"

const int LIGHT_PIN = 33;

const int HIGH_THRESHOLD = 3000;
const int LOW_THRESHOLD = 2500;

const unsigned long INTERVAL = 300;
unsigned long lastReadTime = 0;

bool alertActive = false;

void setup()
{
    Serial.begin(115200);
    pinMode(LIGHT_PIN, INPUT);
}

void loop()
{
    unsigned long currentMillis = millis();

    if (currentMillis - lastReadTime >= INTERVAL)
    {
        lastReadTime = currentMillis;

        int lightVal = analogRead(LIGHT_PIN);

        if (lightVal > HIGH_THRESHOLD && !alertActive)
        {
            alertActive = true;
            Serial.println("ALERT=1");
        }
        else if (lightVal < LOW_THRESHOLD && alertActive)
        {
            alertActive = false;
            Serial.println("ALERT=0");
        }
    }
}