// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"

using namespace std;

// Add your test cases here

TEST(test_stub) {
    // Add test code here
    List<int> my_list;
    List<int>::Iterator iter = my_list.begin();
    ++iter;

    ASSERT_TRUE(true);
}

TEST_MAIN()
