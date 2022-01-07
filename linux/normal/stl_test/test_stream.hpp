#include "../common.h"
#include <sstream>
#include <iostream>


#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>

using namespace std;

class test_stream
{
private:
    /* data */
public:
    test_stream(/* args */);
    ~test_stream();
};

test_stream::test_stream(/* args */)
{
    ilog("test stream in");
    string str="114 Hello", str3;
    int i=0;
    stringstream sst;
    sst << "115";
    sst >> str3;
    cout << "i=" << str3 <<endl;
    sst.str("");
    sst << "haha";
    //sst << "heihei";
    sst >> str3;
    cout << str3<<endl;
    cout << str3<<endl;
    cout<<sst.str()<<endl;

     stringstream sstream;
 
    // 将多个字符串放入 sstream 中
    sstream << "first" << " " << "string,";
    sstream << " second string";
    cout << "strResult is: " << sstream.str() << endl;
 
    // 清空 sstream
    sstream.str("");
    sstream << "third string";
    cout << "After clear, strResult is: " << sstream.str() << endl;
}

test_stream::~test_stream()
{
}
