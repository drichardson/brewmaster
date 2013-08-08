#include <stdio.h>
#include <stdbool.h>
#include "DDObjects.h"

static int gTestCount = 0;
static int gTestSuccessCount = 0;

static void TestIsTrue(bool isTrue, const char* failureMessage);

static void run_tests(void);
static void run_array_tests();

int main(int argc, char** argv)
{
	run_tests();

	printf("%d of %d unit tests succeeded.\n", gTestSuccessCount, gTestCount);

	return gTestSuccessCount == gTestCount;
}

static void TestIsTrue(bool isTrue, const char* failureMessage)
{
	gTestCount++;

	if ( isTrue )
	{
		gTestSuccessCount++;
	}
	else
	{
		printf("Test %d FAILED. %s\n", gTestCount, failureMessage);
	}
}

static void run_tests(void)
{
	run_array_tests();
}

static void run_array_tests()
{
    TestIsTrue(true, "Should work");	
    TestIsTrue(false, "Should fail");	
}
