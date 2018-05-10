#include <SPI.h>
#include "led.h"

#define LED_NB 3

uint8_t r[LED_NB] = {0};
uint8_t g[LED_NB] = {0};
uint8_t b[LED_NB] = {0};
int val = 0;
int sign = 0;

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

  if ((sign % 2) == 0) {
    r[0] = 0x00;
    g[0] = 0x00;
    b[0] = 0xEE;
  } else {
    r[0] = 0x0;
    g[0] = 0x0;
    b[0] = 0x0;
  }

  if ((sign % 5) == 0) {
    g[1] = 0xFF;
    g[2] = 0xFF;
    r[1] = 0xFF;
    r[2] = 0xFF;
    b[1] = 0xFF;
    b[2] = 0xFF;
 } else {
    g[1] = 0x77;
    g[2] = 0x77;
    r[1] = 0xFF;
    r[2] = 0xFF;
    b[1] = 0x00;
    b[2] = 0x00;
 }

  sign++;
  sendPattern(r, g, b, LED_NB);
}
