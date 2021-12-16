#pragma once
#include "../common.h"

/* set的使用
1 去重
2 自动排序
*/
class test_set
{
private:
    /* data */
public:
    test_set(/* args */);
    ~test_set();
};

test_set::test_set(/* args */)
{
    ilog("test set in");
    //std::vector<int> v = {44,22,55,33,11};
    std::vector<int> v = {44,22,55,44,33,11};
    std::set<int> s(v.begin(),v.end());
    for(std::set<int>::const_iterator it=s.begin(); it!=s.end(); it++){
        cout<<" "<<*it;
    }
    cout<<endl;
    //插入一个元素
    s.insert(23);
    //移除一个元素
    s.erase(10);
    //移除一个元素不在集合中的元素
    //此时什么也不做，n作为返回值将会是0
    //指明没有元素移除
    size_t n=s.erase(98);
    cout<<"n = "<<n<<endl;

    //使用迭代器，找到一个元素
    std::set<int>::const_iterator result=s.find(11);
    if(result == s.end()){
        cout<<"set not find"<<endl;
    }

    std::set<int> other;
    //交换两个集合的内容
    std::swap(s, other);

    //清楚所有的内容
    other.clear();
}

test_set::~test_set()
{
}
