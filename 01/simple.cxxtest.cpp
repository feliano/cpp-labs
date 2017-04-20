#include <cxxtest/TestSuite.h>

#include "count_if_followed_by.h"


class MyTestSuite : public CxxTest::TestSuite {
  public:
    void test1 () {
      char const  data[6] = {'G','G','X','G','X','G'};
      int  const test_len = 4;

      int  const   result = count_if_followed_by (data, test_len, 'X', 'G');

      // SYNOPSIS:
      //   result should be 1 since the length specified is 4,
      //   and only one pair of [X, G] is present in that range!

      TS_ASSERT_EQUALS(result, 1);
    }

    void test2() {

      char const data[6] = {'G','G','X','G','X','G'};
      int const test_len = 0;

      int const result = count_if_followed_by(data,test_len,'G','X');

      // SYNOPSIS:
      //   result should be 0 since the length specified is 0,
      
      TS_ASSERT_EQUALS(result,0);
    }

    void test3() {

      char const data[0] = {};
      int const test_len = 10;

      int const result = count_if_followed_by(data,test_len,'G','X');

      // SYNOPSIS:
      //   result should be 0 since the data is empty

      TS_ASSERT_EQUALS(result,0);
    }

    void test4() {
      char const data[5] = {'G','G','G','X','X'};
      int const test_len = 5;

      int const result = count_if_followed_by(data,test_len,'G','G');

      // Synopsis:
      // result should be 2 since the 3 adjacent G's will produce
      // two pairs

      TS_ASSERT_EQUALS(result,2);
    }

    void test5() {
        char const data[5] = {'G','G','G','X','X'};
        int const test_len = 2;

        int const result = count_if_followed_by(data,test_len,'G','G');

        // Synopsis:
        // result should be 1 since the adjacent G's will produce
        // 1 pair in the range 2

        TS_ASSERT_EQUALS(result,1);
    }

};

