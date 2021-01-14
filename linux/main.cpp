#include <iostream>
#include <boost/lambda/lambda.hpp>
#include <boost/signals2/connection.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include "boost_test/boost_test.h"

using namespace std;

class database
{
    public:
    void flush();
    inline void say(){
        cout<<"Hello func!"<<endl;
    };
};

int main(void)
{
    database aa;
    aa.say();
    cout<<"Hello world!"<<endl;
    cout<<"Hello world2!"<<endl;
    cout<<"Hello world3!"<<endl;
    cout<<"Hello world4!"<<endl;
    test_boost();
}