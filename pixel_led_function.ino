// Code by : ScitiveX
// WS2812b led strip Functions_Effects
//    ___              _      _        _                    __  __
//   / __|    __      (_)    | |_     (_)    __ __    ___   \ \/ /
//   \__ \   / _|     | |    |  _|    | |    \ V /   / -_)   >  <
//   |___/   \__|_   _|_|_   _\__|   _|_|_   _\_/_   \___|  /_/\_\  
// _|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|
// "`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'
//

// Video Part - 1 :  https://youtu.be/G0me3hRd8rI
// Video Part - 2 :  https://youtu.be/uqrHAzT7U1k

// Library Download Link : https://github.com/FastLED/FastLED/archive/refs/heads/master.zip
#include <FastLED.h>

#define LED_PIN 5
#define NUM_LEDS 21

CRGB leds[NUM_LEDS]; // array of CRGB objects

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS); // Initialize the LED strip
}

void loop() {
  for (int i = 0 ; i < 5; i++) {
    f1(0, 0, 255, 80);
    all_off(10);
  }
  for (int i = 0 ; i < 5; i++) {
    f2(255, 0, 0, 80);
    all_off(10);
  }
  for (int i = 0 ; i < 5; i++) {
    f3(255, 0, 0, 80);
    all_off(10);
  }
  for (int i = 0 ; i < 5; i++) {
    f4(0, 255, 0, 80);
    all_off(10);
  }
}


void f1(int r, int g, int b, int t1) {

  for (int i = 0 ; i < NUM_LEDS ; i++) {
    leds[i] = CRGB(r, g, b);
    FastLED.show();
    delay(t1);
  }
}

void f2(int r, int g, int b, int t2) {

  for (int i = 0 ; i < NUM_LEDS ; i++) {
    leds[i] = CRGB(r, g, b);
    FastLED.show();
    delay(t2);
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
    delay(t2);
  }

}


void f3(int r, int g, int b, int t3) {
  for (int i = 0 ; i < NUM_LEDS - 5 ; i++) {
    leds[i] = CRGB(r, g, b);
    leds[NUM_LEDS - i - 1] = CRGB(r, g, b);
    FastLED.show();
    delay(t3);
  }
  leds[4] = CRGB(255, 255, 255);
  leds[5] = CRGB(255, 255, 255);
  FastLED.show();
  delay(t3);
}


void f4(int r, int g, int b, int t4) {
  for (int i = 0 ; i < NUM_LEDS ; i += 2) {
    leds[i] = CRGB(r, g, b);
  }
  FastLED.show();
  delay(t4);
  all_off(10);

  for (int i = 0 ; i < NUM_LEDS ; i += 2) {
    leds[i + 1] = CRGB(255, 255, 255);
  }
  FastLED.show();
  delay(t4);
  all_off(10);
}


void all_off(int d_t) {
  for (int i = 0 ; i < NUM_LEDS ; i++) {
    leds[i] = CRGB(0, 0, 0);
  }
  FastLED.show();
  delay(d_t);
}
