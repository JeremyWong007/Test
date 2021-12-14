#include "../common.h"

using namespace std;

/*
总结：
decltype是为了解决复杂的类型声明而使用的关键字，称作decltype类型说明符。
std::declval将任意类型 T 转换成引用类型，令在 decltype 表达式中不必经过构造函数就能使用成员函数。

decltype可以作用于变量、表达式及函数名。①作用于变量直接得到变量的类型；
②作用于表达式，结果是左值的表达式得到类型的引用，结果是右值的表达式得到类型；③作用于函数名会得到函数类型，不会自动转换成指针。

decltype不会去真的求解表达式的值，可以放心使用。
*/
struct A{
    virtual int value()=0;
};
int add_to(int &des, int ori){
    return 1;
};

class test_decltype
{
private:
    /* data */
public:
    test_decltype(/* args */);
    ~test_decltype();
};

test_decltype::test_decltype(/* args */)
{
    ilog("test decltype in");
    #if 0
    const int ci = 0, &cj = ci;

    // x的类型是const int
    decltype(ci) x = 0;

    // y的类型是const int &
    decltype(cj) y = x;
    cout<<typeid(ci).name()<<typeid(cj).name()<<typeid(x).name()<<typeid(y).name()<<endl;
    #endif
    
    int i = 42, *p = &i, &r = i;
    // r + 0是一个表达式
    // 算术表达式返回右值
    // b是一个int类型
    decltype(r + 0) b;
    b = 1;

    // *p是左值，c是一个int &
    decltype(*p) c = i;

    // 加了括号，变成了表达式
    // 返回的是i的左值形式
    // 因此ri的类型是int &
    decltype((i)) ri = i;

    //temp是指向int类型的指针的引用
    decltype((p)) temp = p;

    //使用decltype获得函数add_to的类型
    decltype(add_to) *pf = add_to;

    cout<<b<<c<<ri<<"temp="<<temp<<"pf:"<<pf(i,i);

    decltype(std::declval<A>().value()) a=0;  //int a
    (void)a;
}

test_decltype::~test_decltype()
{
}
