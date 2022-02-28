#include "../common.h"
#include <math.h>

using namespace std;

class test_float
{
private:
    /* data */
public:
    test_float(/* args */);
    ~test_float();
};

test_float::test_float(/* args */)
{
    ilog("test float in");
    float f1 = 1.01;
    float f2 = 1.02;
    if(fabs(f1 - f2) < 1e-9){
        cout << "f1 == f2" << endl;
    }
    else{
        cout << "f1 != f2" << endl;
    }
}

test_float::~test_float()
{
}
