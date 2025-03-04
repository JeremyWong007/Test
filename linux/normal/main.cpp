#include <iostream>
#include <boost/lambda/lambda.hpp>
#include <boost/signals2/connection.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include "boost_test/boost_test.h"
#include <locale.h>
#include <libintl.h>
#include "common.h"
#include "stl_test/stl_test.hpp"
#include "boost_test/boost_test.hpp"
#include "sundries/sundries_test.hpp"
#include "exercises/exercises.hpp"

log4cpp::Category& root = log4cpp::Category::getRoot();
log4cpp::Category& mainCategory = root.getInstance("main");

using namespace std;

#define LOCALEDIR "/usr/share/locale/"      /* 设置 mo 文件所在基目录(该目录下会有 zh_CN, zh_TW 等等这些目录) */
#define PACKAGE "foonly"    /* 函数的第 1 个参数 domainname */


void tmp_test()
{
    cout<<"tmp test start"<<endl;
    std::cout<<"****************************************************************************************************************************************"<<std::endl;
    cout<<"value = "<<('j'-'a'+6)<<endl;
    string str="ABC";
    cout<<"length="<<str.length()<<"size="<<str.size()<<"str:"<<str<<endl;
}

int main(void)
{
    try{
        char *p=setlocale(LC_ALL,"");
        bindtextdomain (PACKAGE, LOCALEDIR);
        textdomain (PACKAGE);
        cout<<"local is "<<p<<endl;
        cout<<"中文显示"<<endl;

        //std::string initFileName = "/data/info/git/test/linux/normal/log4cpp.properties";
        std::string initFileName = "../log4cpp.properties";
        log4cpp::PropertyConfigurator::configure(initFileName);
        ilog("Application Test start");

        boost_test t_boost;
        stl_test t_stl;
        sundries_test t_sundries;
        exercises exec;
        
        #ifdef SHOWSTR
        //    cout<<"In TEST_IN_LINUX"<<endl;
        #else
        //    cout<<"Not in TEST_IN_LINUX"<<endl;
        #endif
        //cout<<SHOWSTR<<endl;
    }catch(std::exception e){
        elog("exception caught %s", e.what());
    }catch(...){
        elog("unknown exception.");
    }
    log4cpp::Category::shutdown();
    
    return 0;
}