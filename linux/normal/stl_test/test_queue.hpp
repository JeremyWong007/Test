#include "../common.h"
#include <queue>

/*
queue:

deque:双端队列

*/

using namespace std;
class test_queue
{
private:
    /* data */
public:
    test_queue(/* args */);
    ~test_queue();
};

test_queue::test_queue(/* args */)
{
    ilog("test equeue in");
    std::queue<std::string> queue1;
    queue1.push("Lao li");
    queue1.push("Lao wang");
    queue1.push("Lao yu");
    cout << "First is " << queue1.front() << endl;
    cout << "size is " << queue1.size() << endl;
    cout << "Last is " << queue1.back() << endl;
    queue1.push("Lao chen");
    queue1.push("Lao ying");
    queue1.push("Lao tu");
    queue1.pop();
    queue1.pop();
    cout << "Leave 2 and come 3" << endl;
    cout << "First is " << queue1.front() << endl;
    cout << "size is " << queue1.size() << endl;
    cout << "Last is " << queue1.back() << endl;
}

test_queue::~test_queue()
{
}
