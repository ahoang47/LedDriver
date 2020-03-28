#include "build/temp/_test_LedDriver.c"
#include "src/LedDriver.h"
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
