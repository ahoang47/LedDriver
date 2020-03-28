#ifndef LEDDRIVER_H
#define LEDDRIVER_H
#include <stdint.h>
void init_Led(uint16_t * address);
void led_TurnOn(int ledNumber);
void led_TurnOff(int ledNumber);
#endif // LEDDRIVER_H
