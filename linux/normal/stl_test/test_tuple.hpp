#include "../common.h"
#include <iostream>

using namespace std;

template<typename Tuple, size_t N>
struct tuple_show
{
    static void show(const Tuple& t, std::ostream& os){
        tuple_show<Tuple, N-1>::show(t, os);
        os << ", " << std::get<N-1>(t);
    }
};
template<typename Tuple>
struct tuple_show<Tuple, 1>
{
    static void show(const Tuple& t, std::ostream& os){
        os << std::get<0>(t);
    }
};
template<typename... Args>
std::ostream& operator<<(std::ostream& os, std::tuple<Args...>& t){
    os<<"[";
    tuple_show<decltype(t), sizeof...(Args)>::show(t, std::cout);
    os<<"]";
    return os;
}

class test_tuple
{
private:
    /* data */
public:
    test_tuple(/* args */);
    ~test_tuple();
        
    auto make(void){
        static int i=2;
        //tuple<int, float, double, long, long long> first(12, 1.2, 3.4, 11, 22);
        tuple<int&, string, float, double, long, long long> first=std::make_tuple(std::ref(i), "hello", 1.2, 3.4, 11, 22);
        std::get<0>(first) = 3;
        cout<<"get0:"<<std::get<0>(first)<<endl;
        cout<<"tuple_size="<<std::tuple_size<decltype(first)>::value<<endl;
        std::tuple_element<1,decltype(first)>::type str("Haha");
        cout<<"str="<<str<<endl;
        float f=5.5;
        std::tie(std::ignore, str, f, std::ignore, std::ignore, std::ignore) = first;
        cout<<"str2="<<str<<endl;
        auto second = std::tuple_cat(first, std::make_tuple(33, 44, "world"));
        return first;
    }
};

test_tuple::test_tuple(/* args */)
{
    ilog("test tuple in");
    auto tt = make();
    cout<<tt;
}

test_tuple::~test_tuple()
{
}
