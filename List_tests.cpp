// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"

using namespace std;

// Add your test cases here

TEST(ittershit) {
    // Add test code here
    List<int> my_list;
    List<int> list2(my_list);
    ASSERT_TRUE(list2.empty());

    my_list.push_back(2);
    my_list.push_front(1);
    my_list.push_back(3);
    my_list.push_front(0);

    List<int> list5(my_list);
    ASSERT_TRUE(!list5.empty());

    List<int>::Iterator iter = my_list.begin();
    ++iter;
    ASSERT_TRUE(iter.get()->datum==1);


    int i = 0; while(i-->4)my_list.pop_back();
    List<int> list3(my_list);
    ASSERT_TRUE(list3.empty());
    i = 0; while(i-->4)my_list.push_front(0);
    i = 0; while(i-->4)my_list.pop_front();
    List<int> list4(my_list);
    ASSERT_TRUE(list4.empty());

}

TEST_MAIN()
