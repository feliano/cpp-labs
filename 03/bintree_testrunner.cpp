/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
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
#include "testtree.cpp"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "testtree.cpp", 8, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_test1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 28, "test1" ) {}
 void runTest() { suite_MyTestSuite.test1(); }
} testDescription_suite_MyTestSuite_test1;

static class TestDescription_suite_MyTestSuite_test2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test2() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 42, "test2" ) {}
 void runTest() { suite_MyTestSuite.test2(); }
} testDescription_suite_MyTestSuite_test2;

static class TestDescription_suite_MyTestSuite_test3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test3() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 59, "test3" ) {}
 void runTest() { suite_MyTestSuite.test3(); }
} testDescription_suite_MyTestSuite_test3;

static class TestDescription_suite_MyTestSuite_test4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test4() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 77, "test4" ) {}
 void runTest() { suite_MyTestSuite.test4(); }
} testDescription_suite_MyTestSuite_test4;

static class TestDescription_suite_MyTestSuite_test5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test5() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 95, "test5" ) {}
 void runTest() { suite_MyTestSuite.test5(); }
} testDescription_suite_MyTestSuite_test5;

static class TestDescription_suite_MyTestSuite_test6 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test6() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 108, "test6" ) {}
 void runTest() { suite_MyTestSuite.test6(); }
} testDescription_suite_MyTestSuite_test6;

static class TestDescription_suite_MyTestSuite_test7 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test7() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 124, "test7" ) {}
 void runTest() { suite_MyTestSuite.test7(); }
} testDescription_suite_MyTestSuite_test7;

static class TestDescription_suite_MyTestSuite_test8 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test8() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 140, "test8" ) {}
 void runTest() { suite_MyTestSuite.test8(); }
} testDescription_suite_MyTestSuite_test8;

static class TestDescription_suite_MyTestSuite_test9 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test9() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 155, "test9" ) {}
 void runTest() { suite_MyTestSuite.test9(); }
} testDescription_suite_MyTestSuite_test9;

static class TestDescription_suite_MyTestSuite_test10 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test10() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 170, "test10" ) {}
 void runTest() { suite_MyTestSuite.test10(); }
} testDescription_suite_MyTestSuite_test10;

static class TestDescription_suite_MyTestSuite_test11 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test11() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 194, "test11" ) {}
 void runTest() { suite_MyTestSuite.test11(); }
} testDescription_suite_MyTestSuite_test11;

static class TestDescription_suite_MyTestSuite_test12 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test12() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 212, "test12" ) {}
 void runTest() { suite_MyTestSuite.test12(); }
} testDescription_suite_MyTestSuite_test12;

static class TestDescription_suite_MyTestSuite_test13 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test13() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 229, "test13" ) {}
 void runTest() { suite_MyTestSuite.test13(); }
} testDescription_suite_MyTestSuite_test13;

static class TestDescription_suite_MyTestSuite_test14 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test14() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 245, "test14" ) {}
 void runTest() { suite_MyTestSuite.test14(); }
} testDescription_suite_MyTestSuite_test14;

static class TestDescription_suite_MyTestSuite_test15 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test15() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 264, "test15" ) {}
 void runTest() { suite_MyTestSuite.test15(); }
} testDescription_suite_MyTestSuite_test15;

static class TestDescription_suite_MyTestSuite_test16 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test16() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 279, "test16" ) {}
 void runTest() { suite_MyTestSuite.test16(); }
} testDescription_suite_MyTestSuite_test16;

static class TestDescription_suite_MyTestSuite_test17 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test17() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 295, "test17" ) {}
 void runTest() { suite_MyTestSuite.test17(); }
} testDescription_suite_MyTestSuite_test17;

static class TestDescription_suite_MyTestSuite_test18 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test18() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 311, "test18" ) {}
 void runTest() { suite_MyTestSuite.test18(); }
} testDescription_suite_MyTestSuite_test18;

static class TestDescription_suite_MyTestSuite_test19 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test19() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 327, "test19" ) {}
 void runTest() { suite_MyTestSuite.test19(); }
} testDescription_suite_MyTestSuite_test19;

static class TestDescription_suite_MyTestSuite_test20 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test20() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 340, "test20" ) {}
 void runTest() { suite_MyTestSuite.test20(); }
} testDescription_suite_MyTestSuite_test20;

static class TestDescription_suite_MyTestSuite_test21 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test21() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 357, "test21" ) {}
 void runTest() { suite_MyTestSuite.test21(); }
} testDescription_suite_MyTestSuite_test21;

static class TestDescription_suite_MyTestSuite_test22 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test22() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 388, "test22" ) {}
 void runTest() { suite_MyTestSuite.test22(); }
} testDescription_suite_MyTestSuite_test22;

static class TestDescription_suite_MyTestSuite_test23 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test23() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 414, "test23" ) {}
 void runTest() { suite_MyTestSuite.test23(); }
} testDescription_suite_MyTestSuite_test23;

static class TestDescription_suite_MyTestSuite_test24 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test24() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 439, "test24" ) {}
 void runTest() { suite_MyTestSuite.test24(); }
} testDescription_suite_MyTestSuite_test24;

static class TestDescription_suite_MyTestSuite_test25 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test25() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 465, "test25" ) {}
 void runTest() { suite_MyTestSuite.test25(); }
} testDescription_suite_MyTestSuite_test25;

static class TestDescription_suite_MyTestSuite_test26 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test26() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 489, "test26" ) {}
 void runTest() { suite_MyTestSuite.test26(); }
} testDescription_suite_MyTestSuite_test26;

static class TestDescription_suite_MyTestSuite_test27 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test27() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 512, "test27" ) {}
 void runTest() { suite_MyTestSuite.test27(); }
} testDescription_suite_MyTestSuite_test27;

static class TestDescription_suite_MyTestSuite_test28 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test28() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 536, "test28" ) {}
 void runTest() { suite_MyTestSuite.test28(); }
} testDescription_suite_MyTestSuite_test28;

static class TestDescription_suite_MyTestSuite_test29 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test29() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 561, "test29" ) {}
 void runTest() { suite_MyTestSuite.test29(); }
} testDescription_suite_MyTestSuite_test29;

static class TestDescription_suite_MyTestSuite_test30 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test30() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 589, "test30" ) {}
 void runTest() { suite_MyTestSuite.test30(); }
} testDescription_suite_MyTestSuite_test30;

static class TestDescription_suite_MyTestSuite_test31 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test31() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 629, "test31" ) {}
 void runTest() { suite_MyTestSuite.test31(); }
} testDescription_suite_MyTestSuite_test31;

static class TestDescription_suite_MyTestSuite_test32 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test32() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 656, "test32" ) {}
 void runTest() { suite_MyTestSuite.test32(); }
} testDescription_suite_MyTestSuite_test32;

static class TestDescription_suite_MyTestSuite_test33 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test33() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 684, "test33" ) {}
 void runTest() { suite_MyTestSuite.test33(); }
} testDescription_suite_MyTestSuite_test33;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
