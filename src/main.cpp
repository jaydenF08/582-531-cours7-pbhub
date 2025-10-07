#include <Arduino.h>

#include <FastLED.h>
// CRGB keyPixel;
CRGB atomPixel;

#define BROCHE_ATOM_FIL_BLANC 32
#define BROCHE_ATOM_FIL_JAUNE 26
#define BROCHE_ATOM_BOUTON 39
#define BROCHE_ATOM_PIXEL 27

#include <M5_PbHub.h>
M5_PbHub myPbHub;

#define KEY_CHANNEL 0

void setup()
{
  // keyPixel = CRGB(255, 255, 255); // BLANC

  // FastLED.addLeds<WS2812, BROCHE_ATOM_FIL_JAUNE, GRB>(&keyPixel, 1);

  FastLED.addLeds<WS2812, BROCHE_ATOM_PIXEL, GRB>(&atomPixel, 1);

  // pinMode(BROCHE_ATOM_FIL_BLANC, INPUT);

  pinMode(BROCHE_ATOM_BOUTON, INPUT);

  Wire.begin();
  myPbHub.begin();

  myPbHub.setPixelCount(KEY_CHANNEL, 1);
}

void loop()
{
  // int maLectureKey = digitalRead(BROCHE_ATOM_FIL_BLANC);

  int maLectureKey = myPbHub.digitalRead(KEY_CHANNEL);

  int maLectureAtomBouton = digitalRead(BROCHE_ATOM_BOUTON);

  if (maLectureKey == 1)
  {
    // keyPixel = CRGB(0, 0, 0);
    myPbHub.setPixelColor(KEY_CHANNEL, 0, 0, 0, 0);
  }
  else
  {
    // keyPixel = CRGB(127, 255, 0);

    myPbHub.setPixelColor(KEY_CHANNEL, 0, 127, 255, 0);
  }

  if (maLectureAtomBouton == 1)
  {

    atomPixel = CRGB(0, 0, 0);
  }
  else
  {

    atomPixel = CRGB(127, 255, 0);
  }

  FastLED.show();

  delay(20);
}
