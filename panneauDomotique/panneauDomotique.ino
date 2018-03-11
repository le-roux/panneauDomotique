#include <SPI.h>
#include "led.h"

#define LED_NB 2

uint8_t r[LED_NB] = {0};
uint8_t g[LED_NB] = {0};
uint8_t b[LED_NB] = {0};
int val = 0;
int sign = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0));

  sendInitFrame();
  sendColor(0, 0, 0);
  sendColor(0, 0, 0);
  sendEndFrame();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(200);

    r[sign] = 0xFF;
    g[sign] = 0;
    r[1 - sign] = 0;
    g[1 - sign] = 0xFF;

  sign = 1 - sign;
  sendPattern(r, g, b, LED_NB);

}
