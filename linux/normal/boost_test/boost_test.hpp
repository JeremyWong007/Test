#include<iostream>
#include <vector>

#include<boost/tuple/tuple.hpp> 
#include<boost/tuple/tuple_io.hpp> 
#include <boost/tuple/tuple_comparison.hpp>
#include <boost/bind.hpp>
#include "boost_test.h"
#include <boost/hana/fwd/if.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/assert.hpp>
#include <boost/static_assert.hpp>
#include <boost/thread.hpp>
#include <boost/array.hpp>
#include <boost/signals2.hpp>

#include "../common.h"
log4cpp::Category& boostCategory = root.getInstance("boost");

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

void func1()
{
	std::cout << "func1()函数被调用." << std::endl;
}
 
void func2()
{
	std::cout << "func2()函数被调用." << std::endl;
}
 
void func3()
{
	std::cout << "func3()函数被调用." << std::endl;
}
 
class my_object
{
public:
	void operator()(int param)
	{
		std::cout << "仿函数被调用: " << param << std::endl;
	}
};
 
//测试组号时用
template<int N>
struct Slot
{
	void operator()()
	{
		std::cout << "Slot current N value is : " << N << std::endl;
	}
};
 
int func4(int param)
{
	std::cout << "func4()函数被调用." << std::endl;
	return param + 10;
}
 
//合并器
template<typename T>
struct Combiner {
	typedef vector<T> result_type;
	template<typename InputIterator>
	result_type operator()(InputIterator first, InputIterator last) const {
		if (first == last) {
			return result_type(0);
		}
		return result_type(first, last);
	}
};
 
int func5(int param)
{
	std::cout << "func5()函数被调用." << std::endl;
	return param + 5;
}
 
int func6(int param)
{
	std::cout << "func6()函数被调用." << std::endl;
	return param + 6;
}
 
int func7(int param)
{
	std::cout << "func7()函数被调用." << std::endl;
	return param + 7;
}
 
int func8(int param)
{
	std::cout << "func8()函数被调用." << std::endl;
	return param + 8;
}
 
void test_signal2()
{
    ilog("test signal2 start");
	//设置槽的调用顺序
	boost::signals2::signal<void()> sig_void;
	sig_void.connect(&func1);  
	sig_void.connect(&func2, boost::signals2::at_front);//将会第一个被调用
	sig_void();
#if 1	
	//设置槽带参数
	boost::signals2::signal<void(int)> sig_obj;
	sig_obj.connect(my_object());
	sig_obj(10);
 
	//设置组号:根据组号分成组操作，组号小的函数先调用，组号大的后调用；
	//同一组号，调用顺序根据boost::signals2::at_back等设置的顺序调用
	boost::signals2::signal<void()> sig_slot;
	sig_slot.connect(10, Slot<1>());
	sig_slot.connect(10, Slot<2>());
	sig_slot.connect(9, Slot<3>());
	sig_slot.connect(9, Slot<4>(), boost::signals2::at_back);
	sig_slot.connect(11, Slot<5>());
	sig_slot.connect(11, Slot<6>());
	sig_slot.connect(11, Slot<7>(), boost::signals2::at_front);
 
	std::cout << "sig_slot信号关联的插槽数量： " << sig_slot.num_slots() << std::endl;
	
	if(!sig_slot.empty())
		sig_slot();
 
	//接收槽函数的返回值
	boost::signals2::signal<int(int)> sig_return;
	sig_return.connect(&func4);
 
	//一个信号对应一个槽函数时可以
	int m = *sig_return(100);
	std::cout << m << std::endl;
	//断开之前所有的信号-槽连接
	sig_return.disconnect_all_slots();
 
	//一个信号对应多个槽函数时：使用合并器获取所有的返回值
	boost::signals2::signal<int(int), Combiner<int> > sig_ret_combin;
	sig_ret_combin.connect(&func5);
	sig_ret_combin.connect(&func6);
	
	auto result = sig_ret_combin(200);
	for (const auto& i : result)
	{
		std::cout << i << std::endl;
	}
 
	//通过boost::signals::shared_connection_block 管理连接
	boost::signals2::signal<int(int)> sig_mgr;
	boost::signals2::shared_connection_block c = sig_mgr.connect(&func7);
 
	c.block();//连接被阻塞
	if (c.blocking())
		std::cout << "连接被阻塞" << std::endl;
	sig_mgr(12);//不会被调用
	std::cout << "解除连接阻塞" << std::endl;
	c.unblock();//解除阻塞
	sig_mgr(12);//会被调用
	std::cout << "shared_connection_block 测试结束" << std::endl;
	
	//boost::signals::connection管理连接
	boost::signals2::signal<int(int)> sig_mgr1;
	boost::signals2::connection c1 = sig_mgr1.connect(&func7);
	if (c1.connected())
		sig_mgr1(12);
	//断开连接
	c1.disconnect();
 
	//boost::signals::scoped_connection管理：析构时会自动释放连接
	boost::signals2::signal<int(int)> sig_mgr2;
	{
		boost::signals2::scoped_connection c2 = sig_mgr2.connect(&func8);
		std::cout << "当前fun8的连接数： " << sig_mgr2.num_slots() << std::endl;
		sig_mgr2(12);
	}
	std::cout << "当前fun8的连接数2： " << sig_mgr2.num_slots() << std::endl;
	//连接已被释放，相应槽函数不会被调用
	sig_mgr2(12);
#endif
}
 
 

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
void test_tuple1()
{
    typedef boost::tuple<std::string, std::string, int> person1;
    person1 p1("Bob","ShangHai",20);
    person1 p2("Alice","Ningbo",18);
    std::cout<<p1<<p2<<std::endl;
    auto tt=boost::make_tuple("Jerry",11,22,33);
    std::cout<<tt<<std::endl;
}

class boost_test
{
private:
	/* data */
public:
	boost_test(/* args */);
	~boost_test();
};

boost_test::boost_test(/* args */)
{
	std::cout<<"****************************************************************************************************************************************"<<std::endl;
    ilog("Test boost begin");
    //test_tuple1();
    //test_bind();
    //test_multi_index_container();
    //asio_test();
    //test_eos_name();
    //test_assert();
    //datetimer_test();
    //test_client();
    //test_asio();
    //test_signal2();
}

boost_test::~boost_test()
{
}
