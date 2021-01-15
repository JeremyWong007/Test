#include <iostream>
#include <optional>
#include<boost/tuple/tuple.hpp> 
#include<boost/tuple/tuple_io.hpp> 
#include <boost/tuple/tuple_comparison.hpp>
#include <boost/bind.hpp>

using namespace std;

/*
compile command:g++ -std=c++17 main.cpp -o main
*/
//#include <boost/asio.hpp>
//#include <boost/thread.hpp>
//#include <boost/date_time/posix_time/posix_time.hpp>
using namespace std;


// void Print(const boost::system::error_code &ec)
// {
//     cout<<"Hello World!"<<endl;
//     cout<<boost::this_thread::get_id()<<endl;
// }
int asio_test()
{
    // cout<<"asio test start."<<endl;
    // cout<<boost::this_thread::get_id()<<endl;
    // boost::asio::io_service io;
    // boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));

    // t.async_wait(Print);
    // cout<<"to run"<<endl;
    // io.run();
    // cout<<"exit"<<endl;
    return 0;
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

int main(void)
{
    cout<<"Hello world"<<endl;
    optional<int> a(10);
    a=11;
    int b=a.value();
    cout<<"a="<<a.value()<<endl;
    cout<<"b="<<b<<endl;
    test_tuple();
    return 0;
}