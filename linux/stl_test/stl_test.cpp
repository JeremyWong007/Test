#include <iostream>
#include <optional>
#include <variant>
#include <array>

using namespace std;

template<typename T1,typename T2,typename T3>
void func1(T2 a){
    cout<<"fucn1:"<<a<<endl;
}

template<typename T1,typename T2,typename T3>
struct st1{
    template<typename T4>
    void func1(T4 a){
        cout<<"fucn1:"<<a<<endl;
    }
};


void test_template(){
    cout<<"test template start"<<endl;
    func1<int,int,int>(9);
    st1<int,int,string> s1;
    s1.template func1("tt");
    s1.func1("HaHa");

    /*
    总结：
    1 template的最后一个模板参数与函数入参相同时可以省略。如果不是最后一个参数，不可以省略。
    2 .template告诉编译器后面的变量为模板。
    */
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

class Cars{
    private:
    int price=20;
    friend class Drivers;
};
class Drivers{
    Cars c;
    public:
    void show()
    {
        cout<<"Drivers price is"<<c.price<<endl;
    }
};

void test_friend()
{
    cout<<"test friend start"<<endl;
    Drivers d;
    d.show();
}
struct teststring{
    public:
    uint64_t value;
    teststring(uint64_t v):value(v){};

    /**
     *  Returns the length of the %name
     */
    constexpr uint8_t length()const {
        constexpr uint64_t mask = 0xF800000000000000ull;

        if( value == 0 )
        return 0;

        uint8_t l = 0;
        uint8_t i = 0;
        for( auto v = value; i < 13; ++i, v <<= 5 ) {
        if( (v & mask) > 0 ) {
            l = i;
        }
        }

        return l + 1;
    }

    char* write_as_string( char* begin, char* end, bool dry_run = false )const {
         static const char* charmap = ".12345abcdefghijklmnopqrstuvwxyz";
         constexpr uint64_t mask = 0xF800000000000000ull;

         if( dry_run || (begin + 13 < begin) || (begin + 13 > end) ) {
            char* actual_end = begin + length();
            if( dry_run || (actual_end < begin) || (actual_end > end) ) return actual_end;
         }

         auto v = value;
         for( auto i = 0; i < 13; ++i, v <<= 5 ) {
            if( v == 0 ) return begin;

            auto indx = (v & mask) >> (i == 12 ? 60 : 59);
            *begin = charmap[indx];
            ++begin;
         }

         return begin;
      }

      /**
       *  Returns the name as a string.
       *
       *  @brief Returns the name value as a string by calling write_as_string() and returning the buffer produced by write_as_string()
       */
      std::string to_string()const {
         char buffer[13];
         auto end = write_as_string( buffer, buffer + sizeof(buffer) );
         return {buffer, end};
      }
};
void test_string()
{
    cout<<"test string start"<<endl;
    teststring ts(1122334455);
    cout<<ts.to_string()<<endl;
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
    std::optional<int> a(10);
    cout<<"a = "<<a.value()<<endl;
}

void test_simple()
{
    std::array<int,10> a={3,4};
    cout<<"array:"<<a.size()<<" "<<a[1]<<" "<<a[2]<<endl;
}

extern int test_smartptr();
void test_std()
{
    cout<<"test std start."<<endl;
    std::cout<<"********************************************************************************************"<<std::endl;
    test_simple();
    test_optional();
    test_smartptr();
    test_variant();
    test_lambda();
    test_string();
    test_friend();
    test_namespace();
    test_template();
}