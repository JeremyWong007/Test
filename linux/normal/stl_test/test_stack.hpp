#include "../common.h"
#include <stack>

using namespace std;
class test_stack
{
private:
    /* data */
public:
    test_stack(/* args */);
    ~test_stack();
};

test_stack::test_stack(/* args */)
{
    ilog("test stack in");
    std::stack<std::string> st;
    st.push("Hello");
    st.push("world");
    st.push(".");
    cout << "st is " << st.top();
    st.pop();
    cout << " " << st.top();
    st.pop();
    cout << " " << st.top();
    st.pop();
    //cout << " " << st.top();
    cout << endl;
}

test_stack::~test_stack()
{
}
