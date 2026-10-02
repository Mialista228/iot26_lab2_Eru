

#include "Arduino.h"

const int BUTTON_PIN = 25;
const int LED_RED = 26;
const int LED_GREEN = 27;
const int LED_YELLOW = 12;
const int LED_BLUE = 14;

const int LED_PINS[] = {LED_RED, LED_GREEN, LED_YELLOW, LED_BLUE};
const int NUM_LEDS = 4;

int pressCount = 0;
bool lastButtonState = LOW;

void upd()
{
    for (int i = 0; i < NUM_LEDS; i++)
    {
        if (i < pressCount)
        {
            digitalWrite(LED_PINS[i], HIGH);
        }
        else
        {
            digitalWrite(LED_PINS[i], LOW);
        }
    }
}

void setup()
{
    Serial.begin(115200);

    pinMode(BUTTON_PIN, INPUT);

    for (int i = 0; i < NUM_LEDS; i++)
    {
        pinMode(LED_PINS[i], OUTPUT);
    }

    upd();
}

void ex4()
{
    bool currentButtonState = digitalRead(BUTTON_PIN);

    delay(10);
    if (lastButtonState == HIGH && currentButtonState == LOW)
    {
        pressCount = (pressCount + 1) % 5;

        upd();

        Serial.print("count=");
        Serial.println(pressCount);

        delay(50);
    }

    lastButtonState = currentButtonState;
}

void loop()
{
    ex4();
}
