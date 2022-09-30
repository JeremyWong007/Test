#include <vector>
#include <functional>
#include "../common.h"

using namespace std;

class test_function
{
private:
    /* data */
    void call(std::function<void(int, int, int)> f){
        cout << "test_function call in" << endl;
        if(f){
            f(1,2,3);
        }
        else{
            cout << "f is null" << endl;
        }
    }
public:
    test_function(/* args */);
    ~test_function();
};

void f1(int a, int b, int c){
    cout << "f: " << a << b << c <<endl;
}

test_function::test_function(/* args */)
{
    ilog("test function in");
    
    //std::function<void(int, int, int)> f;
    //call(std::function<void(int, int, int)>());
    call(f1);
    
}

test_function::~test_function()
{
}
