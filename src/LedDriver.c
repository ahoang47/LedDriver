#include "LedDriver.h"
#include <stdint.h>

static uint16_t * LedAddress;
static uint16_t ledIndexToBit(int ledNumber)
{
	return (1 << (ledNumber-1));
}
static uint16_t ledImage;

void init_Led(uint16_t *physicalAddress)
{
	LedAddress = physicalAddress;
	ledImage = 0;
	*LedAddress = ledImage;
}

void led_TurnOn(int ledNumber)
{
	if (ledNumber <= 0 || ledNumber > 16) return;
	ledImage |= ledIndexToBit(ledNumber);
	*LedAddress = ledImage;
}

void led_TurnOff(int ledNumber)
{
	if (ledNumber <= 0 || ledNumber > 16) return;
	ledImage &= ~ledIndexToBit(ledNumber);
	*LedAddress = ledImage;
}

void led_TurnAllOn(void)
{
	ledImage = 0xffff;
	*LedAddress = ledImage;
}
