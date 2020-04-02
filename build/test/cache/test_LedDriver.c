#include "build/temp/_test_LedDriver.c"
#include "src/LedDriver.h"
#include "src/RuntimeErrorStub.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"
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

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0)), (UNITY_INT)(UNITY_INT8 )((virtualLeds)), (

((void *)0)

), (UNITY_UINT)(17), UNITY_DISPLAY_STYLE_HEX8);

}



void test_TurnOn1(void)

{

 led_TurnOn(1);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((1)), (UNITY_INT)(UNITY_INT8 )((virtualLeds)), (

((void *)0)

), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_HEX8);

}



void test_TurnOff1(void)

{

 led_TurnOff(1);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0)), (UNITY_INT)(UNITY_INT8 )((virtualLeds)), (

((void *)0)

), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_HEX8);

}



void test_TurnOnMultiple(void)

{

 led_TurnOn(1);

 led_TurnOn(2);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x03)), (UNITY_INT)(UNITY_INT8 )((virtualLeds)), (

((void *)0)

), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_HEX8);

 init_Led(&virtualLeds);

 led_TurnOn(7);

 led_TurnOn(6);

 UnityAssertEqualNumber((UNITY_INT)((0b0000000001100000)), (UNITY_INT)((virtualLeds)), (

((void *)0)

), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_INT);

}



void test_TurnOnAlreadyOn(void)

{

 led_TurnOn(1);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x01)), (UNITY_INT)(UNITY_INT8 )((virtualLeds)), (

((void *)0)

), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_HEX8);

 led_TurnOn(1);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x01)), (UNITY_INT)(UNITY_INT8 )((virtualLeds)), (

((void *)0)

), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_HEX8);

}



void test_TurnOffMultiple(void)

{

 led_TurnOn(1);

 led_TurnOn(2);

 led_TurnOff(1);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x02)), (UNITY_INT)(UNITY_INT8 )((virtualLeds)), (

((void *)0)

), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_HEX8);

}



void test_TurnOffAlreadyOff(void)

{

 led_TurnOn(1);

 led_TurnOff(1);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x00)), (UNITY_INT)(UNITY_INT8 )((virtualLeds)), (

((void *)0)

), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_HEX8);

 led_TurnOff(1);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x00)), (UNITY_INT)(UNITY_INT8 )((virtualLeds)), (

((void *)0)

), (UNITY_UINT)(65), UNITY_DISPLAY_STYLE_HEX8);

}



void test_TurnAllOn(void)

{

 led_TurnAllOn();

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xffff)), (UNITY_INT)(UNITY_INT16)((virtualLeds)), (

((void *)0)

), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_HEX16);

}



void test_LedMemory(void)

{

 virtualLeds = 0xffff;

 led_TurnOn(8);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x80)), (UNITY_INT)(UNITY_INT16)((virtualLeds)), (

((void *)0)

), (UNITY_UINT)(78), UNITY_DISPLAY_STYLE_HEX16);

}



void test_Boundaries(void)

{

 led_TurnOn(1);

 led_TurnOn(16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x8001)), (UNITY_INT)(UNITY_INT16)((virtualLeds)), (

((void *)0)

), (UNITY_UINT)(85), UNITY_DISPLAY_STYLE_HEX16);

}



void test_TurnOnOutOfBounds(void)

{

 led_TurnOn(17);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((virtualLeds)), (

((void *)0)

), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_HEX16);

 led_TurnOn(33);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((virtualLeds)), (

((void *)0)

), (UNITY_UINT)(93), UNITY_DISPLAY_STYLE_HEX16);

 led_TurnOn(100000);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((virtualLeds)), (

((void *)0)

), (UNITY_UINT)(95), UNITY_DISPLAY_STYLE_HEX16);

}



void test_TurnOffOutOfBounds(void)

{

 led_TurnAllOn();

 led_TurnOff(17);

 led_TurnOff(33);

 led_TurnOff(100000);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((virtualLeds)), (

((void *)0)

), (UNITY_UINT)(104), UNITY_DISPLAY_STYLE_HEX16);

}





void test_OOB(void)

{

 UnityIgnore( (("What should we do at runtime oob?")), (UNITY_UINT)(110));

}



void test_OOBProduceRTError(void)

{

 led_TurnOn(-1);

 UnityAssertEqualString((const char*)(("LED Driver: out-of-bounds LED")), (const char*)((RuntimeErrorStub_GetLastError())), (

((void *)0)

), (UNITY_UINT)(116));

 UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((RuntimeErrorStub_GetLastParameter())), (

((void *)0)

), (UNITY_UINT)(117), UNITY_DISPLAY_STYLE_INT);

}
