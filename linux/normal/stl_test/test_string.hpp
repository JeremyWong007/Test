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
    bool replaceAll(string &str1,string from, string to){
        string::size_type n=0;
        bool ret = false;
        while(n != string::npos){
            n = str1.find(from, n);
            if(n != string::npos){
                str1.replace(n, from.size(), to);
                n += to.size();
                ret = true;
            }
        }
        return ret;
    }
};

test_string::test_string(/* args */)
{
    cout<<"test string start"<<endl;
    string str="Hello! Nice to meet you. How do you do. you you";

    cout<<"find num: "<<findNum(str, "you")<<endl;
    cout<<"find_first_of:"<<str.find_first_of("yuNiH")<<endl;
    cout<<"find_first_not_of:"<<str.find_first_not_of("HeloNic")<<endl;

    string str2=str;
    replaceAll(str2, "you", "him");
    cout << "str2:" << str2 <<endl;

    int num=0;
    string::iterator it = str.begin();
    for(; it!=str.end(); it++){
        if(*it == 'o'){
            num++;
        }
    }
    cout << "o's num = "<<num<<endl;
}

test_string::~test_string()
{
}
