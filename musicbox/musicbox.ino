#include "pitches.h"
#include "button.h"
#include "buzzer.h"

#define PIN_BUTTON_MEL_ONE 3
#define PIN_BUTTON_MEL_TWO 4
#define PIN_BUTTON_OFF 5
#define PIN_BUZZER 6

Button buttonMelodyOne(PIN_BUTTON_MEL_ONE);
Button buttonMelodyTwo(PIN_BUTTON_MEL_TWO);
Button buttonOff(PIN_BUTTON_OFF);
Buzzer buzzer(PIN_BUZZER);

int notes[] = {NOTE_A4, NOTE_SILENCE, NOTE_G4, NOTE_SILENCE};
double durations[] = {8, 1, 4, 1};
int melodyLength = 4;

int notes2[] = {NOTE_C4, NOTE_SILENCE, NOTE_G4, NOTE_SILENCE};
double durations2[] = {4, 1, 4, 1};
int melodyLength2 = 4;

void setup()
{
    buzzer.setMelody(notes, durations, melodyLength);
    Serial.begin(115200);
}

void loop()
{
    buzzer.playSound();

    if (buttonOff.wasPressed())
    {
        buzzer.turnSoundOff();
    }

    if (buttonMelodyOne.wasPressed())
    {
        buzzer.setMelody(notes, durations, melodyLength);
        buzzer.turnSoundOn();
    }

    if (buttonMelodyTwo.wasPressed())
    {
        buzzer.setMelody(notes2, durations2, melodyLength2);
        buzzer.turnSoundOn();
    }
}