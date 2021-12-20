#include "../common.h"

using namespace std;


class test_string
{
private:
    /* data */
public:
    test_string(/* args */);
    ~test_string();
    int findNum(string str1, string str2){
        string::size_type ret=0;
        int num=0;
        while(ret != string::npos){
            ret = str1.find(str2, ret);
            //cout << "ret=" << ret << "npos:" <<string::npos;
            if(ret != string::npos){
                num++;
                ret++;
            }
        }
        return num;
    }
};

test_string::test_string(/* args */)
{
    cout<<"test string start"<<endl;
    string str="Hello! Nice to meet you. How do you do. you you";
    cout<<"find num: "<<findNum(str, "you")<<endl;
}

test_string::~test_string()
{
}
