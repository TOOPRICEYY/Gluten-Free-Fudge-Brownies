// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"

using namespace std;

// Add your test cases here

TEST(ittergarb) {
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
    
    ASSERT_TRUE(*iter==1);
    my_list.pop_back();
    
    --iter;
    ++iter;
    ++iter;
    ASSERT_TRUE(*iter==2);
    
    int i = 3; while(i-->0)my_list.pop_back();
    List<int> list3(my_list);
    ASSERT_TRUE(list3.empty());
    i = 12; while(i-->0)my_list.push_front(0);
    i = 12; while(i-->0)my_list.pop_front();
    List<int> list4(my_list);
    ASSERT_TRUE(list4.empty());
    list4.clear();
    list3.clear();
    list2.clear();
    my_list.clear();
    list5.clear();


}
TEST(ittershit) {
    // Add test code here
    List<int> my_list;
    ASSERT_TRUE(my_list.size()==0);

    my_list.push_back(4);
    my_list.push_front(6);
    my_list.push_back(7);
    my_list.push_front(3);
    
    List<int> list5(my_list);
    ASSERT_TRUE(!list5.empty());
    
    List<int>::Iterator iter = my_list.begin();
    List<int>::Iterator iter2 = my_list.begin();
    --++iter;
    ASSERT_TRUE(*iter==3);
    my_list.pop_back();
    ++iter;
    ++iter;
    ASSERT_TRUE(iter!=iter2);
    ++iter2;
    ASSERT_TRUE(*iter==4);
    --iter;
    ASSERT_TRUE(iter==iter2);
    ++iter2;
    my_list.erase(iter);
    my_list.erase(iter2);
    my_list.erase(my_list.begin());

    List<int> list3(my_list);
    ASSERT_TRUE(list3.empty()&&my_list.empty()&&list3.size()==0);
    int i = 4; while(i-->0)my_list.push_front(i);
    i = 3; 
    while(i-->0){
        my_list.pop_front(); 
        ASSERT_TRUE(my_list.size()==i+1); 
        ASSERT_EQUAL(my_list.front(),3-i);
    }
    ASSERT_TRUE(list3.empty());
    list3.clear();
    my_list.clear();
    ASSERT_TRUE(my_list.size()==0);
    ASSERT_TRUE(list5.size()!=0);
    list5.clear();

}

TEST(ittershit2) {
    List<float> l1;
    l1.push_back(1.2);
    l1.push_front(1.4);
    l1.push_front(1.9);
    l1.push_front(1.6);
    l1.pop_front();


    List<float> l2(l1);

    List<float>::Iterator  i1 = l1.begin();
    List<float>::Iterator  i2 = l2.begin();
    List<float>::Iterator  i3 = l1.end();

    ASSERT_TRUE(++++i1!=i3);
    --i1;
    --++i2;
    ASSERT_TRUE(--i1!=i2);
    ASSERT_TRUE(*i1==*i2);

    l1.empty();
    l2.pop_front();
    l2.pop_front();
    ASSERT_TRUE(l2.size()==1&&!l2.empty())
    l2.pop_front();
    ASSERT_TRUE(l2.size()==0&&l2.empty());




}

// pretty sure there's something wrong with copyall
// noticed that test ittergarb only checks if copied
// list is empty, but doesn't check if the element's
// prev and next variables are right. also doesnt check
// if the first and last are correct
// i try to do that in the test below w/ list 2

TEST(dontlookatthis) { 
    List<int> l1;
    l1.push_back(2);
    l1.push_front(1);
    
    List<int>::Iterator wow = l1.begin();
    --++wow;
    ASSERT_TRUE(*wow==1);
    ASSERT_TRUE(*wow!=2);
    ASSERT_EQUAL(l1.back(), 2);
    ++wow;
    ASSERT_EQUAL(*wow, l1.back());
    
    List<int> l2;
    l2 = l1;
    List<int>::Iterator pop(l2.begin());
    l2.insert(pop,3);
    List<int>::Iterator pop2(l2.begin());
    ASSERT_EQUAL(*pop2, 3);
    ASSERT_EQUAL(*pop,1);
    ++pop;
    ASSERT_EQUAL(*pop,2);
    l2.erase(pop);

    List<int> l3(l2);
    List<int>::Iterator crack;
    crack = l3.begin();
    ASSERT_EQUAL(*crack, 3);
    l3.pop_back();
    l3.pop_front();
    ASSERT_TRUE(l3.empty());
    l1.clear();
    l2.clear();


}
// need test case where you insert() at end,begin,mid
// need test case where you erase() at end,begin,mid


TEST_MAIN()

