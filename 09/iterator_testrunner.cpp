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
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "testtree.cpp", 7, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_test1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 27, "test1" ) {}
 void runTest() { suite_MyTestSuite.test1(); }
} testDescription_suite_MyTestSuite_test1;

static class TestDescription_suite_MyTestSuite_test2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test2() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 41, "test2" ) {}
 void runTest() { suite_MyTestSuite.test2(); }
} testDescription_suite_MyTestSuite_test2;

static class TestDescription_suite_MyTestSuite_test3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test3() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 58, "test3" ) {}
 void runTest() { suite_MyTestSuite.test3(); }
} testDescription_suite_MyTestSuite_test3;

static class TestDescription_suite_MyTestSuite_test4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test4() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 76, "test4" ) {}
 void runTest() { suite_MyTestSuite.test4(); }
} testDescription_suite_MyTestSuite_test4;

static class TestDescription_suite_MyTestSuite_test5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test5() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 94, "test5" ) {}
 void runTest() { suite_MyTestSuite.test5(); }
} testDescription_suite_MyTestSuite_test5;

static class TestDescription_suite_MyTestSuite_test6 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test6() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 107, "test6" ) {}
 void runTest() { suite_MyTestSuite.test6(); }
} testDescription_suite_MyTestSuite_test6;

static class TestDescription_suite_MyTestSuite_test7 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test7() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 123, "test7" ) {}
 void runTest() { suite_MyTestSuite.test7(); }
} testDescription_suite_MyTestSuite_test7;

static class TestDescription_suite_MyTestSuite_test8 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test8() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 139, "test8" ) {}
 void runTest() { suite_MyTestSuite.test8(); }
} testDescription_suite_MyTestSuite_test8;

static class TestDescription_suite_MyTestSuite_test9 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test9() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 154, "test9" ) {}
 void runTest() { suite_MyTestSuite.test9(); }
} testDescription_suite_MyTestSuite_test9;

static class TestDescription_suite_MyTestSuite_test10 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test10() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 169, "test10" ) {}
 void runTest() { suite_MyTestSuite.test10(); }
} testDescription_suite_MyTestSuite_test10;

static class TestDescription_suite_MyTestSuite_test11 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test11() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 193, "test11" ) {}
 void runTest() { suite_MyTestSuite.test11(); }
} testDescription_suite_MyTestSuite_test11;

static class TestDescription_suite_MyTestSuite_test12 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test12() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 211, "test12" ) {}
 void runTest() { suite_MyTestSuite.test12(); }
} testDescription_suite_MyTestSuite_test12;

static class TestDescription_suite_MyTestSuite_test13 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test13() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 228, "test13" ) {}
 void runTest() { suite_MyTestSuite.test13(); }
} testDescription_suite_MyTestSuite_test13;

static class TestDescription_suite_MyTestSuite_test14 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test14() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 244, "test14" ) {}
 void runTest() { suite_MyTestSuite.test14(); }
} testDescription_suite_MyTestSuite_test14;

static class TestDescription_suite_MyTestSuite_test15 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test15() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 263, "test15" ) {}
 void runTest() { suite_MyTestSuite.test15(); }
} testDescription_suite_MyTestSuite_test15;

static class TestDescription_suite_MyTestSuite_test16 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test16() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 278, "test16" ) {}
 void runTest() { suite_MyTestSuite.test16(); }
} testDescription_suite_MyTestSuite_test16;

static class TestDescription_suite_MyTestSuite_test17 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test17() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 294, "test17" ) {}
 void runTest() { suite_MyTestSuite.test17(); }
} testDescription_suite_MyTestSuite_test17;

static class TestDescription_suite_MyTestSuite_test18 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test18() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 310, "test18" ) {}
 void runTest() { suite_MyTestSuite.test18(); }
} testDescription_suite_MyTestSuite_test18;

static class TestDescription_suite_MyTestSuite_test19 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test19() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 326, "test19" ) {}
 void runTest() { suite_MyTestSuite.test19(); }
} testDescription_suite_MyTestSuite_test19;

static class TestDescription_suite_MyTestSuite_test20 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test20() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 339, "test20" ) {}
 void runTest() { suite_MyTestSuite.test20(); }
} testDescription_suite_MyTestSuite_test20;

static class TestDescription_suite_MyTestSuite_test21 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test21() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 356, "test21" ) {}
 void runTest() { suite_MyTestSuite.test21(); }
} testDescription_suite_MyTestSuite_test21;

static class TestDescription_suite_MyTestSuite_test22 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test22() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 387, "test22" ) {}
 void runTest() { suite_MyTestSuite.test22(); }
} testDescription_suite_MyTestSuite_test22;

static class TestDescription_suite_MyTestSuite_test23 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test23() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 413, "test23" ) {}
 void runTest() { suite_MyTestSuite.test23(); }
} testDescription_suite_MyTestSuite_test23;

static class TestDescription_suite_MyTestSuite_test24 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test24() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 438, "test24" ) {}
 void runTest() { suite_MyTestSuite.test24(); }
} testDescription_suite_MyTestSuite_test24;

static class TestDescription_suite_MyTestSuite_test25 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test25() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 464, "test25" ) {}
 void runTest() { suite_MyTestSuite.test25(); }
} testDescription_suite_MyTestSuite_test25;

static class TestDescription_suite_MyTestSuite_test26 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test26() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 488, "test26" ) {}
 void runTest() { suite_MyTestSuite.test26(); }
} testDescription_suite_MyTestSuite_test26;

static class TestDescription_suite_MyTestSuite_test27 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test27() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 511, "test27" ) {}
 void runTest() { suite_MyTestSuite.test27(); }
} testDescription_suite_MyTestSuite_test27;

static class TestDescription_suite_MyTestSuite_test28 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test28() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 535, "test28" ) {}
 void runTest() { suite_MyTestSuite.test28(); }
} testDescription_suite_MyTestSuite_test28;

static class TestDescription_suite_MyTestSuite_test29 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test29() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 560, "test29" ) {}
 void runTest() { suite_MyTestSuite.test29(); }
} testDescription_suite_MyTestSuite_test29;

static class TestDescription_suite_MyTestSuite_test30 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test30() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 588, "test30" ) {}
 void runTest() { suite_MyTestSuite.test30(); }
} testDescription_suite_MyTestSuite_test30;

static class TestDescription_suite_MyTestSuite_test31 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test31() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 628, "test31" ) {}
 void runTest() { suite_MyTestSuite.test31(); }
} testDescription_suite_MyTestSuite_test31;

static class TestDescription_suite_MyTestSuite_test32 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test32() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 655, "test32" ) {}
 void runTest() { suite_MyTestSuite.test32(); }
} testDescription_suite_MyTestSuite_test32;

static class TestDescription_suite_MyTestSuite_test33 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test33() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 683, "test33" ) {}
 void runTest() { suite_MyTestSuite.test33(); }
} testDescription_suite_MyTestSuite_test33;

static class TestDescription_suite_MyTestSuite_test34 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test34() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 712, "test34" ) {}
 void runTest() { suite_MyTestSuite.test34(); }
} testDescription_suite_MyTestSuite_test34;

static class TestDescription_suite_MyTestSuite_test35 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test35() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 739, "test35" ) {}
 void runTest() { suite_MyTestSuite.test35(); }
} testDescription_suite_MyTestSuite_test35;

static class TestDescription_suite_MyTestSuite_test36 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test36() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 769, "test36" ) {}
 void runTest() { suite_MyTestSuite.test36(); }
} testDescription_suite_MyTestSuite_test36;

static class TestDescription_suite_MyTestSuite_test37 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test37() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 798, "test37" ) {}
 void runTest() { suite_MyTestSuite.test37(); }
} testDescription_suite_MyTestSuite_test37;

static class TestDescription_suite_MyTestSuite_test38 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test38() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 828, "test38" ) {}
 void runTest() { suite_MyTestSuite.test38(); }
} testDescription_suite_MyTestSuite_test38;

static class TestDescription_suite_MyTestSuite_test39 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test39() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 859, "test39" ) {}
 void runTest() { suite_MyTestSuite.test39(); }
} testDescription_suite_MyTestSuite_test39;

static class TestDescription_suite_MyTestSuite_test40 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test40() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 891, "test40" ) {}
 void runTest() { suite_MyTestSuite.test40(); }
} testDescription_suite_MyTestSuite_test40;

static class TestDescription_suite_MyTestSuite_test41 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test41() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 923, "test41" ) {}
 void runTest() { suite_MyTestSuite.test41(); }
} testDescription_suite_MyTestSuite_test41;

static class TestDescription_suite_MyTestSuite_test42 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test42() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 949, "test42" ) {}
 void runTest() { suite_MyTestSuite.test42(); }
} testDescription_suite_MyTestSuite_test42;

static class TestDescription_suite_MyTestSuite_test43 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test43() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 983, "test43" ) {}
 void runTest() { suite_MyTestSuite.test43(); }
} testDescription_suite_MyTestSuite_test43;

static class TestDescription_suite_MyTestSuite_test44 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test44() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 1017, "test44" ) {}
 void runTest() { suite_MyTestSuite.test44(); }
} testDescription_suite_MyTestSuite_test44;

static class TestDescription_suite_MyTestSuite_test45 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test45() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 1052, "test45" ) {}
 void runTest() { suite_MyTestSuite.test45(); }
} testDescription_suite_MyTestSuite_test45;

static class TestDescription_suite_MyTestSuite_test46 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test46() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 1085, "test46" ) {}
 void runTest() { suite_MyTestSuite.test46(); }
} testDescription_suite_MyTestSuite_test46;

static class TestDescription_suite_MyTestSuite_test47 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test47() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 1119, "test47" ) {}
 void runTest() { suite_MyTestSuite.test47(); }
} testDescription_suite_MyTestSuite_test47;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
