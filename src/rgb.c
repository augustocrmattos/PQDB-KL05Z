#include "io.h"

void rgbColor(int led) {
	if (led & 1) {
		digitalWrite(LED_R_PIN, HIGH);
	} else {
		digitalWrite(LED_R_PIN, LOW);
	}
	if (led & 2) {
		digitalWrite(LED_G_PIN, HIGH);
	} else {
		digitalWrite(LED_G_PIN, LOW);
	}
	if (led & 4) {
		digitalWrite(LED_B_PIN, HIGH);
	} else {
		digitalWrite(LED_B_PIN, LOW);
	}
}

void turnOn(int led) {
	if (led & 1) {
		digitalWrite(LED_R_PIN, HIGH);
	}
	if (led & 2) {
		digitalWrite(LED_G_PIN, HIGH);
	}
	if (led & 4) {
		digitalWrite(LED_B_PIN, HIGH);
	}
}

void turnOff(int led) {
	if (led & 1) {
		digitalWrite(LED_R_PIN, LOW);
	}
	if (led & 2) {
		digitalWrite(LED_G_PIN, LOW);
	}
	if (led & 4) {
		digitalWrite(LED_B_PIN, LOW);
	}
}

void rgbInit(void) {
	pinMode(LED_R_PIN, OUTPUT);
	pinMode(LED_G_PIN, OUTPUT);
	pinMode(LED_B_PIN, OUTPUT);
}
