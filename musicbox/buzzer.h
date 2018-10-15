#pragma once

#define BUZZER_DEFAULT_NOTE_DURATION 100

class Buzzer
{
public:
    Buzzer(int _pin)
    {
        pin = _pin;
        pinMode(pin, OUTPUT);

        isEnabled = false;
        currentNote = 0;
        noteStartedMs = 0;

        notes = 0;
        durations = 0;
        melodyLength = 0;

        noteDurationMs = BUZZER_DEFAULT_NOTE_DURATION;
    }

    void turnSoundOn()
    {
        isEnabled = true;
        currentNote = 0;
        noteStartedMs = 0;
    }

    void turnSoundOff()
    {
        isEnabled = false;
        currentNote = 0;
        noteStartedMs = 0;
        noTone(pin);
    }

    void setMelody(int _notes[], double _durations[], int _melodyLength)
    {
        notes = _notes;
        durations = _durations;
        melodyLength = _melodyLength;
    }

    void setNoteDuration(unsigned long _noteDurationMs)
    {
        noteDurationMs = _noteDurationMs;
    }

    void playSound()
    {
        if (!isEnabled)
            return;

        unsigned long duration = round(noteDurationMs*durations[currentNote]);
        if ((millis() - noteStartedMs) > duration)
        {
            int note = notes[currentNote];
            
            if (note == NOTE_SILENCE)
                noTone(pin);
            else 
                tone(pin, notes[currentNote]);

            noteStartedMs = millis();
            currentNote = (currentNote + 1)%melodyLength;
        }
    }

private:
    int pin;
    bool isEnabled;

    int currentNote;
    unsigned long noteStartedMs;

    int* notes;
    double* durations;
    int melodyLength;

    unsigned long noteDurationMs;
};
