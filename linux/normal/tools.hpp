#pragma once
#include <time.h>
#include <sys/time.h>
#include <string>

using namespace std;

class tools
{
private:
    /* data */
public:
    tools(/* args */);
    ~tools();

    // template<typename Func, typename... Args>
    // static void test_runTime(Func f, Args... a){
    //     f(a...);
    // }
    template<typename Func>
    static void test_runTime(Func f, string name=""){
        timeval time_start,time_end;
        gettimeofday(&time_start, nullptr);
        f();
        gettimeofday(&time_end, nullptr);
        cout<<"Run func"<<(name.empty()?"":" ")<<name<<" time: "<< \
        (time_end.tv_sec - time_start.tv_sec) * 1000000 + time_end.tv_usec - time_start.tv_usec \
        <<" us"<<endl;
    }
};
