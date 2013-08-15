#include <stdio.h>
#include <stdbool.h>
#include "DDObjects.h"
#include "class.h"

static int gTestCount = 0;
static int gTestSuccessCount = 0;

static void TestIsTrue(bool isTrue, const char* failureMessage);
static void TestIsFalse(bool isFalse, const char* failureMessage);
static void TestNotNull(void const* p, const char* failureMessage);

static void run_tests(void);
static void run_class_tests(void);

int main(int argc, char** argv) {
	run_tests();

	printf("%d of %d unit tests succeeded.\n", gTestSuccessCount, gTestCount);

	return gTestSuccessCount == gTestCount ? 0 : 1;
}

static void TestIsTrue(bool isTrue, const char* failureMessage) {
	gTestCount++;

	if ( isTrue ) {
		gTestSuccessCount++;
	} else {
		fprintf(stdout, "Test %d FAILED. %s\n", gTestCount, failureMessage);
	}
}

static void TestIsFalse(bool isFalse, const char* failureMessage) {
    return TestIsTrue(!isFalse, failureMessage);
}

static void TestNotNull(void const* p, const char* failureMessage) {
    TestIsTrue(p != NULL, failureMessage);
}

static void run_tests(void) {
    run_class_tests();
}


static void run_class_tests(void) {
    dd_class rootClass = dd_new_class(NULL);
    TestNotNull(rootClass, "Couldn't create root class");
    dd_class derived1 = dd_new_class(rootClass);
    TestNotNull(derived1, "Couldn't create derived1");
    TestIsTrue(dd_is_kind_of(derived1, rootClass), "derived not kind of root");
    dd_class derived2 = dd_new_class(rootClass);
    TestIsFalse(dd_is_kind_of(derived1, derived2), "derived1 should not be kind of derived2");
}

