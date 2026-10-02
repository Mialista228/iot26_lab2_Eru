

#include "Arduino.h"

#define LIGHT_PIN 33

const unsigned long SAMPLE_INTERVAL = 1000;
unsigned long previousMillis = 0;

void setup()
{
    Serial.begin(115200);
    pinMode(LIGHT_PIN, INPUT);
}

void loop()
{
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= SAMPLE_INTERVAL)
    {
        previousMillis = currentMillis;

        int firstSample = analogRead(LIGHT_PIN);
        int minVal = firstSample;
        int maxVal = firstSample;
        long sum = firstSample;

        for (int i = 1; i < 10; i++)
        {
            int sample = analogRead(LIGHT_PIN);

            if (sample < minVal)
            {
                minVal = sample;
            }
            if (sample > maxVal)
            {
                maxVal = sample;
            }
            sum += sample;
            delay(100);
        }

        int avgVal = sum / 10;

        Serial.print("min=");
        Serial.print(minVal);
        Serial.print(" max=");
        Serial.print(maxVal);
        Serial.print(" avg=");
        Serial.println(avgVal);
    }
}