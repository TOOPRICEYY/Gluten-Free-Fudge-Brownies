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
    --iter;
    my_list.pop_front();
    ASSERT_TRUE(*iter==1);

    
    int i = 2; while(i-->0)my_list.pop_back();
    List<int> list3(my_list);
    ASSERT_TRUE(list3.empty());
    i = 4; while(i-->0)my_list.push_front(i);
    i = 3; 
    while(i-->0){
        my_list.pop_front(); 
        ASSERT_TRUE(my_list.size()==i+1); 
        ASSERT_EQUAL(my_list.front(),3-i);
    }
    ASSERT_TRUE(list3.empty());
    list3.clear();
    list2.clear();
    my_list.clear();
    list5.clear();


}
/*
TEST(test_ctor) {
    // Add test code here
    List<double> my_list;
    
    my_list.push_back(5.2);
    my_list.push_back(4.3);
    List<double>::Iterator iter = my_list.begin();
    ++iter;
    my_list.push_front(6.8);
    my_list.push_front(1.2);
    my_list.pop_front();
    my_list.pop_back();
    my_list.print();
    
    //cout << "1: "<<*iter <<endl;

    List<double> list2(my_list);
    list2.print();
    List<double>::Iterator iter2 = list2.begin();
    ASSERT_TRUE(!list2.empty());


    //ASSERT_FALSE(iter == iter2);
    cout << "1: "<<*iter << " 2 : "<<*iter2<<endl; 
    cout << "1: "<<iter.get() << " 2 : "<<iter2.get()<<endl; 

    my_list.clear();
    list2.clear();    
}
*/
TEST_MAIN()

