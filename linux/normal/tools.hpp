#pragma once

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
    static void test_runTime(Func f){
        
        f();
    }
};
