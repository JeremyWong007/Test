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
}

test_list::~test_list()
{
}
