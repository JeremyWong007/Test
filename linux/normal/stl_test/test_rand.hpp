#include "../common.h"

using namespace std;

class test_rand
{
private:
    /* data */
public:
    test_rand(/* args */);
    ~test_rand();
};

test_rand::test_rand(/* args */)
{
    ilog("test rand in");
    srand(time(0));
    //srand(1);
    cout<<"rand:"<<rand()<<" "<<rand()<<" "<<rand()<<endl;
    //srand(time(0)+1);
    srand(1);
    srand(time(0)+1);
    cout<<"rand:"<<rand()<<" "<<rand()<<" "<<rand()<<endl;
}

test_rand::~test_rand()
{
}
