#pragma once
#include "../common.h"

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
    std::vector<int> v = {11,22,33,44,55};
    std::set<int> s(v.begin(),v.end());
    for(int i=0; i<(int)s.size(); i++){
        //cout<<" "<<s[i]<<endl;
    }
}

test_set::~test_set()
{
}
