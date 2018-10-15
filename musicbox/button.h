#pragma once

#define BUTTON_DEBOUNCE_DELAY 50

class Button
{
public:
    Button(int _pin)
    {
        pin = _pin;
        state = LOW;
        debounceState = LOW;

        pinMode(pin, INPUT_PULLUP);
    }

    bool wasPressed()
    {
        bool result = false;
        int lastSeen = state;
        readButtonWithDebounce();

        if (lastSeen == HIGH && state == LOW)
            result = true;

        return result;
    }

    void readButtonWithDebounce()
    {  
        int current = digitalRead(pin);

        if (current != debounceState)
            debounceLastMs = millis();

        if ((millis() - debounceLastMs) > BUTTON_DEBOUNCE_DELAY)
            state = current;

        debounceState = current;
    }

private:
    int pin;
    int state;
    int debounceState;
    unsigned long debounceLastMs;
};