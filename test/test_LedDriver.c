#include "unity.h"

#include "LedDriver.h"
static uint16_t virtualLeds = 0xFF; 

void setUp(void)
{
	init_Led(&virtualLeds);
}

void tearDown(void)
{
}

void test_InitLed(void)
{
	TEST_ASSERT_EQUAL_HEX8(0, virtualLeds);
}

void test_TurnOn1(void)
{
	led_TurnOn(1);
	TEST_ASSERT_EQUAL_HEX8(1, virtualLeds);	
}

void test_TurnOff1(void)
{
	led_TurnOff(1);
	TEST_ASSERT_EQUAL_HEX8(0, virtualLeds);
}

void test_TurnOnMultiple(void)
{
	led_TurnOn(1);
	led_TurnOn(2);
	TEST_ASSERT_EQUAL_HEX8(0x03, virtualLeds);
	init_Led(&virtualLeds);
	led_TurnOn(7);
	led_TurnOn(6);
	TEST_ASSERT_EQUAL(0b0000000001100000, virtualLeds);
}

void test_TurnOnAlreadyOn(void)
{
	led_TurnOn(1);
	TEST_ASSERT_EQUAL_HEX8(0x01, virtualLeds);
	led_TurnOn(1);
	TEST_ASSERT_EQUAL_HEX8(0x01, virtualLeds);
}
