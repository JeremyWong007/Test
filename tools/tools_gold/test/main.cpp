/*
编译：
g++ main.cpp -o test
g++ main.cpp -o test -g  增加调试信息
*/

#include <iostream>
#include "test_dir_file.hpp"

using namespace std;


int main() {
    cout<<"Hello world!"<<endl;
    test_dir_file t_dir_file;
    return 0;
}