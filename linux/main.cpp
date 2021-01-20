#include <iostream>
#include <boost/lambda/lambda.hpp>
#include <boost/signals2/connection.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include "boost_test/boost_test.h"
#include <locale.h>
#include <libintl.h>

using namespace std;

extern void test_std();

class database
{
    public:
    void flush();
    inline void say(){
        cout<<"Hello func!"<<endl;
    };
};

#define LOCALEDIR "/usr/share/locale/"      /* 设置 mo 文件所在基目录(该目录下会有 zh_CN, zh_TW 等等这些目录) */
#define PACKAGE "foonly"    /* 函数的第 1 个参数 domainname */

int main(void)
{
    char *p=setlocale(LC_ALL,"");
    bindtextdomain (PACKAGE, LOCALEDIR);
    textdomain (PACKAGE);
    cout<<"local is "<<p<<endl;
    cout<<"中文显示"<<endl;
    database aa;
    aa.say();
    cout<<"Hello world!"<<endl;
    cout<<"Hello world2!"<<endl;
    cout<<"Hello world3!"<<endl;
    cout<<"Hello world4!"<<endl;
    test_boost();
    test_std();
}