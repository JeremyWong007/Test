#include <vector>
#include "../common.h"

using namespace std;

class test_vector
{
private:
    /* data */
public:
    test_vector(/* args */);
    void test_vector_iter();
    ~test_vector();
};

void test_vector::test_vector_iter()
{
    ilog("test_vector_iter in");
    vector<int> v{1,2,3};
    auto it = v.begin();
    auto a = *it;
    ilog("a=%d", a);
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);
    a = *it;
    ilog("a=%d", a);
}

test_vector::test_vector(/* args */)
{
    ilog("test vector in");
    vector<vector<int>> vv{{1,2,3},{4,5,6},{7,8,9}};
    cout << vv[1][2] << endl;
    cout << vv[2][2] << endl;
    cout << vv[0][1] << endl;
    vv.resize(4);
    vector<int> v2={1,2,3,4};
    v2.resize(5,2);
    print(v2);

    test_vector_iter();
}

test_vector::~test_vector()
{
}
