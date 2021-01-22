#include <iostream>

using namespace std;

void say(int a,int b=10,int c=11)
{
    cout<<"say:"<<a<<b<<c<<endl;
}

void sundries_test()
{
    cout<<"sundries test start"<<endl;
    say(1);
    say(1,2);
    say(1,2,3);
}