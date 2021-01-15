#include <iostream>
#include <optional>

using namespace std;

extern int test_smartptr();


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

void test_std()
{
    cout<<"test std start."<<endl;
    test_optional();
    test_smartptr();
}