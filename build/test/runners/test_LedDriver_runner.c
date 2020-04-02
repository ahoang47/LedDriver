/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_InitLed(void);
extern void test_TurnOn1(void);
extern void test_TurnOff1(void);
extern void test_TurnOnMultiple(void);
extern void test_TurnOnAlreadyOn(void);
extern void test_TurnOffMultiple(void);
extern void test_TurnOffAlreadyOff(void);
extern void test_TurnAllOn(void);
extern void test_LedMemory(void);
extern void test_Boundaries(void);
extern void test_TurnOnOutOfBounds(void);
extern void test_TurnOffOutOfBounds(void);
extern void test_OOBProduceRTError(void);
extern void test_IsLedOn(void);
extern void test_IsLedOff(void);
extern void test_OOBAlwaysOff(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
}
static void CMock_Verify(void)
{
}
static void CMock_Destroy(void)
{
}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}
/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, int line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {

            setUp();
            func();

    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}


/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_LedDriver.c");
  run_test(test_InitLed, "test_InitLed", 15);
  run_test(test_TurnOn1, "test_TurnOn1", 20);
  run_test(test_TurnOff1, "test_TurnOff1", 26);
  run_test(test_TurnOnMultiple, "test_TurnOnMultiple", 32);
  run_test(test_TurnOnAlreadyOn, "test_TurnOnAlreadyOn", 43);
  run_test(test_TurnOffMultiple, "test_TurnOffMultiple", 51);
  run_test(test_TurnOffAlreadyOff, "test_TurnOffAlreadyOff", 59);
  run_test(test_TurnAllOn, "test_TurnAllOn", 68);
  run_test(test_LedMemory, "test_LedMemory", 74);
  run_test(test_Boundaries, "test_Boundaries", 81);
  run_test(test_TurnOnOutOfBounds, "test_TurnOnOutOfBounds", 88);
  run_test(test_TurnOffOutOfBounds, "test_TurnOffOutOfBounds", 98);
  run_test(test_OOBProduceRTError, "test_OOBProduceRTError", 107);
  run_test(test_IsLedOn, "test_IsLedOn", 114);
  run_test(test_IsLedOff, "test_IsLedOff", 123);
  run_test(test_OOBAlwaysOff, "test_OOBAlwaysOff", 132);

  return UnityEnd();
}
