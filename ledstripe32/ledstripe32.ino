#include <Adafruit_NeoPixel.h>

#define PIN 13 //
#define NUMPIXELS 32

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int redColor = 0;
int greenColor = 0;
int blueColor = 0;
int delayvar = 50;

void setup(){
    Serial.begin(9600);
    pixels.begin();
}

void loop(){

    monster();
}
void setColor(){
    redColor = random(0, 255);
    greenColor = random(0,255);
    blueColor = random(0, 255);
}

void monster(){
    setColor();

  for (int i=0; i < NUMPIXELS; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    Serial.println(analogRead(A5));
    delayvar = map(analogRead(A5), 0, 1023, 25, 200);
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));

    // This sends the updated pixel color to the hardware.
    pixels.show();

    // Delay for a period of time (in milliseconds).
    delay(delayvar);
    }
}