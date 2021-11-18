#include<boost/tuple/tuple.hpp> 
#include<boost/tuple/tuple_io.hpp> 
#include <boost/tuple/tuple_comparison.hpp>
#include <boost/bind.hpp>
#include<iostream>
#include "boost_test.h"
#include <boost/hana/fwd/if.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/assert.hpp>
#include <boost/static_assert.hpp>
#include <boost/thread.hpp>
#include <boost/array.hpp>
#include "thread.hpp"

/* keys:
boost::tuple
boost::make_tuple

boost::bind  生成函数对象，以供表达式调用
std::bind1st,bind2st函数绑定器，把二元函数对象变为一元函数对象。
vector<A>::iterator t=find_if(a.begin(),a.end(),bind2nd(compare(), ”33″));

boost::ref
一般情况下传值语义都是可行的，但也有很多特殊情况，作为参数的函数对象拷贝代价过高(具有复杂的内部状态)，或者不希望拷贝对象(内部状态不应该被改变)，甚至拷贝是不可行的(noncopyable、单件)。
boost.ref应用代理模式，引入对象引用的包装器概念解决了这个问题。
*/
using namespace std;
using boost::bind;

extern void test_asio();
extern int datetimer_test();

void test_assert(void)
{
    cout<<"test assert start"<<endl;
    BOOST_ASSERT(16==0x10);
    BOOST_ASSERT(true);
    //BOOST_ASSERT_MSG(16==0x11,"calac error.");
    BOOST_STATIC_ASSERT(16==0x10);
    BOOST_STATIC_ASSERT(true);
    cout<<"true is"<<true<<"false is"<<false<<endl;
}

struct name {
private:
    uint64_t value = 0;

public:
    constexpr explicit name( uint64_t v ) : value(v) {}
    constexpr name() = default;

    std::string to_string()const;
};

std::string name::to_string()const {
    static const char* charmap = ".12345abcdefghijklmnopqrstuvwxyz";

    std::string str(13,'.');

    uint64_t tmp = value;
    for( uint32_t i = 0; i <= 12; ++i ) {
        char c = charmap[tmp & (i == 0 ? 0x0f : 0x1f)];
        str[12-i] = c;
        tmp >>= (i == 0 ? 4 : 5);
    }

    boost::algorithm::trim_right_if( str, []( char c ){ return c == '.'; } );
    return str;
}
void test_eos_name()
{
    cout<<"test eos name start."<<endl;
    //name n(14526054933851013120);
    //name n2(6138663577826885632);
    //cout<<n.to_string()<<","<<n2.to_string()<<endl;
}

void fun(int x, int y) {
  cout << x << ", " << y << endl;
}
void test_bind()
{
    cout<<"test bind start."<<endl;
    //boost::bind(&fun,3,4)();

    int a[] = {0,1,2,3,4,5,6,7,8,9};
    int* p = find_if(a, a+10,
    bind(logical_and<bool>(),
    bind(logical_and<bool>(),
    bind(greater<int>(), _1, 1),
    bind(less<int>(), _1, 6)),
    bind(logical_not<bool>(),
    bind(modulus<int>(), _1, 2))));
    cout << *p<<endl;
    cout<<"test bind end."<<endl;
}
void test_tuple()
{
    typedef boost::tuple<std::string, std::string, int> person1;
    person1 p1("Bob","ShangHai",20);
    person1 p2("Alice","Ningbo",18);
    std::cout<<p1<<p2<<std::endl;
    auto tt=boost::make_tuple("Jerry",11,22,33);
    std::cout<<tt<<std::endl;
}

void test_thread(){
    std::cout<<"test_thread in"<<std::endl;
    named_thread_pool threadPool("test", 4);
}

void test_boost(void)
{
    std::cout<<"Test boost begin"<<std::endl;
    std::cout<<"********************************************************************************************"<<std::endl;
    //test_tuple();
    //test_bind();
    //test_multi_index_container();
    //asio_test();
    //test_eos_name();
    //test_assert();
    //datetimer_test();
    //test_thread();
    //test_client();
    test_asio();
}