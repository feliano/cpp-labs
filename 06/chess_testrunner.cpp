/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MyTestSuite_init = false;
#include "chess.cxxtest.cpp"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "chess.cxxtest.cpp", 8, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_test1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 10, "test1" ) {}
 void runTest() { suite_MyTestSuite.test1(); }
} testDescription_suite_MyTestSuite_test1;

static class TestDescription_suite_MyTestSuite_test2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test2() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 108, "test2" ) {}
 void runTest() { suite_MyTestSuite.test2(); }
} testDescription_suite_MyTestSuite_test2;

static class TestDescription_suite_MyTestSuite_test3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test3() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 188, "test3" ) {}
 void runTest() { suite_MyTestSuite.test3(); }
} testDescription_suite_MyTestSuite_test3;

static class TestDescription_suite_MyTestSuite_test4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test4() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 268, "test4" ) {}
 void runTest() { suite_MyTestSuite.test4(); }
} testDescription_suite_MyTestSuite_test4;

static class TestDescription_suite_MyTestSuite_test5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test5() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 350, "test5" ) {}
 void runTest() { suite_MyTestSuite.test5(); }
} testDescription_suite_MyTestSuite_test5;

static class TestDescription_suite_MyTestSuite_test6 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test6() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 429, "test6" ) {}
 void runTest() { suite_MyTestSuite.test6(); }
} testDescription_suite_MyTestSuite_test6;

static class TestDescription_suite_MyTestSuite_test7 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test7() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 508, "test7" ) {}
 void runTest() { suite_MyTestSuite.test7(); }
} testDescription_suite_MyTestSuite_test7;

static class TestDescription_suite_MyTestSuite_test8 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test8() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 587, "test8" ) {}
 void runTest() { suite_MyTestSuite.test8(); }
} testDescription_suite_MyTestSuite_test8;

static class TestDescription_suite_MyTestSuite_test9 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test9() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 665, "test9" ) {}
 void runTest() { suite_MyTestSuite.test9(); }
} testDescription_suite_MyTestSuite_test9;

static class TestDescription_suite_MyTestSuite_test10 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test10() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 740, "test10" ) {}
 void runTest() { suite_MyTestSuite.test10(); }
} testDescription_suite_MyTestSuite_test10;

static class TestDescription_suite_MyTestSuite_test11 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test11() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 819, "test11" ) {}
 void runTest() { suite_MyTestSuite.test11(); }
} testDescription_suite_MyTestSuite_test11;

static class TestDescription_suite_MyTestSuite_test12 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test12() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 898, "test12" ) {}
 void runTest() { suite_MyTestSuite.test12(); }
} testDescription_suite_MyTestSuite_test12;

static class TestDescription_suite_MyTestSuite_test13 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test13() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 976, "test13" ) {}
 void runTest() { suite_MyTestSuite.test13(); }
} testDescription_suite_MyTestSuite_test13;

static class TestDescription_suite_MyTestSuite_test14 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test14() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 1054, "test14" ) {}
 void runTest() { suite_MyTestSuite.test14(); }
} testDescription_suite_MyTestSuite_test14;

static class TestDescription_suite_MyTestSuite_test15 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test15() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 1132, "test15" ) {}
 void runTest() { suite_MyTestSuite.test15(); }
} testDescription_suite_MyTestSuite_test15;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
