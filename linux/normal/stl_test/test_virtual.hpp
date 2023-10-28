#pragma once

#include "../common.h"
using namespace std;

//参考链接： https://zhuanlan.zhihu.com/p/611317234


class Base {
public:
	virtual void a() { std::cout << " a()" << std::endl; }
	virtual void b() { std::cout << " b()" << std::endl; }
	virtual void c() { std::cout << " c()" << std::endl; }
};

class SubClass : public Base {
public:
	virtual void a() { std::cout << " subclass a()" << std::endl; }
	virtual void d() { std::cout << " d()" << std::endl; }
};

namespace manySubClass{
    class Base {
    public:
        virtual void vFunc1() { std::cout << "  Base::vFunc1" << std::endl; }
        virtual void vFunc2() { std::cout << "  Base::vFunc2" << std::endl; }
        virtual void vFunc3() { std::cout << "  Base::vFunc3" << std::endl; }
    };

    class Base2 {
    public:
        virtual void vBase2Func1() { std::cout << "  Base2::vFunc1" << std::endl; }
        virtual void vBase2Func2() { std::cout << "  Base2::vFunc2" << std::endl; }
    };

    class Base3 {
    public:
        virtual void vBase3Func1() { std::cout << "  Base3::vFunc1" << std::endl; }
        virtual void vBase3Func2() { std::cout << "  Base3::vFunc2" << std::endl; }
    };



    class SubClass : public Base , public Base2, public Base3 {
        /**
         *覆盖父类Base的vFunc1
        */
        virtual void vFunc1() { std::cout << " SubClass::vFunc1" << std::endl; }
        virtual void vFunc() { std::cout << " SubClass::vFunc" << std::endl; }
        /**
         *覆盖父类Base2的vBase2Func1
        */
        virtual void vBase2Func1() { std::cout << "  SubClass::vBase2Func1" << std::endl; }
        };

    void test(){
        ilog("manySubClass test in");
        SubClass sub;
        printf("size of sub object: %d \n", sizeof(sub));
        typedef void(*FUNCTION)();
        /**
            *Base有三个函数 vFunc1 & vFunc2 & vFunc3
            *Base2有两个函数 vFunc1 & vFunc2
            *Base3有两个函数 vFunc1 & vFunc2
            *从继承顺序知道虚函数表顺序是 vTablePtr1--->vTablePtr2--->vTablePtr3
            */

        /**
            *对象地址的前三个地址内容分别是指向vTable1的指针vTablePtr1 & 指向vTable2的指针vTablePtr2 
            * & 指向vTable3的指针vTablePtr3
            */
        
        /**
         *虚函数表一 Base vTablePtr1 (地址)
        */
        std::int64_t *subAddress = (std::int64_t*)&sub;
        std::int64_t *vTablePtr1 = (std::int64_t*)*(subAddress);
        
        /**
         *虚函数表二 Base2 vTablePtr2（地址）
        */
        std::int64_t *subAddress2 = (std::int64_t*)&sub + 1;
        std::int64_t *vTablePtr2 = (std::int64_t*)*(subAddress2);

        /**
         *虚函数表三 Base3 vTablePtr3 (地址)
        */

        std::int64_t *subAddress3 = (std::int64_t*)&sub + 2;
        std::int64_t *vTablePtr3 = (std::int64_t*)*(subAddress3);


        /**
         *定义测试函数
        */

        //Base
        std::int64_t *pBaseFunc1 = (std::int64_t *)*(vTablePtr1 + 0);
        std::int64_t *pBaseFunc2 = (std::int64_t *)*(vTablePtr1 + 1);
        std::int64_t *pBaseFunc3 = (std::int64_t *)*(vTablePtr1 + 2);
        std::int64_t *pBaseFunc4 = (std::int64_t *)*(vTablePtr1 + 3);
            
        //Base2 
        std::int64_t *pBase2Func1 = (std::int64_t *)*(vTablePtr2 + 0);
        std::int64_t *pBase2Func2 = (std::int64_t *)*(vTablePtr2 + 1);

        //Base3
        std::int64_t *pBase3Func1 = (std::int64_t *)*(vTablePtr3 + 0);
        std::int64_t *pBase3Func2 = (std::int64_t *)*(vTablePtr3 + 1);

        /**
            *调用测试函数
            */ 

        //Base
        (FUNCTION(pBaseFunc1))();
        (FUNCTION(pBaseFunc2))();
        (FUNCTION(pBaseFunc3))();
        (FUNCTION(pBaseFunc4))();

        //Base2
        (FUNCTION(pBase2Func1))();
        (FUNCTION(pBase2Func2))();

        //Base3
        (FUNCTION(pBase3Func1))();
        (FUNCTION(pBase3Func2))();
    }
}

namespace diamondInheritance{
    class Base {
    public:
        virtual void vBaseFunc1() { std::cout << "  Base::vFunc1" << std::endl; }
        virtual void vBaseFunc2() { std::cout << "  Base::vFunc2" << std::endl; }
        virtual void vBaseFunc3() { std::cout << "  Base::vFunc3" << std::endl; }
    };

    class SubClass1 : public Base {
    public:
        /**
         *继承自Base的vBaseFunc1
        */
        virtual void vBaseFunc1() { std::cout << "  SubClass1::Base::vFunc1" << std::endl; }
        virtual void vSubClass1Func() { std::cout << "  SubClass1::vFunc" << std::endl; }
    };

    class SubClass2 : public Base {
    public:
        /**
         *继承自Base的vBaseFunc2 
        */
        virtual void vBaseFunc2() { std::cout << "  SubClass2::Base::vFunc2" << std::endl; }
        virtual void vSubClass2Func() { std::cout << "  SubClass2::vFunc" << std::endl; }
    };


    class SubSubClass : public SubClass1, public SubClass2 {
    public:
        /**
         *继承自SubClass1& SubClass2 的vBaseFunc1 :所以两个虚函数表都应该被修改
        */
        //virtual void vBaseFunc1() { std::cout << "  SubSubClass::vFunc1" << std::endl; }
        /**
         *继承自SubClass2 & SubClass1 的vBaseFunc2 :所以两个虚函数表都应该被修改
        */
        //virtual void vBaseFunc2() { std::cout << "  SubSubClass::vFunc2" << std::endl; }
        
        virtual void vSubSubClassFunc() { std::cout << "  SubSubClass::vFunc" << std::endl; }


    };


    int test()
    {
        ilog("diamondInheritance test in");
        SubSubClass subsub;

        printf("size of sub object: %d \n", sizeof(subsub));

        typedef void(*FUNCTION)();

        /**
         *虚函数表一 Base vTablePtr1 (地址)
        */
        std::int64_t *subAddress = (std::int64_t*)&subsub;
        std::int64_t *vTablePtr1 = (std::int64_t*)*(subAddress);


        /**
         *虚函数表二 Base2 vTablePtr2（地址）
        */
        std::int64_t *subAddress2 = (std::int64_t*)&subsub + 1;
        std::int64_t *vTablePtr2 = (std::int64_t*)*(subAddress2);


        /**
         *定义测试函数
        */

        //SubClass1
        std::int64_t *pBaseFunc1 = (std::int64_t *)*(vTablePtr1 + 0);
        std::int64_t *pBaseFunc2 = (std::int64_t *)*(vTablePtr1 + 1);
        std::int64_t *pBaseFunc3 = (std::int64_t *)*(vTablePtr1 + 2);
        std::int64_t *pBaseFunc4 = (std::int64_t *)*(vTablePtr1 + 3);
        std::int64_t *pBaseFunc5 = (std::int64_t *)*(vTablePtr1 + 4);
        
        //SubClass2 
        std::int64_t *pBase2Func1 = (std::int64_t *)*(vTablePtr2 + 0);
        std::int64_t *pBase2Func2 = (std::int64_t *)*(vTablePtr2 + 1);
        std::int64_t *pBase2Func3 = (std::int64_t *)*(vTablePtr2 + 2);
        std::int64_t *pBase2Func4 = (std::int64_t *)*(vTablePtr2 + 3);

        

        /**
         *SubClass1继承自Base有三个虚函数&自身定义了一个虚函数
        */
        
        (FUNCTION(pBaseFunc1))();
        (FUNCTION(pBaseFunc2))();
        (FUNCTION(pBaseFunc3))();
        (FUNCTION(pBaseFunc4))();
        (FUNCTION(pBaseFunc5))();

        /**
         *SubClass2 继承自Base有三个虚函数&自身定义了一个虚函数
        */
        (FUNCTION(pBase2Func1))();
        (FUNCTION(pBase2Func2))();
        (FUNCTION(pBase2Func3))();
        (FUNCTION(pBase2Func4))();

        return 0;
    }
}

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
    void test_virtual1(){
        ilog("test_virtual1 in");        
        Base base;
        int64_t *p = (int64_t *)&base;
        (   *((void(*)())*((std::int64_t*)(*p) + 1))   )     ();
        (   ((void(*)())*((std::int64_t*)(*((std::int64_t*)&base)) + 0))   )     ();
        (   ((void(*)())*((std::int64_t*)(*((std::int64_t*)&base)) + 1))   )     ();
        (   ((void(*)())*((std::int64_t*)(*((std::int64_t*)&base)) + 2))   )     ();
    }
    void test_virtual_subclass(){
        ilog("test_virtual_subclass in");
        SubClass sub;
        (   ((void(*)())*((std::int64_t*)(*((std::int64_t*)&sub)) + 0))   )     ();
        (   ((void(*)())*((std::int64_t*)(*((std::int64_t*)&sub)) + 1))   )     ();
        (	((void(*)())*((std::int64_t*)(*((std::int64_t*)&sub)) + 2))   )     ();
        (   ((void(*)())*((std::int64_t*)(*((std::int64_t*)&sub)) + 3))   )     ();
    }
    void test_virtual_sub3(){

    }
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

    test_virtual1();
    test_virtual_subclass();
    test_virtual_sub3();
    manySubClass::test();
    diamondInheritance::test();
}

test_virtual::~test_virtual()
{
}