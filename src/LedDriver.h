#ifndef LEDDRIVER_H
#define LEDDRIVER_H
#include <stdint.h>
#include <stdbool.h>
void init_Led(uint16_t * address);
void led_TurnOn(int ledNumber);
void led_TurnOff(int ledNumber);
void led_TurnAllOn(void);
bool led_IsOn(int ledNumber);
bool led_IsOff(int ledNumber);
#endif // LEDDRIVER_H
