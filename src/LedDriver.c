#include "LedDriver.h"
#include <stdint.h>

static uint16_t * LedAddress;

void init_Led(uint16_t * address)
{
	LedAddress = address;
	*address = 0;
}
