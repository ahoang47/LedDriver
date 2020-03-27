#include "unity.h"

#include "LedDriver.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_InitLed(void)
{
	uint16_t virtualLeds = 0xFF;
	init_Led(&virtualLeds);
	TEST_ASSERT_EQUAL_HEX8(0, virtualLeds);
}
