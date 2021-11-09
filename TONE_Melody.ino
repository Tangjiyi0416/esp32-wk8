#include "pitches.h"

int freq = 2000;
int channel = 0;
int resolution = 8;

int tonePin = 12;

int melody[] = {
  NOTE_D7, NOTE_A5, NOTE_A5, NOTE_D7, NOTE_A5, NOTE_A5,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_D7, NOTE_D7, NOTE_C7,
  NOTE_D7, NOTE_A5, NOTE_A5, NOTE_D7, NOTE_A5, NOTE_A5,
  NOTE_G4, NOTE_G4, NOTE_D7, NOTE_D7, NOTE_G4, 
};
int noteDurations[] = {
  4, 4, 2, 4, 4, 2,
  4, 4, 4, 4, 4, 4,2,
  4, 4, 2, 4, 4, 2, 
  4, 4, 4, 4, 2,
};

void setup() {
  Serial.begin(115200);
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(tonePin, channel);
}

void loop() {
    for (int thisNote = 0; thisNote < 42; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];
      ledcWriteTone(channel, melody[thisNote]);
      delay(noteDuration);
      ledcWriteTone(channel, 0);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
    }
}
