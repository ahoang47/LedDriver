#include "unity.h"
#include "RuntimeErrorStub.h"
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

void test_TurnOffMultiple(void)
{
	led_TurnOn(1);
	led_TurnOn(2);
	led_TurnOff(1);
	TEST_ASSERT_EQUAL_HEX8(0x02, virtualLeds);
}

void test_TurnOffAlreadyOff(void)
{
	led_TurnOn(1);
	led_TurnOff(1);
	TEST_ASSERT_EQUAL_HEX8(0x00, virtualLeds);
	led_TurnOff(1);
	TEST_ASSERT_EQUAL_HEX8(0x00, virtualLeds);
}

void test_TurnAllOn(void)
{
	led_TurnAllOn();
	TEST_ASSERT_EQUAL_HEX16(0xffff, virtualLeds);
}

void test_LedMemory(void)
{
	virtualLeds = 0xffff;
	led_TurnOn(8);
	TEST_ASSERT_EQUAL_HEX16(0x80, virtualLeds);
}

void test_Boundaries(void)
{
	led_TurnOn(1);
	led_TurnOn(16);
	TEST_ASSERT_EQUAL_HEX16(0x8001, virtualLeds);
}

void test_TurnOnOutOfBounds(void)
{
	led_TurnOn(17);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
	led_TurnOn(33);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
	led_TurnOn(100000);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

void test_TurnOffOutOfBounds(void)
{
	led_TurnAllOn();
	led_TurnOff(17);
	led_TurnOff(33);
	led_TurnOff(100000);
	TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLeds);
}

void test_OOBProduceRTError(void)
{
	led_TurnOn(-1);
	TEST_ASSERT_EQUAL_STRING("LED Driver: out-of-bounds LED", RuntimeErrorStub_GetLastError());
	TEST_ASSERT_EQUAL(-1, RuntimeErrorStub_GetLastParameter());
}

void test_IsLedOn(void)
{
	TEST_ASSERT_FALSE(led_IsOn(11));
	led_TurnOn(11);
	TEST_ASSERT_TRUE(led_IsOn(11));
	led_TurnOff(11);
	TEST_ASSERT_FALSE(led_IsOn(11));
}

void test_IsLedOff(void)
{
	TEST_ASSERT_TRUE(led_IsOff(11));
	led_TurnOn(11);
	TEST_ASSERT_FALSE(led_IsOff(11));
	led_TurnOff(11);
	TEST_ASSERT_TRUE(led_IsOff(11));
}

void test_OOBAlwaysOff(void)
{
	TEST_ASSERT_FALSE(led_IsOn(17));
	TEST_ASSERT_FALSE(led_IsOn(0));
	TEST_ASSERT_TRUE(led_IsOff(0));
	TEST_ASSERT_TRUE(led_IsOff(17));
}

