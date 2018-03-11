#ifndef LED_H
#define LED_H

#include <stdint.h>

void sendInitFrame(void);
void sendColor(uint8_t r, uint8_t g, uint8_t b);
void sendEndFrame(void);
void sendPattern(uint8_t r[], uint8_t g[], uint8_t b[], int size);
#endif
