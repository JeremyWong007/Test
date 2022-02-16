#include <iostream>
#include <optional>
#include <variant>
#include <array>
#include <functional>
#include <vector>
#include <fstream>
#include <sstream>
#include <boost/filesystem/path.hpp>
#include <boost/core/demangle.hpp>
#include <unistd.h>
#include <pwd.h>
#include <typeinfo>
#include <cmath>
#include "StlTestForClass.hpp"
#include "../common.h"
#include "test_set.hpp"
#include "test_virtual.hpp"
#include "test_enable_if.hpp"
#include "test_rand.hpp"
#include "test_va_list.hpp"
#include "test_tuple.hpp"
#include "test_decltype.hpp"
#include "test_queue.hpp"
#include "test_array.hpp"
#include "test_stack.hpp"
#include "test_list.hpp"
#include "test_heap.hpp"
#include "test_string.hpp"
#include "test_stream.hpp"

log4cpp::Category& stlCategory = root.getInstance("stl");

namespace bfs = boost::filesystem;

using namespace std;

void test_exception(){
    cout<<"test_exception in"<<endl;
    try{
        log4cpp::Category *p=0;
        typeid(*p);
    }
    catch(std::exception e){
        elog("exception caught %s",e.what());
        throw;
    }
}

void test_map(){
   cout<<"test_map start"<<endl;
   map<string,string> m;
   m["name"]="lili";
   cout<<"name:"<<m["name"]<<endl;
   cout<<"name2:"<<m["name2"]<<endl;
}

struct http_plugin_defaults {
    //If empty, unix socket support will be completely disabled. If not empty,
    // unix socket support is enabled with the given default path (treated relative
    // to the datadir)
    string default_unix_socket_path;
    //If non 0, HTTP will be enabled by default on the given port number. If
    // 0, HTTP will not be enabled by default
    uint16_t default_http_port{11};
};
void ttt(http_plugin_defaults a)
{
   cout<<"a="<<a.default_http_port<<a.default_unix_socket_path;
}
void test_struct(){
   cout<<"test_struct start"<<endl;
   http_plugin_defaults a;
   ttt({
       .default_unix_socket_path="sfdf",
       .default_http_port=22
   });
}

void test_cast(){
    cout<< "test cast start."<<endl;
    string s="Hello";
    int &a=reinterpret_cast<int&>(s);
    cout<<"string a: "<<a<<endl;
    int *p=reinterpret_cast<int*>(&s);
    cout<<"string a: "<<*p<<endl;
}


void process(int& i){
    cout << "process(int&):" << i << endl;
}
void process(int&& i){
    cout << "process(int&&):" << i << endl;
}

template<typename T>
void myforward(T&& i){
    cout << "myforward(int&&):" << i << endl;
    process(forward<T>(i));
}

void test_wanmeizhuanfa()
{
    int a = 0;
    process(a); //a被视为左值 process(int&):0
    process(1); //1被视为右值 process(int&&):1
    process(move(a)); //强制将a由左值改为右值 process(int&&):0
    myforward(2);  //右值经过forward函数转交给process函数，却称为了一个左值，
    //原因是该右值有了名字  所以是 process(int&):2
    myforward(move(a));  // 同上，在转发的时候右值变成了左值  process(int&):0
    // forward(a) // 错误用法，右值引用不接受左值
    myforward(a);
}

int add(int a,int b){
    return a+b;
}
/*
总结
由两种值类型，左值和右值。
有三种引用类型，左值引用、右值引用和通用引用。左值引用只能绑定左值，右值引用只能绑定右值，通用引用由初始化时绑定的值的类型确定。
const int& 常量左值引用，算是一个“万能”的引用类型，它可以绑定非常量左值、常量左值、右值
左值和右值是独立于他们的类型的，右值引用可能是左值可能是右值，如果这个右值引用已经被命名了，他就是左值。
引用折叠规则：所有的右值引用叠加到右值引用上仍然是一个右值引用，其他引用折叠都为左值引用。当T&&为模板参数时，输入左值，它将变成左值引用，输入右值则变成具名的右值应用。
移动语义可以减少无谓的内存拷贝，要想实现移动语义，需要实现移动构造函数和移动赋值函数。
std::move()将一个左值转换成一个右值，强制使用移动拷贝和赋值函数，这个函数本身并没有对这个左值什么特殊操作。
std::forward()和universal references通用引用共同实现完美转发。
用empalce_back()替换push_back()增加性能。
https://www.jianshu.com/p/d19fc8447eaa
*/

int& getyinyong(){
    static int cc=22;
    print(cc);
    return cc;
}
void test_yinyong(){
    cout<<"test yinyong start"<<endl;
    int b=11;
    int&& a=std::move(b);
    cout<<"a="<<a<<endl;

    const int& c=1;
    cout<<"c="<<c<<endl;
    int&& d=add(3,4);
    cout<<"d="<<d<<endl;
    test_wanmeizhuanfa();
    
    int& dd = getyinyong();
    dd=55;
    getyinyong();
}

class testTypeid{
    int type;
};

void test_typeid(){
    cout<<"test typeid start."<<endl;
    cout<<typeid(1.1f).name()<<endl;
    int a=10;
    cout<<typeid(a).name()<<endl;
    string s="Hello!";
    cout<<typeid(s).name()<<endl;
    testTypeid tt;
    cout<<typeid(tt).name()<<endl;
}

class time_point{
    public:
    operator string()const;
    private:
    int microsecond=11;
};

time_point::operator string()const{
    return(to_string(microsecond));
}

void test_operator(){
    cout<<"test operator start."<<endl;
    time_point t;
    cout<<"microsecond is: "<<string(t)<<endl;

}

class wife;
class husband;
class family{
private:
    string house="wangke";
    string car="dazhong";
    friend class wife;
    friend class husband;
};

class husband{
    public:
    void myhouse(family f){
        cout<<"husband in "<<f.house<<endl;
    }
    void mycar(family f){
        cout<<f.car;
    }
    void call(wife w);
};
class wife{
    public:
    void myhouse(family f){
        cout<<"wife in "<<f.house<<endl;
    }
    void mycar(family f){
        cout<<f.car;
    }
    //类内定义的友元函数，实际是全局函数
    friend void call(wife &w){
        cout<<"call wife "<<w.name<<endl;
    }
    private:
    string name="pretty girl";
    friend void husband::call(wife w);
};
void husband::call(wife w){
    cout<<"husband call "<<w.name;
}

void test_friend(){
    ilog("test friend in.");
    family f;
    husband m;
    wife w;
    m.myhouse(f);
    w.myhouse(f);
    call(w);
    m.call(w);
}

#include <limits>
void test_numeric_limits()
{
    cout<<"test numeric_limits start"<<endl;
    cout<<"double:"<<numeric_limits<double>::max()<<endl;
    cout<<"float:"<<numeric_limits<float>::max()<<endl;
    cout<<"int:"<<numeric_limits<int>::max()<<endl;
    cout<<"int16:"<<numeric_limits<int16_t>::max()<<endl;
    cout<<"uint16:"<<numeric_limits<uint16_t>::max()<<endl;
    cout<<"int64:"<<numeric_limits<int64_t>::max()<<endl;
    int16_t tt = std::numeric_limits<int16_t>::min();
    int32_t t32 = (int32_t)tt;
    cout<<"blocks:"<<tt<<"   "<<t32<<endl;
}

using int16bye=int;
using vectorv = vector<int>;
struct name2;
bfs::path determine_home_directory()
{
   bfs::path home;
   cout<<"getuid "<<getuid()<<endl;
   //struct passwd* pwd = getpwuid(getuid());
//    if(pwd) {
//       home = pwd->pw_dir;
//       cout<<"pwd:"<<home.string();
//    }
   //else {
      home = getenv("HOME");
   //}
   if(home.empty())
      home = "./";
    cout<<"end home:"<<home;
   return home;
}
void test_path()
{
    cout<<"test path start."<<endl;
    determine_home_directory();
}


struct tss{
    int a=11;
    int b=22;
    string sayhello="Hello world!";
    friend std::stringstream& operator << ( std::stringstream& out, const tss& n ) {
        out<<n.sayhello<<n.a<<n.b<<endl;
        return out;
    }
    friend std::stringstream& operator >> ( std::stringstream& out, tss& nn ) {
        nn.a=88;
        nn.b=99;
        nn.sayhello="hello goodbay";
        return out;
    }
};

void test_sstream(void){
    cout<<"test sstream start."<<endl;
    stringstream s;
    string result="99988";
    int n=0;
    s<<result;
    s>>n;
    cout<<"n is "<<n<<endl;
    stringstream s2;
    tss ts,ts2;
    ts.a=311;
    ts.b=322;
    ts.sayhello="say goodbay";
    s2.clear();
    s2<<ts;
    s2>>ts2;
    cout<<"ts2 is: "<<ts2.sayhello<<endl;
}

void test_ofstream(void){
    cout<<"test_ofstream start"<<endl;
    std::ofstream out;
    out.open("../resource/testof.rs");
    if(out.fail()){
        cout<<"out open file err!"<<endl;
    }
    out<<"Hello fstream";
    out<<"Niece."<<std::endl;
    out<<"End"<<endl;
}

void test_using(int a,int b)
{
    std::cout<<"test using start"<<std::endl;
}

void test_hash(void)
{
    cout<<"test hash start"<<endl;
    string i="10";


    int16bye aa=10;
    std::cout<<"test using"<<aa<<std::endl;
    vectorv vv;
    vv.push_back(11);
    vv.push_back(22);
    std::cout<<vv[0]<<vv[1]<<endl;
    
    test_using(1,1);
    #define DD(a,b) (a-b)
    #define DDD(a,b) test_using(a,b)
    DDD(1,2);
    // using dd = vector<int>;
}

 struct name2 {
   private:
      __uint128_t value = 0;

   public:
      constexpr explicit name2( uint64_t v ) {
         value = static_cast<__uint128_t>(v);
      }
      constexpr explicit name2( int64_t v ) {
         value = static_cast<__uint128_t>(v);
      }
      constexpr explicit name2( __uint128_t v ) : value(v) {}
      constexpr name2() = default;
      constexpr uint64_t to_uint64_t()const { return static_cast<uint64_t>(value); }
 };

void test_uint128(void)
{
    __uint128_t a=13;
    __int64_t b=11;
    a=b;
    cout<<b<<endl;
    name2 cc(b);
    name2 dd(a);
    //cout<<a<<endl;
}

template<typename T1,typename T2,typename T3>
void func11(T2 a){
    cout<<"fucn1:"<<a<<endl;
}

template<typename T1,typename T2,typename T3>
struct st1{
    template<typename T4>
    void func11(T4 a){
        cout<<"fucn1:"<<a<<endl;
    }
};

class abstract_plugin{
    public:
        int a=0;
        virtual void set(int aa) = 0;
};
class plugin1 : public abstract_plugin{
    void set(int aa){a=aa;cout<<"plugin1 a="<<a;}
};
class plugin2 : public abstract_plugin{
    void set(int aa){a=aa;cout<<"plugin2 a="<<a;}
};
class plugin3 : public abstract_plugin{
    void set(int aa){a=aa;cout<<"plugin3 a="<<a;}
};
class app{
    public:
        app(){};
        template<typename... Ts>
        void init(){
            init1({find<Ts>()...});
        }
        template<typename Plugin>
        Plugin* find(){
            string name=typeid(Plugin).name();
            auto itr=pulgs.find(name);
            if(itr == pulgs.end()){
                return nullptr;
            }
            return dynamic_cast<Plugin*>(itr->second.get());
        }
        void init1(vector<abstract_plugin*> va){
            for(uint i=0;i<va.size();i++){
                if(nullptr==va[i]){
                    cout<<"va["<<i<<"] is null"<<endl;
                }
                else{
                    cout<<"va set "<<i<<endl;
                    va[i]->set(i);
                }
            }
        };
        void set_args(){
            auto p1=new plugin1();
            auto p2=new plugin2();
            pulgs["plug1"].reset(p1);
            pulgs["plug2"].reset(p2);
        }
    private:
        map<string,unique_ptr<abstract_plugin>> pulgs;
};


void test_template(){
    cout<<"test template start"<<endl;
    func11<int,int,int>(9);
    st1<int,int,string> s1;
    s1.template func11("tt");
    s1.func11("HaHa");
    /*
    总结：
    1 template的最后一个模板参数与函数入参相同时可以省略。如果不是最后一个参数，不可以省略。
    2 .template告诉编译器后面的变量为模板。
    */

   //测试模板参数包
   class app a;
   a.set_args();
   a.init<plugin1,plugin2>();
}

namespace tafio {
    string N1="N1_tafio";
    namespace chain_apis {
        using namespace tafio;
        void test1(){
            cout<<"test1"<<N1<<endl;
        }
        string N1="N1_tafio_chain_apis";
        void test2()
        {
            cout<<"test2"<<N1<<endl;
        }
       
    }
}
void test_namespace()
{
    cout<<"test namespce start."<<endl;
    //cout<<"N1:"<<N1<<endl;
    cout<<"tafio N1:"<<tafio::N1<<endl;
    cout<<"chain_apis N1:"<<tafio::chain_apis::N1<<endl;
    tafio::chain_apis::test1();
    tafio::chain_apis::test2();
    /*
    总结：
    宏与命名空间不相干。宏在预处理阶段处理，namespace在编译阶段生效
    命名空间中可以using自己，相当于没有操作
    可以定义using中已有的变量，定义前使用是的是using的变量，定义后使用的是定义的变量。
    */
    
}

void test_lambda()
{
    cout<<"test lambda start."<<endl;
    int a=11;
    int b=12;
    auto f = [&](auto& x) {
        cout << x << endl;
        cout << b << endl;
        };
    f(a);
    //stlTestForClass t;
}

void test_variant()
{
    
    cout<<"test variant start."<<endl;
    variant<int, double, string> v; // v == 0
    v = 1;
    bool has_int = holds_alternative<int>(v);
    bool has_double = holds_alternative<double>(v);
    cout << v.index() << has_int << has_double << get<0>(v) << *get_if<0>(&v) << endl; // 01011
    v = 2.0;
    cout << v.index() << (get_if<int>(&v) == nullptr) << get<1>(v) << get<double>(v) << endl; // 1122
    v = "a";
    cout << v.index() << get<2>(v) << get<string>(v) << endl; // 2aa
}

std::optional<int> div_int(int a, int b) {
    if (b != 0) {
        return std::make_optional<int>(a / b);
    }
    return {};
}

void test_optional()
{
    cout<<"test_optional start"<<endl;
    std::optional<int> a(10);
    cout<<"a = "<<a.value()<<endl;
    std::optional<string> str("Hello!");
    cout<<"str = "<<str.value()<<endl;
    if(!str){
        cout<<"!str is true"<<endl;
    }else{
        cout<<"!str is false"<<endl;
    }
}

void test_simple()
{
    std::array<int,10> a={3,4};
    cout<<"array:"<<a.size()<<" "<<a[1]<<" "<<a[2]<<endl;
}

#define FOREACH_INTERP_RESULT(V)                                            \
  V(Ok, "ok")                                                               \
  /* returned from the top-most function */                                 \
  V(Returned, "returned")                                                   \
  /* memory access is out of bounds */                                      \
  V(TrapMemoryAccessOutOfBounds, "out of bounds memory access")             \
  /* atomic memory access is unaligned  */                                  \
  V(TrapAtomicMemoryAccessUnaligned, "atomic memory access is unaligned")   \
  /* converting from float -> int would overflow int */                     \
  V(TrapIntegerOverflow, "integer overflow")                                \
  /* dividend is zero in integer divide */                                  \
  V(TrapIntegerDivideByZero, "integer divide by zero")                      \
  /* converting from float -> int where float is nan */                     \
  V(TrapInvalidConversionToInteger, "invalid conversion to integer")        \
  /* function table index is out of bounds */                               \
  V(TrapUndefinedTableIndex, "undefined table index")                       \
  /* function table element is uninitialized */                             \
  V(TrapUninitializedTableElement, "uninitialized table element")           \
  /* unreachable instruction executed */                                    \
  V(TrapUnreachable, "unreachable executed")                                \
  /* call indirect signature doesn't match function table signature */      \
  V(TrapIndirectCallSignatureMismatch, "indirect call signature mismatch")  \
  /* ran out of call stack frames (probably infinite recursion) */          \
  V(TrapCallStackExhausted, "call stack exhausted")                         \
  /* ran out of value stack space */                                        \
  V(TrapValueStackExhausted, "value stack exhausted")                       \
  /* we called a host function, but the return value didn't match the */    \
  /* expected type */                                                       \
  V(TrapHostResultTypeMismatch, "host result type mismatch")                \
  /* we called an import function, but it didn't complete succesfully */    \
  V(TrapHostTrapped, "host function trapped")                               \
  /* we attempted to call a function with the an argument list that doesn't \
   * match the function signature */                                        \
  V(ArgumentTypeMismatch, "argument type mismatch")                         \
  /* we tried to get an export by name that doesn't exist */                \
  V(UnknownExport, "unknown export")                                        \
  /* the expected export kind doesn't match. */                             \
  V(ExportKindMismatch, "export kind mismatch")

enum class Result1 {
#define V(Name, str) Name,
  FOREACH_INTERP_RESULT(V)
#undef V
};

enum class rr{
    OK,
    RETURN
};

extern int test_smartptr();

class stl_test
{
private:
    /* data */
public:
    stl_test(/* args */);
    ~stl_test();
};

stl_test::stl_test(/* args */)
{
    //cout<<"result:"<<int(rr::OK)<<endl;
    //cout<<"result:"<<int(Result1::Ok)<<int(Result1::Returned);
    std::cout<<"****************************************************************************************************************************************"<<std::endl;
    ilog("test std start.");
    // test_numeric_limits();
    // test_simple();
    // test_optional();
    // test_smartptr();
    // test_variant();
    // test_lambda();
    // test_namespace();
    // test_template();
    // test_uint128();
    // test_hash();
    // test_ofstream();
    // test_sstream();
    // test_path();
    // test_friend();
    // test_operator();
    // test_typeid();
    // test_yinyong();
    // test_cast();
    // test_struct();
    // test_map();
    // cerr<<"it is std error."<<endl;
    // clog<<"it is std log"<<endl;
    // cout<<"numeric_limits int64_t:"<<std::numeric_limits<int64_t>::max()<<endl;
    // cout<<"numeric_limits int8_t:"<<std::numeric_limits<int8_t>::max()<<endl;  //无法正确输出
    // cout<<"numeric_limits int16_t:"<<std::numeric_limits<int16_t>::max()<<endl;
    // cout<<"std::log1p: "<<std::log1p(0.05);
    // test_exception();
    // test_decltype t_decltype;
    // test_tuple t_tuple;
    // test_rand t_rand;
    // test_enable_if t_enable_if;
    // test_virtual t_virtual;
    // test_set t_set;
    // test_va_list t_va;
    // test_queue t_equeue;
    // test_array t_array;
    // test_stack t_stack;
    // test_list t_list;
    // test_heap t_heap;
    //test_string t_str;
    //test_stream t_stream;
}

stl_test::~stl_test()
{
}
