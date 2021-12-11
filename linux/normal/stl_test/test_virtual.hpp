#pragma once

#include "../common.h"
using namespace std;

//test_virtual
class A_base
{
public:
    int i=22;
    virtual void func() {
        cout<<"call A_base's func"<<i<<endl;
    }
    virtual void func2() {}
    virtual void func3() {}
    void func5(){}
private:
    int j=12;
};
class A_base1{
    public:
    int i=44;
    virtual void func4(){
        cout<<"call A_base1's func"<<i<<endl;
    }
    void func5(){}
};
class C{
    protected:
    int i=66;
};
//多重继承时，会有多个函数表。
class B : public A_base, public A_base1
{
    public:
    void func() {
        cout<<"call B's func"<<i<<endl;
        //父类的私有成员，子类内部也无法访问
        //cout<<"j="<<j<<endl;
    }
    
    public:
    int i=33;
};

class test_virtual
{
private:
    /* data */
public:
    test_virtual(/* args */);
    ~test_virtual();
};

test_virtual::test_virtual(/* args */)
{
    ilog("test_virtual in");
    cout<<"size:" << sizeof(A_base) << ", " << sizeof(B)<<endl;
    B bb;
    bb.i = 55;
    bb.A_base::i=66;
    bb.func();
    bb.A_base::func();
    bb.A_base1::func5();
    //bb.func5();  //两个基类中都有func5，编译报错，提示有歧义
}

test_virtual::~test_virtual()
{
}
