/*
list: 双向链表

forward_list: 单向链表
*/
#include "../common.h"
#include <list>
#include <algorithm>

using namespace std;
class test_list
{
private:
    /* data */
public:
    test_list(/* args */);
    ~test_list();
};

test_list::test_list(/* args */)
{
    ilog("test list in");
    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    for(auto i : l){
        cout << " " << i;
    }
    cout << endl;
    l.push_front(-1);
    l.push_front(-2);
    l.pop_back();
    for(auto i : l){
        cout << " " << i;
    }
    cout << endl;

    std::list<int> l2={5,6,9,8,4,1,2,5,4,8,7,9};
    //l2.sort([](const int& a1, const int& a2){return(a1 > a2);});
    //l2.sort(std::greater<int>());
    //l2.sort(std::less<int>());
    //l2.reverse();
    //l2.remove(8);
    l2.remove_if([](const int& x){return (x%3)==0;});
    cout << "l2:";
    for(auto n : l2){
        cout << " " << n;
    }
    cout<<endl;

    std::list<int> l3={5,6,9,8,4,1,2,5,4,8,7,9};
    std::list<int>::iterator it1=l3.begin();
    std::list<int>::iterator it2=l3.begin();
    for(int i=0; i<4; i++){
        it2++;
    }
    std::list<int> l3_1(it1, it2);
    l3_1.front()=99;
    l3_1.back()=88;
    print(l3_1);
    //*it1=88;
    it1=it2;
    for(int i=0; i<4; i++){
        it2++;
    }
    std::list<int> l3_2(it1, it2);
    print(l3_2);
    it1=it2;
    for(int i=0; i<4; i++){
        it2++;
    }
    std::list<int> l3_3(it1, it2);
    print(l3_3);
    print(l3);
}

test_list::~test_list()
{
}
