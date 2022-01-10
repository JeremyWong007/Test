/*stream
使用场景：
1 格式转换
2 string s; getline(cin,s); stringstream ss(s); for(string s1;ss>>s1;cout<<s1<<endl); 

注意：
1 如果你打算在多次转换中使用同一个stringstream对象，记住在每次转换前要使用clear()方法；
2 那么把stringstream类内部的缓冲区正确的清空方式是什么呢? stringstream ss; 答案是: ss.str(“”) 
3 所以, 保险起见, 每次缓冲区格式化后, 都通过clear(), str(“”) 两个函数都调用, 把stingstream类复位.
*/

#include "../common.h"
#include <sstream>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class test_stream
{
private:
    /* data */
public:
    test_stream(/* args */);
    ~test_stream();
    
    void test_fstream(){
        ifstream file;
        file.open("../input.txt");
        stringstream ss;
        string str,str2;
        while(getline(file, str)){
            //cout<<str<<endl;
            stringstream ss(str);
            while (getline(ss, str2, ' '))
            {
                cout<<str2<<endl;
            }
            // while(ss>>str2){
            //     cout<<str2<<endl;
            // }
        }
        file.close();
    }
};

test_stream::test_stream(/* args */)
{
    ilog("test stream in");
    string str="114 Hello", str3;
    int i=0;
    stringstream sst;
    sst << "115";
    //sst >> str3;
    cout << "i=" << str3 <<endl;
    //sst.clear();
    //sst.str("");
    sst << "haha";
    //sst << "heihei";
    sst >> str3;
    cout << str3<<endl;
    cout << str3<<endl;
    cout<<sst.str()<<endl;

    stringstream sstream;
    // 将多个字符串放入 sstream 中
    sstream << "first" << " " << "string,";
    sstream << " second string";
    cout << "strResult is: " << sstream.str() << endl;
 
    // 清空 sstream
    //sstream.str("");
    sstream << "third string";
    cout << "After clear, strResult is: " << sstream.str() << endl;

    int a=119;
    float f=11.22;
    //string str4;
    //tools::to_string(str4, a);
    //cout<<"str4:"<<str4<<endl;
    //tools::to_string(str4, f);
    //cout<<"str4:"<<str4<<endl;
    cout<<tools::convert<string>(a)<<endl;
    cout<<tools::convert<string>(f)<<endl;

    // string str5;
    // getline(cin, str5, ',');
    // cout<<"str5: "<<str5<<endl;
    // stringstream ss(str5);
    // for(string str; ss>>str; cout<<str<<endl);

    test_fstream();
}

test_stream::~test_stream()
{
}
