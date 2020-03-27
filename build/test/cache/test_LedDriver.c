#include "build/temp/_test_LedDriver.c"
#include "src/LedDriver.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"




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

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0)), (UNITY_INT)(UNITY_INT8 )((virtualLeds)), (

((void *)0)

), (UNITY_UINT)(17), UNITY_DISPLAY_STYLE_HEX8);

}
