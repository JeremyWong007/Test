#pragma once
#include <time.h>
#include <sys/time.h>
#include <string>
#include <list>

using namespace std;

template<typename T>
void print(T a)
{
    cout << "print: " << a << endl;
}
template<typename T>
void print(std::list<T> l){
    cout << "print: ";
    for(auto a : l){
        cout << " " << a;
    }
    cout << endl;
}
template<typename T>
void print(std::vector<T> l){
    cout << "print: ";
    for(auto a : l){
        cout << " " << a;
    }
    cout << endl;
}
template<typename T>
void print(std::vector<std::vector<T>> l){
    cout << "print: ";
    for(auto a : l){
        for(auto b : a){
            cout << " " << b;
        }
    }
    cout << endl;
}

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};
void print(ListNode* l){
    cout << "print: ";
    while(l != nullptr){
        cout << " " << l->val;
        l = l->next;
    }
}

class tools
{
private:
    /* data */
public:
    tools(/* args */);
    ~tools();

    // template<typename Func, typename... Args>
    // static void test_runTime(Func f, Args... a){
    //     timeval time_start,time_end;
    //     gettimeofday(&time_start, nullptr);
    //     f(a...);
    //     gettimeofday(&time_end, nullptr);
    //     cout<<"Run type2 func time: "<< 
    //     (time_end.tv_sec - time_start.tv_sec) * 1000000 + time_end.tv_usec - time_start.tv_usec 
    //     <<" us"<<endl;
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

    template<typename T>
    static void to_string(string& str, const T& input){
        ostringstream oss;
        oss << input;
        str = oss.str();
    }

    template<typename Outtype, typename Intype>
    static Outtype convert(const Intype in){
        stringstream ss;
        ss << in;
        Outtype result;
        ss >> result;
        return result;
    }
};
