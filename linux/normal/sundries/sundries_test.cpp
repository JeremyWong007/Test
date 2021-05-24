#include <iostream>
#include <vector>
#include <map>

using namespace std;

#include <iomanip>
void show_vector(vector<char> &v){
    std::cout<<"show:";
    for(auto c:v){
        uint8_t tmp=c;
        std::cout<<std::hex<<std::setw(2)<<std::setfill('0')<<(uint64_t)tmp<<std::dec;
    }
    std::cout<<std::endl;
}

void test_show(){
    cout<<"test show start."<<endl;
    vector<char> data;
    data.push_back(0x1);
    data.push_back(0xff);
    data.push_back(0xee);
    show_vector(data);
}

void test_fucptr(){
    cout<<"test fuc ptr start."<<endl;
    int aa = 15;
    auto it = [&]{
        cout<<"aa="<<aa;
        return aa;
    };
    it();
    cout<<"end?"<<endl;
}

void say(int a,int b=10,int c=11)
{
    cout<<"say:"<<a<<b<<c<<endl;
}

void sundries_test()
{
    cout<<"#######################################################################################"<<endl;
    cout<<"sundries test start"<<endl;
    say(1);
    say(1,2);
    say(1,2,3);
    test_fucptr();
    test_show();
}