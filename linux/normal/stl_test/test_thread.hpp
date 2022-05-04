#include "../common.h"
#include <thread>

using namespace std;

class test_thread
{
private:
    /* data */
public:
    test_thread(/* args */);
    ~test_thread();
};

test_thread::test_thread(/* args */)
{
    ilog("test_thread in");
    auto f = [](int i){
        cout<<"i="<<i<<"thread id: "<<std::this_thread::get_id()<<endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    };
    thread t1(f, 2);
    t1.join();

    std::shared_ptr<std::thread> pth;
    pth = std::make_shared<std::thread>(f, 3);
    pth->join();
}

test_thread::~test_thread()
{
}
