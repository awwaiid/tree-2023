// #include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <WiFi.h>

#define ONBOARD_NUMPIXELS        1
#define ONBOARD_NEOPIXEL_PIN     PIN_NEOPIXEL
Adafruit_NeoPixel onboard_pixels(
  ONBOARD_NUMPIXELS,
  ONBOARD_NEOPIXEL_PIN,
  NEO_GRB + NEO_KHZ800
);

#define TREE_NUMPIXELS        100
#define TREE_NEOPIXEL_PIN     A3
Adafruit_NeoPixel tree_pixels(
    TREE_NUMPIXELS,
    TREE_NEOPIXEL_PIN,
    NEO_GRB + NEO_KHZ800
);

void setup() {
  Serial.begin(115200);
  onboard_pixels.begin();
  onboard_pixels.setBrightness(20);

  tree_pixels.begin();
  tree_pixels.setBrightness(128);
}

void loop() {
  // say hi
  Serial.println("Hello!");

  // set color to red
  Serial.println("Onboard red");
  onboard_pixels.fill(0xFF0000);
  onboard_pixels.show();
  delay(500); // wait half a second

  // turn off
  Serial.println("Onboard off");
  onboard_pixels.fill(0x000000);
  onboard_pixels.show();
  delay(500); // wait half a second
              //
  // set color to red
  Serial.println("Tree red");
  tree_pixels.fill(0xFF0000);
  tree_pixels.show();
  delay(500); // wait half a second

  // turn off
  Serial.println("Tree off");
  tree_pixels.fill(0x000000);
  tree_pixels.show();
  delay(500); // wait half a second

  Serial.println("Tree individual");
  for(int i=0; i<tree_pixels.numPixels(); i++) {
    tree_pixels.setPixelColor(i, 0xFF0000);
    tree_pixels.show();
    delay(100);
  }

  Serial.println("Tree off");
  tree_pixels.fill(0x000000);
  tree_pixels.show();
}
