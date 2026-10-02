#include <Arduino.h>

#define LED_RED 26
#define LED_GREEN 27
#define LED_YELLOW 12
#define LED_BLUE 14

const int LED_PINS[] = {LED_RED, LED_GREEN, LED_YELLOW, LED_BLUE, LED_YELLOW, LED_GREEN};
const char *LED_NAMES[] = {"RED", "GREEN", "YELLOW", "BLUE", "YELLOW", "GREEN"};
const int TOTAL_STEPS = sizeof(LED_PINS) / sizeof(LED_PINS[0]);

int stepIndex = 0;

void setup()
{
    Serial.begin(115200);

    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);

    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_BLUE, LOW);
}

void loop()
{
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_BLUE, LOW);

    int activePin = LED_PINS[stepIndex];
    digitalWrite(activePin, HIGH);

    Serial.print("chase=");
    Serial.println(LED_NAMES[stepIndex]);

    stepIndex = (stepIndex + 1) % TOTAL_STEPS;

    delay(150);
}