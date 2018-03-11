#include "led.h"
#include "SPI.h"

void sendInitFrame(void) {
	SPI.transfer(0x00);
	SPI.transfer(0x00);
	SPI.transfer(0x00);
	SPI.transfer(0x00);
}

void sendColor(uint8_t r, uint8_t g, uint8_t b) {
	SPI.transfer(0xE1);
	SPI.transfer(b);
	SPI.transfer(g);
	SPI.transfer(r);
}

void sendEndFrame(void) {
	SPI.transfer(0xFF);
	SPI.transfer(0xFF);
	SPI.transfer(0xFF);
	SPI.transfer(0xFF);
}

void sendPattern(uint8_t r[], uint8_t g[], uint8_t b[], int size) {
	int index;
	sendInitFrame();
	for (index = 0; index < size; index++) {
		sendColor(r[index], g[index], b[index]);
	}
	sendEndFrame();
}
