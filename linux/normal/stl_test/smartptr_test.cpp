#include <memory>
#include <iostream>

using namespace std;

class Tiger{
    public:
    Tiger(){}
    ~Tiger(){}
    void say(){
        cout<<"This is tiger"<<endl;
    }
};

void test_unique_ptr()
{
    auto uptr=make_unique<Tiger>();
    uptr->say();
}

class Bad
{
public:
std::shared_ptr<Bad> getptr() {
return std::shared_ptr<Bad>(this);
}
~Bad() { std::cout << "Bad::~Bad() called" << std::endl; }
};

void test_smartptr_bad()
{
    // 错误的示例，每个shared_ptr都认为自己是对象仅有的所有者
    std::shared_ptr<Bad> bp1(new Bad());
    std::shared_ptr<Bad> bp2 = bp1->getptr();
    // 打印bp1和bp2的引用计数
    std::cout << "bp1.use_count() = " << bp1.use_count() << std::endl;
    std::cout << "bp2.use_count() = " << bp2.use_count() << std::endl;
} // Bad 对象将会被删除两次

struct Good:std::enable_shared_from_this<Good>
{
    public:
    std::shared_ptr<Good> getptr(){
        return shared_from_this();
    }
    ~Good(){std::cout<<"Good::~Good() called"<<std::endl;}
};

void test_smartptr()
{
    std::cout<<"test ptr start"<<std::endl;
    //test_smartptr_bad();
    // {
    //     std::shared_ptr<Good> gp1(new Good());
    //     std::shared_ptr<Good> gp2 = gp1->getptr();
    //     // 打印gp1和gp2的引用计数
    //     std::cout << "gp1.use_count() = " << gp1.use_count() << std::endl;
    //     std::cout << "gp2.use_count() = " << gp2.use_count() << std::endl;
    // }
    test_unique_ptr();
}