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
#include "testmatrix.cpp"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "testmatrix.cpp", 7, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_test1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 10, "test1" ) {}
 void runTest() { suite_MyTestSuite.test1(); }
} testDescription_suite_MyTestSuite_test1;

static class TestDescription_suite_MyTestSuite_test2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test2() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 20, "test2" ) {}
 void runTest() { suite_MyTestSuite.test2(); }
} testDescription_suite_MyTestSuite_test2;

static class TestDescription_suite_MyTestSuite_test3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test3() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 32, "test3" ) {}
 void runTest() { suite_MyTestSuite.test3(); }
} testDescription_suite_MyTestSuite_test3;

static class TestDescription_suite_MyTestSuite_test4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test4() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 44, "test4" ) {}
 void runTest() { suite_MyTestSuite.test4(); }
} testDescription_suite_MyTestSuite_test4;

static class TestDescription_suite_MyTestSuite_test5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test5() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 58, "test5" ) {}
 void runTest() { suite_MyTestSuite.test5(); }
} testDescription_suite_MyTestSuite_test5;

static class TestDescription_suite_MyTestSuite_test6 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test6() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 71, "test6" ) {}
 void runTest() { suite_MyTestSuite.test6(); }
} testDescription_suite_MyTestSuite_test6;

static class TestDescription_suite_MyTestSuite_test7 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test7() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 82, "test7" ) {}
 void runTest() { suite_MyTestSuite.test7(); }
} testDescription_suite_MyTestSuite_test7;

static class TestDescription_suite_MyTestSuite_test8 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test8() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 94, "test8" ) {}
 void runTest() { suite_MyTestSuite.test8(); }
} testDescription_suite_MyTestSuite_test8;

static class TestDescription_suite_MyTestSuite_test9 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test9() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 107, "test9" ) {}
 void runTest() { suite_MyTestSuite.test9(); }
} testDescription_suite_MyTestSuite_test9;

static class TestDescription_suite_MyTestSuite_test10 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test10() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 120, "test10" ) {}
 void runTest() { suite_MyTestSuite.test10(); }
} testDescription_suite_MyTestSuite_test10;

static class TestDescription_suite_MyTestSuite_test11 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test11() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 131, "test11" ) {}
 void runTest() { suite_MyTestSuite.test11(); }
} testDescription_suite_MyTestSuite_test11;

static class TestDescription_suite_MyTestSuite_test12 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test12() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 156, "test12" ) {}
 void runTest() { suite_MyTestSuite.test12(); }
} testDescription_suite_MyTestSuite_test12;

static class TestDescription_suite_MyTestSuite_test13 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test13() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 184, "test13" ) {}
 void runTest() { suite_MyTestSuite.test13(); }
} testDescription_suite_MyTestSuite_test13;

static class TestDescription_suite_MyTestSuite_test14 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test14() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 209, "test14" ) {}
 void runTest() { suite_MyTestSuite.test14(); }
} testDescription_suite_MyTestSuite_test14;

static class TestDescription_suite_MyTestSuite_test15 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test15() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 234, "test15" ) {}
 void runTest() { suite_MyTestSuite.test15(); }
} testDescription_suite_MyTestSuite_test15;

static class TestDescription_suite_MyTestSuite_test16 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test16() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 259, "test16" ) {}
 void runTest() { suite_MyTestSuite.test16(); }
} testDescription_suite_MyTestSuite_test16;

static class TestDescription_suite_MyTestSuite_test17 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test17() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 284, "test17" ) {}
 void runTest() { suite_MyTestSuite.test17(); }
} testDescription_suite_MyTestSuite_test17;

static class TestDescription_suite_MyTestSuite_test18 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test18() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 299, "test18" ) {}
 void runTest() { suite_MyTestSuite.test18(); }
} testDescription_suite_MyTestSuite_test18;

static class TestDescription_suite_MyTestSuite_test19 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test19() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 324, "test19" ) {}
 void runTest() { suite_MyTestSuite.test19(); }
} testDescription_suite_MyTestSuite_test19;

static class TestDescription_suite_MyTestSuite_test20 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test20() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 346, "test20" ) {}
 void runTest() { suite_MyTestSuite.test20(); }
} testDescription_suite_MyTestSuite_test20;

static class TestDescription_suite_MyTestSuite_test21 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test21() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 367, "test21" ) {}
 void runTest() { suite_MyTestSuite.test21(); }
} testDescription_suite_MyTestSuite_test21;

static class TestDescription_suite_MyTestSuite_test22 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test22() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 387, "test22" ) {}
 void runTest() { suite_MyTestSuite.test22(); }
} testDescription_suite_MyTestSuite_test22;

static class TestDescription_suite_MyTestSuite_test23 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test23() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 408, "test23" ) {}
 void runTest() { suite_MyTestSuite.test23(); }
} testDescription_suite_MyTestSuite_test23;

static class TestDescription_suite_MyTestSuite_test24 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test24() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 429, "test24" ) {}
 void runTest() { suite_MyTestSuite.test24(); }
} testDescription_suite_MyTestSuite_test24;

static class TestDescription_suite_MyTestSuite_test25 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test25() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 451, "test25" ) {}
 void runTest() { suite_MyTestSuite.test25(); }
} testDescription_suite_MyTestSuite_test25;

static class TestDescription_suite_MyTestSuite_test26 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test26() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 479, "test26" ) {}
 void runTest() { suite_MyTestSuite.test26(); }
} testDescription_suite_MyTestSuite_test26;

static class TestDescription_suite_MyTestSuite_test27 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test27() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 523, "test27" ) {}
 void runTest() { suite_MyTestSuite.test27(); }
} testDescription_suite_MyTestSuite_test27;

static class TestDescription_suite_MyTestSuite_test28 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test28() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 557, "test28" ) {}
 void runTest() { suite_MyTestSuite.test28(); }
} testDescription_suite_MyTestSuite_test28;

static class TestDescription_suite_MyTestSuite_test29 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test29() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 572, "test29" ) {}
 void runTest() { suite_MyTestSuite.test29(); }
} testDescription_suite_MyTestSuite_test29;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
