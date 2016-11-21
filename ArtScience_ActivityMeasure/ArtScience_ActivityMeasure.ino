/*Tomas de Camino Beck
www.funcostarica.org

*/
#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>

#define MAX 15000 //maximo de actividad

int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(A9, INPUT);
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (CircuitPlayground.slideSwitch()) {
    count = 0;
    CircuitPlayground.clearPixels();
    CircuitPlayground.redLED(HIGH);
    delay(30000);
    
  } else {
    CircuitPlayground.redLED(LOW);
    count += digitalRead(A9);
    pixelMeter(count, 0, MAX);
  }
}

void pixelMeter(float value, float minimum, float maximum) {
  int p = map(value, minimum, maximum, 0, 9);
  CircuitPlayground.clearPixels();
  for (int i = 0; i <= p; i++) {
    int c = map(i, 0, 9, 0, 255);
    CircuitPlayground.setPixelColor(i, CircuitPlayground.strip.Color(255, 0, 0));
  }
}
