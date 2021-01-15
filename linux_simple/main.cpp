#include <iostream>
#include <optional>

using namespace std;

/*
compile command:g++ -std=c++17 main.cpp -o main
*/
int main(void)
{
    cout<<"Hello world"<<endl;
    optional<int> a(10);
    a=11;
    int b=a.value();
    cout<<"a="<<a.value()<<endl;
    cout<<"b="<<b<<endl;
    return 0;
}