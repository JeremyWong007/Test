#include <iostream>
#include <boost/assert.hpp>

using namespace std;

extern void say(void);

int main(void)
{
    cout<<"Hello world!"<<endl;
    say();
    BOOST_ASSERT(1);
}