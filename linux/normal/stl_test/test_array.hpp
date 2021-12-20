/*
array: 固定大小数组

vector: 可变大小数组

*/
#pragma once
#include "../common.h"
#include <array>
#include <algorithm>

using namespace std;

class test_array
{
private:
    /* data */
public:
    test_array(/* args */);
    ~test_array();
};

test_array::test_array(/* args */)
{
    ilog("test array in");
    std::array<int, 7> arr = {11, 22, 33, 44, 55, 66, 77};
    std::for_each(arr.begin(), arr.end(), [](int &i){
        cout << " " << ++i;
    });
    cout << endl;

    cout << "show part2:";
    for(int i : arr){
        cout << " " << i;
    }
    cout << endl;
}

test_array::~test_array()
{
}
