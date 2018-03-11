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
  delay(10);
  r[0] = val;
  r[1] = val;
  g[0] = val;
  g[1] = val;
  b[0] = val;
  b[1] = val;
  sendPattern(r, g, b, LED_NB);
  if (sign) {
    val++;
  } else {
    val--;
  }
  if ((val == 0) || (val == 250)) {
    sign = 1 - sign;
  }

}
