#include "LedDriver.h"
#include <stdint.h>
#include "RuntimeErrorStub.h"
#include <stdbool.h>
#define FIRST_LED 1
#define LAST_LED 16

static uint16_t * LedAddress;
static uint16_t ledImage;
static bool isLedOOB(int ledNumber)
{
	if (ledNumber < FIRST_LED || ledNumber > LAST_LED)
	{
		RUNTIME_ERROR("LED Driver: out-of-bounds LED", ledNumber);
		return true;
	}
	else return false;
}

static uint16_t ledIndexToBit(int ledNumber)
{
	return (1 << (ledNumber-1));
}

static void updateHardware(void)
{
	*LedAddress = ledImage;
}

void init_Led(uint16_t *physicalAddress)
{
	LedAddress = physicalAddress;
	ledImage = 0;
	updateHardware();
}

void led_TurnOn(int ledNumber)
{
	if (isLedOOB(ledNumber)) return;
	ledImage |= ledIndexToBit(ledNumber);
	updateHardware();
}

void led_TurnOff(int ledNumber)
{
	if (isLedOOB(ledNumber)) return;
	ledImage &= ~ledIndexToBit(ledNumber);
	updateHardware();
}

void led_TurnAllOn(void)
{
	ledImage = 0xffff;
	updateHardware();
}
