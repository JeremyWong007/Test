#include "../common.h"
#include <iostream>
#include <functional>
#include "../tools.hpp"

using namespace std;

class sort_test
{
private:
    /* data */
    std::vector<int> inputVector={1,3,2,8,4,2};
public:
    sort_test(/* args */);
    ~sort_test();

    void insert_sort(){
        for(int i=0; i<(int)inputVector.size(); i++){
            for(int j=i; j>0; j--){
                if(inputVector[j] < inputVector[j-1]){
                    int tmp = inputVector[j];
                    inputVector[j] = inputVector[j-1];
                    inputVector[j-1] = tmp;
                }
            }
        }
        cout<<"insert_sort:";
        for(int i=0; i<(int)inputVector.size(); i++){
            cout<<" "<<inputVector[i];
        }
        cout<<endl;
    }

    void xier_sort(){

    }
    void test(int i, string str){
        cout<<"test "<<i<<" "<<str<<endl;
    }
    void test2(string str){
        cout<<"test "<<str<<endl;
    }
};

sort_test::sort_test(/* args */)
{
    ilog("test sort in");
    //insert_sort();
    auto f = std::bind(&sort_test::insert_sort, this);
    tools::test_runTime<>(f);
}

sort_test::~sort_test()
{
}
