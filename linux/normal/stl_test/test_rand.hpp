/*
调用方法：
  初次使用  
    srand(time(0));
    rand();
  再次使用  
    srand(1);
    srand(time(0));
    rand();

重新初始化：可用1作seed值，srand(1)
在任何调用srand之前调用rand与以1作为seed调用srand产生相同的序列
*/
#include "../common.h"
#include "../tools.hpp"

using namespace std;

class test_rand
{
private:
    /* data */
public:
    test_rand(/* args */);
    ~test_rand();

    void test_many_rand(int n){
        srand(1);
        srand(time(0)+1);
        for(int i=0; i<n; i++){
            rand();
        }
    }
};

test_rand::test_rand(/* args */)
{
    ilog("test rand in");
    srand(time(0));
    //srand(1);
    cout<<"rand:"<<rand()<<" "<<rand()<<" "<<rand()<<endl;
    //srand(time(0)+1);
    srand(1);
    srand(time(0)+1);
    cout<<"rand:"<<rand()<<" "<<rand()<<" "<<rand()<<endl;

    auto f = std::bind(&test_rand::test_many_rand, this, 1000000);
    tools::test_runTime<>(f);
}

test_rand::~test_rand()
{
}
