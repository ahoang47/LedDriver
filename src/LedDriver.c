#include "LedDriver.h"
#include <stdint.h>

static uint16_t * LedAddress;

void init_Led(uint16_t *physicalAddress)
{
	LedAddress = physicalAddress;
	*LedAddress = 0;
}

void led_TurnOn(int ledNumber)
{
	*LedAddress |= (1 << (ledNumber-1));
}

void led_TurnOff(int ledNumber)
{
	*LedAddress &= ~(1 << (ledNumber-1));
}
